/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:13:27 by jfarinha          #+#    #+#             */
/*   Updated: 2024/12/27 20:05:03 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <MLX42/MLX42.h>

# define FOV 90.0f
# define ZFAR 1000.0f
# define WINW 1400
# define WINH 720
# define WINNAME "Fdf"
# define STDW 500.0f
# define STDH 500.0f
# define ZNEAR 0.1f
# define GRIDSCALE 5
# define PI 3.14159265359
# define DEGREETORAD(angle) (angle * PI) / 180;

/*
** Make Vector Defines
*/
#define MAKE_VECTOR2F(x, y)         (t_vector2f){{{x, y}}}
#define MAKE_VECTOR2I(x, y)         (t_vector2i){{{x, y}}}
#define MAKE_VECTOR3F(x, y, z)      (t_vector3f){{{x, y, z}}}
#define MAKE_VECTOR3I(x, y, z)      (t_vector3i){{{x, y, z}}}
#define MAKE_VECTOR4F(x, y, z, w)   (t_vector4f){{{x, y, z, w}}}
#define MAKE_VERTOR4I(x, y, z, w)   (t_vector4i){{{x, y, z, w}}}

/*
** Some Key codes
*/
# define XK_ESC		0xFF1B
# define XK_UP		0xFF52
# define XK_DOWN	0xFF54
# define XK_LEFT	0xFF51
# define XK_RIGHT	0xFF53
# define XK_Z		0x007A
# define XK_S		0x0073
# define XK_Q		0x0071
# define XK_D		0x0064
# define XK_A		0x0061
# define XK_E		0x0065
# define XK_W		0x0077
# define XK_KP_ADD	0xffab
# define XK_KP_SUB	0xffad
# define MK_ESC		53

typedef unsigned char	t_uchar;
typedef unsigned int	t_size;

/*
**  Matrix type definitions
*/
typedef struct          s_matrix3f
{
    union
    {   
        float m[3][3];
       
        struct
        {
            float m00, m01, m02, m03;
            float m10, m11, m12, m13;
            float m20, m21, m22, m23;
            float m30, m31, m32, m33;

        };

    };
}                       t_matrix3f, *ptr_matrix3f;

typedef struct          s_matrix4f
{
    union
    {   
        float m[4][4];
       
        struct
        {
            float m00, m01, m02, m03;
            float m10, m11, m12, m13;
            float m20, m21, m22, m23;
            float m30, m31, m32, m33;

        };

    };
}                       t_matrix4f, *ptr_matrix4f;

/*
**  VectorI type definitions
*/
typedef struct			s_vector2i
{
    union
    {
        int m[2];
       
        struct 
        {
            int	x;
	        int	y;
        };
    };
}						t_vector2i, *ptr_vector2i;

typedef struct			s_vector2ui
{
    union
    {
        unsigned int m[2];
       
        struct 
        {
            unsigned  int	x;
            unsigned  int	y;
        };
    };
}                       t_vector2ui, *ptr_vector2ui;

typedef struct			s_vector3i
{
    union
    {
        int m[3]; 

        struct
        {
	        int x;
	        int y;
	        int z;
        };
    };
}                       t_vector3i, *ptr_vector3i;

typedef struct          s_vector4i 
{
    union
    {
        int m[4];

        struct
        {
            int x;
            int y;
            int z;
            int w;
        };
    };
}                       t_vector4i, *ptr_vector4i;

/*
**  VectorF type definitions
*/
typedef struct			s_vector2f
{
    union
    {
        float m[2];
       
        struct 
        {
            float	x;
	        float	y;
        };
    };
}						t_vector2f, *ptr_vector2f;

typedef struct			s_vector3f
{
    union
    {
        float m[3]; 

        struct
        {
	        float	x;
	        float	y;
	        float	z;
        };
    };
}                       t_vector3f, *ptr_vector3f;

typedef struct          s_vector4f
{
    union
    {
        float m[4];

        struct
        {
            float x;
            float y;
            float z;
            float w;
        };
    };
}                       t_vector4f, *ptr_vector4f;

/*
**  System type definitions
*/
typedef struct		s_sys
{
	mlx_t	    	*mlx;
	t_vector4f      **map;
	t_vector3f  	translate;
	t_vector3f  	scale;
	t_vector3f  	rotation;
	t_matrix4f  	projection;
	t_size	    	size_x;
	t_size	    	size_y;
	t_size	    	size_z;
	float	    	a;
	float	    	f;
	float	    	q;
    float           angle;
    mlx_image_t     *screenSurface;
}			    	t_sys;

/*
**Brazehan internal data structure
*/
typedef struct      s_BrazehanData
{
    mlx_image_t     *screen;
    t_vector2i      delta;
    t_vector2i      sign;
    t_vector2i      start;
    t_vector2i      end;
    int             error;
    int             color;
}                   t_brazehanData;

/*
** Draw.c
*/
void         		draw(void *env);
void				line(t_sys *sys, t_vector2f a, t_vector2f b, int color);
t_matrix4f			loadProjection(void);

/*
** Utils.c
*/
int					on_screen(t_vector4f pt);
int					mkcolor(t_uchar a, t_uchar b, t_uchar g, t_uchar r);
/*
** Hook.c
*/
void				keyhook(void *p);
/*
**Load.c
*/
void				load(char *map, t_sys *env);
/*
**Matrix4
*/
ptr_matrix4f		newMatrix4f(void);
void				delMatrix4(ptr_matrix4f m);
/*
**MatrixOp.c
*/
void				matrix4Mul(ptr_matrix4f a, ptr_matrix4f b, ptr_matrix4f buff);
t_vector4f			vec4Mul(t_matrix4f mat, ptr_vector4f vec);
t_vector4f	        vec4MulHomogenous(t_matrix4f mat, ptr_vector4f vec);
/*
**Transform.c
*/
void    		    initTranslate(t_sys *env, ptr_matrix4f m);
void				initScale(t_sys *env, ptr_matrix4f m);
void				initRotation(t_sys *env, ptr_matrix4f m);
/*
**ScreenBuffer.c
*/
int                 drawBuffer(t_sys *env);
void                freeScreenSurface(t_sys *env);
void                clearScreenSurface(t_sys *env, int color);
void                putPixelToScreenSurface(mlx_image_t *screen, t_vector2i point, int color);
mlx_image_t         *initScreenSurface(t_sys *env, t_size width, t_size height);
void                resizeScreenSurface(int32_t width, int32_t height, void *sys);
/*
**Line.c
*/
void                ddaLine(t_sys *env, t_vector2f a, t_vector2f b, int color);
void                brazehanLine(t_sys *env, t_vector2i a, t_vector2i b, int color);
/*
**Math.c
*/
int                 mini(int  a, int b);
int                 maxi(int  a, int b);
float               minf(float a, float b);
float               maxf(float a, float b);
double              mind(double a, double b);
double              maxd(double a, double b);
/*
**Vector.C
*/
t_vector2f          clampVector2f(t_vector2f clampValue, t_vector2f min, t_vector2f max);
t_vector2i          clampVector2i(t_vector2i clampValue, t_vector2i min, t_vector2i max);
t_vector3f          clampVector3f(t_vector3f clampValue, t_vector3f min, t_vector3f max);
t_vector3i          clampVector3i(t_vector3i clampValue, t_vector3i min, t_vector3i max);
t_vector4f          clampVector4f(t_vector4f clampValue, t_vector4f min, t_vector4f max);
t_vector4i          clampVector4i(t_vector4i clampValue, t_vector4i min, t_vector4i max);
t_vector2i          divVector2iByScalar(t_vector2i vector, int scalar);
t_vector2f          divVector2fByScalar(t_vector2f vector, float scalar);
t_vector3i          divVector3iByScalar(t_vector3i vector, int scalar);
t_vector3f          divVector3fByScalar(t_vector3f vector, float scalar);
t_vector4i          divVector4iByScalar(t_vector4i vector, int scalar);
t_vector4f          divVector4fByScalar(t_vector4f vector, float scalar);
t_vector2i          mulVector2iByScalar(t_vector2i vector, int scalar);
t_vector2f          mulVector2fByScalar(t_vector2f vector, float scalar);
t_vector3i          mulVector3iByScalar(t_vector3i vector, int scalar);
t_vector3f          mulVector3fByScalar(t_vector3f vector, float scalar);
t_vector4i          mulVector4iByScalar(t_vector4i vector, int scalar);
t_vector4f          mulVector4fByScalar(t_vector4f vector, float scalar);
#endif

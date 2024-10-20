/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:13:27 by jfarinha          #+#    #+#             */
/*   Updated: 2019/09/26 20:45:40 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define FOV 90.0f
# define ZFAR 1000.0f
# define WINW 800.0f
# define WINH 600.0f
# define STDW 500.0f
# define STDH 500.0f
# define ZNEAR 0.1f
# define SWAPSCREENSURFACE(screenSurface) screenSurface = screenSurface->next;
# define GRIDSCALE 5

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
typedef void            *t_image;

/*
**  Matrix type definitions
*/
typedef struct          s_matrix3f
{
    union
    {   
        double m[3][3];
       
        struct
        {
            double m00, m01, m02, m03;
            double m10, m11, m12, m13;
            double m20, m21, m22, m23;
            double m30, m31, m32, m33;

        };

    };
}                       t_matrix3f, *ptr_matrix3f;

typedef struct          s_matrix4f
{
    union
    {   
        double m[4][4];
       
        struct
        {
            double m00, m01, m02, m03;
            double m10, m11, m12, m13;
            double m20, m21, m22, m23;
            double m30, m31, m32, m33;

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
        double m[2];
       
        struct 
        {
            double	x;
	        double	y;
        };
    };
}						t_vector2i, *ptr_vector2i;

typedef struct			s_vector3i
{
    union
    {
        double m[3]; 

        struct
        {
	        double	x;
	        double	y;
	        double	z;
        };
    };
}                       t_vector3i, *ptr_vector3i;

typedef struct          s_vector4i 
{
    union
    {
        double m[4];

        struct
        {
            double x;
            double y;
            double z;
            double w;
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
        double m[2];
       
        struct 
        {
            double	x;
	        double	y;
        };
    };
}						t_vector2f, *ptr_vector2f;

typedef struct			s_vector3f
{
    union
    {
        double m[3]; 

        struct
        {
	        double	x;
	        double	y;
	        double	z;
        };
    };
}                       t_vector3f, *ptr_vector3f;

typedef struct          s_vector4f
{
    union
    {
        double m[4];

        struct
        {
            double x;
            double y;
            double z;
            double w;
        };
    };
}                       t_vector4f, *ptr_vector4f;

typedef struct          s_screenSurface
{
    t_image                 image;
    int                     pixelSize;
    int                     lineSize;
    int                     indian;
    char *                  addr;
    struct s_screenSurface  *next;
}                       t_screenSurface;

/*
**  System type definitions
*/
typedef struct		s_sys
{
	t_vector4f      **map;
	t_vector3f  	translate;
	t_vector3f  	scale;
	t_vector3f  	rotation;
	t_matrix4f  	projection;
	t_size	    	size_x;
	t_size	    	size_y;
	t_size	    	size_z;
	double	    	a;
	double	    	f;
	double	    	q;
	void	    	*mlx;
	void		    *win;
    t_screenSurface *screenSurface;
}			    	t_sys;

/*
** Draw.c
*/
int         		draw(t_sys *env);
void				line(t_sys *sys, t_vector4f a, t_vector4f b, int color);
t_matrix4f			loadProjection(double a, double f, double q);
/*
** Utils.c
*/
int					on_screen(t_vector4f pt);
int					mkcolor(t_uchar r, t_uchar g, t_uchar b);
/*
** Hook.c
*/
int					keyhook(int keycode, void *p);
/*
**Load.c
*/
void				load(char *map, t_sys *env);
/*
**Matrix4
*/
ptr_matrix4f		newMatrix4(void);
void				delMatrix4(ptr_matrix4f m);
/*
**MatrixOp.c
*/
void				matrix4Mul(ptr_matrix4f a, ptr_matrix4f b, ptr_matrix4f buff);
t_vector4f			vec4Mul(t_matrix4f mat, ptr_vector4f vec);
/*
**Transform.c
*/
void				initTranslate(t_sys *env, ptr_matrix4f m);
void				initScale(t_sys *env, ptr_matrix4f m);
void				initRotation(t_sys *env, ptr_matrix4f m);
/*
**ScreenBuffer.c
*/
void                clearScreenSurface(t_sys *env);
void                freeScreenSurface(t_sys *env);
t_screenSurface     *initScreenSurface(t_sys *env, t_size width, t_size height);
t_screenSurface     *resizeSceenSurface(t_sys *env, t_size width, t_size height);
#endif

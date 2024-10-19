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
typedef struct          s_matrix4f
{
    union
    {             
        /*  
        ** Index array definition
        */
        float m[4][4];
        /*
        ** Explicit Name Variables
        */
        struct
        {
            float m00, m01, m02, m03;
            float m10, m11, m12, m13;
            float m20, m21, m22, m23;
            float m30, m31, m32, m33;

        };

    };
}                       t_matrix4f, *p_matrix4f;
typedef struct			s_point
{
    double	x;
	double	y;
}						t_point;
typedef struct          s_screenSurface
{
    t_image                 image;
    int                     pixelSize;
    int                     lineSize;
    int                     indian;
    char *                  addr;
    struct s_screenSurface  *next;
}                       t_screenSurface;
typedef struct			s_vector3f
{
	double	x;
	double	y;
	double	z;
}					t_vector3f;
typedef struct		s_sys
{
	t_vector3f  	**map;
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
void				line(t_sys *sys, t_vector3f a, t_vector3f b, int color);
t_matrix4f			loadProjection(double a, double f, double q);
/*
** Utils.c
*/
int					on_screen(t_vector3f pt);
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
p_matrix4f			newMatrix4(void);
void				delMatrix4(p_matrix4f m);
/*
**MatrixOp.c
*/
void				matrix4Mul(p_matrix4f a, p_matrix4f b, p_matrix4f buff);
t_vector3f			vec4Mul(p_matrix4f mat, t_vector3f vec);
/*
**Transform.c
*/
void				initTranslate(t_sys *env, p_matrix4f m);
void				initScale(t_sys *env, p_matrix4f m);
void				initRotation(t_sys *env, p_matrix4f m);
/*
**ScreenBuffer.c
*/
void                clearScreenSurface(t_sys *env);
void                freeScreenSurface(t_sys *env);
t_screenSurface     *initScreenSurface(t_sys *env, t_size width, t_size height);
t_screenSurface     *resizeSceenSurface(t_sys *env, t_size width, t_size height);
#endif

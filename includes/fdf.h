/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:13:27 by jfarinha          #+#    #+#             */
/*   Updated: 2018/11/06 15:53:36 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINW 600
# define WINH 400
# define STDW 30
# define STDH 30
/*
** Some Key codes
*/
# define XK_ESC		53
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
typedef unsigned char	t_uchar;
typedef unsigned int	t_size;
typedef struct		s_point
{
	double	x;
	double	y;
}					t_point;
typedef struct		s_vector3f
{
	double	x;
	double	y;
	double	z;
}					t_vector3f;
typedef struct		s_sys
{
	t_vector3f	**map;
	t_vector3f	cam;
	t_size		size_x;
	t_size		size_y;
	void		*mlx;
	void		*win;
}				t_sys;
/*
** Draw.c
*/
void				draw(t_sys *env);
void				line(t_sys sys, t_point a, t_point b, int color);
/*
** Utils.c
*/
int					on_screen(t_point pt);
int					mkcolor(t_uchar r, t_uchar g, t_uchar b);
t_point				vectop(t_vector3f vector, t_vector3f cam);
/*
** Hook.c
*/
int					keyhook(int keycode, void *p);
/*
**Load.c
*/
void				load(char *map, t_sys *env);
#endif

#include <fdf.h>
#include <libft.h>
#include <mlx.h>
#include <stdio.h>
// #define malloc(x) NULL

t_screenSurface *initScreenSurface(t_sys *env, t_size width, t_size height) {
    t_screenSurface *surface1 = malloc(sizeof(t_screenSurface));
    t_screenSurface *surface2 = malloc(sizeof(t_screenSurface));

    ft_thrower(!env->mlx, "MLX pointer is NULL");
    ft_thrower(!surface1,
             "Couldn't malloc enought space to allocate surface 1\n");
    ft_thrower(!surface2,
             "Couldn't malloc enought space to allocate surface 2\n");

    surface1->image = (t_image)mlx_new_image(env->mlx, width, height);
    surface1->next = surface2;
    surface2->image = (t_image)mlx_new_image(env->mlx, width, height);
    surface2->next = surface1;

    ft_thrower(!surface1->image,
             "mlx couldn't allocate enought space for the surface1");
    ft_thrower(!surface2->image,
             "mlx couldn't allocate enought space for the surface2");

    surface1->addr = mlx_get_data_addr(surface1->image, &surface1->pixelSize, &surface1->lineSize, &surface1->indian);
    surface2->addr = mlx_get_data_addr(surface2->image, &surface2->pixelSize, &surface2->lineSize, &surface2->indian);

    return (surface1);
}

t_screenSurface *resizeScreenSurface(t_sys *env, t_size width, t_size height) {
    freeScreenSurface(env);
    t_screenSurface *tmp = initScreenSurface(env, width, height);

  return (tmp);
}
void freeScreenSurface(t_sys *env) 
{
  t_screenSurface *screenSurface1 = env->screenSurface;
  t_screenSurface *screenSurface2 = env->screenSurface->next;

  if (screenSurface1->image)
    mlx_destroy_image(env->mlx, screenSurface1->image);
  if (screenSurface2->image)
    mlx_destroy_image(env->mlx, screenSurface2->image);
  if (screenSurface1)
    free(screenSurface1);
  if (screenSurface2)
    free(screenSurface2);
}

void clearScreenSurface(t_sys *env)
{
    t_screenSurface *screen = env->screenSurface;

   printf("Pixel size: %d, %d pixels per line, in Indian %d at addr: %p\n", screen->pixelSize, screen->lineSize / (screen->pixelSize / 8), screen->indian, screen->addr);
}

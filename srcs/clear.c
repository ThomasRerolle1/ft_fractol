#include "../include/fractol.h"

void	clear_img(t_img *img)
{
	if (img)
	{
		free(img->addr);
		free(img);
		img = NULL;
	}
}

void	clear_env(t_env *env)
{
	if (env)
	{
		env->mlx = NULL;
		env->mlx_win = NULL;
		clear_img(env->img);
		free(env);
		env = NULL;
	}
}


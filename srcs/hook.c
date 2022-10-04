/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:10:19 by trerolle          #+#    #+#             */
/*   Updated: 2022/10/04 19:34:08 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_hook(int keycode, t_env *env)
{
	(void)env;
	if (keycode == K_ESC)
	{
		quit_hook(env);
		return (1);
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_env *env)
{
	convert_win_to_graph(env->plan, (double)x, (double)y);
	if (keycode == 1 && env->fractal_type == 2)
	{
		env->plan->real_julia = env->plan->x_img;
		env->plan->img_julia = env->plan->y_img;
		create_set(env);
		mlx_put_image_to_window(env->mlx, env->mlx_win, env->img->img, 0, 0);
	}
	if (keycode == 5 || keycode == 4)
		scroll_up(env, keycode);
	return (0);
}

int	scroll_up(t_env *env, int keycode)
{
	if (keycode == 5)
	{
		env->plan->x_abs /= 1.1;
		env->plan->y_abs /= 1.1;
		env->plan->x_max = env->plan->x_abs / 2;
		env->plan->y_max = env->plan->y_abs / 2;
	}
	else
	{
		env->plan->x_abs *= 1.1;
		env->plan->y_abs *= 1.1;
		env->plan->x_max = env->plan->x_abs / 2;
		env->plan->y_max = env->plan->y_abs / 2;
	}
	create_set(env);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img->img, 0, 0);
	return (0);
}

int	quit_hook(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img->img);
	mlx_destroy_window(env->mlx, env->mlx_win);
	clear_env(env);
	exit(0);
	return (0);
}

int	list_hooks(t_env *env)
{
	mlx_key_hook(env->mlx_win, key_hook, env);
	mlx_mouse_hook(env->mlx_win, mouse_hook, env);
	mlx_hook(env->mlx_win, 17, 1L << 4, quit_hook, env);
	return (0);
}

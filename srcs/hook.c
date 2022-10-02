/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:10:19 by trerolle          #+#    #+#             */
/*   Updated: 2022/10/02 20:43:42 by trerolle         ###   ########.fr       */
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
	//double	old_x_origin;
	//double	old_y_origin;


	convert_win_to_graph(env->plan, (double)x, (double)y);
	if (keycode == 1 && env->fractal_type == 2)
	{
		env->plan->real_julia = env->plan->x_img;
		env->plan->img_julia = env->plan->y_img;
		create_set(env);
		mlx_put_image_to_window(env->mlx, env->mlx_win, env->img->img, 0, 0);
	}
	if (keycode == 5)
	{
		scroll_up(env);
	}
	return (0);
}

int	scroll_up(t_env *env)
{
	t_complex	*new_frame;
/*	

	backup = env->plan;
	new_frame = env->plan;
	delta = env->plan;

	new_frame->x_abs = env->plan->x_abs / 1.1;
	new_frame->y_abs = env->plan->y_abs / 1.1;
	// compute delta
	delta->x_abs = env->plan->x_abs - new_frame->x_abs;
	delta->y_abs = env->plan->y_abs - new_frame->y_abs;
	// update all axes
	env->plan->x_max +=  delta->x_abs / 2;
	env->plan->x_min -=  delta->x_abs / 2;
	env->plan->y_max +=  delta->y_abs / 2;
	env->plan->y_min -=  delta->y_abs / 2;


	new_frame->x_abs = new_frame->x_abs / 1.1;
	new_frame->y_abs = new_frame->y_abs / 1.1;
	new_frame->x_max = new_frame->x_abs / 2 + new_frame->x_max/2.2; 
	new_frame->y_max = new_frame->y_abs / 2 + new_frame->y_max/2.2;*/
	double	delta_x;
	double	delta_y;

	new_frame = env->plan;
	delta_x = env->plan->x_abs;
	delta_y = env->plan->y_abs;

	new_frame->x_abs = new_frame->x_abs / 1.1;
	new_frame->y_abs = new_frame->y_abs / 1.1;
	delta_x -= new_frame->x_abs;
	delta_y -= new_frame->y_abs;
	new_frame->x_max +=  delta_x / 2;
	new_frame->y_max +=  delta_y / 2;
	new_frame->x_max -= (new_frame->x_img / WIN_WIDTH - 0.5) * delta_x * 2;
	new_frame->y_max -= (new_frame->y_img / WIN_HEIGHT - 0.5) * delta_y * 2;

	env->plan = new_frame;
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
	(void)env;
	//mlx_hook(env->mlx_win, 6, 64, mlx_scroll_up_hook, env);
	mlx_key_hook(env->mlx_win, key_hook, env);
	mlx_mouse_hook(env->mlx_win, mouse_hook, env);
	mlx_hook(env->mlx_win, 17, 1L << 4, quit_hook, env);
	return (0);
}

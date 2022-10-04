/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:10:23 by trerolle          #+#    #+#             */
/*   Updated: 2022/10/03 20:03:28 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_complex	*init_complex(t_env *env)
{
	t_complex	*plan;

	plan = (t_complex *)malloc(sizeof(t_complex));
	if (!plan)
	{
		clear_env(env);
		exit(1);
	}
	plan->origin_x = 0;
	plan->origin_y = 0;
	plan->x_img = 0;
	plan->y_img = 0;
	plan->x_max = 2;
	plan->x_abs = 4;
	plan->y_max = 2;
	plan->y_abs = 4;
	plan->real_julia = 0.285;
	plan->img_julia = 0.01;
	return (plan);
}

t_img	*init_img(t_env	*env)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	img->img = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (img);
}

t_env	*init_env(int fractal_type)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		exit(1);
	env->mlx = mlx_init();
	env->mlx_win = mlx_new_window(env->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");
	env->img = init_img(env);
	env->plan = init_complex(env);
	env->fractal_type = fractal_type;
	return (env);
}

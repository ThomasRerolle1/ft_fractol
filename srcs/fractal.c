/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:17:58 by trerolle          #+#    #+#             */
/*   Updated: 2022/10/03 20:01:10 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	convert_win_to_graph(t_complex *plan, double x_win, double y_win)
{
	plan->x_img = (x_win / WIN_WIDTH) * plan->x_abs - plan->x_max;
	plan->y_img = -((y_win / WIN_HEIGHT) * plan->y_abs - plan->y_max);
}

int	mandelbrot_set(t_complex *plan, double new_x, double new_y, int iterations)
{
	double	tmp_real;
	double	tmp_img;

	iterations++;
	tmp_real = new_x;
	tmp_img = new_y;
	new_x = tmp_real * tmp_real - tmp_img * tmp_img + plan->x_img;
	new_y = 2 * tmp_real * tmp_img + plan->y_img;
	if (iterations == 100 || (new_x * new_x + new_y * new_y) > 4)
		return (iterations);
	return (mandelbrot_set(plan, new_x, new_y, iterations));
}

int	julia_set(t_complex *plan, double new_x, double new_y, int iter)
{
	double	tmp_real;
	double	tmp_img;

	iter++;
	tmp_real = new_x;
	tmp_img = new_y;
	new_x = tmp_real * tmp_real - tmp_img * tmp_img + plan->real_julia;
	new_y = 2 * tmp_real * tmp_img + plan->img_julia;
	if (iter == 100 || ((new_x * new_x) + (new_y * new_y)) > 4)
		return (iter);
	return (julia_set(plan, new_x, new_y, iter));
}

void	create_set(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			convert_win_to_graph(env->plan, (double)x, (double)y);
			if (env->fractal_type == 1)
				put_color_to_fractal(env, mandelbrot_set(env->plan, 0, 0, 0),
					x, y);
			else
				put_color_to_fractal(env, julia_set(env->plan, env->plan->x_img,
						env->plan->y_img, 0), x, y);
			x++;
		}
		y++;
	}
}

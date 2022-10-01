/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:17:58 by trerolle          #+#    #+#             */
/*   Updated: 2022/10/01 18:29:07 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	convert_win_to_graph(t_complex *plan, double x_win, double y_win)
{
	plan->x_img = (x_win / WIN_WIDTH) * plan->x_abs - plan->x_max;
	plan->y_img = -((y_win / WIN_HEIGHT) * plan->y_abs - plan->y_max);
	//printf("r plan = %f, i plan = %f\n", plan->x_img, plan->y_img);
}

int	mandelbrot_set(t_complex *plan, double new_x, double new_y, int iterations)
{
	double	tmp_real;
	double	tmp_img;

	iterations++;
	tmp_real = new_x;
	tmp_img = new_y;
	new_x = pow(tmp_real, 2) - pow(tmp_img, 2) + plan->x_img;
	new_y = 2 * tmp_real * tmp_img + plan->y_img;
	//if (iterations  == 100 || new_x > 2 || -2 > new_x || new_y > 2 || -2 > new_y)
	if (iterations == 100 || sqrt(new_x * new_x + new_y * new_y) > 2)
		return (iterations);
	return (mandelbrot_set(plan, new_x, new_y, iterations));
}

void	create_mandelbrot_set(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			convert_win_to_graph(env->plan, (double)x, (double)y);
			put_color_to_fractal(env, mandelbrot_set(env->plan, 0, 0, 0), x, y);
			x++;
		}
		y++;
	}
}

int	julia_set(t_complex *plan, double new_x, double new_y, int iter)
{
	double	tmp_real;
	double	tmp_img;

	iter++;
	tmp_real = new_x;
	tmp_img = new_y;
	new_x = pow(tmp_real, 2) - pow(tmp_img, 2) + plan->real_julia;
	new_y = 2 * tmp_real * tmp_img + plan->img_julia;
	//printf("x = %f y = %f iter = %i\n", new_x, new_y, iter);
	//if (iter  == 500 || new_x > 2 || -2 > new_x || new_y > 2 || -2 > new_y)
	if (iter == 100 || sqrt((new_x * new_x) + (new_y * new_y)) > 2)
		return (iter);
	return (julia_set(plan, new_x, new_y, iter));
}

void	create_julia_set(t_env *env, char **argv, int argc)
{
	int	x;
	int	y;

	y = 0;
	printf("Julia set in Progress...\n");
	//printf("%f\n", env->plan->real_julia);
	if (argc > 2)
		env->plan->real_julia = ft_atoi(argv[2]);
	if (argc == 4)
		env->plan->img_julia = ft_atoi(argv[3]);
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			convert_win_to_graph(env->plan, (double)x, (double)y);
			put_color_to_fractal(env, julia_set(env->plan, env->plan->x_img, env->plan->y_img, 0), x, y);
			x++;
		}
		y++;
	}
}
/*
int	main()
{
	t_complex	*plan;
	t_env	*env;
	env = init_env(1);
	plan = env->plan;
	convert_win_to_graph(plan, WIN_WIDTH/2, WIN_HEIGHT);
	printf("x_img %f, y_img %f", plan->x_img, plan->y_img);
	return (0);
}*/

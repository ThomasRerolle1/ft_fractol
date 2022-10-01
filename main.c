/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:51:26 by trerolle          #+#    #+#             */
/*   Updated: 2022/10/01 18:32:07 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"


void	choose_fractal_set(t_env *env, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (env->fractal_type == 1)
	{
		create_mandelbrot_set(env);
	}
	if (env->fractal_type == 2)
	{
		create_julia_set(env, argv, argc);
	}
}	

void	put_color_to_fractal(t_env *env, int iterations, int x, int y)
{
	if (iterations < 1)
		return (my_mlx_pixel_put(env->img, x, y, RED));
	if (iterations < 2)
		return (my_mlx_pixel_put(env->img, x, y, BLUE));
	if (iterations < 3)
		return (my_mlx_pixel_put(env->img, x, y, GREEN));
	if (iterations < 4)
		return (my_mlx_pixel_put(env->img, x, y, YELLOW));
	if (iterations < 5)
		return (my_mlx_pixel_put(env->img, x, y, PURPLE));
	if (iterations < 6)
		return (my_mlx_pixel_put(env->img, x, y, CYAN));
	if (iterations < 7)
		return (my_mlx_pixel_put(env->img, x, y, RED));
	if (iterations < 8)
		return (my_mlx_pixel_put(env->img, x, y, BLUE));
	if (iterations < 9)
		return (my_mlx_pixel_put(env->img, x, y, GREEN));
	if (iterations < 10)
		return (my_mlx_pixel_put(env->img, x, y, YELLOW));
	if (iterations < 11)
		return (my_mlx_pixel_put(env->img, x, y, PURPLE));
	if (iterations < 12)
		return (my_mlx_pixel_put(env->img, x, y, CYAN));
	if (iterations < 13)
		return (my_mlx_pixel_put(env->img, x, y, RED));
	if (iterations < 14)
		return (my_mlx_pixel_put(env->img, x, y, BLUE));
	if (iterations < 15)
		return (my_mlx_pixel_put(env->img, x, y, GREEN));
	if (iterations < 16)
		return (my_mlx_pixel_put(env->img, x, y, YELLOW));
	if (iterations < 17)
		return (my_mlx_pixel_put(env->img, x, y, PURPLE));
	if (iterations < 18)
		return (my_mlx_pixel_put(env->img, x, y, CYAN));

	if (iterations < 100)
		return (my_mlx_pixel_put(env->img, x, y, DARK_BLUE));
}

int	main(int argc, char **argv)
{
	t_env	*env;
	(void)argv;
	if (argc < 2)
		return (0);
	env = parse_args(argv, argc);
	choose_fractal_set(env, argc, argv);
	/*int x = 0;
	int y = 0;

	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			
			convert_win_to_graph(env->plan, (double)x, (double)y);
			put_color_to_fractal(env, mandelbrot_set(env->plan, 0, 0, 0), x, y);
			y++;
		}
		x++;
	}*/
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img->img, 0, 0);
	mlx_key_hook(env->mlx_win, key_hook, env);
	mlx_mouse_hook(env->mlx_win, mouse_hook, env);
	mlx_hook(env->mlx_win, 17, 1L << 4, quit_hook, env);
	mlx_loop(env->mlx);
	return (0);
}

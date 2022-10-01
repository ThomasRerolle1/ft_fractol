/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:51:26 by trerolle          #+#    #+#             */
/*   Updated: 2022/10/01 14:47:58 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/fractol.h"

int	main(int argc, char **argv)
{
	t_env	*env;
	(void)argv;
	if (argc < 2)
		return (0);
	env = parse_args(argv);
	//choose_fractal_set(env);
	int x = 0;
	int y = 0;

	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			
			convert_win_to_graph(env->plan, (double)x, (double)y);
			if (mandelbrot_set(env->plan, 0, 0, 0) < 100)
				my_mlx_pixel_put(env->img, x, y, DARK_BLUE);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img->img, 0, 0);
	mlx_key_hook(env->mlx_win, key_hook, env);
	mlx_mouse_hook(env->mlx_win, mouse_hook, env);
	mlx_hook(env->mlx_win, 17, 1L << 4, quit_hook, env);
	mlx_loop(env->mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:51:26 by trerolle          #+#    #+#             */
/*   Updated: 2022/10/03 20:06:56 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fractol.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 2)
		return (0);
	env = parse_args(argv, argc);
	create_set(env);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img->img, 0, 0);
	mlx_key_hook(env->mlx_win, key_hook, env);
	mlx_mouse_hook(env->mlx_win, mouse_hook, env);
	mlx_hook(env->mlx_win, 17, 1L << 4, quit_hook, env);
	mlx_loop(env->mlx);
	return (0);
}

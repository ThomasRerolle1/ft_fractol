/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:10:19 by trerolle          #+#    #+#             */
/*   Updated: 2022/10/01 16:30:20 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	key_hook(int keycode, t_env *env)
{
	(void)env;
	if (keycode == K_ESC)
	{
		ft_putstr_fd("zooo still alive?\n", 1);
		quit_hook(env);
		return (1);
	}
	printf("keycode %i\n", keycode);
	return (0);
}

int	mouse_hook(int x, int y, t_env *env)
{
	(void)env;
	printf("x %i y %i\n", x, y);
	return (0);
}

int	quit_hook(t_env *env)
{
	ft_putstr_fd("zooo still alive?\n", 1);
	mlx_destroy_image(env->mlx, env->img->img);
	ft_putstr_fd("zooo still alive?\n", 1);
	mlx_destroy_window(env->mlx, env->mlx_win);
	ft_putstr_fd("zooo still alive?\n", 1);
	clear_env(env);
	exit(0);
	ft_putstr_fd("zooo still alive?\n", 1);
	return (0);
}

int	list_hooks(t_env *env)
{
	(void)env;
	mlx_key_hook(env->mlx_win, key_hook, env);
	mlx_mouse_hook(env->mlx_win, mouse_hook, env);
	mlx_hook(env->mlx_win, 17, 1L << 4, quit_hook, env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:10:26 by trerolle          #+#    #+#             */
/*   Updated: 2022/10/03 20:06:20 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_env	*parse_args(char **argv, int argc)
{
	int	i;

	i = 2;
	if (argc > 2)
	{
		ft_putstr_fd("Usage /fractol \"mandelbrot (-M)\", \"julia (-J)\"", 1);
		exit(0);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0
		|| ft_strncmp(argv[1], "-M", 3) == 0)
		return (init_env(1));
	if (ft_strncmp(argv[1], "julia", 6) == 0
		|| ft_strncmp(argv[1], "-J", 3) == 0)
		return (init_env(2));
	ft_putstr_fd("Usage /fractol \"mandelbrot (-M)\", \"julia (-J)\"", 1);
	exit(0);
}

//void	ft_atof()

/*
void	choose_fractal_set(t_env *env, int argc, char **argv)
{
	if (env->fractal_type == 1)
	{
		create_mandelbrot_set(env);
	}
	if (env->fractal_type == 2)
	{
		create_julia_set(env);
	}
}*/	

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:10:26 by trerolle          #+#    #+#             */
/*   Updated: 2022/10/01 17:05:29 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_env	*parse_args(char **argv, int argc)
{
	int	i;
	int	j;


	i = 2;
	if (argc > 4)
	{
		printf("Too many arguments");
		exit(0);
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("%s must be a number", argv[i]);
				exit(0);
			}
			j++;
		}
		i++;
	}
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")) == 0 && argc == 2)
		return (init_env(1));
	if (ft_strncmp(argv[1], "julia", ft_strlen("julia")) == 0)
		return (init_env(2));
	printf("%s is not a valid argument\nPlease choose between Mandelbrot and Julia", argv[1]);
	exit(0);
}
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

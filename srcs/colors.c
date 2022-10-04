/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:07:02 by trerolle          #+#    #+#             */
/*   Updated: 2022/10/03 19:59:03 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

void	put_color_to_fractal(t_env *env, int i, int x, int y)
{
	if (i == 100)
		return (my_mlx_pixel_put(env->img, x, y, 0));
	i = 100 - i;
	return (my_mlx_pixel_put(env->img, x, y, ((i << 1) + (i << 10)
				+ (i << 8)) & 0xFFFFFF));
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

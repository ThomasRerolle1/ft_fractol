/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:10:12 by trerolle          #+#    #+#             */
/*   Updated: 2022/10/01 16:30:20 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	clear_img(t_img *img)
{
	if (img)
	{
		free(img);
		img = NULL;
	}
}

void	clear_env(t_env *env)
{
	if (env)
	{
		env->mlx = NULL;
		env->mlx_win = NULL;
		if (env->img)
			clear_img(env->img);
		free(env);
		env = NULL;
	}
}


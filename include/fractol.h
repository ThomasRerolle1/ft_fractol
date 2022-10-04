/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trerolle <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:07:20 by trerolle          #+#    #+#             */
/*   Updated: 2022/10/04 19:33:18 by trerolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx_mac/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//#include "mlx_linux/mlx_int.h"
/*******************COLOR_DEFINITION***************/
# define RED            0xFF0000
# define BLUE             0x0000FF
# define GREEN            0x00FF00
# define YELLOW            0xFFFF00
# define WHITE            0xFFFFFF
# define BLACK            0x000000
# define PURPLE            0xFF00FF
# define CYAN            0x00FFFF
# define ORANGE            0xFFA500
# define BROWN            0xA52A2A
# define GRAY            0x808080

# define LIGHT_GRAY        0xD3D3D3
# define LIGHT_BLUE        0xADD8E6
# define LIGHT_GREEN    0x90EE90
# define LIGHT_RED        0xFF4500
# define LIGHT_PURPLE    0xFF00FF
# define LIGHT_CYAN        0x00FFFF
# define LIGHT_ORANGE    0xFFA500
# define LIGHT_BROWN    0xA52A2A
# define LIGHT_WHITE    0xFFFFFF
# define LIGHT_YELLOW    0xFFFFE0

# define DARK_BLUE        0x00008B
# define DARK_GREEN        0x006400
# define DARK_RED        0x8B0000
# define DARK_PURPLE    0x8B008B
# define DARK_CYAN        0x008B8B
# define DARK_ORANGE    0xFF8C00
# define DARK_BROWN        0x8B4513
# define DARK_GRAY        0xA9A9A9
# define DARK_YELLOW    0xD3D3D3
# define DARK_WHITE        0x696969

/**********************SIZE_DEFINITION*************/
# define WIN_WIDTH	500
# define WIN_HEIGHT	500
/********************KEY_CODES**********************/
# ifdef __gnu_linux__
#  define K_ESC 65307
#  define K_UP 65362
#  define K_DOWN 65364
#  define K_LEFT 65361
#  define K_RIGHT 65363
#  define K_W 119
#  define K_S 115
#  define K_A 97
#  define K_D 100
#  define K_P 112
#  define K_MINUS 45
#  define K_PLUS 113
#  define K_R 114
#  define K_U 117
#  define K_J 106
#  define K_I 105
#  define K_K 107
#  define K_O 111
#  define K_L 108
#  define K_ZOOM_IN 4
#  define K_ZOOM_OUT 5
#  define K_LEFT_CLICK 1
#  define K_RIGHT_CLICK 3
# elif __APPLE__
#  define K_ZOOM_IN 4
#  define K_ZOOM_OUT 5
#  define K_LEFT_CLICK 1
#  define K_RIGHT_CLICK 3
#  define K_ESC 53
#  define K_UP 126
#  define K_DOWN 125
#  define K_LEFT 123
#  define K_RIGHT 124
#  define K_W 13
#  define K_S 1
#  define K_A 0
#  define K_D 2
#  define K_P 35
#  define K_MINUS 27
#  define K_PLUS 24
#  define K_R 15
#  define K_U 32
#  define K_J 38
#  define K_I 34
#  define K_K 40
#  define K_O 31
#  define K_L 37
#  define KEYDOWN 2
#  define KEYUP 3
#  define MOUSE_DOWN  4
#  define MOUSE_UP  5
#  define ON_MOUSEMOVE  6
#  define ON_EXPOSE 12
#  define ON_DESTROY 17
# endif
/*********************STRUCT_DEFINITION************/

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_img;

typedef struct s_complex{
	double	origin_x;
	double	origin_y;
	double	x_img;
	double	y_img;
	double	x_max;
	double	y_max;
	double	x_abs;
	double	y_abs;
	double	real_julia;
	double	img_julia;

}		t_complex;

typedef struct s_env {
	t_img		*img;
	void		*mlx;
	void		*mlx_win;
	t_complex	*plan;
	int			fractal_type;
}		t_env;

/*********************FUNCTIONS_PROTOTYPES************/

t_img		*init_img(t_env	*env);
t_env		*init_env(int fractal_type);
t_complex	*init_complex(t_env *env);
t_env		*parse_args(char **argv, int argc);
int			list_hooks(t_env *env);
int			quit_hook(t_env *env);
int			mouse_hook(int keycode, int x, int y, t_env *env);
int			scroll_up(t_env *env, int keycode);
int			key_hook(int keycode, t_env *env);
void		clear_img(t_img *img);
void		clear_complex(t_complex *plan);
void		clear_env(t_env *env);
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
int			add_shade(double distance, int color);
void		convert_win_to_graph(t_complex *plan, double x_win, double y_win);
int			mandelbrot_set(t_complex *plan, double new_x, double new_y,
				int iterations);
void		put_color_to_fractal(t_env *env, int i, int x, int y);
void		create_mandelbrot_set(t_env *env);
int			julia_set(t_complex *plan, double new_x, double new_y, int iter);
void		create_julia_set(t_env *env, char **argv, int argc);
void		choose_fractal_set(t_env *env, int argc, char **argv);
void		create_set(t_env *env);
int			main(int argc, char **argv);

#endif

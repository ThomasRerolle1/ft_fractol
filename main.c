
/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	*dst;


	dst = data->addr + (y * data->line_length + x * data->bits_per_pixel);
	*(unsigned int*)dst = color;
}

int	add_shade(double distance, int color)
{

	return (color - (color * distance));
}
*/

#include "./include/fractol.h"
/*
int	main(int argc, char **argv)
{
	t_env	*env;
	(void)argv;
	if (argc < 2)
		return (0);
	env = parse_args(argv);
	//choose_fractal_set(env);
	mlx_put_image_to_window(env->mlx, env->mlx_win, env->img->img, 0, 0);
	mlx_key_hook(env->mlx_win, key_hook, env);
	mlx_mouse_hook(env->mlx_win, mouse_hook, env);
	mlx_hook(env->mlx_win, 17, 1L << 4, quit_hook, env);
	mlx_loop(env->mlx);
	return (0);
}

*/

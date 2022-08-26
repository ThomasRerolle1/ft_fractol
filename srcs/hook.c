#include "../include/fractol.h"

int	key_hook(int keycode, t_env *env)
{
	(void)env;
	if (keycode == K_ESC)
		return (quit_hook(env));
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
	mlx_destroy_image(env->mlx, env->mlx_win);
	mlx_destroy_window(env->mlx, env->mlx_win);
	clear_env(env);
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

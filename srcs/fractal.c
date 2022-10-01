#include "../include/fractol.h"

void	convert_win_to_graph(t_complex *plan, double x_win, double y_win)
{
	plan->x_img = (x_win / WIN_WIDTH) * plan->x_abs - plan->x_max;
	plan->y_img = -((y_win / WIN_HEIGHT) * plan->y_abs - plan->y_max);
	//printf("r plan = %f, i plan = %f\n", plan->x_img, plan->y_img);
}

int	mandelbrot_set(t_complex *plan, double new_x, double new_y, int iterations)
{
	double	tmp_real;
	double	tmp_img;

	iterations++;
	tmp_real = new_x;
	tmp_img = new_y;
	new_x = pow(tmp_real, 2) - pow(tmp_img, 2) + plan->x_img;
	new_y = 2 * tmp_real * tmp_img + plan->y_img;
	//printf("x = %f, y = %f, iter = %i\n", new_x, new_y, iterations);
	if (iterations  == 100 || new_x > 2 || -2 > new_x || new_y > 2 || -2 > new_y)
		return (iterations);
	return (mandelbrot_set(plan, new_x, new_y, iterations));
}

/*
int	main()
{
	t_complex	*plan;
	t_env	*env;
	env = init_env(1);
	plan = env->plan;
	convert_win_to_graph(plan, WIN_WIDTH/2, WIN_HEIGHT);
	printf("x_img %f, y_img %f", plan->x_img, plan->y_img);
	return (0);
}*/

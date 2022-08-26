#include "../include/fractol.h"

void	convert_win_to_graph(t_complex *plan, float x_win, float y_win)
{
	plan->x_img = (x_win / WIN_WIDTH) * plan->x_abs - plan->x_max;
	plan->y_img = -((y_win / WIN_HEIGHT) * plan->y_abs - plan->y_max);
}
int	main()
{
	t_complex	*plan;
	t_env	*env;
	env = init_env(1);
	plan = env->plan;
	convert_win_to_graph(plan, WIN_WIDTH/2, WIN_HEIGHT);
	printf("x_img %f, y_img %f", plan->x_img, plan->y_img);
	return (0);
}

#include "../include/fractol.h"

t_env	*parse_args(char **argv)
{
	if (ft_strncmp(argv[1], "mendelbrot", ft_strlen("mendelbrot")) == 0)
		return (init_env(1));
	if (ft_strncmp(argv[1], "Julia", ft_strlen("Julia")) == 0)
		return (init_env(2));
	printf("%s is not a valid argument\nPlease choose between Mendelbrot and Julia", argv[1]);
	exit(0);
}

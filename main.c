#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"

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
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
	//return (0xFFFFFF);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;


	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	add_shade(double distance, int color)
{

	return (color - (color * distance));
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int	t = 0xFF;
	int	r = 0xFF;
	int	g = 0xFF;
	int	b = 0xFF;
	int	trgb = 0;

	printf("%d\n%d\n%d\n%d\n%d\n", t, r, g, b, trgb);
	trgb = create_trgb(t, r, g, b);

	printf("%d\n%d\n%d\n%d\n%d\n", t, r, g, b, trgb);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int  x, y = 0;
	while (y < 1080)
	{
		while (x++ < 1000)
			my_mlx_pixel_put(&img,x ,y , trgb);
		y++;
		//trgb = create_trgb(t, r, g, b);
		//trgb = add_shade(1/y, trgb);
		x = 0;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
		}

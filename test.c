#include "fdf.h"

void	print_line(t_fdf *fdf, t_cor *cor, int color)
{
	cor->deltaY = cor->y_end - cor->y_beg;
	cor->deltaX = cor->x_end - cor->x_beg;
	cor->signX = cor->x_beg < cor->x_end ? 1 : -1;
	cor->signY = cor->y_beg < cor->y_end ? 1 : -1;
	cor->deltaY < 0 ? cor->deltaY *= -1 : 0;
	cor->deltaX < 0 ? cor->deltaX *= -1 : 0;
	cor->error = cor->deltaX - cor->deltaY;
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, cor->x_beg, cor->y_beg, color);
	while(cor->x_beg != cor->x_end || cor->y_beg != cor->y_end)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, cor->x_beg, cor->y_beg, color);
		const int error2 = cor->error * 2;
		if(error2 > -cor->deltaY)
		{
			cor->error -= cor->deltaY;
			cor->x_beg += cor->signX;
		}
		if(error2 < cor->deltaX)
		{
			cor->error += cor->deltaX;
			cor->y_beg += cor->signY;
		}
	}
}

int		main(void)
{
	t_fdf	fdf;
	t_cor	cor;

	cor.x_beg = 250;
	cor.y_beg = 500;
	cor.x_end = 700;
	cor.y_end = 100;
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1920, 1080, "gaudry");
	mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, 250, 250, 0xFF0100);
	mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 252, 250, 0xe7eb00, "BEGIN");
	print_line(&fdf, &cor, 0xFF0100);
	mlx_loop(fdf.mlx_ptr);
}

fdf->map_width * x = fdf->width
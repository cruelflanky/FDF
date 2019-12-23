#include "fdf.h"

void	print_line(void *mlx_ptr, void *win_ptr, t_cor *cor, int color)
{
	const int deltaX = abs(cor->x_end - cor->x_beg);
	const int deltaY = abs(cor->y_end - cor->y_beg);
	const int signX = cor->x_beg < cor->end ? 1 : -1;
	const int signY = cor->y_beg < cor->y_end ? 1 : -1;
	int error = deltaX - deltaY;

    setPixel(cor->end, cor->y_end);
    while(cor->x_beg != cor->end || cor->y_beg != cor->y_end)
   {
        setPixel(cor->x_beg, cor->y_beg);
        const int error2 = error * 2;
        //
        if(error2 > -deltaY)
        {
            error -= deltaY;
            cor->x_beg += signX;
        }
        if(error2 < deltaX)
        {
            error += deltaX;
            cor->y_beg += signY;
        }
    }

}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_cor	cor;

	cor.x_beg = 250;
	cor.y_beg = 500;
	cor.x_end = 700;
	cor.y_end = 100;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "gaudry");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFF0100);
	mlx_string_put(mlx_ptr, win_ptr, 252, 250, 0xe7eb00, "BEGIN");
	print_line(mlx_ptr, win_ptr, &cor, 0xFF0100);
	mlx_key_hook(win_ptr, deal_key, (void *)53);
	mlx_loop(mlx_ptr);
}
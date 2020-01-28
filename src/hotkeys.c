/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotkeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 20:33:49 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/26 17:06:23 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "hotkeys.h"

void	ft_zoom(int key, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	if (key == KEYCODE_PLUS)
		fdf->zoom++;
	else if (key == KEYCODE_MINUS)
		fdf->zoom--;
	if (fdf->zoom < 1)
		fdf->zoom = 1;
	control_text(fdf);
	print_map(fdf, fdf->map);
}

void	ft_color(int key, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	if (key == KEYCODE_C)
		fdf->color += 50000;
	control_text(fdf);
	print_map(fdf, fdf->map);
}

void	ft_move(int key, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	if (key == KEYCODE_RIGHT_ARROW)
		fdf->x_move += 5;
	else if (key == KEYCODE_LEFT_ARROW)
		fdf->x_move -= 5;
	if (key == KEYCODE_UP_ARROW)
		fdf->y_move -= 5;
	else if (key == KEYCODE_DOWN_ARROW)
		fdf->y_move += 5;
	control_text(fdf);
	print_map(fdf, fdf->map);
}

void	ft_z_height(int key, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	if (key == KEYCODE_Z_HEIGHT_DOWN)
		fdf->z_height -= 0.5;
	else if (key == KEYCODE_Z_HEIGHT_UP)
		fdf->z_height += 0.5;
	control_text(fdf);
	print_map(fdf, fdf->map);
}

int		key_press(int key, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	(key == KEYCODE_ESC) ? exit(0) : 0;
	if (key == KEYCODE_PLUS || key == KEYCODE_MINUS)
		ft_zoom(key, fdf);
	if (key == KEYCODE_RIGHT_ARROW || key == KEYCODE_LEFT_ARROW ||
			key == KEYCODE_UP_ARROW || key == KEYCODE_DOWN_ARROW)
		ft_move(key, fdf);
	(key == KEYCODE_ISO) ? ft_iso(fdf) : 0;
	(key == KEYCODE_PARALEL) ? ft_paralel(fdf) : 0;
	if (key == KEYCODE_Z_HEIGHT_DOWN || key == KEYCODE_Z_HEIGHT_UP)
		ft_z_height(key, fdf);
	if (key == KEYCODE_4_NUM || key == KEYCODE_2_NUM ||
			key == KEYCODE_8_NUM || key == KEYCODE_6_NUM ||
			key == KEYCODE_7_NUM || key == KEYCODE_9_NUM ||
			key == KEYCODE_1_NUM || key == KEYCODE_3_NUM)
		ft_rotate(key, fdf);
	if (key == KEYCODE_C)
		ft_color(key, fdf);
	if (key == KEYCODE_T)
		ft_text(fdf);
	return (0);
}

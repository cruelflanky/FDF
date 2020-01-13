/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotkeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 20:33:49 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/13 19:12:15 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int key, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	if (key == KEYCODE_PLUS)
		fdf->zoom++;
	else if (key == KEYCODE_MINUS)
		fdf->zoom--;
	if (fdf->zoom < 1)
		fdf->zoom = 1;
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
	print_map(fdf, fdf->map);
}

void	ft_iso(int key, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->gamma = 0;
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->x_move = 0;
	fdf->y_move = 0;
	fdf->z_height = 0.5;
	fdf->paralel = 0;
	fdf->count = 0;
	print_map(fdf, fdf->map);
}

void	ft_paralel(int key, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->gamma = 0;
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->x_move = 0;
	fdf->y_move = 0;
	fdf->z_height = 0.5;
	fdf->paralel = 1;
	fdf->count = 0;
	print_map(fdf, fdf->map);
}

void	ft_z_height(int key, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	if (key == KEYCODE_Z_HEIGHT_DOWN)
		fdf->z_height -= 1.5;
	else if (key == KEYCODE_Z_HEIGHT_UP)
		fdf->z_height += 1.5;
	print_map(fdf, fdf->map);
}

void	ft_rotate(int key, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	if (key == KEYCODE_2_NUM)
		fdf->alpha += 0.05;
	else if (key == KEYCODE_8_NUM)
		fdf->alpha -= 0.05;
	else if (key == KEYCODE_4_NUM)
		fdf->beta -= 0.05;
	else if (key == KEYCODE_6_NUM)
		fdf->beta += 0.05;
	else if (key == KEYCODE_1_NUM || key == KEYCODE_7_NUM)
		fdf->gamma += 0.05;
	else if (key == KEYCODE_3_NUM || key == KEYCODE_9_NUM)
		fdf->gamma -= 0.05;
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
	(key == KEYCODE_ISO) ? ft_iso(key, fdf) : 0;
	(key == KEYCODE_PARALEL) ? ft_paralel(key, fdf) : 0;
	if (key == KEYCODE_Z_HEIGHT_DOWN || key == KEYCODE_Z_HEIGHT_UP)
		ft_z_height(key, fdf);
	if (key == KEYCODE_4_NUM || key == KEYCODE_2_NUM ||
			key == KEYCODE_8_NUM || key == KEYCODE_6_NUM ||
			key == KEYCODE_7_NUM || key == KEYCODE_9_NUM ||
			key == KEYCODE_1_NUM || key == KEYCODE_3_NUM)
		ft_rotate(key, fdf);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:23:55 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/16 17:26:06 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	control_text(t_fdf *fdf)
{
	if (fdf->text > 0)
	{
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 20, 0xffffff, "Isometric / Parallel: I / P");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 40, 0xffffff, "Randomly change color: C");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 60, 0xffffff, "Move: Arrow keys");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 80, 0xffffff, "Zoom: Numpad + / -");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 100, 0xffffff, "Z height: < / >");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 120, 0xffffff, "Three-dimensional space move:");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 135, 0xffffff, "X axis: Numpad 4 / 6");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 150, 0xffffff, "Y axis: Numpad 2 / 8");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 165, 0xffffff, "Z axis: Numpad 7,9 / 1,3");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 185, 0xffffff, "Hide controls: T");
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 205, 0xffffff, "Exit: ESC");
	}
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
	fdf->color = 2162933;
	control_text(fdf);
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
	fdf->color = 2162933;
	control_text(fdf);
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
	control_text(fdf);
	print_map(fdf, fdf->map);
}

void	ft_text(int key, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->text *= -1;
	control_text(fdf);
	print_map(fdf, fdf->map);
}
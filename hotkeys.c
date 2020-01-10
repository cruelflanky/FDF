/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotkeys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 20:33:49 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/10 20:34:38 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int key, t_fdf *fdf)
{
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
	if (key == KEYCODE_PLUS)
		fdf->zoom++;
	else if (key == KEYCODE_MINUS)
		fdf->zoom--;
	if (fdf->zoom < 1)
		fdf->zoom = 1;
	print_map(fdf, fdf->map);
}


int		key_press(int key, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	if (key == KEYCODE_ESC)
		exit(0);
	if (key == KEYCODE_PLUS || key == KEYCODE_MINUS)
		ft_zoom(key, fdf);
	if (key == KEYCODE_RIGHT_ARROW || key == KEYCODE_LEFT_ARROW ||
			key == KEYCODE_UP_ARROW || key == KEYCODE_DOWN_ARROW)
		ft_move(key, fdf);
	if (key == KEYCODE_ISO)
		ft_iso(key, fdf);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:28:39 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/17 13:48:34 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_x(int *y, int *z, double alpha)
{
	int ex_y;

	ex_y = *y;
	*y = ex_y * cos(alpha) + *z * sin(alpha);
	*z = -ex_y * sin(alpha) + *z * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int ex_x;

	ex_x = *x;
	*x = ex_x * cos(beta) + *z * sin(beta);
	*z = -ex_x * sin(beta) + *z * cos(beta);
}

static void	rotate_z(int *x, int *y, double gamma)
{
	int ex_x;
	int ex_y;

	ex_x = *x;
	ex_y = *y;
	*x = ex_x * cos(gamma) - ex_y * sin(gamma);
	*y = ex_x * sin(gamma) + ex_y * cos(gamma);
}

static void	iso(int *x, int *y, int z)
{
	int ex_x;
	int ex_y;

	ex_x = *x;
	ex_y = *y;
	*x = (ex_x - ex_y) * cos(0.523599);
	*y = -z + (ex_x + ex_y) * sin(0.523599);
}

void	*new_dot(t_xyz *xyz, t_fdf *fdf, char **map)
{
	(xyz->z == 0) ? xyz->z = ft_atoi(map[xyz->x]) : 0;
	xyz->x *= fdf->zoom;
	xyz->y *= fdf->zoom;
	xyz->z *= fdf->zoom / fdf->z_height;
	xyz->x -= (fdf->map_width * fdf->zoom) / 2;
	xyz->y -= (fdf->map_height * fdf->zoom) / 2;
	rotate_x(&xyz->y, &xyz->z, fdf->alpha);
	rotate_y(&xyz->x, &xyz->z, fdf->beta);
	rotate_z(&xyz->x, &xyz->y, fdf->gamma);
	if (!fdf->paralel)
		iso(&xyz->x, &xyz->y, xyz->z);
	xyz->x += (fdf->width) / 2 + fdf->x_move;
	xyz->y += (fdf->height + fdf->map_height * fdf->zoom) / 2 + fdf->y_move;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:26:32 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/24 17:46:31 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		zoom_continue(t_fdf *fdf, t_xyz *xyz, t_map *map, int zoom)
{
	int		old_xyz[3];

	old_xyz[0] = xyz->x;
	old_xyz[1] = xyz->y;
	old_xyz[2] = xyz->z;
	(!zoom) ? fdf->zoom = (fdf->width / 3) / fdf->map_width : 0;
	new_dot(xyz, fdf, map->str);
	while (xyz->y > fdf->height)
	{
		xyz->x = old_xyz[0];
		xyz->y = old_xyz[1];
		xyz->z = old_xyz[2];
		new_dot(xyz, fdf, map->str);
		fdf->zoom--;
	}
	while (xyz->y < 0)
	{
		xyz->x = old_xyz[0];
		xyz->y = old_xyz[1];
		xyz->z = old_xyz[2];
		new_dot(xyz, fdf, map->str);
		fdf->zoom--;
	}
}

void		zoom_check_max(t_fdf *fdf, t_map *begin)
{
	t_map	*map;
	t_xyz	xyz;
	t_xyz	new_xyz;
	int		a;

	xyz.y = 0;
	xyz.z = 0;
	map = begin;
	while (map != NULL)
	{
		fdf->map = map;
		xyz.x = 0;
		while (xyz.x != fdf->map_width)
		{
			if (xyz.z < (a = ft_atoi(map->str[xyz.x])))
			{
				xyz.z = a;
				new_xyz = xyz;
			}
			xyz.x++;
		}
		map = map->next;
		xyz.y++;
	}
	zoom_continue(fdf, &new_xyz, begin, 0);
}

void		zoom_check_min(t_fdf *fdf, t_map *begin)
{
	t_map	*map;
	t_xyz	xyz;

	xyz.y = 0;
	map = begin;
	while (map->next != NULL)
	{
		map = map->next;
		xyz.y++;
	}
	fdf->map = map;
	xyz.x = fdf->map_width - 1;
	xyz.z = ft_atoi(map->str[xyz.x]);
	zoom_continue(fdf, &xyz, begin, fdf->zoom);
}

int			check_params(char **argv, t_fdf *fdf)
{
	int		a;

	a = 0;
	(!(argv[1])) ? ft_error() : 0;
	(argv[2]) ? a = ft_atoi(argv[2]) : 0;
	if (a > 0)
		fdf->width = a;
	else
		fdf->width = FULL_HD_WIDTH;
	(argv[3]) ? a = ft_atoi(argv[3]) : 0;
	if (a > 0)
		fdf->height = a;
	else
		fdf->height = FULL_HD_HEIGHT;
	return (1);
}

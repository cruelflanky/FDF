/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:31:16 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/28 16:43:52 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cor		*new_xyz(t_xyz xyz, int x_end, int y_end, t_fdf *fdf)
{
	t_cor	*num;
	int		y_beg;

	y_beg = xyz.y;
	num = init_cor();
	new_dot(&xyz, fdf, fdf->map->str);
	num->x_beg = xyz.x;
	num->y_beg = xyz.y;
	xyz.x = x_end;
	xyz.y = y_end;
	xyz.z = 0;
	if (y_end > y_beg)
		new_dot(&xyz, fdf, fdf->map->next->str);
	else
		new_dot(&xyz, fdf, fdf->map->str);
	num->x_end = xyz.x;
	num->y_end = xyz.y;
	return (num);
}

void		line(t_fdf *f, t_cor *c, int color)
{
	c->deltay = c->y_end - c->y_beg;
	c->deltax = c->x_end - c->x_beg;
	c->signx = c->x_beg < c->x_end ? 1 : -1;
	c->signy = c->y_beg < c->y_end ? 1 : -1;
	c->deltay < 0 ? c->deltay *= -1 : 0;
	c->deltax < 0 ? c->deltax *= -1 : 0;
	c->error = c->deltax - c->deltay;
	mlx_pixel_put(f->mlx_ptr, f->win_ptr, c->x_beg, c->y_beg, color);
	while (c->x_beg != c->x_end || c->y_beg != c->y_end)
	{
		mlx_pixel_put(f->mlx_ptr, f->win_ptr, c->x_beg, c->y_beg, color);
		c->error2 = c->error * 2;
		if (c->error2 > -c->deltay)
		{
			c->error -= c->deltay;
			c->x_beg += c->signx;
		}
		if (c->error2 < c->deltax)
		{
			c->error += c->deltax;
			c->y_beg += c->signy;
		}
	}
	free(c);
}

void		print_map(t_fdf *fdf, t_map *map)
{
	t_xyz	i;

	i.y = 0;
	i.z = 0;
	fdf->begin = map;
	while (map != NULL)
	{
		fdf->map = map;
		i.x = 0;
		while (i.x != fdf->map_width)
		{
			if (i.x != fdf->map_width - 1)
				line(fdf, new_xyz(i, i.x + 1, i.y, fdf), color(i, fdf, 'x'));
			if (i.y != fdf->map_height - 1)
				line(fdf, new_xyz(i, i.x, i.y + 1, fdf), color(i, fdf, 'y'));
			i.x++;
		}
		map = map->next;
		i.y++;
	}
	fdf->map = fdf->begin;
}

void		read_map(int fd, t_fdf *fdf, t_map *map, t_map *begin)
{
	int		a;
	char	*line;

	while ((a = get_next_line(fd, &line)))
	{
		(a < 0) ? ft_error("argv") : 0;
		ft_list_push_left(&map, ft_strsplit(line, ' '));
		(!begin) ? begin = map : 0;
		ft_strdel(&line);
		fdf->map_height++;
	}
	mapcheck(map, fdf);
	zoom_check_max(fdf, begin);
	zoom_check_min(fdf, begin);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->width, fdf->height, "fdf");
	print_map(fdf, begin);
}

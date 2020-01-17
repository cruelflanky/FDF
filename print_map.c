/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:31:16 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/17 19:58:26 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cor	*new_xyz(t_xyz xyz, int x_end, int y_end, t_fdf *fdf)
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
	free(cor);
}

void	print_map(t_fdf *fdf, t_map *map)
{
	t_xyz	xyz;
	t_cor	*cor;

	xyz.y = 0;
	xyz.z = 0;
	fdf->begin = map;
	while(map != NULL)
	{
		fdf->map = map;
		xyz.x = 0;
		while(xyz.x != fdf->map_width)
		{
			if (xyz.x != fdf->map_width - 1)
				print_line(fdf, cor = new_xyz(xyz, xyz.x + 1, xyz.y, fdf), color(xyz, fdf));
			if (xyz.y != fdf->map_height - 1)
				print_line(fdf, cor = new_xyz(xyz, xyz.x, xyz.y + 1, fdf), color(xyz, fdf));
			xyz.x++;
		}

		map = map->next;
		xyz.y++;
	}
	fdf->map = fdf->begin;
}

// void	map_checker(t_fdf *fdf, t_map *map)
// {
// 	t_xyz	c;
// 	char	**str;

// 	str = map->str;
// 	c.z = 0;
// 	while(map->str[c.x])
// 	{
// 		c.y = 0;
// 		while (str[c.x][c.y] >= '0' && str[c.x][c.y] <= '9'
// 				|| str[c.x][c.y] == '-')
// 		{

// 			c.y++;
// 		}
// 		c.x++;
// 	}
// 	(c.x != fdf->width) ? ft_error : 0;
// }

void	read_map(int fd, t_fdf *fdf, t_map *map, t_map *begin)
{
	int		a;
	char	*line;

	while ((a = get_next_line(fd, &line)))
	{
		ft_list_push_left(&map, ft_strsplit(line, ' '));
		(!begin) ? begin = map : 0;
		ft_strdel(&line);
		fdf->map_height++;
	}
	a = 0;
	while (map->str[a++])
		fdf->map_width++;
	//map_checker(fdf, begin);
	zoom_check_max(fdf, begin);
	zoom_check_min(fdf, begin);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->width, fdf->height, "fdf");
	print_map(fdf, begin);
}
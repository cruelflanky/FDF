/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:47:52 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/21 15:42:26 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		map_checker(t_map *map, int x, int width)
{
	t_xyz	c;
	char	**str;

	str = map->str;
	c.x = x;
	c.y = 0;
	if (x >= width || map == NULL)
		return(0);
	while ((str[c.x][c.y] >= '0' && str[c.x][c.y] <= '9')
			|| str[c.x][c.y] == '-' || str[c.x][c.y] == ',')
	{
		c.y++;
		if (str[c.x][c.y] == 'x' || str[c.x][c.y] == 'X')
			return (atoi_base(&str[c.x][c.y + 2], 16));
	}
	return (0);
}

int		color(t_xyz xyz, t_fdf *fdf)
{
	int		a;

	if ((a = map_checker(fdf->map, xyz.x, fdf->map_width)))
	{
		if (a == map_checker(fdf->map, xyz.x + 1, fdf->map_width))
			return (a);
		else if (a == map_checker(fdf->map->next, xyz.x, fdf->map_width))
			return (a);
	}
	if (ft_atoi(fdf->map->str[xyz.x]) != 0)
		return(fdf->color);
	else
		return(fdf->color + 10551242);
}

void	ft_error()
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		fd;
	t_map	*map;
	t_map	*begin;

	map = NULL;
	fdf = init_fdf();
	begin = map;
	if (argc >= 2)
	{
		check_params(argv, fdf);
		fd = open(argv[1], O_RDONLY);
		(fd <= 0) ? ft_error() : 0;
		read_map(fd, fdf, map, begin);
		control_text(fdf);
		mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
		mlx_loop(fdf->mlx_ptr);
		free(fdf);
	}
	return (0);
}
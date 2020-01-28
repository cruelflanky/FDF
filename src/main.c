/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:47:52 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/28 16:47:09 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "hotkeys.h"
#include "mlx.h"

int		map_checker(t_map *map, int x, int width)
{
	t_xyz	c;
	char	**str;

	str = map->str;
	c.x = x;
	c.y = 0;
	if (x >= width || map == NULL)
		return (0);
	while ((str[c.x][c.y] >= '0' && str[c.x][c.y] <= '9')
			|| str[c.x][c.y] == '-' || str[c.x][c.y] == ',')
	{
		c.y++;
		if (str[c.x][c.y] == 'x' || str[c.x][c.y] == 'X')
			return (rgb_set(&str[c.x][c.y + 1], 16));
	}
	return (0);
}

int		color(t_xyz xyz, t_fdf *fdf, char c)
{
	int		a;

	if ((a = map_checker(fdf->map, xyz.x, fdf->map_width)))
	{
		if (a == map_checker(fdf->map, xyz.x + 1, fdf->map_width)
			&& c == 'x')
			return (a);
		if (fdf->map->next)
			if (a == map_checker(fdf->map->next, xyz.x, fdf->map_width)
				&& c == 'y')
				return (a);
	}
	if (ft_atoi(fdf->map->str[xyz.x]) != 0)
		return (fdf->color);
	else
		return (fdf->color + 10551242);
}

void	ft_error(char *str)
{
	if (ft_strcmp(str, "map") == 0)
		ft_putendl("Map error");
	else if (ft_strcmp(str, "argv") == 0)
		ft_putendl("Wrong arguments");
	else if (ft_strcmp(str, "file") == 0)
		ft_putendl("File error");
	else
		ft_putendl("error");
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
	if (argc >= 2 && argc <= 4)
	{
		check_params(argv, fdf);
		fd = open(argv[1], O_RDONLY);
		(fd <= 0) ? ft_error("file") : 0;
		read_map(fd, fdf, map, begin);
		control_text(fdf);
		mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
		mlx_loop(fdf->mlx_ptr);
		free(fdf);
	}
	else
		ft_error("argv");
	return (0);
}

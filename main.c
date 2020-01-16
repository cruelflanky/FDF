/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:47:52 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/16 18:05:14 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color(t_xyz xyz, t_fdf *fdf)
{
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
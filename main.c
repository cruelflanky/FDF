/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:47:52 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/08 23:28:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_create_elem(void)
{
	t_map *element;

	if (!(element = malloc(sizeof(t_map))))
		return (NULL);
	element->str = NULL;
	element->next = NULL;
	element->count = 0;
	return (element);
}

int		ft_list_push_left(t_map **begin_list)
{
	t_map	*tmp;

	if (begin_list && *begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem();
		return (0);
	}
	else
		*begin_list = ft_create_elem();
	return (1);
}

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

t_cor	new_xyz(t_fdf *fdf, t_map *map)
{
	static t_xyz	*xyz;

	xyz->x = fdf->zoom;
	xyz->y = fdf->zoom;

}

void	print_map(t_fdf *fdf, t_map *map)
{
	int x;
	int y;

	y = 0;
	while(map != NULL)
	{
		x = 0;
		while(map->str[y])
		{
			if (x != fdf->width - 1)
				print_line(fdf, new_xyz(x, y, ),
					new_xyz(x + 1, y, map), get_color());
			if (y != fdf->height - 1)
				print_line(project(new_xyz(x, y, map), fdf),
					project(new_point(x, y + 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
}

void	print_line(t_fdf *fdf, t_cor *cor, int color)
{
	const int deltaX = abs(cor->x_end - cor->x_beg);
	const int deltaY = abs(cor->y_end - cor->y_beg);
	const int signX = cor->x_beg < cor->x_end ? 1 : -1;
	const int signY = cor->y_beg < cor->y_end ? 1 : -1;
	int error = deltaX - deltaY;

	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, cor->x_beg, cor->y_beg, color);
	while(cor->x_beg != cor->x_end || cor->y_beg != cor->y_end)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, cor->x_beg, cor->y_beg, color);
		const int error2 = error * 2;
		if(error2 > -deltaY)
		{
			error -= deltaY;
			cor->x_beg += signX;
		}
		if(error2 < deltaX)
		{
			error += deltaX;
			cor->y_beg += signY;
		}
	}
}

int		check_params(char **argv, t_fdf *fdf)
{
	int a;

	(!(argv[1])) ? ft_error() : 0;
	a = ft_atoi(argv[2]);
	if (a > 0)
		fdf->width = a;
	else
		fdf->width = FULL_HD_WIDTH;
	a = ft_atoi(argv[3]);
	if (a > 0)
		fdf->height = a;
	else
		fdf->height = FULL_HD_HEIGHT;
	fdf->zoom = 1;
	return (1);
}

void	read_map(int fd, t_fdf *fdf, t_map *map, t_map *begin)
{
	int		a;
	char	*line;

	while (a = get_next_line(fd, &line))
	{
		ft_list_push_left(&map);
		map->str = ft_strsplit(line, ' ');
		ft_strdel(&line);
		map->next->count++;
		map = map->next;
	}
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->width, fdf->height, "fdf_ecole_42");
	print_map(fdf, begin);
}

int		main(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;
	t_map	*map;
	t_map	*begin;

	map = NULL;
	begin = map;
	if (argc >= 2)
	{
		check_params(argv, &fdf);
		fd = open(argv[1], O_RDONLY);
		(fd <= 0) ? ft_error() : 0;
		read_map(fd, &fdf, map, begin);
		mlx_pixel_put(fdf.mlx_ptr, fdf.win_ptr, 250, 250, 0xFF0100);
		mlx_string_put(fdf.mlx_ptr, fdf.win_ptr, 252, 250, 0xe7eb00, "BEGIN");
		print_line(&fdf, &fdf.cor, 0xFF0100);
		mlx_key_hook(fdf.win_ptr, deal_key, (void *)53);
		mlx_loop(fdf.mlx_ptr);
	}
	ft_error();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:47:52 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/10 20:32:07 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*ft_create_elem(char **str)
{
	t_map *element;

	if (!(element = malloc(sizeof(t_map))))
		return (NULL);
	element->str = str;
	element->next = NULL;
	return (element);
}

int		ft_list_push_left(t_map **begin_list, char **str)
{
	t_map	*tmp;

	if (begin_list && *begin_list)
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(str);
		return (0);
	}
	else
		*begin_list = ft_create_elem(str);
	return (1);
}

t_cor	*init_cor(void)
{
	t_cor *cor;
	cor = (t_cor *)ft_memalloc(sizeof(t_cor));
	cor->deltaX = 0;
	cor->deltaY = 0;
	cor->error = 0;
	cor->signX = 0;
	cor->signY = 0;
	cor->x_beg = 0;
	cor->y_beg = 0;
	cor->x_end = 0;
	cor->y_end = 0;
	return (cor);
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

void	*new_dot(t_xyz *xyz, t_fdf *fdf, char **map)
{
	xyz->z = ft_atoi(map[xyz->x]);
	xyz->x *= fdf->zoom;
	xyz->y *= fdf->zoom;
	xyz->z *= fdf->zoom / fdf->z_height;
	xyz->x += fdf->width / 4;
	xyz->y += fdf->height / 4;
	rotate_x(&xyz->y, &xyz->z, xyz->alpha);
	rotate_y(&xyz->x, &xyz->z, xyz->beta);
	rotate_z(&xyz->x, &xyz->y, xyz->gamma);
	iso(&xyz->x, &xyz->y, xyz->z);
}

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
}

void	print_map(t_fdf *fdf, t_map *map)
{
	t_xyz	xyz;

	xyz.y = 0;
	xyz.z = 0;
	xyz.alpha = 0;
	xyz.beta = 0;
	xyz.gamma = 0;
	while(map != NULL)
	{
		fdf->map = map;
		xyz.x = 0;
		while(xyz.x != fdf->map_width)
		{
			if (xyz.x != fdf->map_width - 1)
				print_line(fdf, new_xyz(xyz, xyz.x + 1, xyz.y, fdf), 0xe7eb00);
			if (xyz.y != fdf->map_height - 1)
				print_line(fdf, new_xyz(xyz, xyz.x, xyz.y + 1, fdf), 0xe7eb00);
			xyz.x++;
		}
		map = map->next;
		xyz.y++;
	}
}

void	ft_error()
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

int		check_params(char **argv, t_fdf *fdf)
{
	int a;

	a = 0;
	(!(argv[1])) ? ft_error() : 0;
	(argv[2]) ? a = ft_atoi(argv[2]): 0;
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

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	fdf->map = NULL;
	fdf->z_height = 1;
	fdf->zoom = 20;
	fdf->x_move = 0;
	fdf->y_move = 0;
	fdf->map_height = 0;
	fdf->map_width = 0;
	return (fdf);
}

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
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->width, fdf->height, "fdf");
	print_map(fdf, begin);
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
		mlx_loop(fdf->mlx_ptr);
	}
	return (0);
}
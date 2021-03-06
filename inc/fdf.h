/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:45:24 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/28 16:43:29 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "math.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define FULL_HD_WIDTH 1920
# define FULL_HD_HEIGHT 1080

typedef struct		s_cor
{
	int				x_beg;
	int				y_beg;
	int				x_end;
	int				y_end;
	int				deltax;
	int				deltay;
	int				signx;
	int				signy;
	int				error;
	int				error2;
}					t_cor;

typedef struct		s_xyz
{
	int				x;
	int				y;
	int				z;
}					t_xyz;

typedef struct		s_map
{
	char			**str;
	struct s_map	*next;
}					t_map;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				zoom;
	int				width;
	int				map_width;
	int				map_height;
	int				height;
	int				x_move;
	int				y_move;
	int				count;
	int				text;
	t_map			*map;
	t_map			*begin;
	double			gamma;
	double			beta;
	double			alpha;
	float			z_height;
	int				paralel;
	int				color;
}					t_fdf;

int					main(int argc, char **argv);
int					check_params(char **argv, t_fdf *fdf);
void				zoom_check_min(t_fdf *fdf, t_map *begin);
void				zoom_check_max(t_fdf *fdf, t_map *begin);
void				zoom_continue(t_fdf *fdf, t_xyz *xyz, t_map *map, int zoom);
void				read_map(int fd, t_fdf *fdf, t_map *map, t_map *begin);
void				print_map(t_fdf *fdf, t_map *map);
void				new_dot(t_xyz *xyz, t_fdf *fdf, char **map);
void				line(t_fdf *fdf, t_cor *cor, int color);
t_cor				*new_xyz(t_xyz xyz, int x_end, int y_end, t_fdf *fdf);
int					ft_list_push_left(t_map **begin_list, char **str);
t_map				*ft_create_elem(char **str);
t_cor				*init_cor(void);
t_fdf				*init_fdf(void);
void				ft_zoom(int key, t_fdf *fdf);
void				ft_color(int key, t_fdf *fdf);
void				ft_move(int key, t_fdf *fdf);
void				ft_z_height(int key, t_fdf *fdf);
int					key_press(int key, void *param);
void				control_text(t_fdf *fdf);
void				ft_text(t_fdf *fdf);
void				ft_rotate(int key, t_fdf *fdf);
void				ft_paralel(t_fdf *fdf);
void				ft_iso(t_fdf *fdf);
int					color(t_xyz xyz, t_fdf *fdf, char c);
int					map_checker(t_map *map, int x, int width);
void				mapcheck(t_map *begin, t_fdf *fdf);
int					atoi_base(char *str, int base);
int					rgb_set(char *str, int base);
int					ft_power(int power, int num);
void				ft_strup(char *str);
void				rgb_2(char *str, int base, t_color *rgb);
void				rgb_4(char *str, int base, t_color *rgb);
void				rgb_6(char *str, int base, t_color *rgb);
void				ft_error(char *str);

#endif

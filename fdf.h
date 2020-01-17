/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:45:24 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/17 18:42:38 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "math.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define KEYCODE_ESC 53
# define KEYCODE_PLUS 69
# define KEYCODE_MINUS 78
# define KEYCODE_ISO 34
# define KEYCODE_PARALEL 35
# define KEYCODE_RIGHT_ARROW 124
# define KEYCODE_LEFT_ARROW 123
# define KEYCODE_UP_ARROW 126
# define KEYCODE_DOWN_ARROW 125
# define KEYCODE_8_NUM 91
# define KEYCODE_7_NUM 89
# define KEYCODE_9_NUM 92
# define KEYCODE_1_NUM 83
# define KEYCODE_3_NUM 85
# define KEYCODE_2_NUM 84
# define KEYCODE_6_NUM 88
# define KEYCODE_4_NUM 86
# define KEYCODE_C 8
# define KEYCODE_T 17
# define KEYCODE_Z_HEIGHT_DOWN 43
# define KEYCODE_Z_HEIGHT_UP 47

#define FULL_HD_WIDTH 1920
#define FULL_HD_HEIGHT 1080

typedef struct		s_cor
{
	int				x_beg;
	int				y_beg;
	int				x_end;
	int				y_end;
	int				deltaX;
	int				deltaY;
	int				signX;
	int				signY;
	int				error;
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
	int				color;
}					t_map;

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


int					check_params(char **argv, t_fdf *fdf);
void				zoom_check_min(t_fdf *fdf, t_map *begin);
void				zoom_check_max(t_fdf *fdf, t_map *begin);
void				zoom_continue(t_fdf *fdf, t_xyz *xyz, t_map *map, int zoom);
void				read_map(int fd, t_fdf *fdf, t_map *map, t_map *begin);
void				print_map(t_fdf *fdf, t_map *map);
void				*new_dot(t_xyz *xyz, t_fdf *fdf, char **map);
static void			iso(int *x, int *y, int z);
static void			rotate_z(int *x, int *y, double gamma);
static void			rotate_y(int *x, int *z, double beta);
static void			rotate_x(int *y, int *z, double alpha);
void				print_line(t_fdf *fdf, t_cor *cor, int color);
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
void				ft_text(int key, t_fdf *fdf);
void				ft_rotate(int key, t_fdf *fdf);
void				ft_paralel(int key, t_fdf *fdf);
void				ft_iso(int key, t_fdf *fdf);
int					color(t_xyz xyz, t_fdf *fdf);
void				ft_error();

#endif
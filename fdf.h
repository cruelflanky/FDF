/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:45:24 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/13 17:43:52 by gaudry           ###   ########.fr       */
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
	t_map			*map;
	t_map			*begin;
	double			gamma;
	double			beta;
	double			alpha;
	float			z_height;
	int				paralel;
}					t_fdf;

typedef struct		s_color
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
}					t_color;

int		key_press(int key, void *param);
void	print_map(t_fdf *fdf, t_map *map);

#endif
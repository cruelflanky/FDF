/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:45:24 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/11 16:32:45 by gaudry           ###   ########.fr       */
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
# define KEYCODE_RIGHT_ARROW 124
# define KEYCODE_LEFT_ARROW 123
# define KEYCODE_UP_ARROW 126
# define KEYCODE_DOWN_ARROW 125
# define KEYCODE_ZOOM_IN KEYCODE_PLUS
# define KEYCODE_ZOOM_OUT KEYCODE_MINUS
# define KEYCODE_AMPLIFY 47
# define KEYCODE_UNAMPLIFY 43

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
	double			gamma;
	double			beta;
	double			alpha;
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
	t_map			*map;
	float			z_height;
}					t_fdf;

typedef struct		s_color
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
}					t_color;

#endif
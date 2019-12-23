/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:45:24 by gaudry            #+#    #+#             */
/*   Updated: 2019/12/23 16:59:16 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

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

typedef struct		s_cor
{
	int		x_beg;
	int		y_beg;
	int		x_end;
	int		y_end;
}					t_cor;

#endif
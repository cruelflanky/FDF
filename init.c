/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:20:44 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/17 20:00:14 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	fdf->map = NULL;
	fdf->z_height = 1;
	fdf->x_move = 0;
	fdf->y_move = 0;
	fdf->text = 1;
	fdf->map_height = 0;
	fdf->map_width = 0;
	fdf->gamma = 0;
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->paralel = 0;
	fdf->count = 0;
	fdf->color = 2162933;
	return (fdf);
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
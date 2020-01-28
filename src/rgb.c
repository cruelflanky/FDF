/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:47:11 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/28 15:21:46 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rgb_2(char *str, int base, t_color *rgb)
{
	char		num[3];

	num[2] = '\0';
	num[0] = str[0];
	num[1] = str[1];
	rgb->b = (unsigned char)atoi_base(num, base);
}

void	rgb_4(char *str, int base, t_color *rgb)
{
	char		num[3];

	num[2] = '\0';
	num[0] = str[0];
	num[1] = str[1];
	rgb->g = (unsigned char)atoi_base(num, base);
	num[0] = str[2];
	num[1] = str[3];
	rgb->b = (unsigned char)atoi_base(num, base);
}

void	rgb_6(char *str, int base, t_color *rgb)
{
	char		num[3];

	num[2] = '\0';
	num[0] = str[0];
	num[1] = str[1];
	rgb->r = (unsigned char)atoi_base(num, base);
	num[0] = str[2];
	num[1] = str[3];
	rgb->g = (unsigned char)atoi_base(num, base);
	num[0] = str[4];
	num[1] = str[5];
	rgb->b = (unsigned char)atoi_base(num, base);
}

int		rgb_set(char *str, int base)
{
	t_color		rgb;
	int			i;

	((i = ft_strlen(str)) > 6) ? ft_error("error") : 0;
	if (i == 2)
		rgb_2(str, base, &rgb);
	if (i == 4)
		rgb_4(str, base, &rgb);
	if (i == 6)
		rgb_6(str, base, &rgb);
	return ((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xff);
}

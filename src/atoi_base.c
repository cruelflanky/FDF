/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:50:28 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/24 17:46:31 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_strup(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			str[i] -= 32;
		i++;
	}
}

int		ft_power(int power, int num)
{
	int sum;

	sum = num;
	if (power == 0)
		return (1);
	while (power-- > 1)
		sum *= num;
	return (sum);
}

int		atoi_base(char *str, int base)
{
	char	*buf;
	int		i;
	t_xyz	xyz;

	xyz.y = 0;
	i = ft_strlen(str) - 1;
	xyz.z = 0;
	xyz.x = 0;
	buf = "0123456789ABCDEF\0";
	ft_strup(str);
	while (i > -1)
	{
		xyz.z = 0;
		while (buf[xyz.z])
		{
			if (buf[xyz.z] == str[i])
				break ;
			xyz.z++;
		}
		(xyz.z > 15) ? exit(EXIT_FAILURE) : 0;
		xyz.x += ft_power(xyz.y++, base) * xyz.z;
		i--;
	}
	return (xyz.x);
}

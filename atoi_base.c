/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:50:28 by gaudry            #+#    #+#             */
/*   Updated: 2020/01/21 12:52:12 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		ft_power(int power, int num)
{
	int sum;

	sum = num;
	if (power == 0)
		return (1);
	while(power-- > 1)
		sum *= num;
	return (sum);
}

int		atoi_base(char *str, int base)
{
	char	*buf;
	int		i;
	int		index;
	int		num;
	int		power;
	int		power_num;
	int		number;

	power = 0;
	i = ft_strlen(str) - 1;
	index = 0;
	num = 0;
	buf = "0123456789ABCDEF\0";

	if (base < 2 || base > 16)
		return (0);
	while (i > -1)
	{
		index = 0;
		while (buf[index])
		{
			if (buf[index] == str[i])
				break;
			index++;
		}
		(index > 15) ? exit(EXIT_FAILURE) : 0;
		power_num = ft_power(power++, base);
		number = power_num * index;
		num += number;
		i--;
	}
	return (num);
}
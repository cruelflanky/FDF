/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:48:39 by gmeda             #+#    #+#             */
/*   Updated: 2019/12/21 13:52:04 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*convert(int n, int i)
{
	char		*str;

	if (!(str = malloc(sizeof(char) * (i + 2))))
		return (NULL);
	if (n == -2147483648)
	{
		str[1] = '2';
		n = -147483648;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[i + 1] = '\0';
	while (n / 10 != 0)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
	str[i] = n % 10 + '0';
	return (str);
}

char			*ft_itoa(int n)
{
	int			i;
	int			cup;

	i = 0;
	if (n < 0)
		i++;
	cup = n;
	while (cup / 10 != 0)
	{
		cup = cup / 10;
		i++;
	}
	return (convert(n, i));
}

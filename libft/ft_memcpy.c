/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:40:00 by gmeda             #+#    #+#             */
/*   Updated: 2019/12/21 13:52:04 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			len;

	if (n == 0 || s1 == s2)
		return (s1);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	len = 0;
	while (len < n)
	{
		str1[len] = str2[len];
		++len;
	}
	return (s1);
}

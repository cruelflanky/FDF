/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:51:58 by gmeda             #+#    #+#             */
/*   Updated: 2019/12/21 13:52:04 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char			*s1;
	const unsigned char		*s2;
	size_t					i;

	if (len == 0 || dest == src)
		return (dest);
	s1 = (unsigned char*)dest;
	s2 = (unsigned char*)src;
	i = 0;
	if (s2 < s1)
	{
		while (++i <= len)
			s1[len - i] = s2[len - i];
	}
	else
	{
		while (len-- > 0)
			*(s1++) = *(s2++);
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaudry <gaudry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:17:11 by gmeda             #+#    #+#             */
/*   Updated: 2019/12/21 13:52:04 by gaudry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*conc;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(conc = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s1)
		*(conc++) = *(s1++);
	while (*s2)
		*(conc++) = *(s2++);
	*conc = '\0';
	return (conc - len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:48:57 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/07 13:48:57 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char*)str1;
	source = (unsigned char*)str2;
	if (str1 > str2)
	{
		i = n;
		while (i > 0)
		{
			dest[i - 1] = source[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (str1);
}

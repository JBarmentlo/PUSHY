/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:32:39 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/07 14:32:39 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*data;

	i = 0;
	data = (unsigned char*)str;
	while (i < n)
	{
		if (data[i] == (unsigned char)c)
			return (data + i);
		i++;
	}
	return (NULL);
}

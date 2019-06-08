/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:58:12 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/07 13:58:12 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*data;

	i = 0;
	data = (unsigned char*)malloc(size);
	if (data == NULL)
		return (NULL);
	while (i < size)
	{
		data[i] = 0;
		i++;
	}
	return ((void*)data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:22:30 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/07 10:22:30 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*data;

	i = 0;
	data = (unsigned char*)b;
	while (i < len)
	{
		data[i] = (unsigned char)c;
		i++;
	}
	return ((void*)b);
}

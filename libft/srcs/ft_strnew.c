/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:03:08 by gtaja             #+#    #+#             */
/*   Updated: 2019/05/15 14:44:22 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!(result = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (i < size + 1)
		result[i++] = '\0';
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:54:45 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/07 15:54:45 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = ft_strlen(s1) + 1;
	result = (char*)malloc(len * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	return (result);
}

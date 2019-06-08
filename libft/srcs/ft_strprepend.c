/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:45:45 by gtaja             #+#    #+#             */
/*   Updated: 2019/01/29 19:02:23 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_strprepend(char **base, char *more)
{
	char	*tmp;

	if (base == NULL || more == NULL)
		return (0);
	if (*base == NULL)
	{
		if (!(*base = ft_strdup(more)))
			return (0);
		return (1);
	}
	tmp = *base;
	if (!(*base = ft_strnew(ft_strlen(*base) + ft_strlen(more))))
		return (0);
	ft_strcpy(*base, more);
	ft_strcat(*base, tmp);
	free(tmp);
	return (1);
}

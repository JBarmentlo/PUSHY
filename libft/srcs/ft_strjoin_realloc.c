/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:41:39 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/27 10:41:39 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strjoin_realloc(char **dest, char *add, int reverse)
{
	char	*temp;

	if (dest == NULL || *dest == NULL || add == NULL)
		return (-1);
	temp = *dest;
	if (reverse)
		*dest = ft_strjoin(add, temp);
	else
		*dest = ft_strjoin(temp, add);
	free(temp);
	return (ft_strlen(*dest));
}

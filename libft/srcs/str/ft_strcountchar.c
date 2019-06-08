/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcountchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:40:54 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/25 12:41:09 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcountchar(char *str, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			res++;
		i++;
	}
	return (res);
}
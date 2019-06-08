/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloco.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:18:41 by jbarment          #+#    #+#             */
/*   Updated: 2019/05/08 18:50:42 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*malloco(size_t size)
{
	void	*result;

	if (!(result = malloc(size)))
	{
		exit(EXIT_SUCCESS);
		return (NULL);
	}
	return (result);
}

void	*calloco(size_t size, size_t n)
{
	void	*result;

	result = malloco(size * n);
	ft_bzero(result, size * n);
	return (result);
}

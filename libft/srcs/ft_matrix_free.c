/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoiretaja <gregoiretaja@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:37:50 by gregoiretaja      #+#    #+#             */
/*   Updated: 2018/11/13 13:37:50 by gregoiretaja     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_matrix.h"

void			ft_matrix_free(t_matrix **matrix)
{
	unsigned int	x;

	if (matrix == NULL || *matrix == NULL)
		return ;
	x = 0;
	while (x < (*matrix)->width)
	{
		free((*matrix)->data[x]);
		x++;
	}
	free((*matrix)->data);
	free(*matrix);
	*matrix = NULL;
}

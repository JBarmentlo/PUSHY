/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoiretaja <gregoiretaja@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:24:06 by gregoiretaja      #+#    #+#             */
/*   Updated: 2018/11/13 13:24:06 by gregoiretaja     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_matrix.h"

static t_matrix	*ft_alloc_matrix_struct(int width)
{
	t_matrix	*result;

	if (!(result = (t_matrix*)malloc(sizeof(t_matrix))))
		return (NULL);
	if (!(result->data = (int**)malloc(sizeof(int*) * width)))
	{
		free(result);
		return (NULL);
	}
	return (result);
}

static int		ft_alloc_matrix_data(t_matrix *matrix)
{
	int	x;
	int	y;

	x = 0;
	while (x < (int)matrix->width)
	{
		if (!(matrix->data[x] = (int*)malloc(sizeof(int) * matrix->height)))
		{
			while (--x >= 0)
				free(matrix->data[x]);
			free(matrix->data);
			free(matrix);
			return (0);
		}
		y = 0;
		while (y < (int)matrix->height)
		{
			matrix->data[x][y] = 0;
			y++;
		}
		x++;
	}
	return (1);
}

t_matrix		*ft_matrix_create(int width, int height)
{
	t_matrix	*result;

	if (!(result = ft_alloc_matrix_struct(width)))
		return (NULL);
	result->width = width;
	result->height = height;
	if (!ft_alloc_matrix_data(result))
		return (NULL);
	return (result);
}

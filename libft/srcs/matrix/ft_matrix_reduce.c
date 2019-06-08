/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_reduce.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:14:59 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/17 13:14:59 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_start_x(t_matrix *matrix)
{
	int			x;
	int			y;
	int			reduce_this;
	int			start_x;

	x = 0;
	start_x = 0;
	while (x < (int)matrix->width)
	{
		reduce_this = 1;
		y = 0;
		while (y < (int)matrix->height)
		{
			if (matrix->data[x][y] != 0)
				reduce_this = 0;
			y++;
		}
		if (reduce_this && start_x == x)
			start_x++;
		x++;
	}
	return (start_x);
}

static int	ft_get_end_x(t_matrix *matrix)
{
	int			x;
	int			y;
	int			reduce_this;
	int			end_x;

	x = (int)matrix->width - 1;
	end_x = x;
	while (x >= 0)
	{
		reduce_this = 1;
		y = 0;
		while (y < (int)matrix->height)
		{
			if (matrix->data[x][y] != 0)
				reduce_this = 0;
			y++;
		}
		if (reduce_this && end_x == x)
			end_x--;
		x--;
	}
	return (end_x);
}

static int	ft_get_start_y(t_matrix *matrix)
{
	int			x;
	int			y;
	int			reduce_this;
	int			start_y;

	y = 0;
	start_y = 0;
	while (y < (int)matrix->height)
	{
		reduce_this = 1;
		x = 0;
		while (x < (int)matrix->width)
		{
			if (matrix->data[x][y] != 0)
				reduce_this = 0;
			x++;
		}
		if (reduce_this && start_y == y)
			start_y++;
		y++;
	}
	return (start_y);
}

static int	ft_get_end_y(t_matrix *matrix)
{
	int			x;
	int			y;
	int			reduce_this;
	int			end_y;

	y = (int)matrix->height - 1;
	end_y = y;
	while (y >= 0)
	{
		reduce_this = 1;
		x = 0;
		while (x < (int)matrix->width)
		{
			if (matrix->data[x][y] != 0)
				reduce_this = 0;
			x++;
		}
		if (reduce_this && end_y == y)
			end_y--;
		y--;
	}
	return (end_y);
}

/*
** Reduit la matrice sur les bord egale a 0
** La fonction retourne la nouvelle adresse de la matrice
*/

t_matrix	*ft_matrix_reduce(t_matrix **matrix)
{
	t_matrix		*result;
	t_rect			rect;
	unsigned int	x;
	unsigned int	y;

	rect.x = ft_get_start_x(*matrix);
	rect.y = ft_get_start_y(*matrix);
	rect.width = ft_get_end_x(*matrix) - rect.x + 1;
	rect.height = ft_get_end_y(*matrix) - rect.y + 1;
	if (rect.width == (*matrix)->width && rect.height == (*matrix)->height)
		return (*matrix);
	x = rect.x;
	result = ft_matrix_create(rect.width, rect.height);
	while (x < rect.x + rect.width)
	{
		y = rect.y - 1;
		while (++y < rect.y + rect.height)
			result->data[x - rect.x][y - rect.y] = (*matrix)->data[x][y];
		x++;
	}
	ft_matrix_free(matrix);
	*matrix = result;
	return (result);
}

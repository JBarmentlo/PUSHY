/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_localtravel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoiretaja <gregoiretaja@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:05:05 by gregoiretaja      #+#    #+#             */
/*   Updated: 2018/11/13 14:05:05 by gregoiretaja     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

void	ft_matrix_localtravel(t_matrix *matrix, t_rect rect,
	void (*fct)(t_matrix *matrix, t_vector pos))
{
	unsigned int	x;
	unsigned int	y;
	t_vector		vector;

	y = rect.y;
	while (y < matrix->height && y < rect.y + rect.height)
	{
		x = rect.x;
		while (x < matrix->width && x < rect.x + rect.width)
		{
			vector.x = x;
			vector.y = y;
			(*fct)(matrix, vector);
			x++;
		}
		y++;
	}
}

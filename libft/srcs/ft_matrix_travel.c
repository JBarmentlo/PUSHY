/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_travel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoiretaja <gregoiretaja@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:09:27 by gregoiretaja      #+#    #+#             */
/*   Updated: 2018/11/13 14:09:27 by gregoiretaja     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

void	ft_matrix_travel(t_matrix *matrix,
	void (*fct)(t_matrix *matrix, t_vector pos))
{
	t_rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.width = matrix->width;
	rect.height = matrix->height;
	ft_matrix_localtravel(matrix, rect, fct);
}

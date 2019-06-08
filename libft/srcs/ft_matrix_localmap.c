/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_localmap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoiretaja <gregoiretaja@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:26:47 by gregoiretaja      #+#    #+#             */
/*   Updated: 2018/11/14 11:26:47 by gregoiretaja     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_matrix_localmap(t_matrix *m1, t_matrix *m2,
	t_vector pos, int (*fct)(int, int))
{
	unsigned int	x;
	unsigned int	y;

	y = pos.y;
	while (y < pos.y + m2->height && y < m1->height)
	{
		x = pos.x;
		while (x < pos.x + m2->width && x < m1->width)
		{
			m1->data[x][y] = (*fct)(m1->data[x][y],
				m2->data[x - pos.x][y - pos.y]);
			x++;
		}
		y++;
	}
}

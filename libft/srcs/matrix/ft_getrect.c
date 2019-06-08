/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getrect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:44:53 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/13 16:44:53 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

t_rect	ft_getrect(int x, int y, int width, int height)
{
	t_rect rect;

	rect.x = x;
	rect.y = y;
	rect.width = width;
	rect.height = height;
	return (rect);
}

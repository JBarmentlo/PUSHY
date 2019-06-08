/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_show.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoiretaja <gregoiretaja@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:41:55 by gregoiretaja      #+#    #+#             */
/*   Updated: 2018/11/13 13:41:55 by gregoiretaja     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nbrlen(unsigned int nb)
{
	unsigned int len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void			ft_putspaces(unsigned int amount)
{
	unsigned int i;

	i = 0;
	while (i++ < amount)
		ft_putchar(' ');
}

static void			ft_putnbr_dim(unsigned int nb)
{
	int spaces;

	spaces = MATRIX_NBR_LEN - ft_nbrlen(nb);
	if (spaces > 0)
		ft_putspaces((unsigned int)spaces);
	ft_putnbr(nb);
}

void				ft_matrix_show(t_matrix *matrix)
{
	unsigned int spaces;
	unsigned int x;
	unsigned int y;

	spaces = ft_nbrlen(matrix->width) + ft_nbrlen(matrix->height) + 2;
	ft_putnbr(matrix->width);
	ft_putchar('x');
	ft_putnbr(matrix->height);
	ft_putchar(' ');
	y = 0;
	while (y < matrix->height)
	{
		ft_putspaces(y > 0 ? spaces : 0);
		ft_putchar('|');
		x = 0;
		while (x < matrix->width)
		{
			ft_putnbr_dim(matrix->data[x][y]);
			ft_putchar(' ');
			x++;
		}
		ft_putstr("|\n");
		y++;
	}
}

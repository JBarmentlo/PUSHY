/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freechain_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:34:51 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/25 13:56:30 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freechain.h"

void	ft_freechain_adddoubletab(char *freechain_id, void **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		ft_freechain_add(freechain_id, 1, tab[i]);
		i++;
	}
	ft_freechain_add(freechain_id, 1, tab);
}

void	ft_freechain_addmatrix(char *freechain_id, t_matrix *matrix)
{
	unsigned int	i;

	i = 0;
	while (i < matrix->width)
	{
		ft_freechain_add(freechain_id, 1, matrix->data[i]);
		i++;
	}
	ft_freechain_add(freechain_id, 2, matrix->data, matrix);
}

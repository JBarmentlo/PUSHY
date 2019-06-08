/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregoiretaja <gregoiretaja@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:38:12 by gregoiretaja      #+#    #+#             */
/*   Updated: 2018/11/14 11:38:12 by gregoiretaja     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_matrix_map(t_matrix *m1, t_matrix *m2, int (*fct)(int, int))
{
	ft_matrix_localmap(m1, m2, ft_getvector(0, 0), fct);
}

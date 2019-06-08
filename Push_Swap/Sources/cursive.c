/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:07 by jbarment          #+#    #+#             */
/*   Updated: 2019/06/06 15:43:09 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	m_ab(t_s *sys, int size, t_end_list **start)
{
	if (sys->a->size - sorted_till(sys) <= 3)
		sort_three(sys, start);
	else
	{
		a_b(sys, size, start);
		if (size > 2)
			m_ab(sys, size / 2, start);
		m_ba(sys, size / 2 + size % 2, start);
	}
}

void	m_ba(t_s *sys, int size, t_end_list **start)
{
	b_a(sys, size, start);
	if (size / 2 + size % 2 > 1)
		m_ab(sys, size / 2 + size % 2, start);
	if (size / 2 > 0)
		m_ba(sys, size / 2, start);
}

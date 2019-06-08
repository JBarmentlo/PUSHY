/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:08 by jbarment          #+#    #+#             */
/*   Updated: 2019/06/08 18:26:34 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include "libft.h"
#include <string.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	t_s			*sys;
	t_end_list	*start;

	if (ac < 2)
		error();
	start = NULL;
	sys = init(av, ac);
	if (!is_walid(sys))
	{
		sys_free(sys);
		error();
	}
	clean_input(sys);
	if (is_sorted(sys))
	{
		sys_free(sys);
		return (1);
	}
	m_ab(sys, sys->size - sorted_till(sys), &start);
	simplify(&start);
	print_list(&start);
	sys_free(sys);
	free_end_list(&start);
	return (1);
}

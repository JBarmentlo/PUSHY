/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freechain_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:20:10 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/25 13:39:14 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freechain.h"

static void	ft_lstrelink(t_list **lst, t_list *prev, t_list *next)
{
	if (prev != NULL)
		prev->next = next;
	else if (lst != NULL)
		(*lst)->next = next;
}

static void	ft_freechain_content(t_freechain *chain)
{
	t_list		*it;
	t_list		*tmp;

	it = chain->list;
	while (it != NULL)
	{
		tmp = it->next;
		free(it->content);
		free(it);
		it = tmp;
	}
	free(chain);
}

void		ft_freechain_free(char *chain_id)
{
	t_freechain	*result;
	t_list		**chain;
	t_list		*it;
	t_list		*prev;

	chain = ft_freechain_global();
	it = *chain;
	prev = NULL;
	while (it != NULL)
	{
		result = (t_freechain*)it->content;
		if (ft_strequ(result->id, chain_id))
		{
			ft_freechain_content(result);
			ft_lstrelink(chain, prev, it->next);
			free(it);
			return ;
		}
		prev = it;
		it = it->next;
	}
}

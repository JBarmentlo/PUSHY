/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freechain.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 10:31:47 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/25 13:25:02 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freechain.h"
#include <stdarg.h>

t_list			**ft_freechain_global(void)
{
	static t_list	*chain = NULL;

	return (&chain);
}

t_freechain		*ft_freechain_get(char *chain_id)
{
	t_freechain	*result;
	t_list		**chain;
	t_list		*it;

	chain = ft_freechain_global();
	it = *chain;
	while (it != NULL)
	{
		result = (t_freechain*)it->content;
		if (ft_strequ(result->id, chain_id))
			return (result);
		it = it->next;
	}
	result = (t_freechain*)malloco(sizeof(t_freechain));
	result->id = chain_id;
	result->list = NULL;
	ft_lstadd(chain, ft_lstitem(result, sizeof(t_freechain)));
	return (result);
}

void			ft_freechain_add(char *chain_id, int n, ...)
{
	int			i;
	t_freechain	*chain;
	va_list		va;

	va_start(va, n);
	chain = ft_freechain_get(chain_id);
	i = 0;
	while (i < n)
	{
		ft_lstpushback(&(chain->list),
			ft_lstitem(va_arg(va, void*), sizeof(void*)));
		i++;
	}
	va_end(va);
}

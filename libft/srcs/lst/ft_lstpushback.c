/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 14:25:26 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/17 14:25:26 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list	*it;

	if (*alst == NULL)
	{
		ft_lstadd(alst, new);
		return ;
	}
	it = *alst;
	while (it->next != NULL)
		it = it->next;
	it->next = new;
}

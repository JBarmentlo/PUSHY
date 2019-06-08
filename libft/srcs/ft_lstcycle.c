/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:16:53 by exam              #+#    #+#             */
/*   Updated: 2018/11/13 11:53:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_list	**ft_add_viewed(t_list **viewed, t_list *to_add)
{
	int		i;
	int		len;
	t_list	**result;

	i = 0;
	len = 0;
	while (viewed != NULL && viewed[len] != NULL)
		len++;
	if (!(result = (t_list**)malloc((len + 2) * sizeof(t_list*))))
		return (NULL);
	while (i < len)
	{
		result[i] = viewed[i];
		i++;
	}
	result[i] = to_add;
	result[i + 1] = NULL;
	if (viewed != NULL)
		free(viewed);
	return (result);
}

static int		ft_is_already_in_list(t_list **viewed, t_list *to_check)
{
	int	i;

	i = 0;
	if (viewed == NULL)
		return (0);
	while (viewed[i] != NULL)
	{
		if (viewed[i] == to_check)
			return (1);
		i++;
	}
	return (0);
}

int				ft_lstcycle(const t_list *list)
{
	int		i;
	t_list	**viewed;
	t_list	*it;

	if (list == NULL)
		return (0);
	i = 0;
	viewed = NULL;
	it = (t_list*)list;
	if (it == NULL)
		return (0);
	while (it != NULL)
	{
		if (ft_is_already_in_list(viewed, it))
			return (1);
		viewed = ft_add_viewed(viewed, it);
		it = it->next;
	}
	free(viewed);
	return (0);
}

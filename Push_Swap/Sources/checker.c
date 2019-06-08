/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarment <jbarment@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:58:07 by jbarment          #+#    #+#             */
/*   Updated: 2019/06/08 18:32:48 by jbarment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
#include <unistd.h>
#include "libft.h"
#include <fcntl.h>

char	*initio_el_checko(void)
{
	char		buff[100];
	char		*str;
	char		*str_tmp;
	int			red;

	str = malloc(1);
	str[0] = '\0';
	while ((red = read(0, buff, 100)) > 0)
	{
		buff[red] = '\0';
		str_tmp = str;
		str = ft_strjoin(str, buff);
		free(str_tmp);
	}
	return (str);
}

void	end(t_s *sys)
{
	if (is_sorted(sys))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	checker_init(t_s **sys, t_end_list **start, char **str)
{
	*start = NULL;
	if (!is_walid(*sys))
	{
		sys_free(*sys);
		error();
	}
	clean_input(*sys);
	*str = initio_el_checko();
	str_to_list(start, *str);
	free(*str);
}

int		main(int ac, char **av)
{
	t_s			*sys;
	t_end_list	*start;
	t_end_list	*it;
	char		*str;

	if (ac < 2 || av[1][0] == '\0')
		return (0);
	sys = init(av, ac);
	checker_init(&sys, &start, &str);
	it = start;
	while (it)
	{
		if (it->op == NULL)
		{
			sys_free(sys);
			free_end_list(&start);
			error();
		}
		it->op(sys, NULL);
		it = it->next;
	}
	end(sys);
	free_end_list(&start);
}

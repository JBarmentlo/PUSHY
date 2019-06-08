/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:43:50 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/27 13:43:50 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*ft_get_flag_dest(t_conv *conv, char flag)
{
	int	*dest;

	dest = NULL;
	if (flag == '0')
		dest = &(conv->add_zero);
	else if (flag == '-')
		dest = &(conv->left_justify);
	else if (flag == '+')
		dest = &(conv->show_sign);
	else if (flag == ' ')
		dest = &(conv->sign_space);
	else if (flag == '#')
		dest = &(conv->hashtag);
	else if (flag == 'A')
		dest = &(conv->is_array);
	return (dest);
}

static int	ft_set_len_modifier(t_conv *conv, char **start, int prior)
{
	char	*start_cpy;

	start_cpy = *start;
	if (ft_strlen(conv->len_modifier) == 2)
		prior = ft_strncmp(conv->len_modifier, "hh", 2) == 0 ? 1 : 4;
	if (ft_strlen(conv->len_modifier) == 1)
		prior = ft_strncmp(conv->len_modifier, "h", 2) == 0 ? 2 : 3;
	if ((ft_strncmp(*start, "hh", 2) == 0 && prior < 1)
		|| (ft_strncmp(*start, "ll", 2) == 0 && prior < 4))
	{
		ft_strncpy(conv->len_modifier, *start, 2);
		conv->len_modifier[2] = '\0';
	}
	else if ((**start == 'h' && prior < 2) || (**start == 'l' && prior < 3)
		|| (**start == 'L' && prior < 3))
	{
		ft_strncpy(conv->len_modifier, *start, 1);
		conv->len_modifier[1] = '\0';
	}
	if (ft_strncmp(*start, "hh", 2) == 0 || ft_strncmp(*start, "ll", 2) == 0)
		*start = *start + 2;
	else if (**start == 'h' || **start == 'l' || **start == 'L')
		*start = *start + 1;
	return (*start != start_cpy);
}

static void	ft_searchsize(t_conv *conv, char **start)
{
	if (ft_isdigit(**start) && **start != '0')
	{
		conv->size = 0;
		while (ft_isdigit(**start))
		{
			conv->size = conv->size * 10 + **start - '0';
			(*start)++;
		}
	}
	if (**start == '.')
	{
		(*start)++;
		conv->prec_set = 1;
		conv->prec = 0;
		while (ft_isdigit(**start))
		{
			conv->prec = conv->prec * 10 + **start - '0';
			(*start)++;
		}
	}
}

static void	ft_searchflag(t_conv *conv, char **start)
{
	int		i;
	char	flags[10];
	int		*dest;
	char	*start_cpy;

	i = 0;
	start_cpy = *start;
	ft_strcpy(flags, GLOBAL_FLAGS);
	while (flags[i])
	{
		if (!(dest = ft_get_flag_dest(conv, flags[i])))
			return ;
		if (**start == flags[i])
		{
			*dest = 1;
			*start = *start + 1;
		}
		i++;
	}
	ft_searchsize(conv, start);
	ft_set_len_modifier(conv, start, 0);
	if (*start != start_cpy)
		ft_searchflag(conv, start);
}

t_conv		ft_getconv(char *start)
{
	int			i;
	t_conv		conv;

	i = 0;
	start++;
	if (*start == '\0')
	{
		conv.conv = NULL;
		return (conv);
	}
	conv.size = 0;
	conv.prec = 0;
	conv.prec_set = 0;
	conv.add_zero = 0;
	conv.left_justify = 0;
	conv.show_sign = 0;
	conv.sign_space = 0;
	conv.hashtag = 0;
	conv.is_array = 0;
	ft_bzero((void*)conv.len_modifier, 3);
	ft_searchflag(&conv, &start);
	conv.conv = start;
	return (conv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_each.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:07:41 by gtaja             #+#    #+#             */
/*   Updated: 2019/02/27 18:22:46 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *str, char c)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			result++;
		i++;
	}
	return (result);
}

static char	*ft_strdup_word(char **start, char c)
{
	int		i;
	int		len;
	char	*str;
	char	*result;

	len = 0;
	str = *start;
	while (str[len] != c && str[len] != '\0')
		len++;
	result = calloco(sizeof(char), len + 1);
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	*start = *start + len;
	return (result);
}

char		**ft_strsplit_each(char *str, char c)
{
	int		i;
	int		count_words;
	char	**result;

	count_words = ft_count_words(str, c);
	result = (char**)calloco(sizeof(char*), count_words + 1);
	i = 0;
	while (i < count_words)
	{
		result[i] = ft_strdup_word(&str, c);
		if (*str == c)
			str++;
		i++;
	}
	return (result);
}

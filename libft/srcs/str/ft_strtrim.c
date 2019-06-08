/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtaja <gtaja@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:42:34 by gtaja             #+#    #+#             */
/*   Updated: 2018/11/08 16:42:34 by gtaja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen_trimed(char const *s)
{
	int	i;

	i = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while (s[i])
		i++;
	if (i == 0)
		return (0);
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	return (i + 1);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*result;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen_trimed(s);
	if (!(result = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

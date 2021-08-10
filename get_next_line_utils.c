/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwayfare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 03:24:35 by bwayfare          #+#    #+#             */
/*   Updated: 2021/01/23 03:24:38 by bwayfare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strchr(char *str, int ch)
{
	while (*str)
	{
		if (*str == ch)
			return (1);
		str++;
	}
	return (0);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	temp = malloc(sizeof(char *) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	while (s1 != NULL && s1[i] != '\0')
	{
		temp[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		temp[j++] = s2[i];
		i++;
	}
	if (s1 != NULL)
		free(s1);
	temp[j] = '\0';
	return (temp);
}

size_t		ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char		*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*temp;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (s == 0)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * len + 1);
	if (!temp)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			temp[j++] = s[i];
		i++;
	}
	temp[j] = 0;
	return (temp);
}

int			ft_eol(char *str)
{
	char *tmp;

	tmp = str;
	while (*str)
	{
		if (*str == '\n')
			return ((int)(str - tmp));
		str++;
	}
	return ((int)(str - tmp));
}

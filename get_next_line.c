/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwayfare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 03:26:35 by bwayfare          #+#    #+#             */
/*   Updated: 2021/01/23 03:26:36 by bwayfare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;
	char	*pdest;
	char	*psrc;

	i = 0;
	pdest = dest;
	psrc = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *str)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(str) + 1;
	if ((copy = malloc(len)) == NULL)
		return (NULL);
	ft_memcpy(copy, (char *)str, len);
	return (copy);
}

char	*ft_getrem(char *buf, int fd)
{
	char	*tmp;
	int		rf;

	rf = 1;
	if ((tmp = (char *)malloc(BUFFER_SIZE + 1)) == NULL)
		return (NULL);
	if (!buf)
	{
		if ((rf = read(fd, tmp, BUFFER_SIZE)) < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[rf] = '\0';
		buf = ft_strdup(tmp);
	}
	while (rf && !(ft_strchr(buf, '\n')))
	{
		rf = read(fd, tmp, BUFFER_SIZE);
		tmp[rf] = '\0';
		buf = ft_strjoin(buf, tmp);
	}
	free(tmp);
	return (buf);
}

int		get_next_line(int fd, char **line)
{
	static char *buf;
	int			len;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (!(buf = ft_getrem(buf, fd)))
		return (-1);
	len = ft_eol(buf);
	if (ft_strchr(buf, '\n'))
	{
		tmp = buf;
		*line = ft_substr(buf, 0, len);
		buf = ft_substr(tmp, len + 1, ft_strlen(buf) - ft_strlen(*line));
		free(tmp);
		return (1);
	}
	*line = ft_substr(buf, 0, len);
	free(buf);
	buf = NULL;
	return (0);
}

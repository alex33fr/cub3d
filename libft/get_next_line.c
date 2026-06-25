/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprivalo <aprivalo@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:11:30 by aprivalo          #+#    #+#             */
/*   Updated: 2025/12/25 00:41:32 by aprivalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*tab_join;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	tab_join = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!tab_join)
		return (NULL);
	ft_strlcpy(tab_join, s1, len_s1 + 1);
	ft_strlcpy(tab_join + len_s1, s2, len_s2 + 1);
	free(s1);
	return (tab_join);
}

static char	*ft_ret_line(char *s)
{
	ssize_t	i;
	ssize_t	len;
	char	*line;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	len = i + (s[i] == '\n');
	line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = s[i];
		i++;
	}
	return (line);
}

static char	*ft_upd_rest(char *rest)
{
	ssize_t	i;
	char	*upd_rest;

	i = 0;
	while (rest[i])
	{
		if (rest[i] == '\n')
		{
			if (rest[i + 1])
				upd_rest = ft_strdup(rest + i + 1);
			else
				upd_rest = NULL;
			free(rest);
			return (upd_rest);
		}
		i++;
	}
	free(rest);
	return (NULL);
}

static char	*read_to_rest(int fd, char *rest)
{
	char	*buf;
	ssize_t	rd;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	rd = 1;
	while (rd > 0 && (!rest || !ft_strchr(rest, '\n')))
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free(buf);
			return (NULL);
		}
		if (rd > 0)
		{
			buf[rd] = '\0';
			rest = ft_strjoin_gnl(rest, buf);
		}
	}
	free(buf);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = read_to_rest(fd, rest);
	if (!tmp)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	rest = tmp;
	if (!*rest)
	{
		free(rest);
		rest = NULL;
		return (NULL);
	}
	line = ft_ret_line(rest);
	rest = ft_upd_rest(rest);
	return (line);
}

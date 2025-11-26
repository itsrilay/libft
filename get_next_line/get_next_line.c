/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:21:44 by ruisilva          #+#    #+#             */
/*   Updated: 2025/11/26 18:39:04 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_newline(int fd, char *stash);
static char	*get_line(char **stash);
static char	*join_free(char *stash, char *buf);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = gnl_strdup("");
		if (!stash)
			return (NULL);
	}
	temp = read_to_newline(fd, stash);
	if (!temp)
		return (stash = NULL, NULL);
	stash = temp;
	if (*stash == '\0')
		return (free(stash), stash = NULL, NULL);
	line = get_line(&stash);
	return (line);
}

static char	*read_to_newline(int fd, char *stash)
{
	ssize_t	bytes_read;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free(stash), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buf), free(stash), NULL);
		if (bytes_read == 0)
			return (free(buf), stash);
		buf[bytes_read] = '\0';
		stash = join_free(stash, buf);
		if (!stash)
			return (free(buf), NULL);
		if (gnl_strchr(stash, '\n'))
			break ;
	}
	free(buf);
	return (stash);
}

static char	*get_line(char **stash)
{
	char	*n_ptr;
	int		n_len;
	char	*temp;
	char	*line;

	n_ptr = gnl_strchr(*stash, '\n');
	if (!n_ptr)
	{
		line = gnl_strdup(*stash);
		free(*stash);
		*stash = NULL;
		return (line);
	}
	n_len = n_ptr - *stash;
	line = gnl_substr(*stash, 0, n_len + 1);
	temp = gnl_strdup(++n_ptr);
	free(*stash);
	*stash = temp;
	return (line);
}

static char	*join_free(char *stash, char *buf)
{
	char	*temp;

	temp = gnl_strjoin(stash, buf);
	if (!temp)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	free(stash);
	stash = temp;
	return (stash);
}

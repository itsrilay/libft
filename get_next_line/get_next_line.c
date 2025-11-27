/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruisilva <ruisilva@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:21:44 by ruisilva          #+#    #+#             */
/*   Updated: 2025/10/23 14:25:40 by ruisilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_newline(int fd, char *stash);
char	*extract_line(char **stash);
char	*join_free(char *stash, char *buf);

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX] = {NULL};
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = gnl_strdup("");
		if (!stash[fd])
			return (NULL);
	}
	temp = read_to_newline(fd, stash[fd]);
	if (!temp)
		return (stash[fd] = NULL, NULL);
	stash[fd] = temp;
	if (*stash[fd] == '\0')
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	line = extract_line(&stash[fd]);
	return (line);
}

char	*read_to_newline(int fd, char *stash)
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

char	*extract_line(char **stash)
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

char	*join_free(char *stash, char *buf)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:45:50 by fghanem           #+#    #+#             */
/*   Updated: 2025/02/05 11:07:17 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_final_line(char **stash, char *line)
{
	char	*temp;
	char	*newline_pos;
	int		len;

	newline_pos = ft_strchr_gnl(line, '\n');
	if (newline_pos)
	{
		len = (newline_pos - line + 1);
		temp = malloc(len + 1);
		if (!temp)
		{
			free(line);
			return (NULL);
		}
		ft_strlcpy_gnl(temp, line, len + 1);
		*stash = ft_strdup_gnl(newline_pos + 1);
		free(line);
		return (temp);
	}
	else
	{
		free(newline_pos);
		*stash = ft_strdup_gnl("");
		return (line);
	}
}

char	*read_char(int fd, char *stash)
{
	ssize_t		char_read;
	char		*new_stash;
	char		*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr_gnl(stash, '\n'))
	{
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (char_read <= 0)
		{
			free(buffer);
			if ((char_read == 0 && stash[0] == '\0') || char_read == -1)
				return (free(stash), NULL);
			return (stash);
		}
		buffer[char_read] = '\0';
		new_stash = ft_strjoin_gnl(stash, buffer);
		free(stash);
		stash = new_stash;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup_gnl("");
	stash = read_char(fd, stash);
	if (!stash)
	{
		return (NULL);
	}
	line = get_final_line(&stash, stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (line);
}

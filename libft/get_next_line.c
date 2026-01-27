/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eride-ol <eride-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:05:45 by eride-ol          #+#    #+#             */
/*   Updated: 2026/01/27 11:28:39 by eride-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_remaining(char *result)
{
	int		i;
	int		j;
	char	*remainingamount;

	i = 0;
	while (result[i] && result[i] != '\n')
		i++;
	if (!result[i])
	{
		free(result);
		return (NULL);
	}
	remainingamount = ft_calloc((ft_strlen(result) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (result[i])
		remainingamount[j++] = result[i++];
	free(result);
	return (remainingamount);
}

char	*find_line(char *result)
{
	char	*line;
	int		i;

	i = 0;
	if (!result[i])
		return (NULL);
	while (result[i] && result[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (result[i] && result[i] != '\n')
	{
		line[i] = result[i];
		i++;
	}
	if (result[i] && result[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_until_newline(int fd, char *result)
{
	char	*read_buffer;
	char	*temp;
	int		bytes_read;

	if (!result)
		result = ft_calloc(1, 1);
	read_buffer = ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_buffer);
			free(result);
			return (NULL);
		}
		read_buffer[bytes_read] = 0;
		temp = ft_strjoin(result, read_buffer);
		free(result);
		result = temp;
		if (ft_strchr(result, '\n'))
			break ;
	}
	free(read_buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line_result;
	static char	*stash = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	stash = read_until_newline(fd, stash);
	if (!stash)
		return (NULL);
	line_result = find_line(stash);
	if (!line_result)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = find_remaining(stash);
	return (line_result);
}

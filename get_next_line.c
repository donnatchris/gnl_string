/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:53:52 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/18 13:39:26 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Read and add to line until a \n is find or until end of file
int	ft_add_read(int fd, char **p_line)
{
	int		n_read;
	char	*temp;
	char	*buff;

	buff = (char *) malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (1)
	{
		n_read = (int) read(fd, buff, BUFFER_SIZE);
		if (n_read == 0)
			return (free(buff), 1);
		if (n_read == -1)
			return (free(buff), 0);
		buff[n_read] = '\0';
		temp = ft_strjoin(*p_line, buff);
		if (!temp)
		{
			free(buff);
			if (*p_line)
				free(*p_line);
			*p_line = NULL;
			return (0);
		}
		if (*p_line)
			free(*p_line);
		*p_line = temp;
		if (ft_strchr(buff, '\n'))
			return (free(buff), 1);
	}
}

// Cut line after \n and store the rest in remainder
int	ft_check_newline(char **p_line, char **p_remainder)
{
	char	*newline_pos;
	char	*temp;

	if (!*p_line)
		return (0);
	newline_pos = ft_strchr(*p_line, '\n');
	if (newline_pos == NULL)
		return (0);
	if (newline_pos == *p_line + (ft_strlen(*p_line) - 1))
		return (1);
	temp = ft_strndup(*p_line, newline_pos + 1 - *p_line);
	if (!temp)
		return (1);
	*p_remainder = ft_strndup(newline_pos + 1, ft_strlen(newline_pos + 1));
	if (!*p_remainder)
		return (free(temp), 1);
	free(*p_line);
	*p_line = temp;
	return (1);
}

// Add remainder in line (if there is a remainder) and free remainder
int	ft_add_remainder(char **p_line, char **p_remainder)
{
	if (!*p_remainder)
		return (1);
	*p_line = ft_strndup(*p_remainder, ft_strlen(*p_remainder));
	if (!*p_line)
		return (free(*p_remainder), *p_remainder = NULL, 0);
	free(*p_remainder);
	*p_remainder = NULL;
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder = NULL;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_add_remainder(&line, &remainder) == 0)
		return (NULL);
	if (ft_check_newline(&line, &remainder) == 1)
		return (line);
	if (ft_add_read(fd, &line) == 0)
	{
		if (line)
			free(line);
		return (NULL);
	}
	ft_check_newline(&line, &remainder);
	return (line);
}
/*
#include <stdio.h>
int main(void)
{
    int     fd;
    char    *line;

    fd = open("test", O_RDONLY);
    if (fd == -1)
    {
        perror("Open file error");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
	//	sleep(1);
        free(line);
    }
    if (close(fd) == -1)
    {
        perror("Close file error");
        return (1);
    }
    return (0);
}
*/

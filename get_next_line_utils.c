/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdonnat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:54:43 by chdonnat          #+#    #+#             */
/*   Updated: 2024/11/15 14:55:15 by chdonnat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strndup(const char *s, size_t len)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			len;
	unsigned char	uc;

	len = ft_strlen(s);
	uc = (unsigned char) c;
	i = 0;
	while (i <= len)
	{
		if ((unsigned char) s[i] == uc)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	len1;
	char	*result;
	size_t	i;
	size_t	j;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	result = (char *) malloc(len1 + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		result[i++] = s2[j++];
	result[i + j] = '\0';
	return (result);
}

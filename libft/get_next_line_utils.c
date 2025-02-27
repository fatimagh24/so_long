/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:47:33 by fghanem           #+#    #+#             */
/*   Updated: 2025/02/04 16:39:49 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen_gnl(src);
	if (!dst || !src)
		return (src_len);
	if (!size)
		return (src_len);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (src_len);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*str1;
	char	*str2;
	int		i;

	str1 = (char *)s;
	i = ft_strlen_gnl(str1);
	str2 = (char *)malloc((i + 1) * sizeof(char));
	if (!str2)
		return (NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char			*str;
	unsigned char	letter;

	str = (char *)s;
	letter = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == letter)
			return (str);
		str++;
	}
	if (*str == '\0' && letter != '\0')
		return (NULL);
	return (str);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2)
				+ 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

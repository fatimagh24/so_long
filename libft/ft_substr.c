/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:22:29 by fghanem           #+#    #+#             */
/*   Updated: 2024/12/29 15:59:27 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *sub, char const *s,
		unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && s[start])
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
	{
		return (ft_strdup(""));
	}
	if (start + len > str_len)
		len = str_len - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strncpy(sub, s, start, len);
	return (sub);
}
/*
#include <stdio.h>
int main()
{
	char c[] = "123456";
	char *sub = ft_substr(c, 2, sizeof(c));

	printf("%s\n", sub);
	free(sub);
	return(0);
}*/

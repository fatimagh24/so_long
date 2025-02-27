/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:15:53 by fghanem           #+#    #+#             */
/*   Updated: 2024/09/04 12:33:29 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *c);

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	size_src;
	size_t	i;

	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (size_src);
}
/*
int main()
{
	char s[9] = "";
	char d[10];
	printf("%ld\n", ft_strlcpy(d,s,4));
	return (0);
}*/

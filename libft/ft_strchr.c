/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:00:13 by fghanem           #+#    #+#             */
/*   Updated: 2025/01/27 15:42:38 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	if (!c)
		return ((char *)s);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
/*
int main() {
    const char *str = "Hello, world!";
    char ch = '\0';
    char *ptr = ft_strchr(str, ch);

    if (ptr != NULL) {
        printf("Found '%c' at position %ld\n", ch , ptr - str);
    } else {
        printf("Character '%c' not found\n", ch);
    }

    return 0;
}*/

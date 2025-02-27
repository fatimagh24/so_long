/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:38:19 by fghanem           #+#    #+#             */
/*   Updated: 2024/08/29 17:59:25 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*d;
	char		ch;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	ch = (char)c;
	d = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
		{
			j = i;
			d = (char *)&s[j];
		}
		i++;
	}
	if (s[i] == ch)
		d = (char *)&s[i];
	return (d);
}
/*
int main() {
    const char *str = "Hello, world!";
    char ch = 'l';
    char *ptr = ft_strrchr(str, ch);

    if (ptr != NULL)
    {
	    printf("Found '%c' at position %ld\n", ch , ptr - str);
	    printf("%s",ptr);
    }
    else 
    {
	    printf("Character '%c' not found\n", ch);
    }
    return 0;
}*/

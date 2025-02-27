/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:59:54 by fghanem           #+#    #+#             */
/*   Updated: 2024/09/07 13:53:36 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

size_t	ft_strlen(const char *c);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	total;
	char	*c;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	total = (i + j) + 1;
	j = 0;
	i = 0;
	c = (char *)malloc(total);
	if (c == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		c[i++] = s2[j++];
	}
	c[i] = '\0';
	return (c);
}
/*
int main()
{
	char s1[] = "fatima";
	char s2[] = " Ghanem";
	char *j = ft_strjoin(s1,s2);
	printf("%s\n",j);
	return(0);
}*/

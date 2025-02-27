/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:03:51 by fghanem           #+#    #+#             */
/*   Updated: 2024/08/27 10:20:05 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = (unsigned char)c;
		p++;
		n--;
	}
	return (s);
}
/*
int main()
{
	char	test[] = "Hello";
	char	*r = ft_memset(test, 'a', sizeof(test) - 1);
	printf ("%s\n", r);

	char	*p = memset(test, '$', sizeof(test) - 1);
	printf("%s", p);
	return (0);

}*/

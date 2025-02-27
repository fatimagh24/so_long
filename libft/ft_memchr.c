/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:46:05 by fghanem           #+#    #+#             */
/*   Updated: 2024/09/04 11:28:20 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ss;

	ss = (unsigned char *)s;
	c = (unsigned char)c;
	while (n && *ss != c)
	{
		++ss;
		--n;
	}
	if (n)
		return ((void *)ss);
	else
		return (NULL);
}
/*
int main()
{
	char	c[]= "abcds";
	char	*r = ft_memchr(c,'c',sizeof(c));
	char	*t = memchr(c,'c',sizeof(c));
	printf("%s\n",r);
	printf("%s",t);
	return(0);

}*/

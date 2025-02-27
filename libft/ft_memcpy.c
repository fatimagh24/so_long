/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:05:31 by fghanem           #+#    #+#             */
/*   Updated: 2024/08/27 12:47:09 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!d && !s)
		return (NULL);
	while (n > 0)
	{
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (dest);
}
/*
int main(){
char d[10];
char s[] = "hallow my world";

char *c = ft_memcpy(d ,s, sizeof(s)-1);
char *v = memcpy(d, s, sizeof(s)-1);
printf("%s\n\n",v);
printf("%s",c);
return(0);
}*/

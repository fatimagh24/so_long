/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:11:07 by fghanem           #+#    #+#             */
/*   Updated: 2024/08/28 17:19:21 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}
/*
int main()
{
	char buffer[20]; // A buffer of 20 characters

    // Fill buffer with non-zero values for demonstration purposes
    for (int i = 0; i < 20; i++)
    {
        buffer[i] = 'A' + (i % 26); // Fill with letters A to T
    }

    // Print buffer before calling ft_bzero
    printf("Buffer before ft_bzero: ");
    for (int i = 0; i < 20; i++)
    {
        printf("%c", buffer[i]);
    }
    printf("\n");

    // Use ft_bzero to set the first 10 characters to zero
    ft_bzero(buffer, 10);

    // Print buffer after calling ft_bzero
    printf("Buffer after ft_bzero: ");
    for (int i = 0; i < 20; i++)
    {
            printf("%c", buffer[i]);
    }
    printf("\n");

    return 0;
}*/

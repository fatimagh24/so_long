/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:14:53 by fghanem           #+#    #+#             */
/*   Updated: 2024/09/09 17:37:02 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include "libft.h"

static size_t	ft_nlen(long n);
static char		*ft_fill(long nb, char *s, size_t l, size_t neg);

char	*ft_itoa(int n)
{
	long	nb;
	char	*s;
	size_t	l;
	size_t	neg;

	neg = 0;
	nb = n;
	l = ft_nlen(nb);
	if (nb < 0)
		neg = 1;
	s = (char *)malloc(sizeof(char) * (l + 1));
	if (s == NULL)
		return (NULL);
	ft_fill(nb, s, l, neg);
	return (s);
}

static char	*ft_fill(long nb, char *s, size_t l, size_t neg)
{
	if (nb == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	if (neg)
	{
		s[0] = '-';
		nb = -nb;
	}
	s[l--] = '\0';
	while (nb > 0 && l >= neg)
	{
		s[l--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (s);
}

static size_t	ft_nlen(long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}	
	return (len);
}
/*
int main()
{
	  int test_values[] = {0, 1, -1, 123, -123, 2147483647, -2147483648};
    size_t num_tests = sizeof(test_values) / sizeof(test_values[0]);
    char *result;

    for (size_t i = 0; i < num_tests; i++) {
        result = ft_itoa(test_values[i]);
        if (result) {
            printf("itoa(%d) = %s\n", test_values[i], result);
            free(result);
        } else {
            printf("itoa(%d) failed\n", test_values[i]);
        }
    }
	return 0;
}*/

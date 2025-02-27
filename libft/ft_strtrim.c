/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:01:03 by fghanem           #+#    #+#             */
/*   Updated: 2024/09/09 16:02:09 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

size_t		ft_strlen(const char *c);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strchr(const char *s, int c);

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;
	size_t			end;

	start = 0;
	len = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	len = end - start;
	if (len == 0)
		len = end;
	return (ft_substr(s1, start, len));
}
/*
int main()
{
	char s[] = "\tabcds";
	char set[] ="\t";
	char	*c = ft_strtrim(s, set);

	printf("%s" ,c);

	return(0);
}*/

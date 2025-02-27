/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:33:20 by fghanem           #+#    #+#             */
/*   Updated: 2025/01/21 13:43:46 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s);
	copy = (char *)malloc(len + 1);
	if (copy == NULL)
		return (NULL);
	if (*s)
		ft_memcpy(copy, s, len);
	copy[len] = '\0';
	return (copy);
}
/*
int main()
{
	char	s[] = "Fatima Ghanem";
	char	*s2 = ft_strdup(s);
	printf("%s",s2);
	free(s2);
	return(0);
}*/

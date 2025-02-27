/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:52:43 by fghanem           #+#    #+#             */
/*   Updated: 2024/12/22 14:52:45 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *s)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] != '\0')
	{
		if ((s[i] >= '0' && s[i] <= '9'))
			res = res * 10 + (s[i] - '0');
		else if (!(s[i] >= '0' && s[i] <= '9'))
			ft_putstr_fd("Error\n", 2);
		i++;
	}
	return (res * sign);
}

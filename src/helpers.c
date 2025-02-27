/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:47:47 by fghanem           #+#    #+#             */
/*   Updated: 2025/02/04 16:04:29 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_extra(t_data *data)
{
	free_map(data);
	free(data->map);
	free(data);
	exit(1);
}

int	count_c(t_data *data)
{
	int	x;
	int	c;
	int	y;

	y = 0;
	c = 0;
	while (data->map->map && data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

int	count_p(t_data *data)
{
	int	x;
	int	c;
	int	y;

	y = 0;
	c = 0;
	while (data->map->map && data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'P')
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

int	count_e(t_data *data)
{
	int	x;
	int	c;
	int	y;

	y = 0;
	c = 0;
	while (data->map->map && data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'E')
				c++;
			x++;
		}
		y++;
	}
	return (c);
}

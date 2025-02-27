/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:09:02 by fghanem           #+#    #+#             */
/*   Updated: 2025/02/04 12:55:54 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_flood	*init_flood(char **map, t_map *orig_map, int *collects)
{
	t_flood	*flood_data;

	flood_data = malloc(sizeof(t_flood));
	if (!flood_data)
		return (NULL);
	flood_data->mapp = map;
	flood_data->orig_map = orig_map;
	flood_data->collects = collects;
	return (flood_data);
}

int	flood_fill(int x, int y, t_flood *fdata)
{
	if (x < 0 || y < 0 || x >= fdata->orig_map->width
		|| y >= fdata->orig_map->hight)
		return (1);
	if (fdata->mapp[y][x] == '1' || fdata->mapp[y][x] == 'V')
		return (1);
	if (fdata->mapp[y][x] == 'C')
		(*fdata->collects)--;
	if (fdata->mapp[y][x] == 'E')
		fdata->orig_map->exit_path = 1;
	fdata->mapp[y][x] = 'V';
	flood_fill(x + 1, y, fdata);
	flood_fill(x - 1, y, fdata);
	flood_fill(x, y + 1, fdata);
	flood_fill(x, y - 1, fdata);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:50:00 by fghanem           #+#    #+#             */
/*   Updated: 2025/02/05 11:04:53 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_filename(char *str)
{
	str = str + (ft_strlen(str) - 4);
	if (ft_strncmp(str, ".ber", 4) != 0)
		return (1);
	return (0);
}

int	is_rectangular(t_data *data)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(data->map->map[i]);
	i++;
	while (data->map->map[i])
	{
		if (len != ft_strlen(data->map->map[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_content(t_data *data)
{
	int		i;
	int		j;
	char	map_ch;

	i = 0;
	j = 0;
	if (!data->map->map || !data || !data->map)
		return (1);
	while (i < data->map->hight)
	{
		j = 0;
		while (j < data->map->width)
		{
			map_ch = data->map->map[i][j];
			if (map_ch != '1' && map_ch != '0' && map_ch != 'P' && map_ch != 'C'
				&& map_ch != 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_map_closed(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (i == 0 || i == data->map->hight - 1 || j == 0
				|| j == data->map->width - 1)
				if (data->map->map[i][j] != '1')
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_counts(t_data *data)
{
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	data->map->collects = 0;
	player = count_p(data);
	exit = count_e(data);
	data->map->collects = count_c(data);
	if (player != 1)
		return (1);
	if (exit != 1)
		return (1);
	if (data->map->collects == 0)
		return (1);
	return (0);
}

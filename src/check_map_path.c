/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:21:42 by fghanem           #+#    #+#             */
/*   Updated: 2025/02/05 11:40:15 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_map(t_data *data)
{
	if (is_rectangular(data))
	{
		ft_putstr_fd("Error :\nNot rectangular\n", 2);
		free_exit(data);
	}
	if (check_content(data) || check_counts(data))
	{
		ft_putstr_fd("Error :\nInvalid character\n",
			2);
		free_exit(data);
	}
	if (is_map_closed(data))
	{
		ft_putstr_fd("Error :\nMAP is not closed\n", 2);
		free_exit(data);
	}
	if (check_map_path(data))
	{
		ft_putstr_fd("Error :\nInvalid player path\n", 2);
		free_exit(data);
	}
}

int	check_map_path(t_data *data)
{
	int		start_x;
	int		start_y;
	char	**map_copy;
	int		collects;
	t_flood	*f_data;

	start_x = data->player->x_pos;
	start_y = data->player->y_pos;
	collects = data->collect_total;
	map_copy = coppy_map(data->map->map, data->map->hight);
	if (!map_copy)
		return (1);
	f_data = init_flood(map_copy, data->map, &collects);
	if (!f_data)
		return (1);
	flood_fill(start_x, start_y, f_data);
	free(f_data);
	free_2d_array(map_copy, data->map->hight);
	if (collects == 0 && data->map->exit_path)
		return (0);
	return (1);
}

char	**coppy_map(char **orig_map, int height)
{
	char	**copy_map;
	int		i;

	copy_map = malloc(sizeof(char *) * height);
	if (!copy_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy_map[i] = ft_strdup(orig_map[i]);
		if (!copy_map[i])
		{
			free_2d_array(copy_map, i);
			return (NULL);
		}
		i++;
	}
	return (copy_map);
}

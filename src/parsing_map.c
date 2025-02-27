/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:27:30 by fghanem           #+#    #+#             */
/*   Updated: 2025/02/05 11:51:06 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	*init_map(t_data *data)
{
	data->map = NULL;
	data->map = malloc(sizeof(t_map));
	if (!data->map)
	{
		ft_putstr_fd("failed to init map\n", 2);
		free_init_map(data);
	}
	data->map->width = 0;
	data->map->hight = 0;
	data->map->exit_path = 0;
	data->map->map = NULL;
	data->map->collects = 0;
	return (data->map);
}

int	map_lines_count(int map_fd)
{
	int		line_count;
	char	*line;

	line_count = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(map_fd);
		if (!line)
			break ;
		line_count++;
		free(line);
	}
	close(map_fd);
	return (line_count);
}

int	open_map(char *av, t_data *data)
{
	int	map_fd;

	map_fd = open(av, O_RDONLY);
	if (map_fd == -1)
	{
		ft_putstr_fd("error opening map file\n", 2);
		free_extra(data);
	}
	return (map_fd);
}

void	read_map(char *map_path, t_data *data)
{
	int	i;
	int	map_fd;

	i = 0;
	map_fd = open_map(map_path, data);
	if (map_fd == -1)
		free_extra(data);
	data->map->hight = map_lines_count(map_fd);
	if (data->map->hight <= 2)
		free_extra(data);
	data->map->map = malloc(sizeof(char *) * (data->map->hight + 1));
	if (!data->map->map)
		free_extra(data);
	map_fd = open_map(map_path, data);
	while (i < data->map->hight)
	{
		data->map->map[i] = get_next_line(map_fd);
		if (i == 0)
			data->map->width = ft_strlen(data->map->map[i]) - 1;
		i++;
	}
	free(get_next_line(map_fd));
	data->map->map[i] = NULL;
	fix_map(data->map->map);
	close(map_fd);
}

void	fix_map(char **temp)
{
	int	i;
	int	j;

	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (temp[i][j] == '\n')
				temp[i][j] = '\0';
			j++;
		}
		i++;
	}
}

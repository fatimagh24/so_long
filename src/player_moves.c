/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:02:04 by fghanem           #+#    #+#             */
/*   Updated: 2025/02/05 11:40:01 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (!data->player)
	{
		ft_putstr_fd("error allocating memory for player\n", 2);
		free_exit(data);
	}
	data->player->x_pos = 0;
	data->player->y_pos = 0;
	find_px_py(data);
}

void	move_player(t_data *data, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = data->player->x_pos + dx;
	new_y = data->player->y_pos + dy;
	if (data->map->map[new_y][new_x] != '1')
	{
		data->player->x_pos = new_x;
		data->player->y_pos = new_y;
		if (data->map->map[new_y][new_x] == 'C')
		{
			data->collect_total--;
			data->map->map[new_y][new_x] = '0';
		}
		if (data->map->map[new_y][new_x] == 'E')
		{
			if (data->collect_total == 0)
				finish_game(data);
		}
		data->moves++;
		redraw_player(data, data->mlx, data->window);
		ft_putnbr_fd(data->moves, 1);
		write(1, "\n", 1);
	}
}

void	finish_game(t_data *data)
{
	ft_putnbr_fd(++data->moves, 1);
	write(1, "\n", 1);
	free_exit(data);
}

void	find_px_py(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			if (data->map->map[y][x] == 'P')
			{
				data->player->x_pos = x;
				data->player->y_pos = y;
			}
			x++;
		}
		y++;
	}
}

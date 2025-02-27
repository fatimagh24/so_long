/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:32:21 by fghanem           #+#    #+#             */
/*   Updated: 2025/02/05 11:33:45 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_data	*init_data(char **arv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = init_map(data);
	data->moves = 0;
	data->window = NULL;
	data->image = NULL;
	data->player = NULL;
	data->mlx = NULL;
	read_map(arv[1], data);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		free_exit(data);
	}
	init_player(data);
	data->image = init_img_texture(data->mlx, data);
	return (data);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		free_exit(data);
	if (keycode == 119 || keycode == 65362)
	{
		move_player(data, 0, -1);
	}
	if (keycode == 97 || keycode == 65361)
	{
		move_player(data, -1, 0);
	}
	if (keycode == 115 || keycode == 65364)
	{
		move_player(data, 0, 1);
	}
	if (keycode == 100 || keycode == 65363)
	{
		move_player(data, 1, 0);
	}
	return (0);
}

void	open_wind(t_data *data)
{
	data->window = mlx_new_window(data->mlx, data->map->width * 64,
			data->map->hight * 64, "so_long");
	if (!data->window)
		free_exit(data);
}

int	handle_close(t_data *data)
{
	free_exit(data);
	exit(1);
	return (1);
}

int	main(int arc, char **arv)
{
	t_data	*data;

	data = NULL;
	if (arc != 2 || check_filename(arv[1]) == 1)
	{
		ft_putstr_fd("Wrong arguments\n", 2);
		exit(1);
	}
	else if (arc == 2)
	{
		data = init_data(arv);
		if (!data)
			exit(1);
		collectibles_num(data);
		handle_map(data);
		open_wind(data);
		render_textures(data);
		redraw_player(data, data->mlx, data->window);
		mlx_hook(data->window, 2, 1L << 0, handle_keypress, data);
		mlx_hook(data->window, 17, 0, handle_close, data);
		mlx_loop(data->mlx);
	}
	if (data)
		free_exit(data);
	return (0);
}

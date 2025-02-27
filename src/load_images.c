/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:52:04 by fghanem           #+#    #+#             */
/*   Updated: 2025/02/03 16:21:50 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_images	*init_img_texture(void *mlx, t_data *data)
{
	t_images	*imgs;

	imgs = malloc(sizeof(t_images));
	if (!imgs)
	{
		ft_putstr_fd("failed to init images\n", 2);
		free_exit(data);
	}
	imgs->height = 64;
	imgs->width = 64;
	imgs->wall = mlx_xpm_file_to_image(mlx, WALL, &imgs->width, &imgs->height);
	imgs->floor = mlx_xpm_file_to_image(mlx, FLOOR, &imgs->width,
			&imgs->height);
	imgs->exit = mlx_xpm_file_to_image(mlx, DOOR, &imgs->width, &imgs->height);
	imgs->player = mlx_xpm_file_to_image(mlx, PLAYER, &imgs->width,
			&imgs->height);
	imgs->collectible = mlx_xpm_file_to_image(mlx, COLLECTABLE, &imgs->width,
			&imgs->height);
	return (imgs);
}

void	draw_game(int i, int j, t_data *data)
{
	void	*image;

	if (data->map->map[i][j] == '1')
		image = data->image->wall;
	else if (data->map->map[i][j] == '0')
		image = data->image->floor;
	else if (data->map->map[i][j] == 'E')
		image = data->image->exit;
	else if (data->map->map[i][j] == 'P')
		image = data->image->floor;
	else if (data->map->map[i][j] == 'C')
		image = data->image->collectible;
	else
		return ;
	mlx_put_image_to_window(data->mlx, data->window, image, j * 64, i * 64);
}

void	render_textures(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < data->map->hight)
	{
		j = 0;
		while (j < data->map->width)
		{
			draw_game(i, j, data);
			j++;
		}
		i++;
	}
}

void	redraw_player(t_data *data, void *mlx, void *window)
{
	render_textures(data);
	mlx_put_image_to_window(mlx, window, data->image->player,
		data->player->x_pos * 64, data->player->y_pos * 64);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:57:44 by fghanem           #+#    #+#             */
/*   Updated: 2025/02/05 11:18:56 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_exit(t_data *data)
{
	if (data->image)
	{
		free_images(data);
	}
	if (data->map)
	{
		free_map(data);
	}
	if (data->player)
	{
		free(data->player);
	}
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free(data);
	exit(1);
}

void	free_init_map(t_data *data)
{
	if (data)
	{
		free(data->map);
		if (data->map)
		{
			free_map(data);
		}
		free(data);
	}
	exit(1);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map->map)
	{
		while (data->map->map[i])
		{
			free(data->map->map[i]);
			i++;
		}
		free(data->map->map);
		free(data->map);
	}
}

void	free_2d_array(char **arr, int height)
{
	int	i;

	i = 0;
	if (!*arr)
	{
		return ;
	}
	while (i < height)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_images(t_data *data)
{
	if (data->image)
	{
		if (data->image->wall)
			mlx_destroy_image(data->mlx, data->image->wall);
		if (data->image->floor)
			mlx_destroy_image(data->mlx, data->image->floor);
		if (data->image->exit)
			mlx_destroy_image(data->mlx, data->image->exit);
		if (data->image->player)
			mlx_destroy_image(data->mlx, data->image->player);
		if (data->image->collectible)
			mlx_destroy_image(data->mlx, data->image->collectible);
	}
	free(data->image);
	data->image = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collecttibles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:45:29 by fghanem           #+#    #+#             */
/*   Updated: 2025/02/05 11:40:56 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	collectibles_num(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->collect_total = 0;
	i = 0;
	while (i < data->map->hight && data->map->map[i])
	{
		j = 0;
		while (j < data->map->width && data->map->map[i][j])
		{
			if (data->map->map[i][j] == 'C')
			{
				data->collect_total++;
			}
			j++;
		}
		i++;
	}
}

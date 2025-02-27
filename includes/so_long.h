/* ************************************************************************** */
/*		                                                                     */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:57:38 by fghanem           #+#    #+#             */
/*   Updated: 2025/01/19 13:14:23 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WALL "./textures/wall.xpm"
# define PLAYER "./textures/hamtaro.xpm"
# define DOOR "./textures/home.xpm"
# define FLOOR "./textures/floor.xpm"
# define COLLECTABLE "./textures/nuts.xpm"

typedef struct s_images
{
	void		*wall;
	int			height;
	int			width;
	void		*player;
	void		*floor;
	void		*collectible;
	void		*exit;
}				t_images;

typedef struct s_player
{
	int			x_pos;
	int			y_pos;
}				t_player;

typedef struct s_map
{
	char		**map;
	int			hight;
	int			width;
	int			collects;
	int			exit_path;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	int			collect_total;
	int			moves;
	t_player	*player;
	t_map		*map;
	t_images	*image;
}				t_data;

typedef struct s_flood
{
	t_map		*orig_map;
	int			*collects;
	char		**mapp;
}				t_flood;

t_data			*init_data(char **arv);
void			init_player(t_data *data);
t_map			*init_map(t_data *data);
t_images		*init_img_texture(void *mlx, t_data *data);
t_flood			*init_flood(char **map, t_map *orig_map, int *collects);
int				handle_keypress(int keycode, t_data *data);
void			find_px_py(t_data *data);
void			move_player(t_data *data, int dx, int dy);
int				map_lines_count(int map_fd);
void			read_map(char *map_path, t_data *data);
void			draw_game(int i, int j, t_data *data);
void			render_textures(t_data *data);
void			redraw_player(t_data *data, void *mlx, void *window);
void			free_images(t_data *data);
void			free_2d_array(char **arr, int height);
void			free_map(t_data *data);
void			free_exit(t_data *data);
int				flood_fill(int x, int y, t_flood *fdata);
void			collectibles_num(t_data *data);
int				check_filename(char *str);
void			handle_map(t_data *data);
int				is_rectangular(t_data *data);
int				check_content(t_data *data);
int				is_map_closed(t_data *data);
int				check_counts(t_data *data);
char			**coppy_map(char **orig_map, int height);
int				check_map_path(t_data *data);
int				handle_close(t_data *data);
void			fix_map(char **temp);
void			free_extra(t_data *data);
void			free_init_map(t_data *data);
void			finish_game(t_data *data);
int				count_e(t_data *data);
int				count_p(t_data *data);
int				count_c(t_data *data);
void			open_wind(t_data *data);
#endif

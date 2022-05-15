/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:43:12 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/21 18:32:25 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdint.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "./minilibx/mlx.h"
# include "./printf/ft_printf.h"

# define SCALE 32
# define WALL "./IMG/water.xpm"
# define GRASS "./IMG/grass.xpm"
# define EXIT_0 "./IMG/close_chest.xpm"
# define EXIT_1 "./IMG/open_chest.xpm"
# define COIN "./IMG/coin.xpm"
# define PLAYER "./IMG/player.xpm"
# define PLAYER_A "./IMG/player_a.xpm"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}t_mlx;

typedef struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
}t_img;

typedef struct s_player
{
	int		x;
	int		y;
	int		start_x;
	int		start_y;
	int		collect;
	int		steps;
	int		exit_done;
	t_img	*player;
	t_img	*player_a;
}t_player;

typedef struct s_map
{
	int		empty_space;
	int		wall;
	int		collect_max;
	int		map_exit;
	int		player;
	int		width;
	int		height;
	int		size;
	char	**map;
}t_map;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	t_mlx		*mlx;
	t_img		*wall;
	t_img		*grass;
	t_img		*exit_0;
	t_img		*exit_1;
	t_img		*coin;
}t_game;

int		create_height(char *map_file);
int		create_width(char *map_file);
int		create_size(char *map_file);
void	is_rectangle(char *map_file, t_game *game);
void	map_info(t_game *game, char *map_file);
void	check_argv(int argc, char *map_file);
int		main(int argc, char *argv[]);
int		ft_strlen(char *str);
void	check_argv(int argc, char *map_file);
void	map_check_param(t_game *game, char *map_file);
void	create_map(t_game *game, char *map_file);
int		ft_check_another(char *map_file, t_game *game);
void	check_wall(t_game *game);
void	check_player(t_game *game);
int		key_control(int keycode, t_game *vars);
t_game	*ft_init_malloc(void);
void	ft_init_player(t_game *game);
void	key_wsad(int keycode, t_game *game);
void	check_collectable(t_game *game);
void	check_exit(int keycode, t_game *game);
void	ft_init_img(t_game *game);
void	file_init(t_game *game, t_img *img, char *path);
void	ft_render(t_game *game, int keycode);
void	render_grass(t_game *game);
void	render_wall_exit_coin(t_game *game);
void	ft_exit(int malloc, char *str, t_game *game);
void	malloc_free(t_game *game);
void	free_map(t_game *game);
void	key_wsad_utils(t_game *game, int *x_y, int sign);
void	render_player(t_game *game, int keycode);
void	malloc_free_1(t_game *game);

#endif
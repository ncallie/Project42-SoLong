/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:56:01 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/22 16:14:25 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*ft_init_malloc(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->map = (t_map *)malloc(sizeof(t_map));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	game->wall = (t_img *)malloc(sizeof(t_img));
	game->grass = (t_img *)malloc(sizeof(t_img));
	game->exit_0 = (t_img *)malloc(sizeof(t_img));
	game->exit_1 = (t_img *)malloc(sizeof(t_img));
	game->coin = (t_img *)malloc(sizeof(t_img));
	game->player->player = (t_img *)malloc(sizeof(t_img *));
	game->player->player_a = (t_img *)malloc(sizeof(t_img *));
	if (!(game || !game->map) || !(game->mlx) || !(game->wall) || !(game->grass)
		|| !(game->exit_0) || !(game->coin) || !(game->player->player)
		|| !(game->player->player_a) || !(game->exit_1))
		ft_exit(1, "Allocation memory error\n", game);
	return (game);
}

void	ft_init_player(t_game *game)
{
	game->player->x = game->player->start_x;
	game->player->y = game->player->start_y;
	game->player->collect = 0;
	game->player->steps = 0;
	game->player->exit_done = 0;
}

void	file_init(t_game *game, t_img *img, char *path)
{
	img->width = SCALE;
	img->height = SCALE;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr,
			path, &img->width, &img->height);
}

void	file_init_player(t_game *game, t_img *img, char *path)
{
	img->width = SCALE;
	img->height = SCALE;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr,
			path, &img->width, &img->height);
}

void	ft_init_img(t_game *game)
{
	file_init(game, game->grass, GRASS);
	file_init(game, game->wall, WALL);
	file_init(game, game->coin, COIN);
	file_init(game, game->exit_0, EXIT_0);
	file_init(game, game->exit_1, EXIT_1);
	file_init_player(game, game->player->player, PLAYER);
	file_init_player(game, game->player->player_a, PLAYER_A);
	ft_render(game, 5);
}

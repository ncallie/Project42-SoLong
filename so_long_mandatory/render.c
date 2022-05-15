/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:35:21 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/20 12:21:54 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_grass(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
				game->grass->img_ptr, j * SCALE, i * SCALE);
			j++;
		}
		i++;
	}
}

void	render_wall_exit_coin(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map[i][j] == 'E' && game->player->exit_done == 0)
				mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
					game->exit_0->img_ptr, j * SCALE, i * SCALE);
			if (game->map->map[i][j] == 'E' && game->player->exit_done == 1)
				mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
					game->exit_1->img_ptr, j * SCALE, i * SCALE);
			if (game->map->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
					game->coin->img_ptr, j * SCALE, i * SCALE);
			if (game->map->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
					game->wall->img_ptr, j * SCALE, i * SCALE);
			j++;
		}
		i++;
	}
}

void	render_player(t_game *game, int keycode)
{
	if (keycode == 0)
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->player->player_a->img_ptr, game->player->x * SCALE,
			game->player->y * SCALE);
	else
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->player->player->img_ptr, game->player->x * SCALE,
			game->player->y * SCALE);
}

void	ft_render(t_game *game, int keycode)
{
	render_grass(game);
	render_wall_exit_coin(game);
	render_player(game, keycode);
}

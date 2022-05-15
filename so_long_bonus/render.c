/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:35:21 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/21 17:42:11 by ncallie          ###   ########.fr       */
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
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
		game->player->player->img_ptr, game->player->x * SCALE,
		game->player->y * SCALE);
}

void	ft_render(t_game *game, int keycode)
{
	render_wall_exit_coin(game);
}

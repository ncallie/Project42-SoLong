/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control_var_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:52:10 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/21 18:20:44 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_code_w(t_game *game)
{
	if (game->map->map[game->var->y + 1][game->var->x] != '1'
		&& (game->var->y < game->player->y))
		key_wsad_utils_var(game, &game->var->y, 1);
	else if (game->map->map[game->var->y - 1][game->var->x] != '1'
		&& (game->var->y > game->player->y))
		key_wsad_utils_var(game, &game->var->y, 0);
}

void	key_code_s(t_game *game)
{
	if (game->map->map[game->var->y - 1][game->var->x] != '1'
		&& (game->var->y > game->player->y))
		key_wsad_utils_var(game, &game->var->y, 0);
	else if (game->map->map[game->var->y + 1][game->var->x] != '1'
		&& (game->var->y < game->player->y))
		key_wsad_utils_var(game, &game->var->y, 1);
}

void	key_code_d(t_game *game)
{
	if (game->map->map[game->var->y][game->var->x + 1] != '1'
		&& (game->var->x < game->player->x))
		key_wsad_utils_var(game, &game->var->x, 1);
	else if (game->map->map[game->var->y][game->var->x - 1] != '1'
		&& (game->var->x > game->player->x))
		key_wsad_utils_var(game, &game->var->x, 0);
}

void	key_code_a(t_game *game)
{
	if (game->map->map[game->var->y][game->var->x + 1] != '1'
		&& (game->var->x < game->player->x))
		key_wsad_utils_var(game, &game->var->x, 1);
	else if (game->map->map[game->var->y][game->var->x - 1] != '1'
		&& (game->var->x > game->player->x))
		key_wsad_utils_var(game, &game->var->x, 0);
}

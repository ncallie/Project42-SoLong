/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:57:55 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/21 16:53:47 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_wsad(int keycode, t_game *game)
{
	if (keycode == 13)
		if (game->map->map[game->player->y - 1][game->player->x] != '1')
			key_wsad_utils(game, &game->player->y, 0);
	if (keycode == 1)
		if (game->map->map[game->player->y + 1][game->player->x] != '1')
			key_wsad_utils(game, &game->player->y, 1);
	if (keycode == 2)
		if (game->map->map[game->player->y][game->player->x + 1] != '1')
			key_wsad_utils(game, &game->player->x, 1);
	if (keycode == 0)
		if (game->map->map[game->player->y][game->player->x - 1] != '1')
			key_wsad_utils(game, &game->player->x, 0);
	ft_printf("Steps: %d\n", game->player->steps);
}

void	check_collectable(t_game *game)
{
	if (game->map->map[game->player->y][game->player->x] == 'C')
	{
		game->player->collect += 1;
		game->map->map[game->player->y][game->player->x] = '0';
		if (game->player->collect == game->map->collect_max)
			game->player->exit_done = 1;
	}
}

void	check_exit(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_exit(1, "Exit\n", game);
	if (game->map->map[game->player->y][game->player->x] == 'E'
			&& game->player->exit_done == 1)
		ft_exit(1, "Victory!\n", game);
}

void	key_wsad_utils(t_game *game, int *x_y, int sign)
{
	if (sign == 1)
		*x_y += 1;
	else if (sign == 0)
		*x_y -= 1;
	game->player->steps++;
}

int	key_control(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		key_wsad(keycode, game);
		key_wsad_var(keycode, game);
	}
	check_collectable(game);
	check_var_die(game);
	check_exit(keycode, game);
	ft_render(game, keycode);
	return (0);
}

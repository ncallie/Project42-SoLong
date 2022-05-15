/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:46:01 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/21 18:06:23 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_wsad_var(int keycode, t_game *game)
{
	if (keycode == 13)
		key_code_w(game);
	if (keycode == 1)
		key_code_s(game);
	if (keycode == 2)
		key_code_d(game);
	if (keycode == 0)
		key_code_a(game);
}

void	key_wsad_utils_var(t_game *game, int *x_y, int sign)
{
	if (sign == 1)
		*x_y += 1;
	else if (sign == 0)
		*x_y -= 1;
}

void	check_var_die(t_game *game)
{
	if (((game->player->x == game->var->x)
			&& ((game->player->y == game->var->y - 1)
				|| (game->player->y == game->var->y + 1)))
		|| ((game->player->y == game->var->y)
			&& ((game->player->x == game->var->x - 1)
				|| (game->player->x == game->var->x + 1)))
		|| ((game->player->x == game->var->x)
			&& (game->player->y == game->var->y)))
	{
		ft_exit(1, "You die!\n", game);
	}
}

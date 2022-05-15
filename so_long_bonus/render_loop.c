/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:00:59 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/21 18:43:58 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_loop(t_game *game)
{
	int			i;
	int			j;
	static int	g = 0;
	static int	frame = 0;

	if (frame == 500)
	{	
		pre_render_object(game, &g);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->player->player->img_ptr, game->player->x * SCALE,
			game->player->y * SCALE);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->var->var->img_ptr, game->var->x * SCALE,
			game->var->y * SCALE);
		ft_put_steps(game);
	}
	if (frame == 450)
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->var->var->img_ptr, game->var->x * SCALE + 1,
			game->var->y * SCALE);
	if (frame == 1000)
		frame = 0;
	frame += 2;
	return (0);
}

void	render_object(t_game *game, int i, int j, int g)
{
	if (game->map->map[i][j] != '1')
		mlx_put_image_to_window(game->mlx->mlx_ptr,
			game->mlx->win_ptr, game->grass->img_ptr, j * SCALE, i * SCALE);
	if (game->map->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx->mlx_ptr,
			game->mlx->win_ptr, game->wall->img_ptr, j * SCALE, i * SCALE);
	if (game->map->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx->mlx_ptr,
			game->mlx->win_ptr, game->coin[g].img_ptr, j * SCALE, i * SCALE);
	if (game->map->map[i][j] == 'E' && game->player->exit_done == 0)
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->exit_0->img_ptr, j * SCALE, i * SCALE);
	if (game->map->map[i][j] == 'E' && game->player->exit_done == 1)
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
			game->exit_1->img_ptr, j * SCALE, i * SCALE);
}

void	pre_render_object(t_game *game, int *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map->height)
	{
		j = 0;
		while (j++ < game->map->width)
			render_object(game, i, j, *g);
	}
	if (*g < 3)
		(*g)++;
	else if (*g == 3)
		*g = 0;
}

void	ft_put_steps(t_game *game)
{
	char	*nbr;

	nbr = ft_itoa(game->player->steps);
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win_ptr, 10,
		5, 0x000000, "Steps: ");
	mlx_string_put(game->mlx->mlx_ptr, game->mlx->win_ptr, 75,
		5, 0x000000, nbr);
	free(nbr);
}

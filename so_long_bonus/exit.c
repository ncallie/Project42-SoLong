/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:54:47 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/21 18:23:06 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(int malloc, char *str, t_game *game)
{
	if (malloc == 0)
		ft_printf("%s\n", str);
	if (malloc == 1)
	{
		ft_printf("%s\n", str);
		malloc_free(game);
	}
	if (malloc == 2)
	{
		ft_printf("%s\n", str);
		free_map(game);
	}
	exit(EXIT_FAILURE);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->height)
	{
		if (game->map->map[i])
			free(game->map->map[i]);
		i++;
	}
	if (game->map->map)
		free(game->map->map);
}

void	malloc_free(t_game *game)
{
	if (game->wall->img_ptr)
		mlx_destroy_image(game->mlx->mlx_ptr, game->wall->img_ptr);
	free(game->wall);
	if (game->grass->img_ptr)
		mlx_destroy_image(game->mlx->mlx_ptr, game->grass->img_ptr);
	free(game->grass);
	if (game->exit_0->img_ptr)
		mlx_destroy_image(game->mlx->mlx_ptr, game->exit_0->img_ptr);
	free(game->exit_0);
	if (game->exit_1->img_ptr)
		mlx_destroy_image(game->mlx->mlx_ptr, game->exit_1->img_ptr);
	free(game->exit_1);
	free_coin(game);
	if (game->player->player->img_ptr)
		mlx_destroy_image(game->mlx->mlx_ptr, game->player->player->img_ptr);
	free(game->player->player);
	free(game->player);
	if (game->var->var->img_ptr)
		mlx_destroy_image(game->mlx->mlx_ptr, game->var->var->img_ptr);
	free(game->var->var);
	free(game->var);
	malloc_free_1(game);
}

void	free_coin(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (game->coin[i].img_ptr)
			mlx_destroy_image(game->mlx->mlx_ptr, game->coin[i].img_ptr);
		i++;
	}
	free(game->coin);
}

void	malloc_free_1(t_game *game)
{
	if (game->map->map)
		free_map(game);
	if (game->mlx->win_ptr)
		mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
	free(game->map);
	if (game->mlx->mlx_ptr)
		free(game->mlx->mlx_ptr);
	free(game->mlx);
	free(game);
	exit(EXIT_FAILURE);
}

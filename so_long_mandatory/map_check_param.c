/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:30:19 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/18 18:32:42 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check(char flag, char *map_file)
{
	int		fd;
	int		param;
	char	c[1];

	param = 0;
	fd = open(map_file, O_RDONLY);
	while (read(fd, c, 1) == 1)
	{
		if (c[0] == flag)
		param++;
	}
	close(fd);
	return (param);
}

int	ft_check_another(char *map_file, t_game *game)
{
	int		fd;
	char	c[1];

	fd = open(map_file, O_RDONLY);
	while (read(fd, c, 1) == 1)
	{
		if (c[0] != '0' && c[0] != '1' && c[0] != 'C'
			&& c[0] != 'E' && c[0] != 'P' && c[0] != '\n')
			ft_exit(0, "Invalid symbols on the map\n", game);
	}
	close(fd);
	return (1);
}

void	map_check_param(t_game *game, char *map_file)
{
	game->map->empty_space = ft_check('0', map_file);
	game->map->wall = ft_check('1', map_file);
	game->map->collect_max = ft_check('C', map_file);
	game->map->map_exit = ft_check('E', map_file);
	game->map->player = ft_check('P', map_file);
	if (game->map->empty_space > 1 && game->map->wall > 1 && game->map
		->collect_max >= 1 && game->map->map_exit >= 1 && game->map->player
		== 1 && ft_check_another(map_file, game))
		return ;
	ft_exit(1, "Invalid map\n", game);
	malloc_free(game);
}

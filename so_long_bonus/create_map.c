/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:52:20 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/21 11:56:24 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		if ((i == 0) || (i == game->map->height - 1))
		{
			j = 0;
			while (j < game->map->width)
			{
				if (game->map->map[i][j] != '1')
					ft_exit(2, "No wall in the top line\n", game);
				j++;
			}	
		}
		else
		{
			j = 0;
			if ((game->map->map[i][0] != '1')
				|| (game->map->map[i][game->map->width - 1] != '1'))
				ft_exit(2, "No wall on the bottom line\n", game);
		}
		i++;
	}
}

void	check_player(t_game *game)
{
	int	i;
	int	j;
	int	check_pos;

	i = 0;
	j = 0;
	check_pos = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map[i][j] == 'P')
			{
				game->player->start_x = j;
				game->player->start_y = i;
				check_pos++;
			}
			j++;
		}
		i++;
	}
	if (check_pos != 1)
		ft_exit(2, "There is no player on the map or more than one\n", game);
}

void	check_var(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->map[i][j] == 'V')
			{
				game->var->start_x = j;
				game->var->start_y = i;
			}
			j++;
		}
		i++;
	}
}

void	create_map(t_game *game, char *map_file)
{
	int		fd;
	int		i;
	char	tmp[1];

	i = 0;
	fd = open(map_file, O_RDONLY);
	game->map->map = (char **)malloc(sizeof(char **) * game->map->height);
	if (!(game->map->map))
		ft_exit(2, "Memory allocation error for the map\n", game);
	while (i < game->map->height)
	{
		game->map->map[i] = (char *)malloc(sizeof(char *)
				* game->map->width + 1);
		if (!(game->map->map[i]))
			ft_exit(2, "Memory allocation error for the map\n", game);
		read(fd, game->map->map[i], game->map->width);
		game->map->map[i][game->map->width] = '\0';
		i++;
		read(fd, tmp, 1);
	}
	close(fd);
	check_wall(game);
	check_player(game);
	check_var(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:33:03 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/18 18:35:08 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_height(char *map_file)
{
	int		fd;
	int		height;
	char	c[1];

	height = 1;
	fd = open(map_file, O_RDONLY);
	while (read(fd, c, 1) == 1)
	{
		if (c[0] == '\n')
		height++;
	}
	close(fd);
	return (height);
}

int	create_width(char *map_file)
{
	int		fd;
	int		width;
	char	c[1];

	width = 0;
	fd = open(map_file, O_RDONLY);
	while (read(fd, c, 1) == 1)
	{
		if (c[0] == '\n')
			break ;
		width++;
	}
	close(fd);
	return (width);
}

int	create_size(char *map_file)
{
	int		fd;
	int		size;
	char	c[1];

	size = 0;
	fd = open(map_file, O_RDONLY);
	while (read(fd, c, 1) == 1)
			size++;
	close(fd);
	return (size);
}

void	is_rectangle(char *map_file, t_game *game)
{
	int		fd;
	int		i;
	char	c[1];

	i = 0;
	fd = open(map_file, O_RDONLY);
	while (read(fd, c, 1) == 1)
	{
		i++;
		if (c[0] == '\n')
		{
			i--;
			if (i != game->map->width)
				ft_exit(0, "This is not a rectangle\n", game);
			i = 0;
		}
	}
	if (i != game->map->width)
		ft_exit(0, "This is not a rectangle\n", game);
	return ;
}

void	map_info(t_game *game, char *map_file)
{
	game->map->height = create_height(map_file);
	game->map->width = create_width(map_file);
	game->map->size = create_size(map_file);
	is_rectangle(map_file, game);
}

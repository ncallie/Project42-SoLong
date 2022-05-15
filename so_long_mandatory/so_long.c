/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncallie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:54:17 by ncallie           #+#    #+#             */
/*   Updated: 2021/11/22 16:54:26 by ncallie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_argv(int argc, char *map_file)
{
	int	len;
	int	fd;

	if (argc != 2)
		ft_exit(0, "./so_long [map.ber]\n", NULL);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		ft_exit(0, "Error open map\n", NULL);
	close(fd);
	len = ft_strlen(map_file);
	if (len < 5)
		ft_exit(0, "Wrong file permission\n", NULL);
	if (map_file[len - 1] == 'r')
		if (map_file[len - 2] == 'e')
			if (map_file[len - 3] == 'b')
				if (map_file[len - 4] == '.')
					return ;
	ft_exit(0, "Wrong file permission\n", NULL);
}

int	ft_close(t_game *game)
{
	malloc_free(game);
	exit(EXIT_SUCCESS);
	return (1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	check_argv(argc, argv[1]);
	game = ft_init_malloc();
	map_info(game, argv[1]);
	map_check_param(game, argv[1]);
	create_map(game, argv[1]);
	ft_init_player(game);
	game->mlx->mlx_ptr = mlx_init();
	game->mlx->win_ptr = mlx_new_window(game->mlx->mlx_ptr, game->map->width
			* SCALE, game->map->height * SCALE, "so_long");
	ft_init_img(game);
	mlx_key_hook(game->mlx->win_ptr, key_control, game);
	mlx_hook(game->mlx->win_ptr, 17, 0, ft_close, game);
	mlx_loop(game->mlx->mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:50:08 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/02 22:30:39 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	map_closed(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != '\n' && game->map[i] != '\0')
		if (game->map[i++] != '1')
			error(game, "Map is not surrounded by walls.\n");
	i = game->width + 1;
	while (game->map[i] != '\0')
	{
		if (game->map[i] != '1')
			error(game, "Map is not surrounded by walls.\n");
		i += (game->width + 1);
	}
	i = game->width - 1;
	while (game->map[i] != '\0')
	{
		if (game->map[i] != '1')
			error(game, "Map is not surrounded by walls.\n");
		i += (game->width + 1);
	}
	i = ((game->width + 1) * game->height) - (game->width + 1);
	while (game->map[i] != '\n' && game->map[i] != '\0')
		if (game->map[i++] != '1')
			error(game, "Map is not surrounded by walls.\n");
}

static void	map_rectangular(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (game->map[i] != '\0')
	{
		if (game->map[i] == '\n')
		{
			if (x == 0)
				x = i;
			if (x != (i - y) - (y * x))
				error(game, "Map is not rectangular.\n");
			y++;
		}
		i++;
	}
	if ((x - 1) > MAX_WIDTH / 64)
		error(game, "Map is too wide\n");
	if (y > MAX_HEIGHT / 64)
		error(game, "Map is too high\n");
	game->width = x;
	game->height = y;
}

static void	map_must_contain(t_game *game)
{
	int	i;
	int	exit;
	int	collectibles;
	int	player;

	i = 0;
	exit = 0;
	collectibles = 0;
	player = 0;
	while (game->map[i] != '\0')
	{
		if (game->map[i] != 'C' && game->map[i] != 'E' && game->map[i] != 'P'
			&& game->map[i] != '0' && game->map[i] != '1'
			&& game->map[i] != '\n')
			error(game, "Map contains non-allowed characters.\n");
		if (game->map[i] == 'C')
			collectibles++;
		if (game->map[i] == 'E')
			exit++;
		if (game->map[i] == 'P')
			player++;
		i++;
	}
	if (exit != 1 || collectibles < 1 || player != 1)
		error(game, "Map have to contain: exit=1 collectible>=1 player=1\n");
}

void	map_check(t_game *game)
{
	map_must_contain(game);
	map_rectangular(game);
	map_closed(game);
	map_valid_path(game);
}

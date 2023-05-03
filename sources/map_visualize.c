/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_visualize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:44:43 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/02 20:05:02 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_visualize(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = 0;
	y = 0;
	while (game->map[++i] != '\0')
	{
		if (game->map[i] == '0')
			set_floor(game, x++, y);
		if (game->map[i] == '1')
			set_wall(game, x++, y);
		if (game->map[i] == 'C')
			set_collectible(game, x++, y);
		if (game->map[i] == 'E')
			set_exit(game, x++, y);
		if (game->map[i] == 'P')
			set_player(game, x++, y);
		if (game->map[i] == '\n')
		{
			x = 0;
			y++;
		}
	}
}

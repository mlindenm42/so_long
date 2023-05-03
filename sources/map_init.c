/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:53:04 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/02 22:04:26 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_init(t_game *game)
{
	game->mlx = mlx_init(game->width * 64, game->height * 64, "so_long", false);
	if (!game->mlx)
		error(game, "MLX failed.\n");
}

// game->mlx = mlx_init(game->width * 64, game->height * 64, "so_long", true);
// mlx_set_setting(MLX_STRETCH_IMAGE, 1);

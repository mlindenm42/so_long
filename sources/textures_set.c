/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:08:05 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/02 22:04:44 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_floor(t_game *game, int x, int y)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(IMG_FLOOR);
	if (!texture)
		error(game, "Texture failed.\n");
	game->img = mlx_texture_to_image(game->mlx, texture);
	if (!game->img)
		error(game, "Texture to image failed.\n");
	mlx_delete_texture(texture);
	if (mlx_image_to_window(game->mlx, game->img,
			(x * 64), (y * 64)) < 0)
		error(game, "Image to window failed.\n");
	game->img->instances[0].z = 0;
}

void	set_wall(t_game *game, int x, int y)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(IMG_WALL);
	if (!texture)
		error(game, "Texture failed.\n");
	game->img = mlx_texture_to_image(game->mlx, texture);
	if (!game->img)
		error(game, "Texture to image failed.\n");
	mlx_delete_texture(texture);
	if (mlx_image_to_window(game->mlx, game->img,
			(x * 64), (y * 64)) < 0)
		error(game, "Image to window failed.\n");
	game->img->instances[0].z = 0;
}

void	set_collectible(t_game *game, int x, int y)
{
	mlx_texture_t	*texture;

	set_floor(game, x, y);
	texture = mlx_load_png(IMG_COLLECTIBLE);
	if (!texture)
		error(game, "Texture failed.\n");
	game->img = mlx_texture_to_image(game->mlx, texture);
	if (!game->img)
		error(game, "Texture to image failed.\n");
	mlx_delete_texture(texture);
	if (mlx_image_to_window(game->mlx, game->img,
			(x * 64), (y * 64)) < 0)
		error(game, "Image to window failed.\n");
	game->img->instances[0].z = 1;
}

void	set_exit(t_game *game, int x, int y)
{
	mlx_texture_t	*texture;

	set_floor(game, x, y);
	texture = mlx_load_png(IMG_EXIT);
	if (!texture)
		error(game, "Texture failed.\n");
	game->img = mlx_texture_to_image(game->mlx, texture);
	if (!game->img)
		error(game, "Texture to image failed.\n");
	mlx_delete_texture(texture);
	if (mlx_image_to_window(game->mlx, game->img,
			(x * 64), (y * 64)) < 0)
		error(game, "Image to window failed.\n");
	game->img->instances[0].z = 1;
}

void	set_player(t_game *game, int x, int y)
{
	mlx_texture_t	*texture;

	set_floor(game, x, y);
	texture = mlx_load_png(IMG_PLAYER);
	if (!texture)
		error(game, "Texture failed.\n");
	game->player = mlx_texture_to_image(game->mlx, texture);
	if (!game->player)
		error(game, "Texture to image failed.\n");
	mlx_delete_texture(texture);
	if (mlx_image_to_window(game->mlx, game->player,
			((x * 64) + 18), ((y * 64) + 18)) < 0)
		error(game, "Image to window failed.\n");
	game->player->instances[0].z = 3;
}

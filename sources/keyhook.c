/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:19:23 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/02 23:15:41 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libraries/libft/libft.h"	//ft_putnbr_fd();

static int	check_collectible(t_game *game, int x, int y)
{
	if (game->map[((x / 64) + ((y / 64) * ((game->width + 1))))] == 'C'
		&& game->map[(((x + 32) / 64) + (y / 64) * ((game->width + 1)))] == 'C'
		&& game->map[((x / 64) + ((y + 32) / 64) * ((game->width + 1)))] == 'C'
		&& game->map[(((x + 32) / 64) + (((y + 32) / 64)
					* ((game->width + 1))))] == 'C')
	{
		game->map[(((x + 16) / 64) + (((y + 16) / 64)
					* ((game->width + 1))))] = '0';
		set_floor(game, (x + 16) / 64, (y + 16) / 64);
		game->img->instances[0].z = 2;
	}
	return (0);
}

static int	check_exit(t_game *game, int x, int y)
{
	if (game->map[((x / 64) + ((y / 64) * ((game->width + 1))))] == 'E'
		|| game->map[(((x + 32) / 64) + (y / 64) * ((game->width + 1)))] == 'E'
		|| game->map[((x / 64) + ((y + 32) / 64) * ((game->width + 1)))] == 'E'
		|| game->map[(((x + 32) / 64) + (((y + 32) / 64)
					* ((game->width + 1))))] == 'E')
	{
		if (collectible_on_map(game->map))
			return (1);
		if (game->map[((x / 64) + ((y / 64) * ((game->width + 1))))] == 'E'
			&& game->map[(((x + 32) / 64) + (y / 64)
					* ((game->width + 1)))] == 'E'
			&& game->map[((x / 64) + ((y + 32) / 64)
					* ((game->width + 1)))] == 'E'
			&& game->map[(((x + 32) / 64) + (((y + 32) / 64)
						* ((game->width + 1))))] == 'E')
		{
			mlx_close_window(game->mlx);
		}
	}
	return (0);
}

static int	check_wall(t_game *game, int x, int y)
{
	if (game->map[((x / 64) + ((y / 64) * ((game->width + 1))))] == '1'
		|| game->map[(((x + 32) / 64) + (y / 64) * ((game->width + 1)))] == '1'
		|| game->map[((x / 64) + ((y + 32) / 64) * ((game->width + 1)))] == '1'
		|| game->map[(((x + 32) / 64) + (((y + 32) / 64)
					* ((game->width + 1))))] == '1')
		return (1);
	return (0);
}

static int	check(t_game *game, int x, int y)
{
	static int	count = 0;

	if (check_wall(game, x, y))
		return (0);
	if (check_exit(game, x, y))
		return (0);
	if (check_collectible(game, x, y))
		return (0);
	count++;
	ft_putnbr_fd(count, 2);
	write(2, "\n", 1);
	return (1);
}

void	keyhook(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if ((mlx_is_key_down(game->mlx, (MLX_KEY_UP)))
		|| (mlx_is_key_down(game->mlx, (MLX_KEY_W))))
		if (check(game, game->player->instances[0].x,
				game->player->instances[0].y - 4))
			game->player->instances[0].y -= 4;
	if ((mlx_is_key_down(game->mlx, (MLX_KEY_DOWN)))
		|| (mlx_is_key_down(game->mlx, (MLX_KEY_S))))
		if (check(game, game->player->instances[0].x,
				game->player->instances[0].y + 4))
			game->player->instances[0].y += 4;
	if ((mlx_is_key_down(game->mlx, (MLX_KEY_LEFT)))
		|| (mlx_is_key_down(game->mlx, (MLX_KEY_A))))
		if (check(game, game->player->instances[0].x - 4,
				game->player->instances[0].y))
			game->player->instances[0].x -= 4;
	if ((mlx_is_key_down(game->mlx, (MLX_KEY_RIGHT)))
		|| (mlx_is_key_down(game->mlx, (MLX_KEY_D))))
		if (check(game, game->player->instances[0].x + 4,
				game->player->instances[0].y))
			game->player->instances[0].x += 4;
}

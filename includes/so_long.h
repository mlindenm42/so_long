/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:06:16 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/02 23:16:32 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/MLX42/include/MLX42/MLX42.h"

# define IMG_FLOOR			"./textures/grass.png"
# define IMG_WALL			"./textures/stone_on_grass_2.png"
# define IMG_COLLECTIBLE	"./textures/goal.png"
# define IMG_EXIT			"./textures/trophy.png"
# define IMG_PLAYER			"./textures/football32.png"

# define MAX_WIDTH		2560
# define MAX_HEIGHT		1440

# define BUFFER_SIZE	902

typedef struct s_game
{
	mlx_t			*mlx;
	char			*map;
	int				width;
	int				height;
	mlx_image_t		*img;
	mlx_image_t		*player;
}	t_game;

void	error(t_game *game, char *reason);
void	error_valid(t_game *game, char *map_copy, char *reason);
void	free_str(char **str);
void	map_read(t_game *game, char *map);
void	map_check(t_game *game);
void	map_valid_path(t_game *game);
int		collectible_on_map(char *visited);
void	map_init(t_game *game);
void	map_visualize(t_game *game);
void	set_floor(t_game *game, int x, int y);
void	set_wall(t_game *game, int x, int y);
void	set_collectible(t_game *game, int x, int y);
void	set_exit(t_game *game, int x, int y);
void	set_player(t_game *game, int x, int y);
void	keyhook(void *param);

#endif

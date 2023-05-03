/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:01:45 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/02 20:05:02 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libraries/libft/libft.h"	//ft_strlen(); ft_strncmp();

void	free_str(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

void	error_valid(t_game *game, char *map_copy, char *reason)
{
	write(2, "Error\n", 6);
	write(2, reason, ft_strlen(reason));
	free_str(&map_copy);
	free_str(&game->map);
	exit(EXIT_FAILURE);
}

void	error(t_game *game, char *reason)
{
	write(2, "Error\n", 6);
	write(2, reason, ft_strlen(reason));
	free_str(&game->map);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		error(&game, "argc != 2\n");
	if (ft_strlen(argv[1]) <= 4
		|| ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		error(&game, "not a .ber file\n");
	map_read(&game, argv[1]);
	map_check(&game);
	map_init(&game);
	map_visualize(&game);
	mlx_loop_hook(game.mlx, keyhook, &game);
	mlx_loop(game.mlx);
	mlx_delete_image(game.mlx, game.img);
	free(game.map);
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:23:03 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/02 22:43:53 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libraries/libft/libft.h" //ft_calloc();
#include <fcntl.h> //open(); read(); close(); O_RDONLY;

void	map_read(t_game *game, char *map)
{
	int		i;
	int		y;
	int		fd;
	int		length;

	i = 0;
	y = 0;
	fd = 0;
	length = 0;
	game->map = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (game->map == NULL)
		error(game, "calloc 'map' failed\n");
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error(game, "Failed to open file\n");
	length = read(fd, game->map, BUFFER_SIZE);
	if (length < 0)
		error(game, "Failed to read from file\n");
	if (read(fd, game->map, BUFFER_SIZE))
		error(game, "Map to big\n");
	if (game->map[length - 1] != '\n')
		error(game, "No new line at end of file\n");
	close(fd);
}

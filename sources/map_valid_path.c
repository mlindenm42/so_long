/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:55:58 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/02 20:03:50 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libraries/libft/libft.h" //ft_calloc(); ft_strlcpy();

static int	map_valid_exit(t_game *game, char *v, int i)
{
	int	valid;

	valid = 0;
	if (v[i] == 'E' || valid == 1)
	{
		v[i] = 'V';
		return (i);
	}
	v[i] = 'V';
	if (i > game->width)
	{
		if ((v[i - game->width - 1] == '0' || v[i - game->width - 1] == 'E'))
			valid = map_valid_exit(game, v, i - game->width - 1);
	}
	if ((v[i + 1] == '0' || v[i + 1] == 'E') && valid == 0)
		valid = map_valid_exit(game, v, i + 1);
	if (i < (game->width + 1) * game->height)
	{
		if ((v[i + game->width + 1] == '0'
				|| v[i + game->width + 1] == 'E') && valid == 0)
				valid = map_valid_exit(game, v, i + game->width + 1);
	}
	if ((v[i - 1] == '0' || v[i - 1] == 'E') && valid == 0)
		valid = map_valid_exit(game, v, i - 1);
	return (valid);
}

static int	map_valid_collectible(t_game *game, char *v, int i)
{
	int	valid;

	valid = 0;
	if (v[i] == 'C' || valid == 1)
	{
		v[i] = 'V';
		return (i);
	}
	v[i] = 'V';
	if (i > game->width)
	{
		if ((v[i - game->width - 1] == '0' || v[i - game->width - 1] == 'C'))
			valid = map_valid_collectible(game, v, i - game->width - 1);
	}
	if ((v[i + 1] == '0' || v[i + 1] == 'C') && valid == 0)
		valid = map_valid_collectible(game, v, i + 1);
	if (i < (game->width + 1) * game->height)
	{
		if ((v[i + game->width + 1] == '0'
				|| v[i + game->width + 1] == 'C') && valid == 0)
				valid = map_valid_collectible(game, v, i + game->width + 1);
	}
	if ((v[i - 1] == '0' || v[i - 1] == 'C') && valid == 0)
		valid = map_valid_collectible(game, v, i - 1);
	return (valid);
}

static void	map_replace_visited(char *visited)
{
	int	i;

	i = 0;
	while (visited[i] != '\0')
	{
		if (visited[i] == 'V')
			visited[i] = '0';
		i++;
	}
}

int	collectible_on_map(char *visited)
{
	int	i;

	i = 0;
	while (visited[i] != '\0')
	{
		if (visited[i] == 'C')
			return (1);
		i++;
	}
	return (0);
}

void	map_valid_path(t_game *game)
{
	int		player;
	char	*visited;

	player = 0;
	visited = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (visited == NULL)
		error(game, "calloc 'visited' failed\n");
	ft_strlcpy(visited, game->map, ((game->width + 1) * game->height) + 1);
	while (game->map[player] != 'P')
		player++;
	while (collectible_on_map(visited))
	{
		map_replace_visited(visited);
		player = map_valid_collectible(game, visited, player);
		if (player == 0)
			error_valid(game, visited, "Map has no valid path.\n");
	}
	map_replace_visited(visited);
	if (!map_valid_exit(game, visited, player))
		error_valid(game, visited, "Map has no valid path.\n");
	free_str(&visited);
}

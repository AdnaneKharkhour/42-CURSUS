#include "game.h"
#include <stdio.h>
#include "libft/get_next_line.h"

int	count_lines(const char *file)
{
	int		fd;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	while(get_next_line(fd))
		count++;
	close(fd);
	return (count);
}

char **load_map(const char *file)
{
    int fd;
    int i;
    int num_lines;
    char *line;
    char **map;

	i = 0;
	num_lines = count_lines(file);
    map = malloc(sizeof(char *) * (num_lines + 1));
    if (!map)
        return (NULL);
    fd = open(file, O_RDONLY);
	line = get_next_line(fd);
    while (line)
    {
        map[i++] = line;
		line = get_next_line(fd);
    }
    map[i] = NULL;
    close(fd);
    return (map);
}

void	player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

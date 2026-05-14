/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:25:52 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/14 19:37:39 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

enum e_setting_flag
{
	FLAG_NORTH = (1 << 0),
	FLAG_SOUTH = (1 << 1),
	FLAG_WEST = (1 << 2),
	FLAG_EAST = (1 << 3),
	FLAG_FLOOR = (1 << 4),
	FLAG_CEILING = (1 << 5)
};

typedef struct s_settings
{
	int			flags;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			floor_color;
	int			ceiling_color;
}				t_settings;

typedef struct s_cub3d
{
	t_settings	settings;
	t_map		map;
	t_player	player;
	t_mlx		mlx;
}				t_cub3d;

void	print_error(char const *error_message)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, "%s\n", error_message);
}

bool	is_valid_argument(int argc, char const *argv[])
{
	char	*filename;
	size_t	len;

	if (argc != 2)
		return (false);
	filename = ft_strrchr(argv[1], '/');
	if (filename != NULL)
		++filename;
	else
		filename = (char *)argv[1];
	len = ft_strlen(filename);
	if (len <= 4 || ft_strcmp(filename + len - 4, ".cub") != 0)
		return (false);
	return (true);
}

bool	vaildate_argument(int argc, char const *argv[])
{
	if (!is_valid_argument(argc, argv))
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		ft_dprintf(STDERR_FILENO, "usage: %s *.cub\n", argv[0]);
		return (false);
	}
	return (true);
}

static bool	is_incomplete_settings(int flags)
{

}

static char *read_next_setting(int fd)
{

}

static void	cleanup_settings(t_settings *settings)
{

}

bool	parse_setting_line(char *setting_line, t_settings *settings)
{

}

bool	parse_settings(int fd, t_settings *settings)
{
	char	*setting_line;

	while (is_incomplete_settings(settings->flags))
	{
		setting_line = read_next_setting(fd);
		if (setting_line == NULL)
		{
			cleanup_settings(settings);
			return (false);
		}
		if (!parse_setting_line(setting_line, settings))
		{
			free(setting_line);
			cleanup_settings(settings);
			return (false);
		}
		free(setting_line);
	}
	return (true);
}

bool	parse_file(char const *filename, t_settings *settings, t_map *map)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error(strerror(errno));
		return (false);
	}
	if (!parse_settings(fd, settings))
	{
		close(fd);
		return (false);
	}
	if (!parse_map(fd, map))
	{
		cleanup_settings(settings);
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

int main(int argc, char const *argv[])
{
	t_cub3d	cub3d;

	if (!vaildate_argument(argc, argv))
		return (EXIT_FAILURE);
	ft_bzero(&cub3d, sizeof(t_cub3d));
	if (!parse_file(argv[1], &cub3d.settings, &cub3d.map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

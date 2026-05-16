/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:01:11 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 13:01:30 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_incomplete_settings(int flags)
{

}

static char *read_next_setting_line(int fd)
{
	char	*setting_line;
	char	**words;

	while (true)
	{
		setting_line = get_next_line(fd);
		if (errno != 0)
		{
			print_error("fail GNL");
			return (NULL);
		}
		if (setting_line == NULL)
		{
			print_error("settings is incomplete");
			return (NULL);
		}
		replace_char(setting_line, '\n', '\0');
		if (is_blank_line(setting_line))
		{
			free(setting_line);
			continue ;
		}
		return (setting_line);
	}
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
		setting_line = read_next_setting_line(fd);
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

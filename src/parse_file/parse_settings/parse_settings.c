/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:29:17 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 16:32:41 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static bool	assign_setting(char const *identifier, char const *value,
	t_settings *settings)
{
	if (ft_strcmp("NO", identifier) == 0)
		return (set_texture(value, settings, NORTH_ID));
	else if (ft_strcmp("SO", identifier) == 0)
		return (set_texture(value, settings, SOUTH_ID));
	else if (ft_strcmp("WE", identifier) == 0)
		return (set_texture(value, settings, WEST_ID));
	else if (ft_strcmp("EA", identifier) == 0)
		return (set_texture(value, settings, EAST_ID));
	else if (ft_strcmp("F", identifier) == 0)
		return (set_color(value, settings, FLOOR_ID));
	else if (ft_strcmp("C", identifier) == 0)
		return (set_color(value, settings, CEILING_ID));
	else
	{
		print_error("identifier is invalid");
		return (false);
	}
}

bool	parse_setting_line(char *setting_line, t_settings *settings)
{
	char	**words;

	words = ft_split(setting_line, ' ');
	if (words == NULL)
		return (false);
	if (words[1] == NULL)
	{
		print_error("settings is element less");
		free_splitted(words);
		return (false);
	}
	if (words[2] != NULL)
	{
		print_error("element is more");
		free_splitted(words);
		return (false);
	}
	if (!assign_setting(words[0], words[1], settings))
	{
		free_splitted(words);
		return (false);
	}
	free_splitted(words);
	return (true);
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

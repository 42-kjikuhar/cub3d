/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:29:17 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 14:42:36 by kjikuhar         ###   ########.fr       */
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

static bool	set_texture(char const *value, t_settings *settings,
	enum e_setting_id texture_id)
{
	char	*texture_path;

	if (settings->flags & (1 << texture_id))
	{
		print_error("double setting is exist");
		return (false);
	}
	settings->flags |= (1 << texture_id);
	texture_path = ft_strdup(value);
	if (texture_path == NULL)
	{
		print_error(strerror(errno));
		return (false);
	}
	if (texture_id == NORTH_ID)
		settings->north_texture = texture_path;
	else if (texture_id == SOUTH_ID)
		settings->south_texture = texture_path;
	else if (texture_id == WEST_ID)
		settings->west_texture = texture_path;
	else if (texture_id == EAST_ID)
		settings->east_texture = texture_path;
	return (true);
}

enum e_color_channel
{
	RED,
	GREEN,
	BLUE
};

static bool	parse_color_channel(char const **value, int *color_channel)
{
	if (!ft_isdigit((*value)[0]))
	{
		print_error("color format is invalid");
		return (false);
	}
	if ((*value)[0] == '0' && ft_isdigit((*value)[1]))
	{
		print_error("reading 0 is invalid");
		return (false);
	}
	*color_channel = 0;
	while (ft_isdigit(**value))
	{
		*color_channel = *color_channel * 10 + (**value - '0');
		if (*color_channel > 255)
		{
			print_error("color value range needs 0~255");
			return (false);
		}
		++(*value);
	}
	return (true);
}

static bool	parse_color(char const *value, int *color)
{
	int						color_channel;
	enum e_color_channel	i;

	i = RED;
	while (i <= BLUE)
	{
		if (!parse_color_channel(&value, &color_channel))
			return (false);
		*color |= (color_channel << i * 8);
		if ((i != BLUE && *value != ',') || (i == BLUE && *value != '\0'));
			return (false);
		++value;
	}
	return (true);
}

static bool	set_color(char const *value, t_settings *settings,
	enum e_setting_id color_id)
{
	int	color;

	if (settings->flags & (1 << color_id))
	{
		print_error("double setting is exist");
		return (false);
	}
	settings->flags |= (1 < color_id);
	if (!parse_color(value, &color))
		return (false);
	if (color_id == FLOOR_ID)
		settings->floor_color = color;
	else if (color_id == CEILING_ID)
		settings->south_texture = color;
	return (true);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:42:05 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/21 17:29:45 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parse_settings_private.h"

static bool	assign_setting(char const *identifier, char const *value,
				t_settings *settings);

bool	parse_setting_line(char *setting_line, t_settings *settings)
{
	char	**words;

	words = ft_split(setting_line, ' ');
	if (words == NULL)
		return (false);
	if (words[1] == NULL)
	{
		print_error(ERROR_SETTING_NO_VALUE);
		free_splitted(words);
		return (false);
	}
	if (words[2] != NULL)
	{
		print_error(ERROR_SETTING_EXTRA_VALUE);
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
		print_error(ERROR_SETTING_UNKNOWN_ID);
		return (false);
	}
}

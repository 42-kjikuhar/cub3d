/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:29:17 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/01 00:36:44 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parse_file_private.h"

static bool	parse_setting_line(char *setting_line);
static bool	has_single_value(char **words);
static bool	assign_setting(char const *identifier, char *value);

bool	parse_settings(t_list **line_list)
{
	int		setting_count;
	char	*setting_line;

	setting_count = 0;
	while (setting_count < SETTING_COUNT)
	{
		setting_line = ft_lst_pop_front(line_list);
		if (!is_blank_line(setting_line))
		{
			if (!parse_setting_line(setting_line))
			{
				free(setting_line);
				return (false);
			}
			++setting_count;
		}
		free(setting_line);
	}
	return (true);
}

static bool	parse_setting_line(char *setting_line)
{
	char	**words;

	words = ft_split(setting_line, ' ');
	if (words == NULL)
	{
		print_error(strerror(errno));
		return (false);
	}
	if (!has_single_value(words))
	{
		free_splitted(words);
		return (false);
	}
	if (!assign_setting(words[0], words[1]))
	{
		free_splitted(words);
		return (false);
	}
	free_splitted(words);
	return (true);
}

static bool	has_single_value(char **words)
{
	if (words[1] == NULL)
	{
		print_error(ERROR_SETTING_NO_VALUE);
		return (false);
	}
	if (words[2] != NULL)
	{
		print_error(ERROR_SETTING_EXTRA_VALUE);
		return (false);
	}
	return (true);
}

static bool	assign_setting(char const *identifier, char *value)
{
	int const	width = TEXTURE_SIZE;
	int const	height = TEXTURE_SIZE;
	int			color;

	if (ft_strcmp("NO", identifier) == 0)
		return (create_image_from_xpm(value, IMG_NORTH_WALL, width, height));
	else if (ft_strcmp("SO", identifier) == 0)
		return (create_image_from_xpm(value, IMG_SOUTH_WALL, width, height));
	else if (ft_strcmp("WE", identifier) == 0)
		return (create_image_from_xpm(value, IMG_WEST_WALL, width, height));
	else if (ft_strcmp("EA", identifier) == 0)
		return (create_image_from_xpm(value, IMG_EAST_WALL, width, height));
	else
	{
		if (!parse_color(value, &color))
			return (false);
		if (ft_strcmp("F", identifier) == 0)
			set_color(COLOR_FLOOR, color);
		else if (ft_strcmp("C", identifier) == 0)
			set_color(COLOR_CEILING, color);
		return (true);
	}
}

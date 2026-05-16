/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:29:17 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 16:46:46 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static char	*read_next_setting_line(int fd)
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

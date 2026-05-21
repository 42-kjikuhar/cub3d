/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:29:17 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/21 01:35:28 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../parse_file_private.h"
#include "./parse_settings_private.h"

static char	*read_next_setting_line(int fd);

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

	while (true)
	{
		if (!read_next_line(fd, &setting_line))
			return (NULL);
		if (setting_line == NULL)
		{
			print_error(ERROR_SETTING_INCOMPLETE);
			return (NULL);
		}
		if (is_blank_line(setting_line))
		{
			free(setting_line);
			continue ;
		}
		return (setting_line);
	}
}

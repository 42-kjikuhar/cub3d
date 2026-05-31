/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 09:24:42 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 01:18:31 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parse_file_private.h"

static void	check_line(char *line, t_validate_flags *flags, int *settings_flag);
static bool	get_setting_id(char *line, enum e_setting_id *setting_id);
static bool	is_complete_settings(int settings_flag);
static bool	check_validate_flags(t_validate_flags const *flags);

bool	validate_file_format(t_list *line_list)
{
	t_validate_flags	flags;
	int					settings_flag;

	ft_bzero(&flags, sizeof(t_validate_flags));
	flags.incomplete_settings = true;
	flags.no_map = true;
	settings_flag = 0;
	while (line_list != NULL)
	{
		check_line((char *)(line_list->content), &flags, &settings_flag);
		line_list = line_list->next;
	}
	if (!check_validate_flags(&flags))
		return (false);
	return (true);
}

static void	check_line(char *line, t_validate_flags *flags, int *settings_flag)
{
	enum e_setting_id	setting_id;

	if (get_setting_id(line, &setting_id))
	{
		if (*settings_flag & (1 << setting_id))
			flags->duplicate_setting = true;
		*settings_flag |= (1 << setting_id);
		if (is_complete_settings(*settings_flag))
			flags->incomplete_settings = false;
		flags->last_setting = true;
	}
	else if (!is_blank_line(line))
	{
		flags->no_map = false;
		if (flags->incomplete_settings == true)
			flags->invalid_line = true;
		flags->last_setting = false;
	}
	else
	{
		if (flags->no_map == false)
			flags->map_blank_line = true;
	}
}

static bool	get_setting_id(char *line, enum e_setting_id *setting_id)
{
	while (*line == ' ')
		++line;
	if (ft_strcmp("NO", line) == 0 || ft_strncmp("NO ", line, 3) == 0)
		*setting_id = SETTING_NORTH;
	else if (ft_strcmp("SO", line) == 0 || ft_strncmp("SO ", line, 3) == 0)
		*setting_id = SETTING_SOUTH;
	else if (ft_strcmp("WE", line) == 0 || ft_strncmp("WE ", line, 3) == 0)
		*setting_id = SETTING_WEST;
	else if (ft_strcmp("EA", line) == 0 || ft_strncmp("EA ", line, 3) == 0)
		*setting_id = SETTING_EAST;
	else if (ft_strcmp("F", line) == 0 || ft_strncmp("F ", line, 2) == 0)
		*setting_id = SETTING_FLOOR;
	else if (ft_strcmp("C", line) == 0 || ft_strncmp("C ", line, 2) == 0)
		*setting_id = SETTING_CEILING;
	else
		return (false);
	return (true);
}

static bool	is_complete_settings(int settings_flag)
{
	return (settings_flag == (1 << SETTING_COUNT) - 1);
}

static bool	check_validate_flags(t_validate_flags const *flags)
{
	if (flags->incomplete_settings == true)
		print_error(ERROR_SETTING_INCOMPLETE);
	else if (flags->duplicate_setting == true)
		print_error(ERROR_SETTING_DUPLICATE);
	else if (flags->no_map == true)
		print_error(ERROR_MAP_EMPTY);
	else if (flags->last_setting == true)
		print_error(ERROR_MAP_NOT_LAST);
	else if (flags->invalid_line == true)
		print_error(ERROR_SETTING_UNKNOWN_ID);
	else if (flags->map_blank_line == true)
		print_error(ERROR_MAP_EMPTY_LINE);
	else
		return (true);
	return (false);
}

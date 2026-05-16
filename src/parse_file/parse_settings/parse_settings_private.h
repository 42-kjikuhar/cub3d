/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings_private.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:48:55 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 16:57:39 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_SETTINGS_PRIVATE_H
# define PARSE_SETTINGS_PRIVATE_H

# include "cub3d.h"

enum e_setting_id
{
	NORTH_ID,
	SOUTH_ID,
	WEST_ID,
	EAST_ID,
	FLOOR_ID,
	CEILING_ID,
	ID_COUNT
};

enum e_color_channel
{
	RED,
	GREEN,
	BLUE
};

bool	parse_setting_line(char *setting_line, t_settings *settings);
bool	set_texture(char const *value, t_settings *settings,
			enum e_setting_id texture_id);
bool	set_color(char const *value, t_settings *settings,
			enum e_setting_id color_id);

/* utils */
bool	is_incomplete_settings(int flags);

#endif

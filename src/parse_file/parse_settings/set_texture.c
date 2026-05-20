/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:12:32 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/21 01:37:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parse_settings_private.h"

bool	set_texture(char const *value, t_settings *settings,
	enum e_setting_id texture_id)
{
	char	*texture_path;

	if (settings->flags & (1 << texture_id))
	{
		print_error(ERROR_SETTING_DUPLICATE);
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

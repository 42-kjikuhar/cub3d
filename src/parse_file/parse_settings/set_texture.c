/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:12:32 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 16:12:43 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

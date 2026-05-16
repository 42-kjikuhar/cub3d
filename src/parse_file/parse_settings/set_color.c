/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:11:18 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 16:11:30 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:11:18 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/01 00:51:26 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parse_file_private.h"

static bool	parse_color_channel(char const **value, int *color_channel);

bool	parse_color(char const *value, int *color)
{
	int						color_channel;
	enum e_color_channel	i;

	*color = 0;
	i = RED;
	while (i <= BLUE)
	{
		if (!parse_color_channel(&value, &color_channel))
			return (false);
		*color = (*color << 8) | color_channel;
		if (((i == RED || i == GREEN) && *value != ',') \
			|| (i == BLUE && *value != '\0'))
		{
			print_error(ERROR_COLOR_FORMAT);
			return (false);
		}
		++value;
		++i;
	}
	return (true);
}

static bool	parse_color_channel(char const **value, int *color_channel)
{
	if (!ft_isdigit((*value)[0]))
	{
		print_error(ERROR_COLOR_FORMAT);
		return (false);
	}
	if ((*value)[0] == '0' && ft_isdigit((*value)[1]))
	{
		print_error(ERROR_COLOR_LEADING_ZERO);
		return (false);
	}
	*color_channel = 0;
	while (ft_isdigit(**value))
	{
		*color_channel = *color_channel * 10 + (**value - '0');
		if (*color_channel > 255)
		{
			print_error(ERROR_COLOR_RANGE);
			return (false);
		}
		++(*value);
	}
	return (true);
}

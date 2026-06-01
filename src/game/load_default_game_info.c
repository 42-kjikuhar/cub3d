/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_default_game_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 04:30:29 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 04:30:47 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	load_default_game_info(void)
{
	if (!create_image_from_xpm("./assets/greystone.xpm", IMG_FLOOR, \
												TEXTURE_SIZE, TEXTURE_SIZE) \
		|| !create_image_from_xpm("./assets/mossy.xpm", IMG_CEILING, \
												TEXTURE_SIZE, TEXTURE_SIZE))
	{
		return (false);
	}
	return (true);
}


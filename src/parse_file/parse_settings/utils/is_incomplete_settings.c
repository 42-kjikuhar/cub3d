/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_incomplete_settings.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:30:07 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/24 18:06:17 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../parse_settings_private.h"

bool	is_incomplete_settings(int flags)
{
	return ((flags ^ (1 << ID_COUNT) - 1) != 0);
}

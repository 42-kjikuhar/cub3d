/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:40:01 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 16:40:16 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cleanup_settings(t_settings *settings)
{
	if (settings->north_texture != NULL)
		free(settings->north_texture);
	if (settings->south_texture != NULL)
		free(settings->south_texture);
	if (settings->west_texture != NULL)
		free(settings->west_texture);
	if (settings->east_texture != NULL)
		free(settings->east_texture);
}

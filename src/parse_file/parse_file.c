/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:01:11 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 13:29:44 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	parse_file(char const *filename, t_settings *settings, t_map *map)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error(strerror(errno));
		return (false);
	}
	if (!parse_settings(fd, settings))
	{
		close(fd);
		return (false);
	}
	if (!parse_map(fd, map))
	{
		cleanup_settings(settings);
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}

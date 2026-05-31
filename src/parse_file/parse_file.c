/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:35:08 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/31 23:42:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parse_file_private.h"

bool	parse_file(char const *filename)
{
	int		fd;
	t_list	*line_list;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		print_error(strerror(errno));
		return (false);
	}
	if (!read_file_as_line_list(fd, &line_list))
	{
		close(fd);
		return (false);
	}
	if (!validate_file_format(line_list) \
		|| !parse_settings(&line_list) \
		|| !parse_map(&line_list))
	{
		ft_lstclear(&line_list, free);
		return (false);ft_lstclear(&line_list, free);
	}
	return (true);
}

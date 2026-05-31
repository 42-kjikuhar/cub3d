/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_as_line_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 09:26:53 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/31 09:27:21 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./parse_file_private.h"

bool	read_file_as_line_list(int fd, t_list **line_list)
{
	char	*line;

	*line_list = NULL;
	while (true)
	{
		if (!read_next_line(fd, &line))
		{
			ft_lstclear(line_list, free);
			return (false);
		}
		if (line == NULL)
			return (true);
		else if (!ft_lst_push_back(line_list, line))
		{
			print_error(strerror(errno));
			free(line);
			ft_lstclear(line_list, free);
			return (false);
		}
	}
}

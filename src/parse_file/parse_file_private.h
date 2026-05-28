/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:44:06 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/28 23:47:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FILE_PRIVATE_H
# define PARSE_FILE_PRIVATE_H

# include "cub3d.h"

bool	parse_settings(int fd, t_settings *settings);
bool	parse_map(int fd);

/* utils */
bool	read_next_line(int fd, char **next_line);
bool	is_blank_line(const char *s);
void	replace_char(char *str, char from_c, char to_c);

#endif

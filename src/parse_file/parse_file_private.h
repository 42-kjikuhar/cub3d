/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:44:06 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/31 23:27:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FILE_PRIVATE_H
# define PARSE_FILE_PRIVATE_H

# include "cub3d.h"
# include "types.h"

typedef struct s_validate_flags
{
	bool	incomplete_settings;
	bool	duplicate_setting;
	bool	last_setting;
	bool	invalid_line;
	bool	no_map;
	bool	map_blank_line;
}	t_validate_flags;

enum e_setting_id
{
	SETTING_NORTH,
	SETTING_SOUTH,
	SETTING_WEST,
	SETTING_EAST,
	SETTING_FLOOR,
	SETTING_CEILING,
	SETTING_COUNT,
};

enum e_color_channel
{
	RED,
	GREEN,
	BLUE
};

bool	read_file_as_line_list(int fd, t_list **line_list);
bool	validate_file_format(t_list *line_list);
bool	parse_settings(t_list **line_list);
bool	parse_color(char const *value, int *color);
bool	parse_map(t_list **line_list);
bool	parse_map_data(void);

/* utils */
bool	read_next_line(int fd, char **next_line);
bool	is_blank_line(const char *s);
void	free_splitted(char **words);

#endif

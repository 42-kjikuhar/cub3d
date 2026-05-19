/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 12:33:12 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/19 21:52:12 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_PRIVATE_H
# define PARSE_MAP_PRIVATE_H

# include "cub3d.h"

bool	read_map(int fd, t_map *map);
bool	parse_map_data(t_map *map);
void	cleanup_map(t_map *map);
bool	parse_map_cell(t_map *map, int x, int y);

#endif

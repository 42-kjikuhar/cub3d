/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 12:33:12 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/28 23:46:29 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_PRIVATE_H
# define PARSE_MAP_PRIVATE_H

# include "cub3d.h"

bool	read_map(int fd);
bool	parse_map_data(void);
bool	parse_map_cell(int x, int y);

#endif

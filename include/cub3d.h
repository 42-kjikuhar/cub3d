/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:27:17 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 21:18:35 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include "libft.h"
# include "../vec_library/ft_vector.h"

typedef struct s_player
{
	t_ivec2			pos;
	t_ivec2			dir;
}					t_player;

typedef struct s_map
{
	char			**data;
	unsigned int	x_size;
	unsigned int	y_size;
	t_ivec2			player_pos;
	char			player_dir;
}					t_map;

typedef struct s_settings
{
	int			flags;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			floor_color;
	int			ceiling_color;
}				t_settings;

typedef struct s_cub3d
{
	t_settings	settings;
	t_map		map;
	t_player	player;
	// t_mlx		mlx;
}				t_cub3d;

bool	parse_file(char const *filename, t_settings *settings, t_map *map);

#endif

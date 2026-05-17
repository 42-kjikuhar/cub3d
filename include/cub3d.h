/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:27:17 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/17 12:02:48 by kjikuhar         ###   ########.fr       */
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

# define	MAP_FLOOR '0'
# define	MAP_WALL '1'
# define	MAP_BLANK ' '
# define	PLAYER_NORTH 'N'
# define	PLAYER_SOUTH 'S'
# define	PLAYER_WEST 'W'
# define	PLAYER_EAST 'E'

typedef struct s_player
{
	t_ivec2			pos;
	t_ivec2			dir;
}					t_player;

typedef struct s_map
{
	char			**data;
	int				x_size;
	int				y_size;
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

/* error */
void	print_error(char const *error_message);

#endif

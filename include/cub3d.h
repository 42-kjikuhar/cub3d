/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:27:17 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 16:16:00 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "libft.h"
# include "../vec_library/ft_vector.h"

enum e_setting_id
{
	NORTH_ID,
	SOUTH_ID,
	WEST_ID,
	EAST_ID,
	FLOOR_ID,
	CEILING_ID,
	ID_COUNT
};

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
	t_mlx		mlx;
}				t_cub3d;


bool	is_blank_line(const char *s)
void	replace_char(char *str, char from_c, char to_c);

#endif

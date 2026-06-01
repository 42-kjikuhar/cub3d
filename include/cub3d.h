/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:27:17 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/01 23:43:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"

# include "types.h"
# include "error.h"
# include "vector/ivec2.h"
# include "vector/dvec3.h"
# include "parse_file.h"
# include "color.h"
# include "map.h"
# include "game.h"
# include "view.h"
# include "player.h"
# include "ft_mlx.h"
# include "drawer.h"

# ifndef DEBUG
#  define DEBUG 0
# endif

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# define DEG_TO_RAD 0.01745329251994329547 // (M_PI / 180.0)
# define RAD_TO_DEG 57.29577951308232286465 // (180.0 / M_PI)

#endif

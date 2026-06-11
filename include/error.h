/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 01:18:22 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/12 07:19:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// # define ERROR_USAGE "Usage: ./cub3D <*.cub>"
// # define ERROR_FILE_EXTENSION "File must have a '.cub' extension."

/* File */
# define ERROR_FILE_BINARY "Invalid file: not a text file."

/* Settings */
# define ERROR_SETTING_INCOMPLETE "Missing setting: NO SO WE EA F C required."
# define ERROR_SETTING_UNKNOWN_ID "Invalid setting: unknown identifier. Expected NO SO WE EA F C."
# define ERROR_SETTING_DUPLICATE "Invalid setting: duplicated identifier detected."
# define ERROR_SETTING_NO_VALUE "Invalid setting: value required."
# define ERROR_SETTING_EXTRA_VALUE "Invalid setting: must have a single value."

/* Color */
# define ERROR_COLOR_FORMAT "Invalid color: expected R,G,B (0-255)."
# define ERROR_COLOR_LEADING_ZERO "Invalid color: leading zero not allowed."
# define ERROR_COLOR_RANGE "Invalid color: value out of range (0-255)."

/* Map */
# define ERROR_MAP_NOT_LAST "Invalid map: map must be placed at last."
# define ERROR_MAP_TOO_LARGE "Invalid map: too large (x <= INT_MAX && y <= INT_MAX)."
# define ERROR_MAP_EMPTY "Invalid map: empty."
# define ERROR_MAP_EMPTY_LINE "Invalid map: empty lines not allowed."
# define ERROR_MAP_INVALID_CHAR "Invalid map: invalid character detected."
# define ERROR_MAP_NOT_CLOSED "Invalid map: floor cell not closed/surrounded by walls."
# define ERROR_MAP_MULTI_PLAYER "Invalid map: multiple player cells detected."
# define ERROR_MAP_NO_PLAYER "Invalid map: player cell required (N S W E)."

/* MLX */
# define ERROR_MLX_CONNECTION "MLX: Failed to create X-Window connection."
# define ERROR_MLX_WINDOW "MLX: Failed to create window."
# define ERROR_MLX_IMAGE "MLX: Failed to create image."
# define ERROR_MLX_IMAGE_DATA "MLX: Failed to get image data."
# define ERROR_MLX_TEXTURE_LOAD "MLX: Failed to load xpm file texture."

void	print_error(char const *error_message);

#endif

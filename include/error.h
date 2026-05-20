/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 01:18:22 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/21 01:51:33 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// # define ERROR_USAGE "Usage: ./cub3D <*.cub>"
// # define ERROR_FILE_EXTENSION "File must have a '.cub' extension."

# define ERROR_BINARY_FILE "The file is not a text file."

# define ERROR_SETTING_INCOMPLETE \
			"Missing required settings. Expected: NO SO WE EA F C"
# define ERROR_SETTING_UNKNOWN_ID \
			"Unknown identifier. Expected: NO SO WE EA F C"
# define ERROR_SETTING_MISSING_VALUE "Setting value is required."
# define ERROR_SETTING_EXTRA_VALUE "Setting must have a single value."
# define ERROR_SETTING_DUPLICATE "Duplicate setting is detected."

# define ERROR_COLOR_FORMAT "Invalid color format. Expected: R,G,B (0-255)"
# define ERROR_COLOR_LEADING_ZERO "Color value cannot have leading zero."
# define ERROR_COLOR_RANGE "Color value is out of range (0-255)."

# define ERROR_MAP_TOO_LARGE "Map is too large. (x <= INT_MAX && y <= INT_MAX)"
# define ERROR_MAP_EMPTY "Map is empty."
# define ERROR_MAP_EMPTY_LINE "Map cannot have empty lines."
# define ERROR_MAP_INVALID_CHAR "Invalid map character is detected."
# define ERROR_MAP_NOT_CLOSED \
			"Map floor cell is not closed/surrounded by walls."
# define ERROR_MAP_MULTI_PLAYER "Multiple player cells are detected."
# define ERROR_MAP_NO_PLAYER "Map requires a player cell. Expected: N S W E"

# define ERROR_CREATE_MLX_CONNECTION "Failed to create X-Window connection."
# define ERROR_CREATE_MLX_WINDOW "Failed to create window."
# define ERROR_CREATE_MLX_IMAGE "Failed to create image."
# define ERROR_LOAD_TEXTURE "Failed to load texture file."
# define ERROR_GET_TEXTURE_DATA "Failed to get texture data."

void	print_error(char const *error_message);

#endif

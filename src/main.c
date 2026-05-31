/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:25:52 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/06/01 00:35:27 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	validate_argument(int argc, char const *argv[]);
static bool	is_valid_argument(int argc, char const *argv[]);

int	main(int argc, char const *argv[])
{
	if (!validate_argument(argc, argv))
		return (EXIT_FAILURE);
	if (!create_mlx_connection())
		return (EXIT_FAILURE);
	if (!parse_file(argv[1]))
	{
		ft_mlx_destroy();
		return (EXIT_FAILURE);
	}
	init_player(get_map_player());
	init_view(FOV, get_player()->pos, get_player()->dir);
	if (!create_image(IMG_WINDOW, W_WIDTH, W_HEIGHT) \
		|| !create_window(W_WIDTH, W_HEIGHT, W_TITLE))
	{
		cleanup_map();
		ft_mlx_destroy();
		return (EXIT_FAILURE);
	}
	mlx_clear_window(get_mlx_ptr(), get_win_ptr());
	ft_mlx_hooks();
	mlx_loop(get_mlx_ptr());
	cleanup_map();
	ft_mlx_destroy();
	return (EXIT_SUCCESS);
}

static bool	validate_argument(int argc, char const *argv[])
{
	if (!is_valid_argument(argc, argv))
	{
		ft_dprintf(STDERR_FILENO, "Error\n");
		ft_dprintf(STDERR_FILENO, "Usage: %s *.cub\n", argv[0]);
		return (false);
	}
	return (true);
}

static bool	is_valid_argument(int argc, char const *argv[])
{
	char	*filename;
	size_t	len;

	if (argc != 2)
		return (false);
	filename = ft_strrchr(argv[1], '/');
	if (filename != NULL)
		++filename;
	else
		filename = (char *)argv[1];
	len = ft_strlen(filename);
	if (len <= 4 || ft_strcmp(filename + len - 4, ".cub") != 0)
		return (false);
	return (true);
}

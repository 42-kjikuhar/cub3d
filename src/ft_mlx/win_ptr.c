/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 15:26:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/29 17:26:13 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./ft_mlx_private.h"

static void	*g_win_ptr;

void	*win_ptr(void)
{
	return (g_win_ptr);
}

bool	create_window(void)
{
	g_win_ptr = mlx_new_window(mlx_ptr(), W_WIDTH, W_HEIGHT, W_TITLE);
	if (g_win_ptr == NULL)
	{
		print_error(ERROR_MLX_WINDOW);
		return (false);
	}
	return (true);
}

void	cleanup_window(void)
{
	if (g_win_ptr != NULL)
	{
		mlx_destroy_window(mlx_ptr(), g_win_ptr);
		g_win_ptr = NULL;
	}
}

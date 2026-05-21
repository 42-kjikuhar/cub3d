/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_connection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 23:14:25 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/21 23:17:21 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../ft_mlx_private.h"

bool	create_connection(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
	{
		print_error(ERROR_MLX_CONNECTION);
		return (false);
	}
	return (true);
}

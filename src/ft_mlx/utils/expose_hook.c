/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:32:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 18:19:18 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	expose_hook(void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	(void)cub3d;
	return (0);
}

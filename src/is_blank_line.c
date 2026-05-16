/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_blank_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 12:48:38 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 12:52:40 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_blank_line(const char *s)
{
	if (!s)
		return (false);
	while (*s)
	{
		if (*s != ' ')
			return (false);
		s++;
	}
	return (true);
}

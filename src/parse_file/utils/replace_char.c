/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 12:39:41 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/16 12:43:31 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	replace_char(char *str, char from_c, char to_c)
{
	if (str == NULL)
		return ;
	if (from_c == '\0')
		return ;
	if (from_c == to_c)
		return ;
	while (*str != '\0')
	{
		if (*str == from_c)
		{
			*str = to_c;
		}
		str++;
	}
	return ;
}

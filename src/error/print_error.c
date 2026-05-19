/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 12:01:39 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/17 12:01:50 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char const *error_message)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	ft_dprintf(STDERR_FILENO, "%s\n", error_message);
}

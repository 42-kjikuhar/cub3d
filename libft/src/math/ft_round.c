/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:43:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/20 20:38:35 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_round(double x)
{
	if (x >= 0)
		return ((double)(long long)(x + 0.5));
	else
		return ((double)(long long)(x - 0.5));
}

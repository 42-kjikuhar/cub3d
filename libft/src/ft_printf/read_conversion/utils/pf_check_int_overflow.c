/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_check_int_overflow.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 23:18:31 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/26 17:28:41 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

bool	pf_check_int_overflow(const char *format)
{
	long	n;

	n = 0;
	while (ft_isdigit(*format))
	{
		n = n * 10 + (*format - '0');
		if (INT_MAX < n)
			return (true);
		format++;
	}
	return (false);
}

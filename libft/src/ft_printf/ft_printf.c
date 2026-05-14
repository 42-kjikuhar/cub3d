/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:54:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/01 19:34:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_ctx	ctx;
	va_list	ap;

	if (format == NULL)
		return (-1);
	ft_bzero(&ctx, sizeof(t_ctx));
	ctx.dst_type = PRINT_TO_FD;
	ctx.dst.fd = STDOUT_FILENO;
	va_start(ap, format);
	pf_xprintf(&ctx, &ap, format);
	va_end(ap);
	if (ctx.has_error)
		return (PF_ERROR);
	return (ctx.count);
}

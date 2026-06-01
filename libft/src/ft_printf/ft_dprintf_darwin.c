/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_darwin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:38:52 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 22:11:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/pf_defines.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	t_ctx	ctx;
	va_list	ap;

	ft_bzero(&ctx, sizeof(t_ctx));
	ctx.dst_type = PRINT_TO_FD;
	ctx.dst.fd = fd;
	va_start(ap, format);
	pf_xprintf(&ctx, &ap, format);
	va_end(ap);
	if (ctx.has_error)
		return (PF_ERROR);
	return ((int)ctx.count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_p_darwin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 13:30:08 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:33:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"

static void		print_conv_p(t_ctx *ctx, t_conv *conv, uintptr_t pointer);
static size_t	get_length_pointer(uintptr_t pointer);
static void		print_pointer(t_ctx *ctx, uintptr_t pointer);

void	pf_conv_p(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	uintptr_t	pointer;

	pointer = (uintptr_t)va_arg(*ap, void *);
	print_conv_p(ctx, conv, pointer);
}

static void	print_conv_p(t_ctx *ctx, t_conv *conv, uintptr_t pointer)
{
	size_t	len;
	size_t	padding;

	len = get_length_pointer(pointer);
	if ((void *)pointer == NULL && conv->has_prec && conv->precision == 0)
		len = 0;
	padding = 0;
	if (len < (size_t)conv->precision)
		padding = conv->precision - len;
	len += ft_strlen("0x");
	if (conv->width_flags == '\0' \
		|| (conv->width_flags == '0' && conv->has_prec))
	{
		pf_print_space_width(ctx, conv, len + padding);
	}
	pf_print_hexa_preffix(ctx, conv);
	if (conv->width_flags == '0' && !conv->has_prec)
		pf_print_zero_width(ctx, conv, len + padding);
	pf_print_padding(ctx, padding);
	if (!((void *)pointer == NULL && conv->has_prec && conv->precision == 0))
		print_pointer(ctx, pointer);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len + padding);
}

static size_t	get_length_pointer(uintptr_t pointer)
{
	size_t	digits;

	if ((void *)pointer == NULL)
		return (1);
	digits = 0;
	while (pointer)
	{
		pointer /= 16;
		digits++;
	}
	return (digits);
}

static void	print_pointer(t_ctx *ctx, uintptr_t pointer)
{
	if (pointer >= 16)
		print_pointer(ctx, pointer / 16);
	pf_print_char(ctx, "0123456789abcdef"[pointer % 16]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:45:07 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 22:29:16 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/pf_print_utils.h"

static void		print_conv_p(t_ctx *ctx, t_conv *conv, uintptr_t pointer);
static size_t	get_length_pointer(uintptr_t pointer);
static void		print_pointer(t_ctx *ctx, uintptr_t pointer);
static void		print_nullptr(t_ctx *ctx, t_conv *conv);

void	pf_conv_p(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	uintptr_t	pointer;

	pointer = (uintptr_t)va_arg(*ap, void *);
	if ((void *)pointer == NULL)
	{
		print_nullptr(ctx, conv);
		return ;
	}
	print_conv_p(ctx, conv, pointer);
}

static void	print_conv_p(t_ctx *ctx, t_conv *conv, uintptr_t pointer)
{
	size_t		len;
	size_t		padding;

	len = get_length_pointer(pointer);
	padding = 0;
	if (len < (size_t)conv->precision)
		padding = conv->precision - len;
	if (conv->sign_flags != '\0')
		len += ft_strlen("+");
	len += ft_strlen("0x");
	if (conv->width_flags == '\0' \
		|| (conv->width_flags == '0' && conv->has_prec))
	{
		pf_print_space_width(ctx, conv, len + padding);
	}
	pf_print_sign(ctx, conv, false);
	pf_print_strn(ctx, "0x", 2);
	if (conv->width_flags == '0' && !conv->has_prec)
		pf_print_zero_width(ctx, conv, len + padding);
	pf_print_padding(ctx, padding);
	print_pointer(ctx, pointer);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len + padding);
}

static size_t	get_length_pointer(uintptr_t pointer)
{
	size_t	digits;

	digits = 0;
	while (pointer > 0)
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

static void	print_nullptr(t_ctx *ctx, t_conv *conv)
{
	size_t		len;

	len = ft_strlen("(nil)");
	if (conv->width_flags != '-')
		pf_print_space_width(ctx, conv, len);
	pf_print_strn(ctx, "(nil)", len);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:42:54 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:33:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"

static void		print_conv_x(t_ctx *ctx, t_conv *conv, uintmax_t num);
static size_t	get_digits_uintmax_hexa(uintmax_t num);
static void		print_hexa(t_ctx *ctx, t_conv *conv, uintmax_t num);

void	pf_conv_x(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	uintmax_t	num;

	if (!conv->has_prec)
		conv->precision = 1;
	if (conv->length == LENGTH_HH)
		num = (uintmax_t)(unsigned char)va_arg(*ap, unsigned int);
	else if (conv->length == LENGTH_H)
		num = (uintmax_t)(unsigned short int)va_arg(*ap, unsigned int);
	else if (conv->length == LENGTH_LOWER_L)
		num = (uintmax_t)va_arg(*ap, unsigned long int);
	else if (conv->length == LENGTH_LOWER_LL)
		num = (uintmax_t)va_arg(*ap, unsigned long long int);
	else if (conv->length == LENGTH_J)
		num = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (conv->length == LENGTH_Z)
		num = (uintmax_t)va_arg(*ap, size_t);
	else if (conv->length == LENGTH_T)
		num = (uintmax_t)va_arg(*ap, size_t);
	else
		num = (uintmax_t)va_arg(*ap, unsigned int);
	print_conv_x(ctx, conv, num);
}

static void	print_conv_x(t_ctx *ctx, t_conv *conv, uintmax_t num)
{
	size_t		len;
	size_t		padding;

	len = get_digits_uintmax_hexa(num);
	if (num == 0 && conv->precision == 0)
		len = 0;
	padding = 0;
	if (len < (size_t)conv->precision)
		padding = conv->precision - len;
	if (conv->hash_flag == '#' && num != 0)
		len += ft_strlen("0x");
	if (conv->width_flags == '\0'
		|| (conv->width_flags == '0' && conv->has_prec))
		pf_print_space_width(ctx, conv, len + padding);
	if (conv->hash_flag == '#' && num != 0)
		pf_print_hexa_preffix(ctx, conv);
	if (conv->width_flags == '0' && !conv->has_prec)
		pf_print_zero_width(ctx, conv, len + padding);
	pf_print_padding(ctx, padding);
	if (!(num == 0 && conv->precision == 0))
		print_hexa(ctx, conv, num);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len + padding);
}

static size_t	get_digits_uintmax_hexa(uintmax_t num)
{
	size_t	digits;

	if (num == 0)
		return (1);
	digits = 0;
	while (num)
	{
		num /= 16;
		digits++;
	}
	return (digits);
}

static void	print_hexa(t_ctx *ctx, t_conv *conv, uintmax_t num)
{
	if (num >= 16)
		print_hexa(ctx, conv, num / 16);
	if (conv->identifier == 'x')
		pf_print_char(ctx, "0123456789abcdef"[num % 16]);
	else
		pf_print_char(ctx, "0123456789ABCDEF"[num % 16]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:40:00 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/03 21:33:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/print_utils.h"

static void		print_conv_d_i(t_ctx *ctx, t_conv *conv, intmax_t num);
static size_t	get_digits_intmax(intmax_t num);
static void		print_integer(t_ctx *ctx, intmax_t num);

void	pf_conv_d_i(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	intmax_t	num;

	if (!conv->has_prec)
		conv->precision = 1;
	if (conv->length == LENGTH_HH)
		num = (intmax_t)(signed char)va_arg(*ap, int);
	else if (conv->length == LENGTH_H)
		num = (intmax_t)(short int)va_arg(*ap, int);
	else if (conv->length == LENGTH_LOWER_L)
		num = (intmax_t)va_arg(*ap, long int);
	else if (conv->length == LENGTH_LOWER_LL)
		num = (intmax_t)va_arg(*ap, long long int);
	else if (conv->length == LENGTH_J)
		num = (intmax_t)va_arg(*ap, intmax_t);
	else if (conv->length == LENGTH_Z)
		num = (intmax_t)va_arg(*ap, ssize_t);
	else if (conv->length == LENGTH_T)
		num = (intmax_t)va_arg(*ap, ptrdiff_t);
	else
		num = (intmax_t)va_arg(*ap, int);
	print_conv_d_i(ctx, conv, num);
}

static void	print_conv_d_i(t_ctx *ctx, t_conv *conv, intmax_t num)
{
	size_t		len;
	size_t		padding;

	len = get_digits_intmax(num);
	if (num == 0 && conv->precision == 0)
		len = 0;
	padding = 0;
	if (len < (size_t)conv->precision)
		padding = conv->precision - len;
	if (num < 0 || conv->sign_flags != '\0')
		len += ft_strlen("-");
	if (conv->width_flags == '\0'
		|| (conv->width_flags == '0' && conv->has_prec))
		pf_print_space_width(ctx, conv, len + padding);
	pf_print_sign(ctx, conv, num < 0);
	if (conv->width_flags == '0' && !conv->has_prec)
		pf_print_zero_width(ctx, conv, len + padding);
	pf_print_padding(ctx, padding);
	if (!(num == 0 && conv->precision == 0))
		print_integer(ctx, num);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len + padding);
}

static size_t	get_digits_intmax(intmax_t num)
{
	size_t	digits;

	if (num == 0)
		return (1);
	digits = 0;
	while (num != 0)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

static void	print_integer(t_ctx *ctx, intmax_t num)
{
	uintmax_t	u_num;

	u_num = num;
	if (num < 0)
		u_num = -num;
	if (u_num >= 10)
		print_integer(ctx, u_num / 10);
	pf_print_char(ctx, "0123456789"[u_num % 10]);
}

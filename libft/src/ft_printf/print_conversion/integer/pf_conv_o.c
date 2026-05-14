/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:42:06 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/01 19:17:03 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

static void		print_conv_o(t_ctx *ctx, t_conv *conv, uintmax_t num);
static size_t	get_digits_uintmax_octal(uintmax_t num);
static void		print_octal(t_ctx *ctx, uintmax_t num);

void	pf_conv_o(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	uintmax_t	num;

	if (!conv->has_prec)
		conv->precision = 1;
	if (!ft_strcmp(conv->length, "hh"))
		num = (uintmax_t)(unsigned char)va_arg(*ap, unsigned int);
	else if (!ft_strcmp(conv->length, "h"))
		num = (uintmax_t)(unsigned short int)va_arg(*ap, unsigned int);
	else if (!ft_strcmp(conv->length, "l"))
		num = (uintmax_t)va_arg(*ap, unsigned long int);
	else if (!ft_strcmp(conv->length, "ll"))
		num = (uintmax_t)va_arg(*ap, unsigned long long int);
	else if (!ft_strcmp(conv->length, "j"))
		num = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (!ft_strcmp(conv->length, "z"))
		num = (uintmax_t)va_arg(*ap, size_t);
	else if (!ft_strcmp(conv->length, "t"))
		num = (uintmax_t)va_arg(*ap, size_t);
	else
		num = (uintmax_t)va_arg(*ap, unsigned int);
	print_conv_o(ctx, conv, num);
}

static void	print_conv_o(t_ctx *ctx, t_conv *conv, uintmax_t num)
{
	size_t		len;
	size_t		padding;

	len = get_digits_uintmax_octal(num);
	if (num == 0 && conv->precision == 0)
		len = 0;
	padding = 0;
	if (conv->hash_flag == '#' && (num != 0) && (size_t)conv->precision <= len)
		conv->precision = len + 1;
	else if (conv->hash_flag == '#' && num == 0 && conv->precision == 0)
		padding = 1;
	if (len < (size_t)conv->precision)
		padding = conv->precision - len;
	if (conv->width_flags == '\0' \
		|| (conv->width_flags == '0' && conv->has_prec))
	{
		pf_print_space_width(ctx, conv, len + padding);
	}
	else if (conv->width_flags == '0' && !conv->has_prec)
		pf_print_zero_width(ctx, conv, len + padding);
	pf_print_padding(ctx, padding);
	if (!(num == 0 && conv->precision == 0))
		print_octal(ctx, num);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len + padding);
}

static size_t	get_digits_uintmax_octal(uintmax_t num)
{
	size_t	digits;

	if (num == 0)
		return (1);
	digits = 0;
	while (num)
	{
		num /= 8;
		digits++;
	}
	return (digits);
}

static void	print_octal(t_ctx *ctx, uintmax_t num)
{
	if (num >= 8)
		print_octal(ctx, num / 8);
	pf_print_char(ctx, "01234567"[num % 8]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:42:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/01 18:56:07 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

static void		print_conv_u(t_ctx *ctx, t_conv *conv, uintmax_t num);
static size_t	get_digits_uintmax(uintmax_t num);
static void		print_unsigned(t_ctx *ctx, uintmax_t num);

void	pf_conv_u(va_list *ap, t_ctx *ctx, t_conv *conv)
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
	print_conv_u(ctx, conv, num);
}

static void	print_conv_u(t_ctx *ctx, t_conv *conv, uintmax_t num)
{
	size_t		len;
	size_t		padding;

	len = get_digits_uintmax(num);
	if (num == 0 && conv->precision == 0)
		len = 0;
	padding = 0;
	if (len < (size_t)conv->precision)
		padding = conv->precision - len;
	if (conv->width_flags == '\0'
		|| (conv->width_flags == '0' && conv->has_prec))
		pf_print_space_width(ctx, conv, len + padding);
	else if (conv->width_flags == '0' && !conv->has_prec)
		pf_print_zero_width(ctx, conv, len + padding);
	pf_print_padding(ctx, padding);
	if (!(num == 0 && conv->precision == 0))
		print_unsigned(ctx, num);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len + padding);
}

static size_t	get_digits_uintmax(uintmax_t num)
{
	size_t	digits;

	if (num == 0)
		return (1);
	digits = 0;
	while (num)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

static void	print_unsigned(t_ctx *ctx, uintmax_t num)
{
	if (num >= 10)
		print_unsigned(ctx, num / 10);
	pf_print_char(ctx, "0123456789"[num % 10]);
}

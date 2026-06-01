/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exponent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 23:05:28 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/19 17:05:54 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/pf_print_utils.h"

static void	print_num(t_ctx *ctx, int num);

void	pf_print_decimal_exponent(t_ctx *ctx, t_conv *conv, int decimal_exp)
{
	if (conv->identifier == 'e' || conv->identifier == 'g')
		pf_print_char(ctx, 'e');
	else if (conv->identifier == 'E' || conv->identifier == 'G')
		pf_print_char(ctx, 'E');
	if (decimal_exp >= 0)
		pf_print_char(ctx, '+');
	else
		pf_print_char(ctx, '-');
	if (-10 < decimal_exp && decimal_exp < 10)
		pf_print_char(ctx, '0');
	print_num(ctx, decimal_exp);
}

void	pf_print_binary_exponent(t_ctx *ctx, t_conv *conv, int binary_exp)
{
	if (conv->identifier == 'a')
		pf_print_char(ctx, 'p');
	else if (conv->identifier == 'A')
		pf_print_char(ctx, 'P');
	if (binary_exp >= 0)
		pf_print_char(ctx, '+');
	else
		pf_print_char(ctx, '-');
	print_num(ctx, binary_exp);
}

static void	print_num(t_ctx *ctx, int num)
{
	unsigned int	n;

	n = num;
	if (num < 0)
		n = ~num + 1;
	if (n >= 10)
		print_num(ctx, n / 10);
	pf_print_char(ctx, "0123456789"[n % 10]);
}

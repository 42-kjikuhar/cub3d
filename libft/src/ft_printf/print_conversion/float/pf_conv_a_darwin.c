/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_a_darwin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 00:18:47 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 22:00:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "./float_internal.h"

static void	process_conv_a(t_ctx *ctx, t_conv *conv, t_pf_float *fp);
static void	normalize_hex(t_pf_float *fp);

void	pf_conv_a_binary64(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	double		num;
	t_pf_float	fp;

	if (conv->has_prec == false)
		conv->precision = PF_BINARY64_FRAC_HEX;
	num = va_arg(*ap, double);
	if (!pf_float_init(&fp, BINARY64_SIZE, 16))
	{
		ctx->has_error = true;
		return ;
	}
	pf_decode_binary64(num, &fp);
	process_conv_a(ctx, conv, &fp);
	pf_float_destroy(&fp);
}

static void	process_conv_a(t_ctx *ctx, t_conv *conv, t_pf_float *fp)
{
	if (fp->value_type == PF_INF)
	{
		pf_print_inf(ctx, conv, fp);
		return ;
	}
	if (fp->value_type == PF_NAN)
	{
		pf_print_nan(ctx, conv, fp);
		return ;
	}
	pf_convert_to_hex(fp);
	normalize_hex(fp);
	pf_round_to_nearest_even(fp, conv->precision);
	pf_print_conv_a(ctx, conv, fp);
}

static void	normalize_hex(t_pf_float *fp)
{
	if (fp->value_type == PF_SUBNORMAL)
	{
		while (fp->radix_point[0] < 8)
		{
			pf_array_double_hex(fp->radix_point, fp->print_frac_size);
			fp->exponent--;
		}
		pf_array_double_hex(fp->radix_point, fp->print_frac_size);
		fp->exponent--;
		fp->radix_point[-1] = 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_conv_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 22:09:41 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 22:19:02 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/pf_print_utils.h"
#include "./float_internal.h"

static size_t	get_length_fixed_point(t_conv *conv, t_pf_float *fp);
static void		print_fixed_point(t_ctx *ctx, t_conv *conv, t_pf_float *fp);

void	pf_print_conv_f(t_ctx *ctx, t_conv *conv, t_pf_float *fp)
{
	size_t	len;

	len = get_length_fixed_point(conv, fp);
	if (conv->width_flags == '\0')
		pf_print_space_width(ctx, conv, len);
	pf_print_sign(ctx, conv, fp->sign);
	if (conv->width_flags == '0')
		pf_print_zero_width(ctx, conv, len);
	print_fixed_point(ctx, conv, fp);
	if (conv->width_flags == '-')
		pf_print_space_width(ctx, conv, len);
}

static size_t	get_length_fixed_point(t_conv *conv, t_pf_float *fp)
{
	size_t	len;
	int		i;

	len = 0;
	if (fp->sign || (fp->sign == 0 && conv->sign_flags != '\0'))
		len += ft_strlen("-");
	if (fp->int_binary == 0)
		len += ft_strlen("0");
	else
	{
		i = 0;
		while (i < fp->print_int_size)
		{
			if (fp->print_buf[i] != 0)
			{
				len += fp->print_int_size - i;
				break ;
			}
			i++;
		}
	}
	if (!(conv->precision == 0 && conv->hash_flag != '#'))
		len += ft_strlen(".");
	len += conv->precision;
	return (len);
}

static void	print_fixed_point(t_ctx *ctx, t_conv *conv, t_pf_float *fp)
{
	int	i;

	i = 0;
	while (i < fp->print_int_size - 1 && fp->print_buf[i] == 0)
		i++;
	while (i < fp->print_int_size)
		pf_print_char(ctx, fp->print_buf[i++] + '0');
	if (conv->precision > 0 || conv->hash_flag == '#')
		pf_print_char(ctx, '.');
	while (conv->precision > 0 && i < fp->print_buf_size)
	{
		pf_print_char(ctx, fp->print_buf[i++] + '0');
		conv->precision--;
	}
	while (conv->precision > 0)
	{
		pf_print_char(ctx, '0');
		conv->precision--;
	}
}

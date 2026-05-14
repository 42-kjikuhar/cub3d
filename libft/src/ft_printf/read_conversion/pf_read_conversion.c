/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_read_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:27:23 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/01 19:03:10 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

static void	read_flags(const char **format, t_conv *conv);
static bool	read_width(\
				va_list *ap, const char **format, t_ctx *ctx, t_conv *conv);
static bool	read_precision(va_list *ap, const char **format, t_conv *conv);
static void	read_length(const char **format, t_conv *conv);

bool	pf_read_conversion(
	va_list *ap, const char **format, t_ctx *ctx, t_conv *conv)
{
	(*format)++;
	read_flags(format, conv);
	if (!read_width(ap, format, ctx, conv))
	{
		ctx->has_error = true;
		return (false);
	}
	if (!read_precision(ap, format, conv))
	{
		ctx->has_error = true;
		return (false);
	}
	read_length(format, conv);
	if (!ft_strchr(PF_CONV, **format))
		return (false);
	conv->identifier = **format;
	(*format)++;
	return (true);
}

static void	read_flags(const char **format, t_conv *conv)
{
	while (ft_strchr(PF_FLAGS, **format))
	{
		if (**format == '#')
			conv->hash_flag = '#';
		else if (**format == '+' || **format == ' ')
		{
			if (conv->sign_flags != '+')
				conv->sign_flags = **format;
		}
		else if (**format == '-' || **format == '0')
		{
			if (conv->width_flags != '-')
				conv->width_flags = **format;
		}
		(*format)++;
	}
}

static bool	read_width(\
				va_list *ap, const char **format, t_ctx *ctx, t_conv *conv)
{
	if (!(ft_isdigit(**format) || **format == '*'))
		return (true);
	if (ft_isdigit(**format))
	{
		if (pf_check_int_overflow(*format))
			return (false);
		conv->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		conv->width = va_arg(*ap, int);
		if (conv->width < 0)
		{
			conv->width_flags = '-';
			conv->width *= -1;
			if (conv->width < 0)
				return (false);
		}
		(*format)++;
	}
	if (PRINTF_RESULT_LIMIT - ctx->count < (size_t)conv->width)
		return (false);
	return (true);
}

static bool	read_precision(va_list *ap, const char **format, t_conv *conv)
{
	if (**format == '.')
	{
		conv->has_prec = true;
		(*format)++;
		if (**format == '*')
		{
			conv->precision = va_arg(*ap, int);
			(*format)++;
			if (conv->precision < 0)
			{
				conv->has_prec = false;
				conv->precision = 0;
			}
		}
		else if (ft_isdigit(**format))
		{
			if (pf_check_int_overflow(*format))
				return (false);
			conv->precision = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
	}
	return (true);
}

static void	read_length(const char **format, t_conv *conv)
{
	if (**format == 'h' || **format == 'l')
	{
		conv->length[0] = **format;
		conv->length[1] = '\0';
		(*format)++;
		if (**format == conv->length[0])
		{
			conv->length[1] = **format;
			conv->length[2] = '\0';
			(*format)++;
		}
	}
	else if (ft_strchr(PF_LENGTH, **format))
	{
		conv->length[0] = **format;
		conv->length[1] = '\0';
		(*format)++;
	}
}

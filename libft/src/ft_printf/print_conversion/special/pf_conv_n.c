/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:43:38 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/01 11:28:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	pf_conv_n(va_list *ap, t_ctx *ctx, t_conv *conv)
{
	if (!ft_strcmp(conv->length, "hh"))
		*(va_arg(*ap, signed char *)) = (signed char)ctx->count;
	else if (!ft_strcmp(conv->length, "h"))
		*(va_arg(*ap, signed short int *)) = (signed short int)ctx->count;
	else if (!ft_strcmp(conv->length, "l"))
		*(va_arg(*ap, long int *)) = (long int)ctx->count;
	else if (!ft_strcmp(conv->length, "ll"))
		*(va_arg(*ap, long long int *)) = (long long int)ctx->count;
	else if (!ft_strcmp(conv->length, "j"))
		*(va_arg(*ap, intmax_t *)) = (intmax_t)ctx->count;
	else if (!ft_strcmp(conv->length, "z"))
		*(va_arg(*ap, ssize_t *)) = (ssize_t)ctx->count;
	else if (!ft_strcmp(conv->length, "t"))
		*(va_arg(*ap, ptrdiff_t *)) = (ptrdiff_t)ctx->count;
	else
		*(va_arg(*ap, int *)) = (int)ctx->count;
}

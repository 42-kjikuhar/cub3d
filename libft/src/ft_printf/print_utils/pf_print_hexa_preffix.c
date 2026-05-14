/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_hexa_preffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:54:12 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/01 11:28:09 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	pf_print_hexa_preffix(t_ctx *ctx, t_conv *conv)
{
	if (ft_strchr("xpa", conv->identifier))
		pf_print_strn(ctx, "0x", 2);
	else if (ft_strchr("XA", conv->identifier))
		pf_print_strn(ctx, "0X", 2);
}

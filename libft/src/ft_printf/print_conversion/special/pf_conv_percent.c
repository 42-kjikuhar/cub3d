/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conv_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:44:58 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 21:41:14 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "ft_printf/pf_print_utils.h"

void	pf_conv_percent(t_ctx *ctx, t_conv *conv)
{
	(void)conv;
	pf_print_char(ctx, '%');
}

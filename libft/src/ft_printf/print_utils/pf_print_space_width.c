/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_space_width.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:58:44 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/01 12:40:24 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	pf_print_space_width(t_ctx *ctx, t_conv *conv, size_t len)
{
	if (conv->width <= 0 || (size_t)conv->width <= len)
		return ;
	pf_print_repeated_char(ctx, ' ', conv->width - len);
}

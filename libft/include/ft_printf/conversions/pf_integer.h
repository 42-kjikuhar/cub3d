/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_integer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:07:50 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/01 11:23:58 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_INTEGER_H
# define PF_INTEGER_H

# include <stdarg.h>

# include "ft_printf/pf_types.h"

void	pf_conv_d_i(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_u(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_x(va_list *ap, t_ctx *ctx, t_conv *conv);
void	pf_conv_o(va_list *ap, t_ctx *ctx, t_conv *conv);

#endif

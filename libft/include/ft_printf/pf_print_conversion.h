/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_conversion.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:24:17 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 22:06:32 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PRINT_CONVERSION_H
# define PF_PRINT_CONVERSION_H

# include <stdarg.h>

# include "ft_printf/pf_types.h"

void	pf_print_conversion(va_list *ap, t_ctx *ctx, t_conv *conv);

#endif

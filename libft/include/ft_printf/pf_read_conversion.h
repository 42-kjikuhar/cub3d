/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_read_conversion.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 01:27:20 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 21:22:37 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_READ_CONVERSION_H
# define PF_READ_CONVERSION_H

# include <stdarg.h>
# include <stdbool.h>

# include "ft_printf/pf_types.h"

bool	pf_read_conversion(\
			va_list *ap, const char **format, t_ctx *ctx, t_conv *conv);

#endif

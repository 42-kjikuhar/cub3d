/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:07:55 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/06 16:14:52 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPES_H
# define LIBFT_TYPES_H

#include <stdint.h>

union u_double
{
	double		value;
	uint64_t	bit;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:32:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/01 20:40:50 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <stdint.h>

double		ft_fabs(double x);
int			ft_rand_r(unsigned int *seed);
double		ft_round(double x);
double		ft_sqrt(double x);
uint32_t	ft_xorshift(uint32_t *seed);

#endif

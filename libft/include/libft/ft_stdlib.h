/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 < stanaka2@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:32:39 by stanaka2          #+#    #+#             */
/*   Updated: 2026/05/06 23:27:35 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>
# include <stdlib.h>

unsigned int	ft_abs_uint(int n);
unsigned long	ft_abs_ulong(long n);
int				ft_atoi(const char *nptr);
double			ft_atof(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_itoa(int n);
void			*ft_reallocf(void *ptr, size_t old_size, size_t new_size);

#endif

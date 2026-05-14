/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka2 <stanaka2@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:32:36 by stanaka2          #+#    #+#             */
/*   Updated: 2026/04/19 16:25:25 by stanaka2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <unistd.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
ssize_t	ft_putchar_fd_bytes(char c, int fd);
ssize_t	ft_putendl_fd_bytes(char *s, int fd);
ssize_t	ft_putnbr_fd_bytes(int n, int fd);
ssize_t	ft_putstr_fd_bytes(char *s, int fd);

#endif

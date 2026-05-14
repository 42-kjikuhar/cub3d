/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:08:07 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/14 13:20:33 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IVEC2_H
# define IVEC2_H

typedef struct s_ivec2
{
	int	x;
	int	y;
}			t_ivec2;


t_ivec2	ivec2_add(t_ivec2 a, t_ivec2 b);
t_ivec2	ivec2_sub(t_ivec2 a, t_ivec2 b);

#endif

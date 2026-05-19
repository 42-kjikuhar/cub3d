/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splitted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 21:36:01 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/19 21:41:33 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_splitted(char **words)
{
	int	i;

	if (words == NULL)
		return ;
	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
	}
	free(words);
}

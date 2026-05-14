/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:25:52 by kjikuhar          #+#    #+#             */
/*   Updated: 2026/05/14 15:49:01 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define SUCCESS 0
#define FAILURE 1

typedef struct s_cub3d
{

}				t_cub3d;

int main(int argc, char const *argv[])
{
	t_cub3d	sim;

	printf("Hello World!\n");
	if (parse_args(argc, argv, &sim) != SUCCESS)
		return (EXIT_FAILURE);
	if (parse_maps(&sim))
		return (EXIT_FAILURE);
	running_sim(&sim);
	free_simulation(&sim);
	return (0);
}

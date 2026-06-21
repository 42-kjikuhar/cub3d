/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjikuhar <kjikuhar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:50:32 by stanaka2          #+#    #+#             */
/*   Updated: 2026/06/21 20:09:23 by kjikuhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_rotate_left(t_player *player)
{
	player->dir = dvec3_rotate(player->dir, dvec3(0, 0, 1), 1);
	player->plane = dvec3_rotate(player->plane, dvec3(0, 0, 1), 1);
}

static void	player_rotate_right(t_player *player)
{
	player->dir = dvec3_rotate(player->dir, dvec3(0, 0, 1), -1);
	player->plane = dvec3_rotate(player->plane, dvec3(0, 0, 1), -1);
}

static bool	is_colliding_with_wall(t_dvec3 new_pos)
{
	int	left = 
}

static void	player_move_forward(t_player *player)
{
	t_dvec3	move;
	t_dvec3	new_pos;

	move = dvec3_scale(PLAYER_SPEED, player->dir);
	new_pos = dvec3_add(player->pos, move);
	if (is_colliding_with_wall(new_pos))
		return ;
	player->pos = new_pos;
}

static void	player_move_back(t_player *player)
{
	t_dvec3	move;

	move = dvec3_scale(-PLAYER_SPEED, player->dir);
	player->pos = dvec3_add(player->pos, move);
}

static void	player_move_left(t_player *player)
{
	t_dvec3	move;

	move = dvec3_scale(PLAYER_SPEED, dvec3_rotate(player->dir, dvec3(0, 0, 1), 90));
	player->pos = dvec3_add(player->pos, move);
}

static void	player_move_right(t_player *player)
{
	t_dvec3	move;

	move = dvec3_scale(PLAYER_SPEED, dvec3_rotate(player->dir, dvec3(0, 0, 1), -90));
	player->pos = dvec3_add(player->pos, move);
}

int	key_press_hook(int keycode, void *param)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)param;
	if (keycode == XK_Escape)
		mlx_loop_end(cub3d->mlx.mlx_ptr);
	if (keycode == XK_Left)
		player_rotate_left(&(cub3d->player));
	if (keycode == XK_Right)
		player_rotate_right(&(cub3d->player));
	if (keycode == XK_w)
		player_move_forward(&(cub3d->player));
	if (keycode == XK_a)
		player_move_left(&(cub3d->player));
	if (keycode == XK_s)
		player_move_back(&(cub3d->player));
	if (keycode == XK_d)
		player_move_right(&(cub3d->player));
	return (0);
}

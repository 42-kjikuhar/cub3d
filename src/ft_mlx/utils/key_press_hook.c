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

static bool	is_blocked_cell(t_map const *map, int x, int y)
{
	char	cell;

	if (y < 0 || y >= map->y_size || x < 0 || x >= map->x_size)
		return (true);
	cell = map->data[y][x];
	return (cell == MAP_WALL || cell == MAP_BLANK);
}

static bool	is_colliding_with_wall(t_map const *map, t_dvec3 new_pos)
{
	double const	corner_x[4] = {new_pos.x - PLAYER_OFFSET, \
		new_pos.x + PLAYER_OFFSET, new_pos.x - PLAYER_OFFSET, \
		new_pos.x + PLAYER_OFFSET};
	double const	corner_y[4] = {new_pos.y - PLAYER_OFFSET, \
		new_pos.y - PLAYER_OFFSET, new_pos.y + PLAYER_OFFSET, \
		new_pos.y + PLAYER_OFFSET};
	int				i;

	i = 0;
	while (i < 4)
	{
		if (is_blocked_cell(map, (int)floor(corner_x[i]), \
				(int)floor(corner_y[i])))
			return (true);
		++i;
	}
	return (false);
}

static void	try_move(t_player *player, t_map const *map, t_dvec3 move)
{
	t_dvec3	new_pos;

	new_pos = dvec3_add(player->pos, move);
	if (is_colliding_with_wall(map, new_pos))
		return ;
	player->pos = new_pos;
}

static void	player_move_forward(t_player *player, t_map const *map)
{
	try_move(player, map, dvec3_scale(PLAYER_SPEED, player->dir));
}

static void	player_move_back(t_player *player, t_map const *map)
{
	try_move(player, map, dvec3_scale(-PLAYER_SPEED, player->dir));
}

static void	player_move_left(t_player *player, t_map const *map)
{
	try_move(player, map, dvec3_scale(PLAYER_SPEED, \
		dvec3_rotate(player->dir, dvec3(0, 0, 1), 90)));
}

static void	player_move_right(t_player *player, t_map const *map)
{
	try_move(player, map, dvec3_scale(PLAYER_SPEED, \
		dvec3_rotate(player->dir, dvec3(0, 0, 1), -90)));
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
		player_move_forward(&(cub3d->player), &(cub3d->map));
	if (keycode == XK_a)
		player_move_left(&(cub3d->player), &(cub3d->map));
	if (keycode == XK_s)
		player_move_back(&(cub3d->player), &(cub3d->map));
	if (keycode == XK_d)
		player_move_right(&(cub3d->player), &(cub3d->map));
	return (0);
}

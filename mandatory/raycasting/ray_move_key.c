/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_move_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:27:47 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/09 23:48:52 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

char	ft_check_pos_p(t_graphic *s_grhc, int player_x, int player_y)
{
	double	distance;
	int		y;
	int		x;

	x = player_x - 2;
	while (x <= 2 + player_x)
	{
		y = (player_y - 2) - 1;
		while (y <= 2 + player_y)
		{
			distance = ((x - player_x) * (x - player_x))
				+ ((y - player_y) * (y - player_y));
			if (distance <= (M_PI * 2) * 2)
			{
				if (ft_check_walls(s_grhc, x, y) == 1)
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

static	void	ft_update_player(t_graphic *s_grhc, double x
					, double y, char key)
{
	if (key == 'A')
	{
		y -= cos(s_grhc->pa) * 3.5;
		x -= sin(s_grhc->pa) * 3.5;
	}
	if (ft_check_pos_p(s_grhc, x, y))
	{
		s_grhc->p_x = x;
		s_grhc->p_y = y;
	}
}

void	ft_move_key(t_graphic *s_grhc, char key)
{
	double	x;
	double	y;

	x = s_grhc->p_x;
	y = s_grhc->p_y;
	if (key == 'W')
	{
		y -= sin(s_grhc->pa) * 4.5;
		x += cos(s_grhc->pa) * 4.5;
	}
	else if (key == 'S')
	{
		y += sin(s_grhc->pa) * 4.5;
		x -= cos(s_grhc->pa) * 4.5;
	}
	else if (key == 'D')
	{
		y += cos(s_grhc->pa) * 4.5;
		x += sin(s_grhc->pa) * 4.5;
	}
	ft_update_player(s_grhc, x, y, key);
}

void	ft_update_angle(t_graphic *s_grhc)
{
	if (s_grhc->pa > 2 * M_PI)
		s_grhc->pa -= (2 * M_PI);
	else if (s_grhc->pa < 0)
		s_grhc->pa += (2 * M_PI);
}

void	ft_move_r_l(t_graphic *s_grhc, char key)
{
	if (key == 'R')
		s_grhc->pa -= 0.1;
	else
		s_grhc->pa += 0.1;
	ft_update_angle(s_grhc);
}

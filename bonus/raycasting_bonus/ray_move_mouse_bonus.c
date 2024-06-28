/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_move_mouse_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:40:44 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/10 03:30:28 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

static	void	right_mouse(t_graphic *s_grhc)
{
	s_grhc->pa += 0.060;
	ft_update_angle(s_grhc);
}

static	void	left_mouse(t_graphic *s_grhc)
{
	s_grhc->pa -= 0.060;
	ft_update_angle(s_grhc);
}

void	ft_update_pos_with_mose(t_graphic	*s_grhc)
{
	int32_t	tmp__x;
	int32_t	tmp__y;

	tmp__x = 0;
	tmp__y = 0;
	tmp__x = s_grhc->mouse_x;
	tmp__y = s_grhc->mouse_y;
	mlx_set_cursor_mode(s_grhc->mlx, MLX_MOUSE_HIDDEN);
	mlx_get_mouse_pos(s_grhc->mlx, &tmp__x, &tmp__y);
	if (tmp__x < s_grhc->mouse_x && tmp__x > 0
		&& tmp__x < WIDTH_WIN && tmp__y > 0 && tmp__y < HEIGHT_WIN)
	{
		s_grhc->mouse_x = tmp__x;
		s_grhc->mouse_y = tmp__y;
		right_mouse(s_grhc);
	}
	else if (tmp__x > s_grhc->mouse_x && tmp__x > 0
		&& tmp__x < WIDTH_WIN && tmp__y > 0 && tmp__y < HEIGHT_WIN)
	{
		s_grhc->mouse_x = tmp__x;
		s_grhc->mouse_y = tmp__y;
		left_mouse(s_grhc);
	}
}

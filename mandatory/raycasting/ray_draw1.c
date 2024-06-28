/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaghrous <yaghrous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:36:37 by yaghrous          #+#    #+#             */
/*   Updated: 2023/11/10 06:21:02 by yaghrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	ft_draw_ray(t_graphic *s_grhc, double x, double y)
{
	if (s_grhc->v_ou_h == 'h')
		mlx_put_pixel(s_grhc->mlx_img, x, y, 0xFF0000FF);
	else
		mlx_put_pixel(s_grhc->mlx_img, x, y, 0x00000000);
}

void	ft_img_p(t_graphic *s_grhc, int player_x, int player_y, int color)
{
	double	distance;
	int		y;
	int		x;

	x = player_x - 2;
	while (x <= 2 + player_x)
	{
		y = player_y - 2;
		while (y <= 2 + player_y)
		{
			distance = ((x - player_x) * (x - player_x))
				+ ((y - player_y) * (y - player_y));
			if (distance <= (M_PI * 2) * 2)
				mlx_put_pixel(s_grhc->mlx_img, x, y, color);
			y++;
		}
		x++;
	}
}

void	ft_draw_murs_vide(t_graphic *s_grhc, int x_pxl, int y_pxl, int color)
{
	int			y;
	int			x;

	x = x_pxl;
	while (x < (S_QUARE - 1) + x_pxl)
	{
		y = y_pxl;
		while (y < (S_QUARE - 1) + y_pxl)
			mlx_put_pixel(s_grhc->mlx_img, x, y++, color);
		mlx_put_pixel(s_grhc->mlx_img, x, y, 0x222);
		x++;
	}
}

void	ft_rayon(t_graphic *s_grhc)
{
	double	x;
	double	y;
	int		dx;
	int		dy;
	int		steps;

	dx = s_grhc->pdx - s_grhc->p_x;
	dy = s_grhc->pdy - s_grhc->p_y;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	s_grhc->x_incr = (double)dx / (double)steps;
	s_grhc->y_incr = (double)dy / (double)steps;
	x = s_grhc->p_x;
	y = s_grhc->p_y;
	while (--steps >= 0)
		ft_draw_ray(s_grhc, x += s_grhc->x_incr,
			y += s_grhc->y_incr);
}

void	ft_draw_s_f(t_graphic *s_grhc)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH_WIN)
	{
		y = -1;
		while (++y < HEIGHT_WIN)
		{
			if (y < HEIGHT_WIN / 2)
				mlx_put_pixel(s_grhc->mlx_img, x, y,
					create_trgb(20, ft_atoi(s_grhc->s_ele->c[0]),
						ft_atoi(s_grhc->s_ele->c[1]),
						ft_atoi(s_grhc->s_ele->c[2])));
			else
				mlx_put_pixel(s_grhc->mlx_img, x, y,
					create_trgb(20, ft_atoi(s_grhc->s_ele->f[0]),
						ft_atoi(s_grhc->s_ele->f[1]),
						ft_atoi(s_grhc->s_ele->f[2])));
		}
	}
}

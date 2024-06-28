/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:49:06 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/07 23:49:09 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	ft_check_walls(t_graphic *s_grhc, double x, double y)
{
	int	i;
	int	j;

	i = (y / S_QUARE);
	j = (x / S_QUARE);
	if ((i >= 0 && i < (s_grhc->s_ele->height_mp - 1))
		&& (j >= 0 && j < ft_lenght(s_grhc->s_ele->maps[i])))
	{
		if (s_grhc->s_ele->maps[i][j] == '1')
			return (1);
	}
	return (0);
}

static	double	ft_distance_vertical(t_graphic *s_grhc, int i)
{
	double		x_prime;
	double		y_prime;

	s_grhc->pdy_v = s_grhc->p_y - tan(s_grhc->pa)
		* (s_grhc->pdx_v - s_grhc->p_x);
	while (1)
	{
		y_prime = s_grhc->pdy_v;
		x_prime = s_grhc->pdx_v;
		if (!((s_grhc->pdy_v > 0 && s_grhc->pdy_v < HEIGHT_WIN)
				&& (s_grhc->pdx_v > 0 && s_grhc->pdx_v < WIDTH_WIN)))
			return (INT32_MAX);
		if (ft_check_walls(s_grhc, s_grhc->pdx_v + i, s_grhc->pdy_v) != 1)
		{
			x_prime = s_grhc->pdx_v + (S_QUARE) * i;
			y_prime = s_grhc->pdy_v - tan(s_grhc->pa)
				* (x_prime - s_grhc->pdx_v);
			s_grhc->pdy_v = y_prime;
			s_grhc->pdx_v = x_prime;
		}
		else
			break ;
	}
	return (sqrt(pow(s_grhc->pdx_v - s_grhc->p_x, 2)
			+ pow(s_grhc->pdy_v - s_grhc->p_y, 2)));
}

double	ft_vertical(t_graphic *s_grhc)
{
	int	i;

	if (s_grhc->pa > (M_PI / 2) && s_grhc->pa < ((3 * M_PI) / 2))
	{
		s_grhc->pdx_v = (((int)(s_grhc->p_x / S_QUARE)) * S_QUARE);
		i = -1;
	}
	else
	{
		s_grhc->pdx_v = (((int)(s_grhc->p_x / S_QUARE)) * S_QUARE + S_QUARE);
		i = 1;
	}
	return (ft_distance_vertical(s_grhc, i));
}

static	double	ft_distnace_horizontal(t_graphic *s_grhc, int i)
{
	double		x_prime;
	double		y_prime;

	s_grhc->pdx_h = s_grhc->p_x
		+ (s_grhc->p_y - s_grhc->pdy_h) / tan(s_grhc->pa);
	while (1)
	{
		y_prime = s_grhc->pdy_h;
		x_prime = s_grhc->pdx_h;
		if (!((s_grhc->pdx_h > 0 && s_grhc->pdx_h < WIDTH_WIN)
				&& (s_grhc->pdy_h > 0 && s_grhc->pdy_h < HEIGHT_WIN)))
			return (INT32_MAX);
		if (ft_check_walls(s_grhc, s_grhc->pdx_h, s_grhc->pdy_h + i) != 1)
		{
			y_prime = s_grhc->pdy_h + (S_QUARE * i);
			x_prime = s_grhc->pdx_h + ((s_grhc->pdy_h
						- y_prime) / tan(s_grhc->pa));
			s_grhc->pdy_h = y_prime ;
			s_grhc->pdx_h = x_prime ;
		}
		else
			break ;
	}
	return (sqrt(pow(s_grhc->pdx_h - s_grhc->p_x, 2)
			+ pow(s_grhc->pdy_h - s_grhc->p_y, 2)));
}

double	ft_horizontal(t_graphic *s_grhc)
{
	int	i;

	if (s_grhc->pa > 0 && s_grhc->pa < M_PI)
	{
		s_grhc->pdy_h = ((int)(s_grhc->p_y / S_QUARE)) * S_QUARE;
		i = -1;
	}
	else
	{
		s_grhc->pdy_h = ((int)(s_grhc->p_y / S_QUARE)) * S_QUARE + S_QUARE;
		i = 1;
	}
	return (ft_distnace_horizontal(s_grhc, i));
}

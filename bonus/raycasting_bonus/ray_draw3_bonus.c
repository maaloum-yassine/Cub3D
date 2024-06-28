/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:53:13 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/10 05:59:43 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

static void	ft_draw(t_graphic *s_grhc, char *sep)
{
	int	i;
	int	j;

	i = -1;
	while (s_grhc->s_ele->maps[++i])
	{
		j = -1;
		while (s_grhc->s_ele->maps[i][++j])
		{
			if (s_grhc->s_ele->maps[i][j] == '1'
				|| ft_check_sep(sep, s_grhc->s_ele->maps[i][j]) == 1)
				ft_draw_murs_vide(s_grhc, j * S_QUARE, i * S_QUARE, 191970);
			else
				ft_draw_murs_vide(s_grhc, j * S_QUARE, i * S_QUARE, 0xFFFFFFFF);
		}
	}
	ft_img_p(s_grhc, s_grhc->p_x, s_grhc->p_y, 0xFF0056);
}

void	ft_draw_mini_map(t_graphic *s_grhc, char *sep)
{
	double	angle;
	int		i;

	i = -1;
	ft_draw(s_grhc, sep);
	angle = s_grhc->pa;
	s_grhc->pa += (M_PI / 6);
	while (++i < WIDTH_WIN)
	{
		ft_update_angle(s_grhc);
		ft_pdx_pdy(s_grhc);
		ft_rayon(s_grhc);
		s_grhc->pa -= (M_PI / 3) / (WIDTH_WIN);
	}
	s_grhc->pa = angle;
}

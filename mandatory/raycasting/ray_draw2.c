/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaghrous <yaghrous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:13:04 by yaghrous          #+#    #+#             */
/*   Updated: 2023/11/10 06:21:15 by yaghrous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	ft_pdx_pdy(t_graphic *s_grhc)
{
	double	distance_h;
	double	distance_v;

	distance_h = ft_horizontal(s_grhc);
	distance_v = ft_vertical(s_grhc);
	if (distance_h < distance_v)
	{
		s_grhc->pdx = s_grhc->pdx_h;
		s_grhc->pdy = s_grhc->pdy_h;
		s_grhc->distance = distance_h;
		s_grhc->v_ou_h = 'h';
	}
	else
	{
		s_grhc->pdx = s_grhc->pdx_v;
		s_grhc->pdy = s_grhc->pdy_v;
		s_grhc->distance = distance_v;
		s_grhc->v_ou_h = 'v';
	}
}

static int	ft_value_img_x(t_graphic *s_grhc, t_texture	*head)
{
	if (head->status == 'N' || head->status == 'S')
		head->img_x = (s_grhc->pdx
				* head->s_img->width) / S_QUARE;
	else
		head->img_x = (s_grhc->pdy
				* head->s_img->width) / S_QUARE;
	return (head->img_x);
}

static	void	ft_put_png(t_graphic *s_grhc, int i, char status)
{
	t_texture		*head;
	unsigned int	index;
	unsigned int	color;
	unsigned int	max;

	head = s_grhc->s_texture;
	while (head)
	{
		if (head->status == status)
			break ;
		head = head->next;
	}
	head->img_x = ft_value_img_x(s_grhc, head);
	max = (head->s_img->height * head->s_img->width)
		* head->s_img->bytes_per_pixel;
	head->img_y = head->s_img->height - ((s_grhc->end - s_grhc->start)
			* head->s_img->height) / s_grhc->w_height;
	index = ((head->img_y * head->s_img->width) + head->img_x)
		* head->s_img->bytes_per_pixel;
	if (index >= max)
		return ;
	color = create_trgb(head->s_img->pixels[index],
			head->s_img->pixels[index + 1],
			head->s_img->pixels[index + 2], head->s_img->pixels[index + 3]);
	mlx_put_pixel(s_grhc->mlx_img, i, s_grhc->start, color);
}

static	void	ft_draw_inside_3d(t_graphic *s_grhc, int i)
{
	if (s_grhc->v_ou_h == 'h')
	{
		if (s_grhc->pa > 0 && s_grhc->pa < M_PI)
			ft_put_png(s_grhc, i, 'N');
		else
			ft_put_png(s_grhc, i, 'S');
	}
	else
	{
		if (s_grhc->pa > (M_PI / 2) && s_grhc->pa < (3 * M_PI) / 2)
			ft_put_png(s_grhc, i, 'W');
		else
			ft_put_png(s_grhc, i, 'E');
	}
}

void	ft_draw_3d(t_graphic *s_grhc, double angle, int i)
{
	double	d;

	d = (WIDTH_WIN / 2) / tan(M_PI / 6);
	s_grhc->distance = s_grhc->distance * cos(s_grhc->pa - angle);
	s_grhc->w_height = (S_QUARE * d) / s_grhc->distance;
	s_grhc->start = (HEIGHT_WIN / 2) - (s_grhc->w_height / 2);
	s_grhc->end = (HEIGHT_WIN / 2) + (s_grhc->w_height / 2);
	while (s_grhc->start < s_grhc->end)
	{
		if (s_grhc->start >= 0 && s_grhc->start < HEIGHT_WIN)
			ft_draw_inside_3d(s_grhc, i);
		s_grhc->start++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:36:39 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/10 05:24:51 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

void	ft_free_texture(t_graphic *s_grhc)
{
	t_texture	*head;
	t_texture	*next;

	head = s_grhc->s_texture;
	while (head)
	{
		if (head->s_img)
			mlx_delete_texture(head->s_img);
		next = head->next;
		free (head);
		head = next;
	}
}

unsigned	int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static	void	ft_check_load_img(t_data *s_dt, mlx_texture_t *img)
{
	if (!img)
		ft_print_err(s_dt,
			"Load texture check the path or format img 'png'! [^_^]\n");
}

static	void	ft_load_texture(t_data *s_dt)
{
	s_dt->s_grhc->s_texture->s_img = mlx_load_png(s_dt->s_ele_mp->no);
	ft_check_load_img(s_dt, s_dt->s_grhc->s_texture->s_img);
	s_dt->s_grhc->s_texture->status = 'N';
	s_dt->s_grhc->s_texture->next->s_img = mlx_load_png(s_dt->s_ele_mp->so);
	ft_check_load_img(s_dt, s_dt->s_grhc->s_texture->next->s_img);
	s_dt->s_grhc->s_texture->next->status = 'S';
	s_dt->s_grhc->s_texture->next->next->s_img
		= mlx_load_png(s_dt->s_ele_mp->we);
	ft_check_load_img(s_dt, s_dt->s_grhc->s_texture->next->next->s_img);
	s_dt->s_grhc->s_texture->next->next->status = 'W';
	s_dt->s_grhc->s_texture->next->next->next->s_img
		= mlx_load_png(s_dt->s_ele_mp->ea);
	ft_check_load_img(s_dt, s_dt->s_grhc->s_texture->next->next->next->s_img);
	s_dt->s_grhc->s_texture->next->next->next->status = 'E';
}

void	ft_initialize_texture(t_data *s_dt)
{
	s_dt->s_grhc->s_texture = malloc(sizeof(t_texture));
	ft_protect_malloc(s_dt, s_dt->s_grhc->s_texture);
	s_dt->s_grhc->s_texture->s_img = NULL;
	s_dt->s_grhc->s_texture->next = malloc(sizeof(t_texture));
	ft_protect_malloc(s_dt, s_dt->s_grhc->s_texture->next);
	s_dt->s_grhc->s_texture->next->s_img = NULL;
	s_dt->s_grhc->s_texture->next->next = malloc(sizeof(t_texture));
	ft_protect_malloc(s_dt, s_dt->s_grhc->s_texture->next->next);
	s_dt->s_grhc->s_texture->next->next->s_img = NULL;
	s_dt->s_grhc->s_texture->next->next->next = malloc(sizeof(t_texture));
	ft_protect_malloc(s_dt, s_dt->s_grhc->s_texture->next->next->next);
	s_dt->s_grhc->s_texture->next->next->next->s_img = NULL;
	s_dt->s_grhc->s_texture->next->next->next->next = NULL;
	ft_load_texture(s_dt);
}

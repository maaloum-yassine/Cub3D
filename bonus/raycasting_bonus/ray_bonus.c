/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:38:03 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/10 05:57:39 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"

void	ft_draw_angle(t_graphic *s_grhc, char *sep)
{
	double	angle;
	int		i;

	ft_draw_s_f(s_grhc);
	i = -1;
	angle = s_grhc->pa;
	s_grhc->pa += (M_PI / 6);
	while (++i < WIDTH_WIN)
	{
		ft_update_angle(s_grhc);
		ft_pdx_pdy(s_grhc);
		ft_draw_3d(s_grhc, angle, i);
		s_grhc->pa -= (M_PI / 3) / (WIDTH_WIN);
	}
	s_grhc->pa = angle;
	ft_draw_mini_map(s_grhc, sep);
}

void	ft_handler(void *param)
{
	t_data	*s_dt;

	s_dt = (t_data *)param;
	if (mlx_is_key_down(s_dt->s_grhc->mlx, MLX_KEY_RIGHT))
		ft_move_r_l(s_dt->s_grhc, 'R');
	else if (mlx_is_key_down(s_dt->s_grhc->mlx, MLX_KEY_LEFT))
		ft_move_r_l(s_dt->s_grhc, 'L');
	else if (mlx_is_key_down(s_dt->s_grhc->mlx, MLX_KEY_W))
		ft_move_key(s_dt->s_grhc, 'W');
	else if (mlx_is_key_down(s_dt->s_grhc->mlx, MLX_KEY_S))
		ft_move_key(s_dt->s_grhc, 'S');
	else if (mlx_is_key_down(s_dt->s_grhc->mlx, MLX_KEY_D))
		ft_move_key(s_dt->s_grhc, 'D');
	else if (mlx_is_key_down(s_dt->s_grhc->mlx, MLX_KEY_A))
		ft_move_key(s_dt->s_grhc, 'A');
	else if (mlx_is_key_down(s_dt->s_grhc->mlx, MLX_KEY_ESCAPE))
	{
		ft_release_memory(s_dt);
		exit(0);
	}
	ft_update_pos_with_mose(s_dt->s_grhc);
	ft_draw_angle(s_dt->s_grhc, s_dt->sep);
}

void	ft_creat_windw(t_data *s_dt)
{
	s_dt->s_grhc->mlx = mlx_init(WIDTH_WIN,
			HEIGHT_WIN, "cub3D", false);
	if (!s_dt->s_grhc->mlx)
		ft_print_err(s_dt, "'mlx_init' failure ![^_^]\n");
	s_dt->s_grhc->mlx_img = mlx_new_image(s_dt->s_grhc->mlx,
			WIDTH_WIN, HEIGHT_WIN);
	if (!s_dt->s_grhc->mlx_img)
		ft_print_err(s_dt, "'mlx_new_image' failed to allocate ![^_^]\n");
	s_dt->s_grhc->mlx_win_img = mlx_image_to_window(s_dt->s_grhc->mlx,
			s_dt->s_grhc->mlx_img, 0, 0);
	if (s_dt->s_grhc->mlx_win_img == -1)
		ft_print_err(s_dt, "'mlx_image_to_window' failure ![^_^]\n");
	ft_initialize_texture(s_dt);
}

void	ft_initialize_s_grhc(t_data	**s_dt)
{
	(*s_dt)->s_grhc = malloc(sizeof(t_graphic));
	ft_protect_malloc((*s_dt), (*s_dt)->s_grhc);
	(*s_dt)->s_grhc->s_ele = (*s_dt)->s_ele_mp;
	(*s_dt)->s_grhc->s_texture = NULL;
	(*s_dt)->s_grhc->mlx = NULL;
	(*s_dt)->s_grhc->mlx_img = NULL;
	(*s_dt)->s_grhc->mlx_win_img = -1;
	(*s_dt)->s_grhc->p_x = ((*s_dt)->s_ele_mp->col_p
			* S_QUARE) + S_QUARE / 2;
	(*s_dt)->s_grhc->p_y = ((*s_dt)->s_ele_mp->row_p
			* S_QUARE) + S_QUARE / 2;
	if ((*s_dt)->s_ele_mp->position == 'N')
		(*s_dt)->s_grhc->pa = M_PI / 2;
	else if ((*s_dt)->s_ele_mp->position == 'E')
		(*s_dt)->s_grhc->pa = 0;
	else if ((*s_dt)->s_ele_mp->position == 'S')
		(*s_dt)->s_grhc->pa = ((3 * M_PI) / 2);
	else
		(*s_dt)->s_grhc->pa = M_PI;
	(*s_dt)->s_grhc->mouse_x = 0;
	(*s_dt)->s_grhc->mouse_y = 0;
	ft_creat_windw((*s_dt));
}

void	ft_raycasting(t_data *s_dt)
{
	ft_initialize_s_grhc(&s_dt);
	mlx_loop_hook(s_dt->s_grhc->mlx, ft_handler, s_dt);
	mlx_loop(s_dt->s_grhc->mlx);
	mlx_terminate(s_dt->s_grhc->mlx);
}

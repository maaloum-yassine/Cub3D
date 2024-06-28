/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:38:22 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/10 05:42:24 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../cub3d.h"
# include <math.h>
# include <stdio.h>

# ifndef S_QUARE
#  define S_QUARE 20
# endif
# ifndef WIDTH_WIN
#  define WIDTH_WIN 1500
# endif

# ifndef HEIGHT_WIN
#  define HEIGHT_WIN 800
# endif

void						ft_update_angle(t_graphic *s_grhc);
void						ft_img_p(t_graphic *s_grhc,
								int player_x, int player_y, int color);
void						ft_rayon(t_graphic *s_grhc);
void						ft_draw_murs_vide(t_graphic *s_grhc, int x_pxl,
								int y_pxl, int color);
unsigned int				create_trgb(int t, int r, int g, int b);
void						ft_draw_s_f(t_graphic *s_grhc);
int							ft_check_walls(t_graphic *s_grhc,
								double x, double y);
void						ft_move_key(t_graphic *s_grhc, char key);
void						ft_move_r_l(t_graphic *s_grhc, char key);
double						ft_horizontal(t_graphic *s_grhc);
double						ft_vertical(t_graphic *s_grhc);
int							ft_check_walls(t_graphic *s_grhc,
								double x, double y);
void						ft_draw_3d(t_graphic *s_grhc, double angle, int i);
void						ft_pdx_pdy(t_graphic *s_grhc);
void						ft_initialize_texture(t_data *s_dt);
#endif

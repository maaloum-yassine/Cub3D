/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_err_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:47:15 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/10 05:06:26 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDL_ERR_BONUS_H
# define HANDL_ERR_BONUS_H
# include "../cub3d_bonus.h"

void		ft_check_line(t_data *s_dt);
void		ft_fill_ell(t_data *s_dt);
void		ft_validate_dr_cl(t_data *s_dt);
void		ft_validate_maps(t_data *s_dt, char *line);
char		ft_check_color(t_data *s_dt, char *color);
void		ft_fiil_struct(t_data *s_dt, char *arg, char c);
void		ft_upd_elem(t_data *s_dt, char c);
int			ft_cont_para_arg(char *color);
char		*ft_update_c(char *color);
char		ft_check_rgb(char **color_rgb);
char		ft_chck_fst_lst_ln(t_data *s_dt, char *line, char *sep);
int			ft_max_column(char **map);
void		ft_fill_pos_plyer(t_ele_map *s_el, int row, int col);
char		ft_chck_insnd(t_data *s_dt);
void		ft_fre_splt_prnt_err(t_data *s_dt, char **spt_l);
#endif

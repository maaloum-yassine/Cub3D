/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_err3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:42:46 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/10 03:33:30 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handl_err_bonus.h"

void	ft_fre_splt_prnt_err(t_data *s_dt, char **spt_l)
{
	ft_free_split(spt_l);
	ft_print_err(s_dt, "Check identifier for map ![^_^]\n");
}

static	char	**ft_fiil_struct3(t_data *s_dt, char *arg)
{
	char	**new_arg;

	new_arg = ft_split(arg);
	ft_protect_malloc(s_dt, arg);
	return (new_arg);
}

static	char	*ft_fiil_struct2(t_data *s_dt, char *arg)
{
	char	*new_arg;

	new_arg = ft_strdup(arg);
	ft_protect_malloc(s_dt, arg);
	return (new_arg);
}

void	ft_fiil_struct(t_data *s_dt, char *arg, char c)
{
	if (c == 'N')
		s_dt->s_ele_mp->no = ft_fiil_struct2(s_dt, arg);
	else if (c == 'S')
		s_dt->s_ele_mp->so = ft_fiil_struct2(s_dt, arg);
	else if (c == 'W')
		s_dt->s_ele_mp->we = ft_fiil_struct2(s_dt, arg);
	else if (c == 'E')
		s_dt->s_ele_mp->ea = ft_fiil_struct2(s_dt, arg);
	else if (c == 'F')
	{
		arg = ft_update_c(arg);
		s_dt->s_ele_mp->f = ft_fiil_struct3(s_dt, arg);
	}
	else if (c == 'C')
	{
		arg = ft_update_c(arg);
		s_dt->s_ele_mp->c = ft_fiil_struct3(s_dt, arg);
	}
	s_dt->size_ele--;
	ft_upd_elem(s_dt, c);
}

char	ft_check_color(t_data *s_dt, char *color)
{
	char	**color_rgb;

	if (ft_cont_para_arg(color) != 2)
		return (0);
	color = ft_update_c(color);
	if (ft_count_w(color, s_dt->sep) != 3)
		return (0);
	color_rgb = ft_split(color);
	if (ft_check_rgb(color_rgb) == 0)
	{
		ft_free_split(color_rgb);
		return (0);
	}
	ft_free_split(color_rgb);
	return (1);
}

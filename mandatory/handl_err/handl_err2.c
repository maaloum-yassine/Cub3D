/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_err2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:42:40 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/10/25 04:11:28 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handl_err.h"

static	void	ft_validate_dr_cl2(t_data *s_dt, char	**spt_l, int index)
{
	char	c;

	c = s_dt->element[index][0];
	if ((c == 'F' || c == 'C') && ft_check_color(s_dt, spt_l[1]) == 0)
	{
		ft_free_split(spt_l);
		ft_print_err(s_dt, "Check identifier 'color' for map ![^_^]\n");
	}
	ft_fiil_struct(s_dt, spt_l[1], c);
	ft_free_split(spt_l);
}

static	int	ft_find_index(char **element, char *str)
{
	int	i;

	i = -1;
	while (element[++i])
	{
		if (!ft_strcmp(element[i], str))
			return (i);
	}
	return (-1);
}

void	ft_validate_dr_cl(t_data *s_dt)
{
	char	**spt_l;
	int		index;

	if (s_dt->element[0])
	{
		if (ft_count_w(s_dt->line, s_dt->sep) != 2)
			ft_print_err(s_dt, "Check element for map ![^_^]\n");
		spt_l = ft_split(s_dt->line);
		index = ft_find_index(s_dt->element, spt_l[0]);
		if (index != -1)
			ft_validate_dr_cl2(s_dt, spt_l, index);
		else
			ft_fre_splt_prnt_err(s_dt, spt_l);
	}
	if (s_dt->element[0] == NULL)
	{
		s_dt->s_ele_mp->height_mp = 1;
		free (s_dt->line);
		free (s_dt->element);
		s_dt->element = NULL;
		s_dt->line = NULL;
		s_dt->check = 3;
	}
}

static	void	ft_initialize_s_ele_mp(t_ele_map **s_ele)
{
	(*s_ele)->maps = NULL;
	(*s_ele)->f = NULL;
	(*s_ele)->c = NULL;
	(*s_ele)->no = NULL;
	(*s_ele)->so = NULL;
	(*s_ele)->we = NULL;
	(*s_ele)->ea = NULL;
}

void	ft_fill_ell(t_data *s_dt)
{
	s_dt->size_ele = 7;
	s_dt->element = malloc(sizeof(char **) * s_dt->size_ele);
	ft_protect_malloc(s_dt, s_dt->element);
	s_dt->element[0] = ft_strdup("NO");
	ft_protect_malloc(s_dt, s_dt->element[0]);
	s_dt->element[1] = ft_strdup("SO");
	ft_protect_malloc(s_dt, s_dt->element[1]);
	s_dt->element[2] = ft_strdup("WE");
	ft_protect_malloc(s_dt, s_dt->element[2]);
	s_dt->element[3] = ft_strdup("EA");
	ft_protect_malloc(s_dt, s_dt->element[3]);
	s_dt->element[4] = ft_strdup("F");
	ft_protect_malloc(s_dt, s_dt->element[4]);
	s_dt->element[5] = ft_strdup("C");
	ft_protect_malloc(s_dt, s_dt->element[5]);
	s_dt->element[6] = NULL;
	s_dt->s_ele_mp = malloc(sizeof(t_ele_map));
	ft_protect_malloc(s_dt, s_dt->s_ele_mp);
	ft_initialize_s_ele_mp(&(s_dt->s_ele_mp));
}

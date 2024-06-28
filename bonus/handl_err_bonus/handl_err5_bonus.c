/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_err5_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:42:51 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/10 03:33:35 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handl_err_bonus.h"

static	char	ft_chck_components_mp(char *line, char *sep)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!(line[i] == '0' || line[i] == '1'
				|| line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W'
				|| ft_check_sep(sep, line[i])))
			return (0);
	}
	return (1);
}

static	void	ft_update_maps(t_data *s_dt, char *line)
{
	char	**new_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_chck_components_mp(line, s_dt->sep) == 0)
		ft_print_err(s_dt, "Composant pour la carte ![^_^]\n");
	new_map = malloc(sizeof(char **) * s_dt->s_ele_mp->height_mp);
	ft_protect_malloc(s_dt, new_map);
	while (s_dt->s_ele_mp->maps[i])
	{
		new_map[j++] = ft_strdup(s_dt->s_ele_mp->maps[i++]);
		ft_protect_malloc(s_dt, new_map[j - 1]);
	}
	new_map[j++] = ft_strdup(line);
	ft_protect_malloc(s_dt, new_map[j - 1]);
	new_map[j] = NULL;
	ft_free_split(s_dt->s_ele_mp->maps);
	s_dt->s_ele_mp->maps = new_map;
}

char	ft_chck_fst_lst_ln(t_data *s_dt, char *line, char *sep)
{
	char	*tmp;
	int		i;

	tmp = ft_strtrim(line, sep);
	ft_protect_malloc(s_dt, tmp);
	i = 0;
	if (tmp[0] != '1' || tmp[ft_lenght(tmp) -1] != '1')
	{
		free (tmp);
		return (0);
	}
	while (tmp[++i])
	{
		if (tmp[i] != '1' && ft_check_sep(sep, tmp[i]) == 0)
		{
			free (tmp);
			return (0);
		}
	}
	free (tmp);
	return (1);
}

void	ft_validate_maps(t_data *s_dt, char *line)
{
	char	*tmp;

	if (s_dt->s_ele_mp->height_mp == 2)
	{
		if (ft_chck_fst_lst_ln(s_dt, line, s_dt->sep) == 0)
			ft_print_err(s_dt, "Border for  map must be '1'! [^_^]\n");
		s_dt->s_ele_mp->maps = malloc(8 * s_dt->s_ele_mp->height_mp);
		ft_protect_malloc(s_dt, s_dt->s_ele_mp->maps);
		s_dt->s_ele_mp->maps[0] = ft_strdup(line);
		ft_protect_malloc(s_dt, s_dt->s_ele_mp->maps[0]);
		s_dt->s_ele_mp->maps[1] = NULL;
	}
	else
	{
		tmp = ft_strtrim(line, s_dt->sep);
		ft_protect_malloc(s_dt, tmp);
		if (tmp[0] != '1' || tmp[ft_lenght(tmp) - 1] != '1')
		{
			free (tmp);
			ft_print_err(s_dt, "Border for  map must be '1'! [^_^]\n");
		}
		else
			ft_update_maps(s_dt, line);
		free (tmp);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_err6_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:42:54 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/10 03:33:39 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handl_err_bonus.h"

static	void	ft_fill(t_chck_path *s__pth, char *target, int row, int col)
{
	if (row < 0 || col >= ft_lenght(s__pth->cpy_mp[row])
		|| s__pth->cpy_mp[row][col] == 'P' || s__pth->cpy_mp[row][col] == '1'
			)
		return ;
	else if (s__pth->cpy_mp[row][col] == '-'
				|| ft_check_sep(s__pth->tmp_sep, s__pth->cpy_mp[row][col]) == 1)
	{
		*target = 0;
		return ;
	}
	else if (s__pth->cpy_mp[row][col] == '0')
		s__pth->cpy_mp[row][col] = 'P';
	ft_fill(s__pth, target, row - 1, col);
	ft_fill(s__pth, target, row + 1, col);
	ft_fill(s__pth, target, row, col - 1);
	ft_fill(s__pth, target, row, col + 1);
}

static	void	ft_initialize_cp_mp(t_data *s_dt, int max_size)
{
	int	i;

	i = -1;
	s_dt->s_ele_mp->s_shk_pth->cpy_mp = malloc(sizeof(char **)
			* s_dt->s_ele_mp->height_mp);
	ft_protect_malloc(s_dt, s_dt->s_ele_mp->s_shk_pth->cpy_mp);
	while (++i < s_dt->s_ele_mp->height_mp - 1)
	{
		s_dt->s_ele_mp->s_shk_pth->cpy_mp[i]
			= malloc(sizeof(char) * max_size + 1);
		ft_protect_malloc(s_dt, s_dt->s_ele_mp->s_shk_pth->cpy_mp[i]);
	}
	s_dt->s_ele_mp->s_shk_pth->cpy_mp[i] = NULL;
}

static	void	ft_fill_cpy_mp(t_data *s_dt, int max_size)
{
	int	j;
	int	x;
	int	i;

	j = -1;
	i = -1;
	while (s_dt->s_ele_mp->maps[++i])
	{
		j = -1;
		x = 0;
		while (s_dt->s_ele_mp->maps[i][++j])
		{
			if (ft_check_sep(s_dt->s_ele_mp->s_shk_pth->tmp_sep,
					s_dt->s_ele_mp->maps[i][j]) == 1)
				s_dt->s_ele_mp->s_shk_pth->cpy_mp[i][x++] = '-';
			else
				s_dt->s_ele_mp->s_shk_pth->cpy_mp[i][x++]
					= s_dt->s_ele_mp->maps[i][j];
		}
		while (x <= max_size - 1)
			s_dt->s_ele_mp->s_shk_pth->cpy_mp[i][x++] = '-';
		s_dt->s_ele_mp->s_shk_pth->cpy_mp[i][x] = '\0';
	}
}

static	char	ft_ch_path(t_data *s_dt)
{
	int		i;
	char	target;

	i = -1;
	target = 1;
	s_dt->s_ele_mp->s_shk_pth = malloc(sizeof(t_ele_map));
	ft_protect_malloc(s_dt, s_dt->s_ele_mp->s_shk_pth);
	s_dt->s_ele_mp->s_shk_pth->tmp_sep = s_dt->sep;
	s_dt->s_ele_mp->width_mp = ft_max_column(s_dt->s_ele_mp->maps);
	ft_initialize_cp_mp(s_dt, s_dt->s_ele_mp->width_mp);
	ft_fill_cpy_mp(s_dt, s_dt->s_ele_mp->width_mp);
	ft_fill(s_dt->s_ele_mp->s_shk_pth, &target,
		s_dt->s_ele_mp->row_p, s_dt->s_ele_mp->col_p);
	ft_free_split(s_dt->s_ele_mp->s_shk_pth->cpy_mp);
	free (s_dt->s_ele_mp->s_shk_pth);
	return (target);
}

char	ft_chck_insnd(t_data *s_dt)
{
	int		col;
	int		row;

	s_dt->s_ele_mp->position = -1;
	row = 0;
	while (s_dt->s_ele_mp->maps[++row])
	{
		col = 0;
		while (s_dt->s_ele_mp->maps[row][++col])
		{
			if (s_dt->s_ele_mp->maps[row][col] == 'N'
				|| s_dt->s_ele_mp->maps[row][col] == 'S'
				|| s_dt->s_ele_mp->maps[row][col] == 'E'
				|| s_dt->s_ele_mp->maps[row][col] == 'W')
			{
				if (s_dt->s_ele_mp->position == -1)
					ft_fill_pos_plyer(s_dt->s_ele_mp, row, col);
				else
					return (2);
			}
		}
	}
	if (s_dt->s_ele_mp->position == -1)
		return (2);
	return (ft_ch_path(s_dt));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_err1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:50:53 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/10/25 04:58:46 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handl_err.h"

static	void	ft_check_element(t_data *s_dt)
{
	if (s_dt->line[0] == '\0')
	{
		if (s_dt->check == 4)
			ft_print_err(s_dt, "The card must not contain newline! [^_^]\n");
		return ;
	}
	if (s_dt->check == 1)
	{
		s_dt->empty = 1;
		ft_fill_ell(s_dt);
		s_dt->check = 2;
	}
	if (s_dt->check == 2)
		ft_validate_dr_cl(s_dt);
	if (s_dt->check > 2 && s_dt->line)
	{
		s_dt->check = 4;
		s_dt->s_ele_mp->height_mp++;
		ft_validate_maps(s_dt, s_dt->line);
	}
}

static	char	*ft_trim_and_sub(t_data *s_dt)
{
	char	*new_line;
	char	*tmp;

	ft_check_line(s_dt);
	if (s_dt->check <= 2)
	{
		new_line = ft_strtrim(s_dt->line, s_dt->sep);
		ft_protect_malloc(s_dt, new_line);
		tmp = new_line;
		new_line = ft_substr(new_line, 0, ft_index_nw_ln(new_line) - 1);
		ft_protect_malloc(s_dt, new_line);
		free (tmp);
	}
	else
	{
		new_line = ft_substr(s_dt->line, 0, ft_index_nw_ln(s_dt->line) - 1);
		ft_protect_malloc(s_dt, new_line);
	}
	return (new_line);
}

static	void	ft_check_maps2(t_data *s_dt)
{
	if (s_dt->empty == 0)
		ft_print_err(s_dt, "File maps is empty! [^_^]\n");
	else if (s_dt->check == 2 || s_dt->check == 3)
		ft_print_err(s_dt, "The elements for the map are not complete! [^_^]\n");
	else if (s_dt->check == 4)
	{
		if (ft_chck_fst_lst_ln(s_dt,
				s_dt->s_ele_mp->maps[s_dt->s_ele_mp->height_mp - 2],
				s_dt->sep) == 0)
			ft_print_err(s_dt, "Border for  map must be '1'! [^_^]\n");
		s_dt->check = ft_chck_insnd(s_dt);
		if (s_dt->check == 0)
			ft_print_err(s_dt,
				"The path in the map is invalid check empty space! [^_^]\n");
		else if (s_dt->check == 2)
			ft_print_err(s_dt,
				"The map contains a single position for player [^_^]\n");
	}
	close(s_dt->fd);
}

static	void	ft_check_maps(t_data *s_dt)
{
	char	*new_line;

	s_dt->line = NULL;
	s_dt->empty = 0;
	s_dt->check = 1;
	s_dt->sep = ft_separator();
	while (1)
	{
		s_dt->line = get_next_line(s_dt->fd);
		if (s_dt->line != NULL)
		{
			new_line = ft_trim_and_sub(s_dt);
			free (s_dt->line);
			s_dt->line = new_line;
			ft_check_element(s_dt);
			free (s_dt->line);
		}
		else
			break ;
	}
	ft_check_maps2(s_dt);
}

void	ft_handl_err(t_data *s_dt)
{
	char			*tmp;
	unsigned int	len;

	len = ft_lenght(s_dt->path_mp);
	tmp = s_dt->path_mp + len - 4;
	if (len < 4 || ft_strcmp(tmp, ".cub") != 0)
		ft_print_err(s_dt, "format file invalid! [^_^]\n");
	s_dt->fd = open(s_dt->path_mp, O_RDONLY);
	if (s_dt->fd == -1)
		ft_print_err(s_dt,
			"openfile , check the path or name of the file! [^_^]\n");
	else
		ft_check_maps(s_dt);
}

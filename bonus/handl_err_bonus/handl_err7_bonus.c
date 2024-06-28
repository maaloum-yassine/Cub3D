/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_err7_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:26:04 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/10 03:33:41 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handl_err_bonus.h"

void	ft_check_line(t_data *s_dt)
{
	char	*new_line;

	if (s_dt->line[0] != '\n')
	{
		new_line = ft_strtrim(s_dt->line, s_dt->sep);
		if (new_line[0] == '\n')
		{
			free (new_line);
			ft_print_err(s_dt,
				"in file map you have a line take separator delete it! [^_^]\n");
		}
		free (new_line);
	}
}

void	ft_fill_pos_plyer(t_ele_map *s_el, int row, int col)
{
	s_el->position = s_el->maps[row][col];
	s_el->col_p = col;
	s_el->row_p = row;
}

int	ft_max_column(char **map)
{
	int	max;
	int	size;
	int	i;

	i = -1;
	max = ft_lenght(map[0]);
	while (map[++i])
	{
		size = ft_lenght(map[i]);
		if (max < size)
			max = size;
	}
	return (max);
}

void	ft_protect_malloc(t_data *s_dt, void *ptr)
{
	if (!ptr)
		ft_print_err(s_dt, "Dynamic allocation of the memoir ![^_^]\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_err4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:42:48 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/10/22 17:43:03 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handl_err.h"

char	ft_check_rgb(char **color_rgb)
{
	int	i;

	i = -1;
	while (color_rgb[++i])
	{
		if (ft_is_digit(color_rgb[i]) == 0)
			return (0);
		else if (!(ft_atoi(color_rgb[i]) >= 0 && ft_atoi(color_rgb[i]) <= 255))
			return (0);
	}
	return (1);
}

char	*ft_update_c(char *color)
{
	int	i;

	i = -1;
	while (color[++i])
	{
		if (color[i] == ',' || color[i] == '\n')
			color[i] = ' ';
	}
	return (color);
}

int	ft_cont_para_arg(char *color)
{
	int	cont;
	int	i;

	cont = 0;
	i = -1;
	while (color[++i])
	{
		if (color[i] == ',' )
			cont++;
	}
	return (cont);
}

void	ft_upd_elem(t_data *s_dt, char c)
{
	char	**new_ele;
	int		i;
	int		j;

	j = 0;
	i = 0;
	new_ele = malloc (sizeof(char **) * s_dt->size_ele);
	ft_protect_malloc(s_dt, new_ele);
	while (s_dt->element[i])
	{
		if (c != s_dt->element[i][0])
		{
			new_ele[j++] = ft_strdup(s_dt->element[i++]);
			ft_protect_malloc(s_dt, new_ele[j - 1]);
		}
		else
			i++;
	}
	new_ele[j] = NULL;
	ft_free_split(s_dt->element);
	s_dt->element = new_ele;
}

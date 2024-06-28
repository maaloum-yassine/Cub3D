/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:12:28 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/10/24 09:11:03 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_cub3d.h"

int	ft_index_nw_ln(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i++] == '\n')
			return (i);
	}
	return (i);
}

char	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i])
	{
		while (str[i])
		{
			if (str[i] < '0' || str[i] > '9')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

unsigned int	ft_atoi(char *str)
{
	int						i;
	int						s;
	unsigned int			nb;

	i = 0;
	nb = 0;
	s = 1;
	if (str[i] == '-')
	{
		s *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (s * nb);
}

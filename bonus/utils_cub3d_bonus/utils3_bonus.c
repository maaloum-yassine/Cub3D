/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:38:13 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/10 03:23:49 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_cub3d_bonus.h"

int	ft_check_sep(char *sep, char c)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i++] == c)
			return (1);
	}
	return (0);
}

int	ft_count_w(char *str, char *sep)
{
	int	lenght_word;
	int	check;
	int	i;

	i = 0;
	lenght_word = 0;
	check = 0;
	while (str[i])
	{
		while (str[i] && (ft_check_sep(sep, str[i]) == 1))
			i++;
		while (str[i] && (ft_check_sep(sep, str[i]) == 0))
		{
			i++;
			check = 1;
		}
		if (check == 1)
		{
			check = 0;
			lenght_word++;
		}
	}
	return (lenght_word);
}

char	*ft_separator(void)
{
	char	*sep;

	sep = malloc(6);
	sep[0] = 9;
	sep[1] = 11;
	sep[2] = 12;
	sep[3] = 13;
	sep[4] = 32;
	sep[5] = '\0';
	return (sep);
}

char	**ft_split(char *str)
{
	char	**s;
	int		i;
	int		j;
	int		index;
	char	*sep;

	sep = ft_separator();
	i = 0;
	j = 0;
	index = 0;
	s = malloc (sizeof(char *) * (ft_count_w(str, sep) + 1));
	if (!s)
		return (NULL);
	while (str[i])
	{
		while ((ft_check_sep(sep, str[j]) == 1) && str[j])
			j++;
		i = j;
		while ((ft_check_sep(sep, str[j]) == 0) && str[j])
			j++;
		if (i != j)
			s[index++] = ft_substr(str, i, j - i);
	}
	s[index] = NULL;
	return (free (sep), s);
}

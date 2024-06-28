/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 02:36:18 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/11/10 03:24:08 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_cub3d_bonus.h"

int	ft_lenght(char *str)
{
	int	lenght;

	lenght = 0;
	while (str[lenght])
		lenght++;
	return (lenght);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	index;

	index = 0;
	while (str1[index] && str2[index] && str1[index] - str2[index] == 0)
		index++;
	return (str1[index] - str2[index]);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;
	int		length;

	if (!s1)
		return (NULL);
	length = ft_lenght(s1);
	i = 0;
	str = malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

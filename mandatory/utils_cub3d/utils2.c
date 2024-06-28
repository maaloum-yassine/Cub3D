/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:55:01 by ymaaloum          #+#    #+#             */
/*   Updated: 2023/10/24 09:07:58 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_cub3d.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == ((char)c))
			return ((char *)s);
		s++;
	}
	if (((char)c) == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*str;
	char	*tmp;
	int		i;
	int		len;

	if (!s1 || !set || s1[0] == '\0')
		return (NULL);
	len = ft_lenght(s1);
	i = 0;
	tmp = (char *)set;
	while (s1[i] && ft_strchr(tmp, s1[i]) != NULL )
	{
		tmp = set;
		i++;
	}
	tmp = set;
	while (len > 0 && ft_strchr(tmp, s1[len -1]) != NULL)
	{
		tmp = set;
		len --;
	}
	if (len - i <= 0)
		return (ft_strdup(""));
	str = ft_substr(s1, i, len - i);
	return (str);
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
			free (str[i++]);
		free (str);
	}
}

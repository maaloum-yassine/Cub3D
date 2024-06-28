/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cub3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 03:41:16 by ymaaloum          #+#    #+#             */
/*   Updated: 2024/06/28 10:37:40 by ymaaloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_CUB3D_H
# define UTILS_CUB3D_H
# include "../../get_next_line/get_next_line.h"

int				ft_lenght(char *str);
int				ft_strcmp(char *str1, char *str2);
int				ft_strncmp(char *s1, char *s2, int n);
void			ft_free_split(char **str);
char			*ft_strdup(char *s1);
unsigned int	ft_atoi(char *str);
char			ft_is_digit(char *str);
char			*ft_strtrim(char *s1, char *set);
int				ft_check_sep(char *sep, char c);
int				ft_count_w(char *str, char *sep);
char			**ft_split(char *str);
char			*ft_separator(void);
int				ft_index_nw_ln(char *line);
#endif

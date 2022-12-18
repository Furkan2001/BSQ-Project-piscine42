/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aekinci <aekinci@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:57:14 by aekinci           #+#    #+#             */
/*   Updated: 2022/08/11 17:14:29 by aekinci          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct info_map
{
	int		line;
	int		clm;
	char	dot;
	char	full;
	char	obs;
}	t_map;
void	ft_putstr(char *str, int q);
int		ft_strlen(char *str);
void	map(void);
int		ft_open_file(char *file);
int		calc_digit(char *file);
char	*which_line(char *file, int count, t_map my_map);
int		count_top(char *file);
int		find_length_width(t_map *my_map, char *file);
char	**fill_array(t_map my_map, char *file, int j);
int		count_top_2(char *file);
char	check_o(int q, char *file);
int		check_all(char **arr, int *brr, int side, char *file);
void	print_all(char **arr, int line, int clm);
int		fill_full(char ***arr, int *brr, int nb, char *file);
int		search_square(char ***arr, t_map my_map, char *file);
int		len_check(t_map my_map, char *file);
int		line_check(t_map my_map);
int		char_check(t_map my_map, char *file, char **arr);
int		top_check(t_map my_map);
int		map_check(t_map my_map, char *file);

#endif

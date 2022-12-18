/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aekinci <aekinci@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:55:34 by aekinci           #+#    #+#             */
/*   Updated: 2022/08/11 17:30:40 by aekinci          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**fill_array(t_map my_map, char *file, int j)
{
	char	**arr;
	int		i;
	int		a;
	char	random;

	a = ft_open_file(file);
	if (count_top(file) == 0)
		return (0);
	while (j++ <= count_top(file))
		read(a, &random, 1);
	arr = (char **) malloc(sizeof(char *) * my_map.line);
	i = -1;
	while (++i < my_map.line)
		arr[i] = (char *) malloc(sizeof(char) * my_map.clm);
	i = -1;
	while (++i < my_map.line)
	{
		j = -1;
		while (++j < my_map.clm)
			read(a, &arr[i][j], 1);
		read(a, &random, 1);
	}
	close(a);
	return (arr);
}

int	top_check(t_map my_map)
{
	char	a;
	char	b;
	char	c;

	a = my_map.dot;
	b = my_map.full;
	c = my_map.obs;
	if ((a == b) || (a == c) || (b == c))
		return (0);
	if ((a < 32 || a > 126) || (b < 32 || b > 126) || (c < 32 || c > 126))
		return (0);
	return (1);
}

int	len_check(t_map my_map, char *file)
{
	int	i;
	int	c;

	i = 1;
	c = ft_strlen(which_line(file, i, my_map));
	if (c == 0)
		return (0);
	while (i <= my_map.line)
	{
		if (ft_strlen(which_line(file, i, my_map)) != c)
			return (0);
		i++;
	}
	return (1);
}

int	line_check(t_map my_map)
{
	if (my_map.line < 1)
		return (0);
	return (1);
}

int	map_check(t_map my_map, char *file)
{
	char	**arr;
	int		j;

	j = 0;
	if (line_check(my_map) == 0)
		return (0);
	if (len_check(my_map, file) == 0)
		return (0);
	if (top_check(my_map) == 0)
		return (0);
	arr = fill_array(my_map, file, j);
	if (arr == 0)
		return (0);
	if (char_check(my_map, file, arr) == 0)
		return (0);
	search_square(&arr, my_map, file);
	print_all(arr, my_map.line, my_map.clm);
	return (1);
}

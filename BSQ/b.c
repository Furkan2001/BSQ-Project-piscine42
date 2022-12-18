/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aekinci <aekinci@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:19:05 by aekinci           #+#    #+#             */
/*   Updated: 2022/08/11 18:21:47 by aekinci          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_top_2(char *file)
{
	int		count;
	char	c;
	int		a;

	a = ft_open_file(file);
	count = 0;
	while (1)
	{
		read(a, &c, 1);
		if (c == '\n')
			break ;
		else
			count++;
	}
	close (a);
	return (count);
}

int	fill_full(char ***arr, int *brr, int nb, char *file)
{
	int		x;
	int		y;
	char	c;

	c = check_o(0, file);
	x = brr[0];
	while (x < nb + brr[0])
	{
		y = brr[1];
		while (y < nb + brr[1])
		{
			arr[0][x][y] = c;
			y++;
		}
		x++;
	}
	return (1);
}

int	search_square(char ***arr, t_map my_map, char *file)
{
	int	side;
	int	brr[2];

	if (my_map.line > my_map.clm)
		side = my_map.clm;
	else
		side = my_map.line;
	while (side > 0)
	{
		brr[0] = -1;
		while (++brr[0] <= my_map.line - side)
		{
			brr[1] = -1;
			while (++brr[1] <= my_map.clm - side)
				if (check_all(*arr, brr, side, file) == 1)
					if (fill_full(arr, brr, side, file) == 1)
						return (1);
		}
		side--;
	}
	return (0);
}

int	char_check(t_map my_map, char *file, char **arr)
{
	int	i;
	int	j;

	if (ft_strlen(which_line(file, 0, my_map)) != (3 + calc_digit(file)))
		return (0);
	i = -1;
	while (++i < my_map.line)
	{
		j = -1;
		while (++j < my_map.clm)
			if (arr[i][j] != my_map.obs &&
					arr[i][j] != my_map.full &&
					arr[i][j] != my_map.dot)
				return (0);
	}
	return (1);
}

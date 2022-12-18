/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aekinci <aekinci@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:59:43 by aekinci           #+#    #+#             */
/*   Updated: 2022/08/11 18:13:05 by aekinci          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_top(char *file)
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
	if (count - calc_digit(file) != 3)
		return (0);
	close (a);
	return (count);
}

int	find_length_width(t_map *my_map, char *file)
{
	int		a;
	int		i;
	char	z;

	my_map->line = 0;
	a = ft_open_file(file);
	while (1)
	{
		read(a, &my_map->dot, 1);
		if (!(my_map->dot >= '0' && my_map->dot <= '9'))
			break ;
		my_map->line *= 10;
		my_map->line = my_map->line + (my_map->dot - '0');
	}
	read(a, &my_map->obs, 1);
	read(a, &my_map->full, 1);
	read(a, &z, 1);
	z = 0;
	i = -1;
	while (z != '\n' && i++ > -100 && read(a, &z, 1))
	{
	}
	close (a);
	return (i);
}

char	check_o(int q, char *file)
{
	int		a;
	int		i;
	char	c;
	int		count;

	count = count_top_2(file);
	i = 0;
	a = ft_open_file(file);
	if (q == 1)
	{
		while (i++ < count - 1)
			read(a, &c, 1);
	}
	else
	{
		while (i < count)
		{
			read(a, &c, 1);
			i++;
		}
	}
	close(a);
	return (c);
}

int	check_all(char **arr, int *brr, int side, char *file)
{
	int	a;
	int	b;

	a = brr[0];
	while (a < side + brr[0])
	{
		b = brr[1];
		while (b < side + brr[1])
		{
			if (arr[a][b] == check_o(1, file))
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

void	print_all(char **arr, int line, int clm)
{
	int	i;
	int	j;

	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < clm)
		{
			write(1, &arr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aekinci <aekinci@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:34:51 by aekinci           #+#    #+#             */
/*   Updated: 2022/08/11 17:56:00 by aekinci          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(char *str, int q)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(q, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int		count;

	count = 0;
	if (str == 0)
		return (0);
	while (str[count] != '\n')
	{
		count++;
	}
	return (count);
}

int	ft_open_file(char *file)
{
	int		a;

	a = open(file, O_RDONLY);
	if (a == -1)
	{
		ft_putstr("Can not open file\n", 2);
		exit (0);
	}
	return (a);
}

int	calc_digit(char *file)
{
	int		count;
	char	c;
	int		a;

	a = ft_open_file(file);
	count = 0;
	while (1)
	{
		read(a, &c, 1);
		if (!(c >= '0' && c <= '9'))
			break ;
		count++;
	}
	return (count);
}

char	*which_line(char *file, int count, t_map my_map)
{
	int		a;
	int		r;
	int		i;
	int		j;
	char	*c;

	j = 0;
	a = ft_open_file(file);
	c = (char *) malloc(sizeof(char) * my_map.clm);
	while (j <= count)
	{
		i = 0;
		r = read(a, &c[i], 1);
		while (c[i] != '\n')
		{
			if ((++i > my_map.clm && j != 0) || ((r == 0) && (j != 0)))
				return (0);
			r = read(a, &c[i], 1);
		}
		if (j != count)
			c[i] = '\0';
		j++;
	}
	close(a);
	return (c);
}

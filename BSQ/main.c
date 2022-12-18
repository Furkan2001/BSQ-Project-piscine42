/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aekinci <aekinci@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:15:52 by aekinci           #+#    #+#             */
/*   Updated: 2022/08/11 18:22:29 by aekinci          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	map(void)
{	
	write(2, "map error\n", 10);
}

int	main(int argc, char **argv)
{
	t_map	my_map;
	int		c;
	char	*file;
	int		i;

	i = 1;
	if (argc == 1)
	{
		file = "file.txt";
		my_map.clm = find_length_width(&my_map, "file.txt");
		c = map_check(my_map, "file.txt");
	}
	while (argc > i)
	{
		my_map.clm = find_length_width(&my_map, argv[i]);
		c = map_check(my_map, argv[i]);
		if (c == 0)
			map();
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaust <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:29:04 by pfaust            #+#    #+#             */
/*   Updated: 2018/01/24 14:37:57 by cvermand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	int x;
	int y;
	int width;
	int	height;

	x = 0;
	y = 0;
	//width = (2 * 10) * 2;
	//height = (3 * 10) * 2;
	width = 11;
	height = 12;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			printf("%-4d", x + (width * y));
			x++;
		}
		printf("\n");
		y++;
	}
}

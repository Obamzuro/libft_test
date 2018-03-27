/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:45:50 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/23 13:51:48 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void		print_incorrect(void *a, void *b, size_t size, size_t byte)
{
	size_t	i;
	char	*arr1;
	char	*arr2;

	arr1 = (char *)a;
	arr2 = (char *)b;
	printf("KO on %zu byte\n", byte);
	i = -1;
	while (++i < size)
		printf("libc[%zu] = %X - %c, your[%zu] = %X - %c\n", i, arr1[i], arr1[i], i, arr2[i], arr2[i]);
}

int				comp_arr(void *a, void *b, size_t size)
{
	size_t	i;
	char	*arr1;
	char	*arr2;

	if (!a && !b)
		return (1);
	else if (!a || !b)
	{
		printf("comp_arr ERROR - some of ptrs is NULL\n");
		return (0);
	}
	arr1 = (char *)a;
	arr2 = (char *)b;
	i = -1;
	while (++i < size)
	{
		if (arr1[i] != arr2[i])
		{
			print_incorrect(arr1, arr2, size, i);
			return (0);
		}
	}
	return (1);
}

int				comp_num(long a, long b)
{
	if (a != b)
	{
		printf("KO\nlibc = %ld, your = %ld\n", a, b);
		return (0);
	}
	return (1);
}

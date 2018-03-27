/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:30:49 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/21 17:59:06 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define AMOUNT_TESTS 10
#define TEST_ARR_SIZE 30
#include "header.h"
#include "libft.h"

static void		arr_filler(int *arr)
{
	arr[0] = -2147483648;
	arr[1] = -2147483647;
	arr[2] = -213;
	arr[3] = -1;
	arr[4] = 0;
	arr[5] = 1;
	arr[6] = 45;
	arr[7] = 98;
	arr[8] = 2147483646;
	arr[9] = 2147483647;
}

static int		char_memset_check(void)
{
	char		pchar[2][TEST_ARR_SIZE];
	long int	cases_iter;
	int			cases[AMOUNT_TESTS];

	arr_filler(cases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		memset(pchar[0], cases[cases_iter], TEST_ARR_SIZE - cases_iter);
		ft_memset(pchar[1], cases[cases_iter], TEST_ARR_SIZE - cases_iter);
		if (!comp_arr(pchar[0], pchar[1], TEST_ARR_SIZE))
			return (0);
		else
			printf("MEMSET CHAR cases_iter %ld - OK\n", cases_iter);
	}
	return (1);
}

static int		uchar_memset_check(void)
{
	unsigned char	puchar[2][TEST_ARR_SIZE];
	long int		cases_iter;
	int				cases[AMOUNT_TESTS];

	arr_filler(cases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		memset(puchar[0], cases[cases_iter], TEST_ARR_SIZE - cases_iter);
		ft_memset(puchar[1], cases[cases_iter], TEST_ARR_SIZE - cases_iter);
		if (!comp_arr(puchar[0], puchar[1], TEST_ARR_SIZE))
			return (0);
		else
			printf("MEMSET UCHAR cases_iter %ld - OK\n", cases_iter);
	}
	return (1);
}

static int		long_memset_check(void)
{
	long		longs[2][TEST_ARR_SIZE];
	long int	cases_iter;
	int			cases[AMOUNT_TESTS];

	arr_filler(cases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		memset(longs[0], cases[cases_iter], TEST_ARR_SIZE * sizeof(long)
				- cases_iter);
		ft_memset(longs[1], cases[cases_iter], TEST_ARR_SIZE * sizeof(long)
				- cases_iter);
		if (!comp_arr(longs[0], longs[1], TEST_ARR_SIZE * sizeof(long)))
			return (0);
		else
			printf("MEMSET LONG cases_iter %ld - OK\n", cases_iter);
	}
	return (1);
}

static int		ulong_memset_check(void)
{
	unsigned long	ulongs[2][TEST_ARR_SIZE];
	long int		cases_iter;
	int				cases[AMOUNT_TESTS];

	arr_filler(cases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		memset(ulongs[0], cases[cases_iter], TEST_ARR_SIZE * sizeof(long)
			- cases_iter);
		ft_memset(ulongs[1], cases[cases_iter], TEST_ARR_SIZE * sizeof(long)
			- cases_iter);
		if (!comp_arr(ulongs[0], ulongs[1], TEST_ARR_SIZE * sizeof(long)))
			return (0);
		else
			printf("MEMSET ULONG cases_iter %ld - OK\n", cases_iter);
	}
	return (1);
}

int				ft_memset_test(void)
{
	printf("========================================\n");
	printf("============= MEMSET CHECK =============\n");
	printf("========================================\n");
	if (!char_memset_check() || !uchar_memset_check() ||
			!long_memset_check() || !ulong_memset_check())
		return (0);
	return (1);
}

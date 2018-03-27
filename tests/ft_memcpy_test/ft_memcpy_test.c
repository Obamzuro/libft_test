/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 22:09:56 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/21 13:05:11 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#define AMOUNT_TESTS 10
#define TEST_ARR_SIZE 30

static void		arr_filler(int *arr, char (*strarr)[TEST_ARR_SIZE])
{
	int i;

	arr[0] = 7;
	arr[1] = 5;
	arr[2] = 10;
	arr[3] = 5;
	arr[4] = 12;
	arr[5] = 4;
	arr[6] = 28;
	arr[7] = 25;
	arr[8] = 30;
	arr[9] = 4;
	i = -1;
	while (++i < AMOUNT_TESTS)
		bzero(strarr[i], TEST_ARR_SIZE);
	memcpy(strarr[0], "qweqweqweqweqwe", 16);
	memcpy(strarr[1], "asdfasdfasdfasdf", 17);
	memcpy(strarr[2], "123450001111111", 16);
	memcpy(strarr[3], "lw21naslqlsgnn", 15);
	memcpy(strarr[4], "olegolegoleg", 13);
	memcpy(strarr[5], "lalalalalalalal", 16);
	memcpy(strarr[6], "u", 2);
	memcpy(strarr[7], "", 1);
	memcpy(strarr[8], "//z/z/z/z/z/z/zkqwitansewt2/o", 30);
	memcpy(strarr[9], " 	qwi	ls;", 10);
}

static int		char_memcpy_check(void)
{
	char		pchar[2][TEST_ARR_SIZE];
	long int	cases_iter;
	int			cases[AMOUNT_TESTS];
	char		strcases[AMOUNT_TESTS][TEST_ARR_SIZE];

	arr_filler(cases, strcases);
	memset(pchar[0], '\0', TEST_ARR_SIZE);
	memset(pchar[1], '\0', TEST_ARR_SIZE);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		memcpy(pchar[0], strcases[cases_iter], cases[cases_iter]);
		ft_memcpy(pchar[1], strcases[cases_iter], cases[cases_iter]);
		if (!comp_arr(pchar[0], pchar[1], TEST_ARR_SIZE))
			return (0);
		else
			printf("MEMCPY CHAR cases_iter %ld - OK\n", cases_iter);
	}
	return (1);
}

static int		uchar_memcpy_check(void)
{
	char		puchar[2][TEST_ARR_SIZE];
	long int	cases_iter;
	int			cases[AMOUNT_TESTS];
	char		strcases[AMOUNT_TESTS][TEST_ARR_SIZE];

	arr_filler(cases, strcases);
	memset(puchar[0], '\0', TEST_ARR_SIZE);
	memset(puchar[1], '\0', TEST_ARR_SIZE);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		memcpy(puchar[0], strcases[cases_iter], cases[cases_iter]);
		ft_memcpy(puchar[1], strcases[cases_iter], cases[cases_iter]);
		if (!comp_arr(puchar[0], puchar[1], TEST_ARR_SIZE))
			return (0);
		else
			printf("MEMCPY UCHAR cases_iter %ld - OK\n", cases_iter);
	}
	return (1);
}

static int		long_memcpy_check(void)
{
	long		longs[2][TEST_ARR_SIZE];
	long int	cases_iter;
	int			cases[AMOUNT_TESTS];
	char		strcases[AMOUNT_TESTS][TEST_ARR_SIZE];

	arr_filler(cases, strcases);
	memset(longs[0], '\0', TEST_ARR_SIZE * sizeof(long));
	memset(longs[1], '\0', TEST_ARR_SIZE * sizeof(long));
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		memcpy(longs[0], strcases[cases_iter], cases[cases_iter]);
		ft_memcpy(longs[1], strcases[cases_iter], cases[cases_iter]);
		if (!comp_arr(longs[0], longs[1], TEST_ARR_SIZE * sizeof(long)))
			return (0);
		else
			printf("MEMCPY LONG cases_iter %ld - OK\n", cases_iter);
	}
	return (1);
}

static int		ulong_memcpy_check(void)
{
	unsigned long	ulongs[2][TEST_ARR_SIZE];
	long int		cases_iter;
	int				cases[AMOUNT_TESTS];
	char			strcases[AMOUNT_TESTS][TEST_ARR_SIZE];

	arr_filler(cases, strcases);
	memset(ulongs[0], '\0', TEST_ARR_SIZE * sizeof(long));
	memset(ulongs[1], '\0', TEST_ARR_SIZE * sizeof(long));
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		memcpy(ulongs[0], strcases[cases_iter], cases[cases_iter]);
		ft_memcpy(ulongs[1], strcases[cases_iter], cases[cases_iter]);
		if (!comp_arr(ulongs[0], ulongs[1], TEST_ARR_SIZE * sizeof(long)))
			return (0);
		else
			printf("MEMCPY ULONG cases_iter %ld - OK\n", cases_iter);
	}
	return (1);
}

int				ft_memcpy_test(void)
{
	printf("=======================================\n");
	printf("============ MEMCPY CHECK =============\n");
	printf("=======================================\n");
	if (!char_memcpy_check() || !uchar_memcpy_check()
		|| !long_memcpy_check() || !ulong_memcpy_check())
		return (0);
	return (1);
}

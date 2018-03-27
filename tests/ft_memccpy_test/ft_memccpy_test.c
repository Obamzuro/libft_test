/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:16:14 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/21 20:24:50 by obamzuro         ###   ########.fr       */
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
	while (++i < AMOUNT_TESTS + 1)
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
	memcpy(strarr[AMOUNT_TESTS], "qazlgjuq\0s", AMOUNT_TESTS);
}

static int		char_memccpy_check(void)
{
	char		pchar[2][TEST_ARR_SIZE];
	int			cases[AMOUNT_TESTS + 1];
	char		strcases[AMOUNT_TESTS + 1][TEST_ARR_SIZE];
	char		*returns[2];

	arr_filler(cases, strcases);
	cases[AMOUNT_TESTS] = -1;
	while (++cases[AMOUNT_TESTS] < AMOUNT_TESTS)
	{
		memset(pchar[0], '\0', TEST_ARR_SIZE);
		memset(pchar[1], '\0', TEST_ARR_SIZE);
		returns[0] = memccpy(pchar[0], strcases[cases[AMOUNT_TESTS]], strcases[AMOUNT_TESTS][cases[AMOUNT_TESTS]], cases[cases[AMOUNT_TESTS]]);
		returns[1] = ft_memccpy(pchar[1], strcases[cases[AMOUNT_TESTS]], strcases[AMOUNT_TESTS][cases[AMOUNT_TESTS]], cases[cases[AMOUNT_TESTS]]);
		if (!comp_arr(pchar[0], pchar[1], TEST_ARR_SIZE) ||
			!comp_arr(returns[0], returns[1], pchar[0] + TEST_ARR_SIZE - returns[0]) ||
			(returns[0] && returns[1] && !comp_num(pchar[0] + TEST_ARR_SIZE - returns[0], pchar[1] + TEST_ARR_SIZE - returns[1])))
			return (0);
		else
			printf("MEMCCPY CHAR cases_iter %d - OK\n", cases[AMOUNT_TESTS]);
	}
	return (1);
}

static int		long_memccpy_check(void)
{
	long		longs[2][TEST_ARR_SIZE];
	int			cases[AMOUNT_TESTS + 1];
	char		strcases[AMOUNT_TESTS + 1][TEST_ARR_SIZE];
	char		*returns[2];

	arr_filler(cases, strcases);
	cases[AMOUNT_TESTS] = -1;
	while (++cases[AMOUNT_TESTS] < AMOUNT_TESTS)
	{
		memset(longs[0], '\0', TEST_ARR_SIZE * sizeof(long));
		memset(longs[1], '\0', TEST_ARR_SIZE * sizeof(long));
		returns[0] = memccpy(longs[0], strcases[cases[AMOUNT_TESTS]], strcases[AMOUNT_TESTS][cases[AMOUNT_TESTS]], cases[cases[AMOUNT_TESTS]]);
		returns[1] = ft_memccpy(longs[1], strcases[cases[AMOUNT_TESTS]], strcases[AMOUNT_TESTS][cases[AMOUNT_TESTS]], cases[cases[AMOUNT_TESTS]]);
		if (!comp_arr(longs[0], longs[1], TEST_ARR_SIZE * sizeof(long)) ||
			!comp_arr(returns[0], returns[1], (char *)longs[0] + TEST_ARR_SIZE * sizeof(long) - returns[0]) ||
			(returns[0] && returns[1] && !comp_num((char *)longs[0] + TEST_ARR_SIZE * sizeof(long) - returns[0], 
				(char *)longs[1] + TEST_ARR_SIZE * sizeof(long) - returns[1])))
			return (0);
		else
			printf("MEMCCPY LONG cases_iter %d - OK\n", cases[AMOUNT_TESTS]);
	}
	return (1);
}

int				ft_memccpy_test(void)
{
	printf("=======================================\n");
	printf("============ MEMCCPY CHECK ============\n");
	printf("=======================================\n");
	if (!char_memccpy_check() || !long_memccpy_check())
		return (0);
	return (1);
}

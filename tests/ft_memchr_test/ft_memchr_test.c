/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:22:51 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/21 16:07:05 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#define AMOUNT_TESTS 10
#define TEST_ARR_SIZE 30

static void		arr_filler(int *arr, char (*strarr)[TEST_ARR_SIZE])
{
	int i;

	arr[0] = 10;
	arr[1] = 5;
	arr[2] = 10;
	arr[3] = 11;
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
	memcpy(strarr[2], "023450000011111", 16);
	memcpy(strarr[3], "023450000011111", 16);
	memcpy(strarr[4], "olegolegoleg", 13);
	memcpy(strarr[5], "lalalalalalalal", 16);
	memcpy(strarr[6], "u", 2);
	memcpy(strarr[7], "", 1);
	memcpy(strarr[8], "//z/z/z/z/z/z/zkqwitansewt2/o", 30);
	memcpy(strarr[9], ";", 10);
	memcpy(strarr[AMOUNT_TESTS], "qa11ga\0\0\0;", AMOUNT_TESTS);
}

static int		char_memchr_check(void)
{
	int			cases[AMOUNT_TESTS + 1];
	char		strcases[AMOUNT_TESTS + 1][TEST_ARR_SIZE];
	char		*returns[2];

	arr_filler(cases, strcases);
	cases[AMOUNT_TESTS] = -1;
	while (++cases[AMOUNT_TESTS] < AMOUNT_TESTS)
	{
		returns[0] = (char *)memchr(strcases[cases[AMOUNT_TESTS]], strcases[AMOUNT_TESTS][cases[AMOUNT_TESTS]], cases[cases[AMOUNT_TESTS]]);
		returns[1] = (char *)ft_memchr(strcases[cases[AMOUNT_TESTS]], strcases[AMOUNT_TESTS][cases[AMOUNT_TESTS]], cases[cases[AMOUNT_TESTS]]);
//		printf("returns[0] = %p\nreturns[1] = %p\n", returns[0], returns[1]);
//		printf("cases[AMOUNT_TESTS] = %d, cases[cases[AMOUNT_TESTS]] = %d, strcases[AMOUNT_TESTS][cases[AMOUNT_TESTS]] = %c\n",
//			cases[AMOUNT_TESTS], cases[cases[AMOUNT_TESTS]], strcases[AMOUNT_TESTS][cases[AMOUNT_TESTS]]);
		if (!comp_arr(returns[0], returns[1], strcases[cases[AMOUNT_TESTS]] + TEST_ARR_SIZE - returns[0] + 1) ||
			!comp_num(strcases[cases[AMOUNT_TESTS]] + TEST_ARR_SIZE - returns[0] + 1, strcases[cases[AMOUNT_TESTS]] + TEST_ARR_SIZE - returns[1] + 1))
			return (0);
		else
			printf("MEMCHR CHAR cases_iter %d - OK\n", cases[AMOUNT_TESTS]);
	}
	return (1);
}

int				ft_memchr_test(void)
{
	printf("=======================================\n");
	printf("============ MEMCHR CHECK =============\n");
	printf("=======================================\n");
	return (char_memchr_check());
}

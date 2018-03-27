/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:34:17 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/23 23:49:01 by obamzuro         ###   ########.fr       */
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

static int		char_memmove_check(void)
{
	char		pchar[2][TEST_ARR_SIZE];
	int			cases[AMOUNT_TESTS + 1];
	char		strcases[AMOUNT_TESTS][TEST_ARR_SIZE];
	char		*returns[2];

	arr_filler(cases, strcases);
	memset(pchar[0], '\0', TEST_ARR_SIZE);
	memset(pchar[1], '\0', TEST_ARR_SIZE);
	cases[AMOUNT_TESTS] = -1;
	while (++cases[AMOUNT_TESTS] < AMOUNT_TESTS)
	{
#ifdef DEBUG
printf("1st = %s, 2nd = %s, 3rd = %d\n", pchar[0], strcases[cases[AMOUNT_TESTS]], cases[cases[AMOUNT_TESTS]]);
#endif
		returns[0] = memmove(pchar[0], strcases[cases[AMOUNT_TESTS]], cases[cases[AMOUNT_TESTS]]);
		returns[1] = ft_memmove(pchar[1], strcases[cases[AMOUNT_TESTS]], cases[cases[AMOUNT_TESTS]]);
#ifdef DEBUG
printf("libc = %s, your = %s\n", returns[0], returns[1]);
#endif
		if (!comp_arr(pchar[0], pchar[1], TEST_ARR_SIZE) ||
			!comp_arr(returns[0], returns[1], TEST_ARR_SIZE))
			return (0);
		else
			printf("MEMMOVE CHAR cases_iter %d - OK\n", cases[AMOUNT_TESTS]);
	}
	return (1);
}

static int		char_overlap_memmove_check(void)
{
	char		pchar[2][TEST_ARR_SIZE];
	char		*returns[2];

	memset(pchar[0], '\0', TEST_ARR_SIZE);
	memset(pchar[1], '\0', TEST_ARR_SIZE);
	returns[0] = memmove(pchar[0], pchar[0] + 8, 10);
	returns[1] = ft_memmove(pchar[0], pchar[0] + 8, 10);
#ifdef DEBUG
printf("1st = %s, 2d = %s, 3d = 10\n", pchar[0], pchar[0] + 8);
printf("libc = %s, your = %s\n", returns[0], returns[1]);
#endif
	if (!comp_arr(pchar[0], pchar[1], TEST_ARR_SIZE) || !comp_arr(returns[0], returns[1], TEST_ARR_SIZE))
		return (0);
	else
		printf("MEMMOVE OVERLAP CHAR cases_iter 1 - OK\n");
	returns[0] = memmove(pchar[0], "sile. qmn[]{}b.alq", 19);
	returns[1] = ft_memmove(pchar[1], "sile. qmn[]{}b.alq", 19);
#ifdef DEBUG
printf("1st = %s, 2d = sile. qmn[]{}b.alq, 3d = 19\n", pchar[0]);
printf("libc = %s, your = %s\n", returns[0], returns[1]);
#endif
	if (!comp_arr(pchar[0], pchar[1], TEST_ARR_SIZE) || !comp_arr(returns[0], returns[1], TEST_ARR_SIZE))
		return (0);
	else
		printf("MEMMOVE OVERLAP CHAR cases_iter 2 - OK\n");
#ifdef DEBUG
printf("1st = %s, 2d = %s, 3d = 10\n", pchar[0] + 2, pchar[0] + 4);
printf("1st = %s, 2d = %s, 3d = 10\n", pchar[1] + 2, pchar[1] + 4);
#endif
	returns[0] = memmove(pchar[0] + 2, pchar[0] + 4, 10);
	returns[1] = ft_memmove(pchar[1] + 2, pchar[1] + 4, 10);
#ifdef DEBUG
printf("libc = %s, your = %s\n", returns[0], returns[1]);
#endif
	if (!comp_arr(pchar[0], pchar[1], TEST_ARR_SIZE) || !comp_arr(returns[0], returns[1], TEST_ARR_SIZE - 2))
		return (0);
	else
		printf("MEMMOVE OVERLAP CHAR cases_iter 3 - OK\n");
#ifdef DEBUG
printf("1st = %s | 2d = %s | 3d = 6 | pchar[0] = %s | pchar[1] + %s\n", pchar[0] + 5, pchar[0] + 2, pchar[0], pchar[1]);
#endif
	returns[0] = memmove(pchar[0] + 5, pchar[0] + 2, 6);
	returns[1] = ft_memmove(pchar[1] + 5, pchar[1] + 2, 6);
#ifdef DEBUG
printf("libc = %s, your = %s\n", returns[0], returns[1]);
#endif
	if (!comp_arr(pchar[0], pchar[1], TEST_ARR_SIZE) || !comp_arr(returns[0], returns[1], 24))
		return (0);
	else
		printf("MEMMOVE OVERLAP CHAR cases_iter 4 - OK\n");
	return (1);
}

int				ft_memmove_test(void)
{
	printf("=======================================\n");
	printf("============ MEMMOVE CHECK ============\n");
	printf("=======================================\n");
	return (char_memmove_check() && char_overlap_memmove_check());
}

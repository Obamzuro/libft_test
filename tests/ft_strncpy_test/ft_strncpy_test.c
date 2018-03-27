/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:29:37 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/21 21:43:12 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#define AMOUNT_TESTS 10
#define TEST_ARR_SIZE 30

static void		arr_filler(int *arr, char (*strarr)[TEST_ARR_SIZE])
{
	int i;

	arr[0] = 20;
	arr[1] = 30;
	arr[2] = 30;
	arr[3] = 10;
	arr[4] = 5;
	arr[5] = 20;
	arr[6] = 1;
	arr[7] = 1;
	arr[8] = 3;
	arr[9] = 4;
	i = -1;
	while (++i < AMOUNT_TESTS)
		bzero(strarr[i], TEST_ARR_SIZE);
	memcpy(strarr[0], "qweqweqweqweqwe", 16);
	memcpy(strarr[1], "12345678901234567890123456789", 30);
	memcpy(strarr[2], "1234a67890123456789012345678", 29);
	memcpy(strarr[3], "123450001111111", 16);
	memcpy(strarr[4], "12345q00r111111", 16);
	memcpy(strarr[5], "lalalalalalalal", 16);
	memcpy(strarr[6], "u", 2);
	memcpy(strarr[7], "ass", 4);
	memcpy(strarr[8], "ass", 4);
	memcpy(strarr[9], "ass", 4);
}

static int		char_strncpy_check(void)
{
	char		pchar[2][TEST_ARR_SIZE];
	char		*returns[2];
	int			cases_iter;
	int			cases[TEST_ARR_SIZE];
	char		strcases[AMOUNT_TESTS][TEST_ARR_SIZE];

	arr_filler(cases, strcases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		bzero(pchar[0], TEST_ARR_SIZE);
		bzero(pchar[1], TEST_ARR_SIZE);
		returns[0] = strncpy(pchar[0], strcases[cases_iter], cases[cases_iter]);
		returns[1] = ft_strncpy(pchar[1], strcases[cases_iter], cases[cases_iter]);
		if (!comp_arr(pchar[0], pchar[1], TEST_ARR_SIZE) ||
			!comp_arr(returns[0], returns[1], TEST_ARR_SIZE))
			return (0);
		else
			printf("STRNCPY CHAR cases_iter %d - OK\n", cases_iter);
	}
	bzero(pchar[0], TEST_ARR_SIZE);
	bzero(pchar[1], TEST_ARR_SIZE);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		returns[0] = strncpy(pchar[0], strcases[cases_iter], cases[cases_iter]);
		returns[1] = ft_strncpy(pchar[1], strcases[cases_iter], cases[cases_iter]);
		if (!comp_arr(pchar[0], pchar[1], TEST_ARR_SIZE) ||
			!comp_arr(returns[0], returns[1], TEST_ARR_SIZE))
			return (0);
		else
			printf("STRNCPY CHAR cases_iter %d - OK\n", cases_iter + AMOUNT_TESTS);
	}
	return (1);
}

int				ft_strncpy_test(void)
{
	printf("=======================================\n");
	printf("============ STRCNPY CHECK ============\n");
	printf("=======================================\n");
	return (char_strncpy_check());
}

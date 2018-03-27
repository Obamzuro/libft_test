/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 20:52:44 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/22 21:11:04 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#define AMOUNT_TESTS 20
#define TEST_ARR_SIZE 30

static void		arr_filler(char (*strarr)[TEST_ARR_SIZE])
{
	int i;

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
	memcpy(strarr[10], "qweqweqweqweqwe", 16);
	memcpy(strarr[11], "asdfasdfasdfasdf", 17);
	memcpy(strarr[12], "023450000011111", 16);
	memcpy(strarr[13], "023450000011111", 16);
	memcpy(strarr[14], "olegolegoleg", 13);
	memcpy(strarr[15], "lalalalalalalal", 16);
	memcpy(strarr[16], "u", 2);
	memcpy(strarr[17], "", 1);
	memcpy(strarr[18], "//z/z/z/z/z/z/zkqwitansewt2/o", 30);
	memcpy(strarr[19], ";", 10);
	memcpy(strarr[AMOUNT_TESTS], "qa11go\0\0\0;l\0,\0ml\0\0z;", AMOUNT_TESTS);
}

static int		char_strrchr_check(void)
{
	char		strcases[AMOUNT_TESTS + 1][TEST_ARR_SIZE];
	char		*returns[2];
	int			cases_iter;

	arr_filler(strcases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		returns[0] = strrchr(strcases[cases_iter], strcases[AMOUNT_TESTS][cases_iter]);
		returns[1] = ft_strrchr(strcases[cases_iter], strcases[AMOUNT_TESTS][cases_iter]);
//		printf("returns[0] = %p\nreturns[1] = %p\n", returns[0], returns[1]);
//		printf("cases[AMOUNT_TESTS] = %d, cases[cases[AMOUNT_TESTS]] = %d, strcases[AMOUNT_TESTS][cases[AMOUNT_TESTS]] = %c\n",
//			cases[AMOUNT_TESTS], cases[cases[AMOUNT_TESTS]], strcases[AMOUNT_TESTS][cases[AMOUNT_TESTS]]);
		if (!comp_arr(returns[0], returns[1], strcases[cases_iter] + TEST_ARR_SIZE - returns[0] + 1) ||
			!comp_num(strcases[cases_iter] + TEST_ARR_SIZE - returns[0] + 1, strcases[cases_iter] + TEST_ARR_SIZE - returns[1] + 1))
			return (0);
		else
			printf("STRRCHR CHAR cases_iter %d - OK\n", cases_iter);
	}
	return (1);
}

int				ft_strrchr_test(void)
{
	printf("=======================================\n");
	printf("============ STRRCHR CHECK ============\n");
	printf("=======================================\n");
	return (char_strrchr_check());
}

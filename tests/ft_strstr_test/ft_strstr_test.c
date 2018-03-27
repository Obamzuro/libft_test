/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:14:27 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/23 14:06:31 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#define AMOUNT_TESTS 20
#define TEST_ARR_SIZE 30

static void		arr_filler(char (*strarr)[AMOUNT_TESTS][TEST_ARR_SIZE])
{
	int i;

	i = -1;
	while (++i < AMOUNT_TESTS)
	{
		bzero(strarr[0][i], TEST_ARR_SIZE);
		bzero(strarr[1][i], TEST_ARR_SIZE);
	}
	memcpy(strarr[0][0], "qweqweqweqweqwe", 16);
	memcpy(strarr[0][1], "asdfasdfasdfasdf", 17);
	memcpy(strarr[0][2], "023450000011111", 16);
	memcpy(strarr[0][3], "023450000011111", 16);
	memcpy(strarr[0][4], "olegolegoleg", 13);
	memcpy(strarr[0][5], "lalalalalalalal", 16);
	memcpy(strarr[0][6], "uqq", 4);
	memcpy(strarr[0][7], "", 1); //not NULL but pointer to first(big) string for strstr("", "");
	memcpy(strarr[0][8], "//z/z/z/z/z/z/zkqwitansewt2/o", 30);
	memcpy(strarr[0][9], ";", 10);
	memcpy(strarr[0][10], "qweqweqweqweqwe", 16);
	memcpy(strarr[0][11], "asdfasdfasdfasdf", 17);
	memcpy(strarr[0][12], "023450000011111", 16);
	memcpy(strarr[0][13], "023450000011111", 16);
	memcpy(strarr[0][14], "olegolegoleg", 13);
	memcpy(strarr[0][15], "lalalalalalalal", 16);
	memcpy(strarr[0][16], "u", 2);
	memcpy(strarr[0][17], "", 1);
	memcpy(strarr[0][18], "//z/\0/z/z/z/z/zkqwitansewt2/o", 30);
	memcpy(strarr[0][19], ";", 10);

	memcpy(strarr[1][0], "eq", 3);
	memcpy(strarr[1][1], "a\0sdf", 6);
	memcpy(strarr[1][2], "0", 2);
	memcpy(strarr[1][3], "2", 2);
	memcpy(strarr[1][4], "egolegg", 8);
	memcpy(strarr[1][5], "lal", 4);
	memcpy(strarr[1][6], "", 1);
	memcpy(strarr[1][7], "", 1);
	memcpy(strarr[1][8], "//z/z/zz/z/z/zkqwitansewt2/o", 29);
	memcpy(strarr[1][9], ";", 2);
	memcpy(strarr[1][10], "qqweqwe", 8);
	memcpy(strarr[1][11], "asdfa", 6);
	memcpy(strarr[1][12], "00011111", 9);
	memcpy(strarr[1][13], "02340011111", 12);
	memcpy(strarr[1][14], "olegolegi", 10);
	memcpy(strarr[1][15], "lalall.", 8);
	memcpy(strarr[1][16], ";", 2);
	memcpy(strarr[1][17], "i", 2);
	memcpy(strarr[1][18], "qwitansewt2/o", 14);
	memcpy(strarr[1][19], "", 1);
}

static int		char_strstr_check(void)
{
	char		strcases[2][AMOUNT_TESTS][TEST_ARR_SIZE];
	char		*returns[2];
	int			cases_iter;

	arr_filler(strcases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		returns[0] = strstr(strcases[0][cases_iter], strcases[1][cases_iter]);
		returns[1] = ft_strstr(strcases[0][cases_iter], strcases[1][cases_iter]);
#ifdef DEBUG
		printf("returns[0] = %s\nreturns[1] = %s\n", returns[0], returns[1]);
		printf("cases_iter = %d, strcases[0][cases_iter] - returns[0] = %ld, strcases[1][cases_iter] - returns[1] = %ld\n",
			cases_iter, strcases[0][cases_iter] - returns[0], strcases[0][cases_iter] - returns[1]);
#endif
		if (!comp_arr(returns[0], returns[1], strcases[0][cases_iter] + TEST_ARR_SIZE - returns[0] + 1) ||
			!comp_num(strcases[0][cases_iter] + TEST_ARR_SIZE - returns[0] + 1, strcases[0][cases_iter] + TEST_ARR_SIZE - returns[1] + 1))
			return (0);
		else
			printf("STRSTR CHAR cases_iter %d - OK\n", cases_iter);
	}
	return (1);
}

int				ft_strstr_test(void)
{
	printf("=======================================\n");
	printf("============ STRSTR CHECK =============\n");
	printf("=======================================\n");
	return (char_strstr_check());
}

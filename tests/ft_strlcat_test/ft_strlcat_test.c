/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 00:36:58 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/22 20:31:05 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#define AMOUNT_TESTS 20
#define TEST_ARR_SIZE 30

static void		arr_filler(int *arr, char (*strarr)[AMOUNT_TESTS][TEST_ARR_SIZE])
{
	int i;

	arr[0] = 30;
	arr[1] = 29;
	arr[2] = 31;
	arr[3] = 13;
	arr[4] = 14;
	arr[5] = 1;
	arr[6] = 2;
	arr[7] = 30;
	arr[8] = 1;
	arr[9] = 0;
	arr[10] = 6;
	arr[11] = 12;
	arr[12] = 30;
	arr[13] = 6;
	arr[14] = 5;
	arr[15] = 10;
	arr[16] = 1;
	arr[17] = 15;
	arr[18] = 3;
	arr[19] = 4;
	i = -1;
	while (++i < AMOUNT_TESTS)
	{
		bzero(strarr[0][i], TEST_ARR_SIZE);
		bzero(strarr[1][i], TEST_ARR_SIZE);
		bzero(strarr[2][i], TEST_ARR_SIZE);
	}
	memcpy(strarr[1][0], "qweqweqweqweqw", 15);
	memcpy(strarr[1][1], "qweqweqweqweqw", 15);
	memcpy(strarr[1][2], "qweqweqweqweqw", 15);
	memcpy(strarr[1][3], "qweqweqweqweqw", 15);
	memcpy(strarr[1][4], "qweqweqweqweqw", 15);
	memcpy(strarr[1][5], "qweqweqweqweqw", 15);
	memcpy(strarr[1][6], "", 2);
	memcpy(strarr[1][7], "u", 2);
	memcpy(strarr[1][8], "u", 2);
	memcpy(strarr[1][9], "", 1);
	memcpy(strarr[1][10], "alsng", 6);
	memcpy(strarr[1][11], "iq", 3);
	memcpy(strarr[1][12], "i", 2);
	memcpy(strarr[1][13], "", 1);
	memcpy(strarr[1][14], "", 1);
	memcpy(strarr[1][15], "q", 1);
	memcpy(strarr[1][16], "q", 1);
	memcpy(strarr[1][17], "qwe", 4);
	memcpy(strarr[1][18], "kak", 4);
	memcpy(strarr[1][19], "o1o", 4);

	memcpy(strarr[0][0], "qweqweqweqweqwe", 16);
	memcpy(strarr[0][1], "qweqweqweqweqwe", 16);
	memcpy(strarr[0][2], "qweqweqweqweqwe", 16);
	memcpy(strarr[0][3], "qweqweqweqweqwe", 16);
	memcpy(strarr[0][4], "qweqweqweqweqwe", 16);
	memcpy(strarr[0][5], "qweqweqweqweqwe", 16);
	memcpy(strarr[0][6], "u", 2);
	memcpy(strarr[0][7], "u", 2);
	memcpy(strarr[0][8], "", 1);
	memcpy(strarr[0][9], "", 1);
	memcpy(strarr[0][10], "", 1);
	memcpy(strarr[0][11], "qw", 3);
	memcpy(strarr[0][12], "qw", 3);
	memcpy(strarr[0][13], "qw", 3);
	memcpy(strarr[0][14], "q", 2);
	memcpy(strarr[0][15], "qw", 3);
	memcpy(strarr[0][16], "qw", 3);
	memcpy(strarr[0][17], "qwe123", 7);
	memcpy(strarr[0][18], "kak", 4);
	memcpy(strarr[0][19], "ooo", 4);

	memcpy(strarr[2][0], "qweqweqweqweqwe", 16);
	memcpy(strarr[2][1], "qweqweqweqweqwe", 16);
	memcpy(strarr[2][2], "qweqweqweqweqwe", 16);
	memcpy(strarr[2][3], "qweqweqweqweqwe", 16);
	memcpy(strarr[2][4], "qweqweqweqweqwe", 16);
	memcpy(strarr[2][5], "qweqweqweqweqwe", 16);
	memcpy(strarr[2][6], "u", 2);
	memcpy(strarr[2][7], "u", 2);
	memcpy(strarr[2][8], "", 1);
	memcpy(strarr[2][9], "", 1);
	memcpy(strarr[2][10], "", 1);
	memcpy(strarr[2][11], "qw", 3);
	memcpy(strarr[2][12], "qw", 3);
	memcpy(strarr[2][13], "qw", 3);
	memcpy(strarr[2][14], "q", 2);
	memcpy(strarr[2][15], "qw", 3);
	memcpy(strarr[2][16], "qw", 3);
	memcpy(strarr[2][17], "qwe123", 7);
	memcpy(strarr[2][18], "kak", 4);
	memcpy(strarr[2][19], "ooo", 4);
}

static int		char_strlcat_check(void)
{
	int			returns[2];
	int			cases_iter;
	char		strcases[3][AMOUNT_TESTS][TEST_ARR_SIZE];
	int			cases[AMOUNT_TESTS];

	arr_filler(cases, strcases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
//		printf("al = %lu\n", strlen(strcases[2][cases_iter]));
		returns[0] = strlcat(strcases[0][cases_iter], strcases[1][cases_iter], cases[cases_iter]);
		returns[1] = ft_strlcat(strcases[2][cases_iter], strcases[1][cases_iter], cases[cases_iter]);
//		int i = -1;
//		while (++i < TEST_ARR_SIZE)
//			printf("%c", strcases[0][cases_iter][i]);
//		printf("\n");
//		i = -1;
//		while (++i < TEST_ARR_SIZE)
//			printf("%c", strcases[2][cases_iter][i]);
//		printf("\n");
		if (!comp_num(returns[0], returns[1]) ||
		!comp_arr(strcases[0][cases_iter], strcases[2][cases_iter], TEST_ARR_SIZE))
			return (0);
		else
			printf("STRLCAT CHAR cases_iter %d - OK\n", cases_iter);
	}
	return (1);
}

int				ft_strlcat_test(void)
{
	printf("=======================================\n");
	printf("============ STRLCAT CHECK ============\n");
	printf("=======================================\n");
	return (char_strlcat_check());
}

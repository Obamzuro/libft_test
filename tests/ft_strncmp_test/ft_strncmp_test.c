/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:11:04 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/24 00:37:53 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#define AMOUNT_TESTS 21
#define TEST_ARR_SIZE 30

static void		arr_filler(int *arr, char (*strarr)[AMOUNT_TESTS][TEST_ARR_SIZE])
{
	int i;

	arr[0] = 16;
	arr[1] = 16;
	arr[2] = 5;
	arr[3] = 5;
	arr[4] = 6;
	arr[5] = 4;
	arr[6] = 2;
	arr[7] = 10;
	arr[8] = 2;
	arr[9] = 1;
	arr[10] = 0;
	arr[11] = 1;
	arr[12] = 2;
	arr[13] = 30;
	arr[14] = 1;
	arr[15] = 1;
	arr[16] = 20;
	arr[17] = 2;
	arr[18] = 1;
	arr[19] = 3;
	arr[20] = 0;
	i = -1;
	while (++i < AMOUNT_TESTS)
	{
		bzero(strarr[0][i], TEST_ARR_SIZE);
		bzero(strarr[1][i], TEST_ARR_SIZE);
	}
	memcpy(strarr[0][0], "qweqweqweqweqwe", 16);
	memcpy(strarr[0][1], "asdfasdfasdfasdf", 17);
	memcpy(strarr[0][2], "123450001111111", 16);
	memcpy(strarr[0][3], "12345q00r111111", 16);
	memcpy(strarr[0][4], "12345q00r111111", 16);
	memcpy(strarr[0][5], "ialalalalalalal", 16);
	memcpy(strarr[0][6], "u", 2);
	memcpy(strarr[0][7], "", 1);
	memcpy(strarr[0][8], "", 1);
	memcpy(strarr[0][9], "", 1);
	memcpy(strarr[0][10], "", 1);
	memcpy(strarr[0][11], "qw", 3);
	memcpy(strarr[0][12], "qw", 3);
	memcpy(strarr[0][13], "qw", 3);
	memcpy(strarr[0][14], "q", 2);
	memcpy(strarr[0][15], "qw", 3);
	memcpy(strarr[0][16], "qw", 3);
	memcpy(strarr[0][17], "qwe123\xff\xee", 9);
	memcpy(strarr[0][18], "kak", 4);
	memcpy(strarr[0][19], "ooo", 4);
	memcpy(strarr[0][20], "q", 2);

	memcpy(strarr[1][0], "qweqweqweqweqwe", 16);
	memcpy(strarr[1][1], "asdfasdfasdfasdf", 17);
	memcpy(strarr[1][2], "123450001111111", 16);
	memcpy(strarr[1][3], "123450001111111", 16);
	memcpy(strarr[1][4], "12345q00r111111", 16);
	memcpy(strarr[1][5], "lalalalalalalal", 16);
	memcpy(strarr[1][6], "u", 2);
	memcpy(strarr[1][7], "", 1);
	memcpy(strarr[1][8], "", 1);
	memcpy(strarr[1][9], "", 1);
	memcpy(strarr[1][10], "", 1);
	memcpy(strarr[1][11], "iq", 3);
	memcpy(strarr[1][12], "iq", 3);
	memcpy(strarr[1][13], "iq", 3);
	memcpy(strarr[1][14], "", 1);
	memcpy(strarr[1][15], "q", 1);
	memcpy(strarr[1][16], "q", 1);
	memcpy(strarr[1][17], "qwe", 4);
	memcpy(strarr[1][18], "kak\xff", 5);
	memcpy(strarr[1][19], "o1o\xff", 5);
	memcpy(strarr[1][20], "a", 2);
}

static int		char_strncmp_check(void)
{
	int			returns[2];
	int			cases_iter;
	int			cases[AMOUNT_TESTS];
	char		strcases[2][AMOUNT_TESTS][TEST_ARR_SIZE];

	arr_filler(cases, strcases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		returns[0] = strncmp(strcases[0][cases_iter], strcases[1][cases_iter], cases[cases_iter]);
		returns[1] = ft_strncmp(strcases[0][cases_iter], strcases[1][cases_iter], cases[cases_iter]);
#ifdef DEBUG
printf("1st = %s, 2nd = %s, 3rd = %d\n", strcases[0][cases_iter], strcases[1][cases_iter], cases[cases_iter]);
printf("libc returns - %d, your - %d\n", returns[0], returns[1]);
#endif
		if (!comp_num(returns[0], returns[1]))
			return (0);
		else
			printf("STRNCMP CHAR cases_iter %d - OK\n", cases_iter);
	}
	return (1);
}

int				ft_strncmp_test(void)
{
	printf("=======================================\n");
	printf("============ STRNCMP CHECK ============\n");
	printf("=======================================\n");
	return (char_strncmp_check());
}

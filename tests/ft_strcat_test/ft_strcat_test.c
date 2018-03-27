/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:51:20 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/21 22:42:32 by obamzuro         ###   ########.fr       */
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
		bzero(strarr[2][i], TEST_ARR_SIZE);
	}
	memcpy(strarr[0][0], "qweqweqweqweqwe", 16);
	memcpy(strarr[0][1], "asdfasdfasdfasdf", 17);
	memcpy(strarr[0][2], "123450001111111", 16);
	memcpy(strarr[0][3], "12345q00r111111", 16);
	memcpy(strarr[0][4], "12345q00r111111", 16);
	memcpy(strarr[0][5], "ialalalalalalal", 16);
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
	memcpy(strarr[2][1], "asdfasdfasdfasdf", 17);
	memcpy(strarr[2][2], "123450001111111", 16);
	memcpy(strarr[2][3], "12345q00r111111", 16);
	memcpy(strarr[2][4], "12345q00r111111", 16);
	memcpy(strarr[2][5], "ialalalalalalal", 16);
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

	memcpy(strarr[1][0], "qweqweqweqweqw", 15);
	memcpy(strarr[1][1], "asdfasdfff", 11);
	memcpy(strarr[1][2], "12341111", 9);
	memcpy(strarr[1][3], "12345", 6);
	memcpy(strarr[1][4], "12345q", 7);
	memcpy(strarr[1][5], "ooo", 4);
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
}

static int		char_strcat_check(void)
{
	char		*returns[2];
	int			cases_iter;
	char		strcases[3][AMOUNT_TESTS][TEST_ARR_SIZE];

	arr_filler(strcases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		returns[0] = strcat(strcases[0][cases_iter], strcases[1][cases_iter]);
		returns[1] = ft_strcat(strcases[2][cases_iter], strcases[1][cases_iter]);
		if (!comp_arr(strcases[0], strcases[2], TEST_ARR_SIZE) ||
			!comp_arr(returns[0], returns[1], TEST_ARR_SIZE))
			return (0);
		else
			printf("STRCAT CHAR cases_iter %d - OK\n", cases_iter);
	}
	return (1);
}

int				ft_strcat_test(void)
{
	printf("=======================================\n");
	printf("============ STRCAT CHECK =============\n");
	printf("=======================================\n");
	return (char_strcat_check());
}

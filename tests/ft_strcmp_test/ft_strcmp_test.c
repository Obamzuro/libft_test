/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:17:34 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/23 23:59:27 by obamzuro         ###   ########.fr       */
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
	memcpy(strarr[0][17], "qwe123", 7);
	memcpy(strarr[0][18], "kak\xff\xee", 6);
	memcpy(strarr[0][19], "ooo", 4);

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
	memcpy(strarr[1][19], "o1o", 4);
}

static int		char_strcmp_check(void)
{
	int			returns[2];
	int			cases_iter;
	char		strcases[2][AMOUNT_TESTS][TEST_ARR_SIZE];

	arr_filler(strcases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		returns[0] = strcmp(strcases[0][cases_iter], strcases[1][cases_iter]);
		returns[1] = ft_strcmp(strcases[0][cases_iter], strcases[1][cases_iter]);
#ifdef DEBUG
printf("1st = %s, 2d = %s\n", strcases[0][cases_iter], strcases[1][cases_iter]);
printf("libc returns - %d, your - %d\n", returns[0], returns[1]);
#endif
		if (!comp_num(returns[0], returns[1]))
			return (0);
		else
			printf("MEMCMP CHAR cases_iter %d - OK\n", cases_iter);
	}
	return (1);
}

int				ft_strcmp_test(void)
{
	printf("=======================================\n");
	printf("============ STRCMP CHECK =============\n");
	printf("=======================================\n");
	return (char_strcmp_check());
}

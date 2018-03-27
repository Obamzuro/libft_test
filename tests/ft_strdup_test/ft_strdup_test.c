/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:04:31 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/21 20:38:47 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#define AMOUNT_TESTS 20
#define TEST_ARR_SIZE 30

static void		arr_filler(int *arr, char (*strarr)[TEST_ARR_SIZE])
{
	arr[0] = 16;
	arr[1] = 17;
	arr[2] = 16;
	arr[3] = 16;
	arr[4] = 16;
	arr[5] = 16;
	arr[6] = 2;
	arr[7] = 1;
	arr[8] = 1;
	arr[9] = 1;
	arr[10] = 1;
	arr[11] = 3;
	arr[12] = 3;
	arr[13] = 3;
	arr[14] = 2;
	arr[15] = 3;
	arr[16] = 3;
	arr[17] = 7;
	arr[18] = 4;
	arr[19] = 4;
	int i;

	i = -1;
	while (++i < AMOUNT_TESTS)
		bzero(strarr[i], TEST_ARR_SIZE);
	memcpy(strarr[0], "qweqweqweqweqwe", 16);
	memcpy(strarr[1], "asdfasdfasdfasdf", 17);
	memcpy(strarr[2], "123450001111111", 16);
	memcpy(strarr[3], "12345q00r111111", 16);
	memcpy(strarr[4], "12345q00r111111", 16);
	memcpy(strarr[5], "ialalalalalalal", 16);
	memcpy(strarr[6], "u", 2);
	memcpy(strarr[7], "", 1);
	memcpy(strarr[8], "", 1);
	memcpy(strarr[9], "", 1);
	memcpy(strarr[10], "", 1);
	memcpy(strarr[11], "qw", 3);
	memcpy(strarr[12], "qw", 3);
	memcpy(strarr[13], "qw", 3);
	memcpy(strarr[14], "q", 2);
	memcpy(strarr[15], "qw", 3);
	memcpy(strarr[16], "qw", 3);
	memcpy(strarr[17], "qwe123", 7);
	memcpy(strarr[18], "kak", 4);
	memcpy(strarr[19], "ooo", 4);
}

static int		char_strdup_check(void)
{
	char		*returns[2];
	int			cases_iter;
	int			cases[AMOUNT_TESTS];
	char		strcases[AMOUNT_TESTS][TEST_ARR_SIZE];

	arr_filler(cases, strcases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		returns[0] = strdup(strcases[cases_iter]);
		returns[1] = ft_strdup(strcases[cases_iter]);
		if (!comp_arr(returns[0], returns[1], cases[cases_iter]))
		{
			free(returns[0]);
			free(returns[1]);
			return (0);
		}
		else
			printf("STRDUP CHAR cases_iter %d - OK\n", cases_iter);
		free(returns[0]);
		free(returns[1]);
	}
	return (1);
}

int				ft_strdup_test(void)
{
	printf("=======================================\n");
	printf("============ STRDUP CHECK =============\n");
	printf("=======================================\n");
	return (char_strdup_check());
}

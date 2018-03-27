/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:34:19 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/21 20:44:18 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#define AMOUNT_TESTS 10
#define TEST_ARR_SIZE 30

static void		arr_filler(char (*strarr)[TEST_ARR_SIZE])
{
	int i;

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
	memcpy(strarr[7], "", 1);
	memcpy(strarr[8], "", 1);
	memcpy(strarr[9], "", 1);
}

static int		char_strcpy_check(void)
{
	char		pchar[2][TEST_ARR_SIZE];
	char		*returns[2];
	int			cases_iter;
	char		strcases[AMOUNT_TESTS][TEST_ARR_SIZE];

	arr_filler(strcases);
	cases_iter = -1;
	bzero(pchar[0], TEST_ARR_SIZE);
	bzero(pchar[1], TEST_ARR_SIZE);
	while (++cases_iter < AMOUNT_TESTS)
	{
		returns[0] = strcpy(pchar[0], strcases[cases_iter]);
		returns[1] = ft_strcpy(pchar[1], strcases[cases_iter]);
		if (!comp_arr(pchar[0], pchar[1], TEST_ARR_SIZE) ||
			!comp_arr(returns[0], returns[1], TEST_ARR_SIZE))
			return (0);
		else
			printf("STRCPY CHAR cases_iter %d - OK\n", cases_iter);
	}
	return (1);
}

int				ft_strcpy_test(void)
{
	printf("=======================================\n");
	printf("============ STRCPY CHECK =============\n");
	printf("=======================================\n");
	return (char_strcpy_check());
}

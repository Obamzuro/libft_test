/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:15:57 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/24 18:10:26 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#define AMOUNT_TESTS 30
#define TEST_ARR_SIZE 30

static void		arr_filler(char (*strarr)[TEST_ARR_SIZE])
{
	int i;

	i = -1;
	while (++i < AMOUNT_TESTS)
		bzero(strarr[i], TEST_ARR_SIZE);
	memcpy(strarr[0], "12348", 6);
	memcpy(strarr[1], "-1224", 6);
	memcpy(strarr[2], "+818", 5);
	memcpy(strarr[3], " 128", 5);
	memcpy(strarr[4], " 	+28", 6);
	memcpy(strarr[5], "   -33", 7);
	memcpy(strarr[6], "	 -28b", 7);
	memcpy(strarr[7], "	 +33a21", 9);
	memcpy(strarr[8], "asdf", 5);
	memcpy(strarr[9], " 	asdf", 7);
	memcpy(strarr[10], "", 1);
	memcpy(strarr[11], "k", 2);
	memcpy(strarr[12], "qw", 3);
	memcpy(strarr[13], "n21ljgan", 8);
	memcpy(strarr[14], "-kka2", 6);
	memcpy(strarr[15], "+ k21", 5);
	memcpy(strarr[16], "1q21w", 6);
	memcpy(strarr[17], "lan+92", 7);
	memcpy(strarr[18], "\a21", 4);
	memcpy(strarr[19], "+\aooo", 6);
	memcpy(strarr[20], "+21474836491", 13);
	memcpy(strarr[21], "-9223372035854775808", 21);
	memcpy(strarr[22], "+9223372035854775808999999999", 30);
	memcpy(strarr[23], "+9229372035854775808", 21);
	memcpy(strarr[24], "-9229372035854775808", 21);
	memcpy(strarr[25], "-2147483647", 12);
	memcpy(strarr[26], "-2147483648", 12);
	memcpy(strarr[27], "-2147483649", 12);
	memcpy(strarr[28], "+2147483648", 12);
	memcpy(strarr[29], "2147483647", 11);
}

static int		char_atoi_check(void)
{
	int			returns[2];
	int			cases_iter;
	char		strcases[AMOUNT_TESTS][TEST_ARR_SIZE];

	arr_filler(strcases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		returns[0] = atoi(strcases[cases_iter]);
		returns[1] = ft_atoi(strcases[cases_iter]);
#ifdef DEBUG
printf("1st = %s\n", strcases[cases_iter]);
printf("libc returns - %d, your - %d\n", returns[0], returns[1]);
#endif
		if (!comp_num(returns[0], returns[1]))
			return (0);
		else
			printf("ATOI CHAR cases_iter %d - OK\n", cases_iter);
	}
	return (1);
}

int				ft_atoi_test(void)
{
	printf("=======================================\n");
	printf("============= ATOI CHECK ==============\n");
	printf("=======================================\n");
	return (char_atoi_check());
}

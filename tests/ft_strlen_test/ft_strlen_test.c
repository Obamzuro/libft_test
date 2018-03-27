/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:49:39 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/21 20:11:04 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#define AMOUNT_TESTS 5
#define TEST_ARR_SIZE 30

static void		arr_filler(char (*strarr)[TEST_ARR_SIZE])
{
	int i;

	i = -1;
	while (++i < AMOUNT_TESTS)
		bzero(strarr[i], TEST_ARR_SIZE);
	memcpy(strarr[0], "qweqweqweqweqwe", 16);
	memcpy(strarr[1], "", 1);
	memcpy(strarr[2], "1", 2);
	memcpy(strarr[3], "12345q00r111111", 16);
	memcpy(strarr[4], "12345q011111", 13);
	memcpy(strarr[5], "ialalalalalalal", 16);
}

static int		char_strlen_check(void)
{
	int			returns[2];
	int			cases_iter;
	char		strcases[AMOUNT_TESTS][TEST_ARR_SIZE];

	arr_filler(strcases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		returns[0] = strlen(strcases[cases_iter]);
		returns[1] = ft_strlen(strcases[cases_iter]);
		if (!comp_num(returns[0], returns[1]))
			return (0);
		else
			printf("STRLEN CHAR cases_iter %d - OK\n", cases_iter);
	}
	return (1);
}

int				ft_strlen_test(void)
{
	printf("=======================================\n");
	printf("============ STRLEN CHECK =============\n");
	printf("=======================================\n");
	return (char_strlen_check());
}

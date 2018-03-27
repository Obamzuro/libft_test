/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:30:49 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/21 13:07:46 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define AMOUNT_TESTS 10
#define TEST_ARR_SIZE 30
#include "header.h"
#include "libft.h"

static void		arr_filler(int *arr)
{
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 10;
	arr[4] = 20;
	arr[5] = 30;
	arr[6] = 28;
	arr[7] = 25;
	arr[8] = 23;
	arr[9] = 15;
}

static int		char_bzero_check(void)
{
	char		pchar[2][TEST_ARR_SIZE];
	long int	cases_iter;
	int			cases[AMOUNT_TESTS];
	char		*test_string;

	test_string = "asdfqnnntn1kallkla.bz. kw,";
	arr_filler(cases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		bzero(pchar[0], TEST_ARR_SIZE);
		bzero(pchar[1], TEST_ARR_SIZE);
		memcpy(pchar[0], test_string, strlen(test_string));
		memcpy(pchar[1], test_string, strlen(test_string));
		bzero(pchar[0], cases[cases_iter]);
		ft_bzero(pchar[1], cases[cases_iter]);
		if (!comp_arr(pchar[0], pchar[1], TEST_ARR_SIZE))
			return (0);
		else
			printf("BZERO CHAR cases_iter %ld - OK\n", cases_iter);
	}
	return (1);
}

static int		uchar_bzero_check(void)
{
	unsigned char	puchar[2][TEST_ARR_SIZE];
	long int		cases_iter;
	int				cases[AMOUNT_TESTS];
	char			*test_string;

	test_string = "asdfqnnntn1kallkla.bz. kw,";
	arr_filler(cases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		bzero(puchar[0], TEST_ARR_SIZE);
		bzero(puchar[1], TEST_ARR_SIZE);
		memcpy(puchar[0], test_string, strlen(test_string));
		memcpy(puchar[1], test_string, strlen(test_string));
		bzero(puchar[0], cases[cases_iter]);
		ft_bzero(puchar[1], cases[cases_iter]);
		if (!comp_arr(puchar[0], puchar[1], TEST_ARR_SIZE))
			return (0);
		else
			printf("BZERO UCHAR cases_iter %ld - OK\n", cases_iter);
	}
	return (1);
}

static int		long_bzero_check(void)
{
	long		longs[2][TEST_ARR_SIZE];
	long int	cases_iter;
	int			cases[AMOUNT_TESTS];
	char		*test_string;

	test_string = "asdfqnnntn1kallkla.bz. aaaaaaaaaaa\
				bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
	arr_filler(cases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		bzero(longs[0], TEST_ARR_SIZE * sizeof(long));
		bzero(longs[1], TEST_ARR_SIZE * sizeof(long));
		memcpy(longs[0], test_string, strlen(test_string));
		memcpy(longs[1], test_string, strlen(test_string));
		bzero(longs[0], cases[cases_iter]);
		ft_bzero(longs[1], cases[cases_iter]);
		if (!comp_arr(longs[0], longs[1], TEST_ARR_SIZE * sizeof(long)))
			return (0);
		else
			printf("BZERO LONG cases_iter %ld - OK\n", cases_iter);
	}
	return (1);
}

static int		ulong_bzero_check(void)
{
	unsigned long	ulongs[2][TEST_ARR_SIZE];
	long int		cases_iter;
	int				cases[AMOUNT_TESTS];
	char			*test_string;

	test_string = "asdfqnnntn1kallkla.bz. aaaaaaaaaaa\
				bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
	arr_filler(cases);
	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		bzero(ulongs[0], TEST_ARR_SIZE * sizeof(long));
		bzero(ulongs[1], TEST_ARR_SIZE * sizeof(long));
		memcpy(ulongs[0], test_string, strlen(test_string));
		memcpy(ulongs[1], test_string, strlen(test_string));
		bzero(ulongs[0], cases[cases_iter]);
		ft_bzero(ulongs[1], cases[cases_iter]);
		if (!comp_arr(ulongs[0], ulongs[1], TEST_ARR_SIZE * sizeof(long)))
			return (0);
		else
			printf("BZERO ULONG cases_iter %ld - OK\n", cases_iter);
	}
	return (1);
}

int				ft_bzero_test(void)
{
	printf("==================================\n");
	printf("========= BZERO CHECK ============\n");
	printf("==================================\n");
	if (!char_bzero_check() || !uchar_bzero_check() ||
		!long_bzero_check() || !ulong_bzero_check())
		return (0);
	return (1);
}

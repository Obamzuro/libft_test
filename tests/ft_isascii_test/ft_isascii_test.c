/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:52:34 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/23 19:02:08 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#define AMOUNT_TESTS 257

static int		char_isascii_check(void)
{
	int			returns[2];
	int			cases_iter;

	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		returns[0] = isascii(cases_iter);
		returns[1] = ft_isascii(cases_iter);
#ifdef ISDEBUG
printf("1st = %d\n", cases_iter);
printf("libc returns - %d, your - %d\n", returns[0], returns[1]);
#endif
		if (!comp_num(returns[0], returns[1]))
			return (0);
		else
			printf("ISASCII %d OK ", cases_iter);
	}
	return (1);
}

int				ft_isascii_test(void)
{
	char a;

	printf("=======================================\n");
	printf("============ ISASCII CHECK ============\n");
	printf("=======================================\n");
	a = char_isascii_check();
	printf("\n");
	return (a);
}

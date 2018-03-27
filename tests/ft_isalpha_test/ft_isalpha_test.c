/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:33:42 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/23 18:46:53 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft.h"
#define AMOUNT_TESTS 257

static int		char_isalpha_check(void)
{
	int			returns[2];
	int			cases_iter;

	cases_iter = -1;
	while (++cases_iter < AMOUNT_TESTS)
	{
		returns[0] = isalpha(cases_iter);
		returns[1] = ft_isalpha(cases_iter);
#ifdef ISDEBUG
printf("1st = %d\n", cases_iter);
printf("libc returns - %d, your - %d\n", returns[0], returns[1]);
#endif
		if (!comp_num(returns[0], returns[1]))
			return (0);
		else
			printf("ISALPHA %d OK ", cases_iter);
	}
	return (1);
}

int				ft_isalpha_test(void)
{
	char a;

	printf("=======================================\n");
	printf("============ ISALPHA CHECK ============\n");
	printf("=======================================\n");
	a = char_isalpha_check();
	printf("\n");
	return (a);
}

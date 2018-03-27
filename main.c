/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:15:47 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/23 19:13:54 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "header.h"

int		main(void)
{
	if (!ft_memset_test() || !ft_bzero_test() || !ft_memcpy_test() || !ft_memccpy_test() ||
			!ft_memmove_test() || !ft_memchr_test() || !ft_memcmp_test() || !ft_strlen_test() ||
			!ft_strdup_test() || !ft_strcpy_test() || !ft_strncpy_test() || !ft_strcat_test() ||
			!ft_strncat_test() || !ft_strlcat_test() || !ft_strchr_test() || !ft_strrchr_test() ||
			!ft_strstr_test() || !ft_strnstr_test() || !ft_strcmp_test() || !ft_strncmp_test() ||
			!ft_atoi_test() || !ft_isalpha_test() || !ft_isdigit_test() || !ft_isalnum_test() ||
			!ft_isascii_test() || !ft_isprint_test() || !ft_toupper_test() || !ft_tolower_test())
		printf("KO\n");
	else
		printf("OK\n");
	return (0);
}

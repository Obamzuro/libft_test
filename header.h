/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:39:27 by obamzuro          #+#    #+#             */
/*   Updated: 2018/03/23 19:13:36 by obamzuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <string.h>
# include <ctype.h>

int		comp_arr(void *a, void *b, size_t size);
int		comp_num(long a, long b);
int		ft_memset_test();
int		ft_bzero_test();
int		ft_memcpy_test();
int		ft_memccpy_test();
int		ft_memmove_test();
int		ft_memchr_test();
int		ft_memcmp_test();
int		ft_strlen_test();
int		ft_strdup_test();
int		ft_strcpy_test();
int		ft_strncpy_test();
int		ft_strcat_test();
int		ft_strncat_test();
int		ft_strlcat_test();
int		ft_strchr_test();
int		ft_strrchr_test();
int		ft_strstr_test();
int		ft_strnstr_test();
int		ft_strcmp_test();
int		ft_strncmp_test();
int		ft_atoi_test();
int		ft_isalpha_test();
int		ft_isdigit_test();
int		ft_isalnum_test();
int		ft_isascii_test();
int		ft_isprint_test();
int		ft_toupper_test();
int		ft_tolower_test();
#endif

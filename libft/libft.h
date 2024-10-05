/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:02:03 by marcsilv          #+#    #+#             */
/*   Updated: 2024/10/05 14:57:01 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <ctype.h>
# include <errno.h>
# include "../push_swap.h"

int		ft_putnbr(int n);
int		ft_isdigit(int c);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_atoi(const char *str);
int		ft_ptr_len(uintptr_t num);
int		ft_num_len(unsigned int num);
int		ft_print_matrix(char **matrix);
int		lower(unsigned int decimalnumber);
int		upper(unsigned int decimalnumber);
int		ft_print_unsigned(unsigned int n);
int		ft_printf(const char *myString, ...);
int		ft_print_ptr(unsigned long long ptr);
int		ft_strcmp(const char *s1, const char *s2);
int		find_specifier(char myString, va_list args);

char	*ft_uitoa(unsigned int n);
char	**ft_split(char const *s, char c);

size_t	ft_strlen(const char *s);
size_t	ft_matrix_len(char **matrix);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

void	ft_put_ptr(uintptr_t num);
void	ft_matrix_free(char **matrix);
void	ft_copy_array(int *dest, int *src, int size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

long	ft_atoi_long(const char *nptr);

#endif

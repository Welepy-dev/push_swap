/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:02:03 by marcsilv          #+#    #+#             */
/*   Updated: 2024/09/30 13:16:31 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stddef.h>
# include <limits.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>
# include "../so_long.h"

int		ft_putnbr(int n);
int		ft_isdigit(int c);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_ptr_len(uintptr_t num);
int		ft_atoi(const char *nptr);
int		ft_num_len(unsigned int num);
int		ft_print_unsigned(unsigned int n);
int		ft_print_ptr(unsigned long long ptr);
int		ft_printf(const char *my_string, ...);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_uitoa(unsigned int n);
char	*ft_strchr(const char *s, int c);
char	**ft_split(char const *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	print_error(char *error);
void	ft_put_ptr(uintptr_t num);
void	ft_matrix_free(char **matrix);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

size_t	ft_strlen(const char *s);
size_t	ft_matrix_len(char **matrix);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif

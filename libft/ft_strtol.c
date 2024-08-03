/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:38:22 by marcsilv          #+#    #+#             */
/*   Updated: 2024/08/03 17:54:14 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

long strtol(const char *nptr, char **endptr, int base) {
    const char *s = nptr;
    long result = 0;
    int sign = 1;
    int overflow = 0;

    // Skip whitespace
    while (ft_isspace(*s)) {
        s++;
    }

    // Handle optional sign
    if (*s == '+' || *s == '-') {
        if (*s == '-') {
            sign = -1;
        }
        s++;
    }

    // Validate the base
    if (base == 0) {
        if (*s == '0') {
            if (s[1] == 'x' || s[1] == 'X') {
                base = 16;
                s += 2;
            } else {
                base = 8;
                s++;
            }
        } else {
            base = 10;
        }
    } else if (base == 16 && *s == '0' && (s[1] == 'x' || s[1] == 'X')) {
        s += 2;
    }

    // Convert the number
    while (*s) {
        int digit;
        if (ft_isdigit(*s)) {
            digit = *s - '0';
        } else if (ft_isalpha(*s)) {
            digit = ft_tolower(*s) - 'a' + 10;
        } else {
            break;
        }

        if (digit >= base) {
            break;
        }

        if (result > (LONG_MAX - digit) / base) {
            overflow = 1;
            break;
        }

        result = result * base + digit;
        s++;
    }

    // Set endptr to the character that stopped the scan
    if (endptr) {
        *endptr = (char *)s;
    }

    if (overflow) {
        return sign == 1 ? LONG_MAX : LONG_MIN;
    }

    return result * sign;
}

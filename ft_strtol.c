/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:45:00 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/11/17 21:14:19 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	long (cutoff), acc = 0;
	int (c), neg = 0, any = 0, cutlim;
	const char *(s) = nptr;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		{ neg = 1; s++; }
	else if (*s == '+')
		s++;
	if ((base == 0 || base == 16) && *s == '0' && (s[1] == 'x' || s[1] == 'X'))
		s += 2, base = 16;
	if (base == 0)
		base = (*s == '0' ? 8 : 10);
	cutoff = neg ? LONG_MIN : LONG_MAX;
	cutlim = cutoff % base; cutoff /= base;
	if (neg) 
	{
		cutlim = -cutlim;
		if (cutlim > 0)
		{
			cutlim -= base;
			cutoff++;
		}
	}
    while ((c = (unsigned char) *s))
	{
        if (ft_isdigit(c)) c -= '0';
        else if (ft_isalpha(c)) c -= (ft_isupper(c) ? 'A' - 10 : 'a' - 10);
        else break;

        if (c >= base) break;

        if (any >= 0) {
            if (neg) {
                if (__builtin_sub_overflow(acc, c, &acc) || acc < cutoff) {
                    acc = LONG_MIN;
                    any = -1;
                } else {
                    acc = acc * base - c;
                    any = 1;
                }
            } else {
                if (__builtin_add_overflow(acc, c, &acc) || acc > cutoff) {
                    acc = LONG_MAX;
                    any = -1;
                } else {
                    acc = acc * base + c;
                    any = 1;
                }
            }
        }
        s++;
    }

    if (endptr) *endptr = (char *)(any ? s : nptr);
    return acc;
}

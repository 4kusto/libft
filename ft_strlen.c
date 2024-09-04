/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsuka <yuotsuka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:05:11 by yuotsuka          #+#    #+#             */
/*   Updated: 2024/06/23 02:59:02 by yuotsuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const unsigned long int	*g_lwptr;
unsigned long int		g_lw;
unsigned long int		g_hi;
unsigned long int		g_lo;

static size_t	ft_len_1(const char *cp, char *s)
{
	if (cp[0] == 0)
		return (cp - s);
	if (cp[1] == 0)
		return (cp - s + 1);
	if (cp[2] == 0)
		return (cp - s + 2);
	if (cp[3] == 0)
		return (cp - s + 3);
}

static size_t	ft_len_2(const char *cp, char *s)
{
	if (cp[4] == 0)
		return (cp - s + 4);
	if (cp[5] == 0)
		return (cp - s + 5);
	if (cp[6] == 0)
		return (cp - s + 6);
	if (cp[7] == 0)
		return (cp - s + 7);
}

static void	ft_len(const char *cp, char *s)
{
	while (1)
	{
		g_lw = *g_lwptr++;
		if (((g_lw - g_lo) & ~g_lw & g_hi) != 0)
		{
			ft_len_1(cp, s);
			if (sizeof(g_lw) > 4)
			{
				ft_len_2(cp, s);
			}
		}
	}
}

size_t	ft_strlen(const char *s)
{
	const char *(char_ptr) = s;
	const char *(cp) = (const char *)(g_lwptr - 1);
	while (((unsigned long int)char_ptr & (sizeof(g_lw) - 1)) != 0)
	{
		if (*char_ptr == '\0')
			return (char_ptr - s);
		++char_ptr;
	}
	g_lwptr = (unsigned long int *)char_ptr;
	g_hi = 0x80808080L;
	g_lo = 0x01010101L;
	if (sizeof(g_lw) > 4)
	{
		g_hi = ((g_hi << 16) << 16) | g_hi;
		g_lo = ((g_lo << 16) << 16) | g_lo;
	}
	if (sizeof(g_lw) > 8)
		abort();
	ft_len(cp, s);
}

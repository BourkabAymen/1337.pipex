/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:47:38 by abourkab          #+#    #+#             */
/*   Updated: 2022/10/22 15:22:04 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//cette fonction détermine si le caractère c est non affichable ou non 
static int	ft_iswspc(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
	{
		return (1);
	}
	return (0);
}

// this function solve the problem of overflowing 
static int	to_int(unsigned long long x, int sign)
{
	if (x >= 9223372036854775807 && sign == 1)
		return (-1);
	else if (x > 9223372036854775807 && sign == -1)
		return (0);
	else
		return ((int)x);
}

// cette fonction convertie un nombre contenu dans nptr en sa base décimale
int	ft_atoi(const char *nptr)
{
	int					i;
	unsigned long long	res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] != '\0' && ft_iswspc(nptr[i]) == 1)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] != '\0' && ft_isdigit(nptr[i]) == 1)
	{
		res *= 10;
		res += nptr[i] - 48;
		i++;
	}
	return (to_int(res, sign) * sign);
}

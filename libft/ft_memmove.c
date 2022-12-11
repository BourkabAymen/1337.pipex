/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:58:28 by abourkab          #+#    #+#             */
/*   Updated: 2022/10/14 22:37:50 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Cette fonction fait la meme chose que ft_memcpy mais elle prend en 
// considération le problème de overlopping (c'est à dire que l'adresse de 
// la destination est supérieure à celle de la source) et donc l'opération 
// du copier coller se fait du dernier byte au premier byte.

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (!dest && !src)
		return (0);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		s1 = (unsigned char *)(dest + (n - 1));
		s2 = (unsigned char *)(src + (n - 1));
		while (n--)
		{
			*s1-- = *s2--;
		}
	}
	return (dest);
}

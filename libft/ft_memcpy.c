/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:57:47 by abourkab          #+#    #+#             */
/*   Updated: 2022/10/16 18:07:22 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Cette fonction prend n bytes ( n caractères dans la chaine src ) 
// et stocke chaque byte de src dans dest après avoir effectué le typecasting 
// en unsigned char qui est le type qui peut etre représenté en 8 bits (1 byte) 
// et ce en passant par s1 et s2.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (!n || dest == src)
		return (dest);
	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*(s1 + i) = *(s2 + i);
		i++;
	}
	return (dest);
}

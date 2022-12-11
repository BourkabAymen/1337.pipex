/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:58:50 by abourkab          #+#    #+#             */
/*   Updated: 2022/10/17 15:09:02 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Cette fonction prend n bytes et y stocke le caractère c 
// (ayant un code ascii) type casted to unsigned char
// dans chaque byte 
// à partir de l'adresse s en passant par une variable buff 
// de type unsigned char 
// qui est le type qui peut etre représenté en 8 bits (1 byte).
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buff;

	buff = s;
	i = 0;
	while (i < n)
	{
		buff[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

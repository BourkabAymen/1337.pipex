/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:48:24 by abourkab          #+#    #+#             */
/*   Updated: 2022/10/20 23:53:31 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// cette fonction réserve de la mémoire tout en l'initialisant par 0 
// "Null terminated character"
// Dans la calloc on va reserver count element ayant size bytes 
// which means that the calloc function reserve count * size bytes 
void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count != 0 && size >= SIZE_MAX / count)
		return (NULL);
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}

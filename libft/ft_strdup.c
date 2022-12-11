/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:01:09 by abourkab          #+#    #+#             */
/*   Updated: 2022/10/20 07:24:24 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// cette fonction crées une copie de src tout en réservant de la mémoire 
// dans le heap
char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (copy)
	{
		while (i <= ft_strlen(src))
		{
			copy[i] = src[i];
			i++;
		}
		return (copy);
	}
	else
		return (NULL);
}

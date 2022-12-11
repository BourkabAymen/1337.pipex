/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:11:18 by abourkab          #+#    #+#             */
/*   Updated: 2022/10/23 03:33:01 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// cette fonction renvoie l'adresse de la première occurence de needle dans
//  haystack tout en ne balayant pas les n bytes (size de haystack) car 
//  il suffit d'itérer en maximum n - ft_strlen(needle) fois pour vérifier 
//  l'appartenance de needle dans haystack
char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack && n == 0)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	j = ft_strlen(needle);
	while (haystack[i] != '\0' && i < n)
	{
		if (haystack[i] == needle[0] && n - i >= j
			&& ft_strncmp(&haystack[i], needle, j) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}

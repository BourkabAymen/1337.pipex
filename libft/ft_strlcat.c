/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:02:25 by abourkab          #+#    #+#             */
/*   Updated: 2022/10/23 05:25:29 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// cette fonction fait la concaténation de size - s1_len - 1 caractères de 
// s2 typecasted dans s1.
size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	if (!s1 && size == 0)
		return (ft_strlen(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = s1_len;
	if (size <= s1_len)
		return (s2_len + size);
	while (s2[i] != '\0' && i < size - s1_len - 1)
	{
		s1[j] = s2[i];
		i++;
		j++;
	}
	s1[j] = '\0';
	return (s2_len + s1_len);
}

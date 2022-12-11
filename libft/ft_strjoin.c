/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:02:09 by abourkab          #+#    #+#             */
/*   Updated: 2022/10/23 05:36:56 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// cette fonction fait la jonction d'une chaine de caractère s1 
// avec une autre s2 dans une autre appellée str tout en appelant 
// ft_strlcpy et ft_strlcat
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(total_len * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, total_len);
	ft_strlcat(str, s2, total_len);
	str[total_len - 1] = '\0';
	return (str);
}

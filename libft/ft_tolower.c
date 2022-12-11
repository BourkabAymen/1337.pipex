/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:12:55 by abourkab          #+#    #+#             */
/*   Updated: 2022/10/17 15:29:02 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// cette fonction rend les caractères alphabétiques en miniscule en code ascii
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

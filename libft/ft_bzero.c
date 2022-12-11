/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourkab <abourkab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:48:07 by abourkab          #+#    #+#             */
/*   Updated: 2022/10/18 20:33:32 by abourkab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Cette fonction prend n bytes et y stocke the Null terminated character
//dans chaque byte à partir de l'adresse s en appelant la fonction ft_memset
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

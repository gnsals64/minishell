/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:18:20 by hunpark           #+#    #+#             */
/*   Updated: 2022/07/15 16:30:06 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dc;
	const unsigned char	*sc;

	dc = dest;
	sc = src;
	if (dc == NULL && sc == NULL)
		return (0);
	if (dc > sc)
	{
		while (n-- > 0)
			*(dc + n) = *(sc + n);
	}
	else
	{
		while (n-- > 0)
			*dc++ = *sc++;
	}
	return (dest);
}

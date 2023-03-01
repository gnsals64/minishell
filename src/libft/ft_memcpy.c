/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:48:30 by hunpark           #+#    #+#             */
/*   Updated: 2022/07/13 20:12:03 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char		*temp;
	const unsigned char	*s;

	temp = dest;
	s = src;
	if (temp == NULL && s == NULL)
		return (0);
	while (num-- > 0)
		*temp++ = *s++;
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:16:50 by hunpark           #+#    #+#             */
/*   Updated: 2022/07/22 16:46:40 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	tmp = NULL;
	while (c > 256)
		c %= 256;
	while (1)
	{
		if (*s == c)
			tmp = (char *)s;
		if (*s == '\0')
			return (tmp);
		s++;
	}
	return (0);
}

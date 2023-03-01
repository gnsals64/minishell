/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:31:49 by hunpark           #+#    #+#             */
/*   Updated: 2022/07/15 15:42:58 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char *)s1);
	while (i < n && s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] && i + j < n)
		{
			j++;
			if (s2[j] == 0)
				return ((char *)&s1[i]);
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:54:37 by marvin            #+#    #+#             */
/*   Updated: 2023/03/22 16:52:21 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
	{
		str = ft_strdup(s1);
		free(s1);
		return (str);
	}
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(sizeof(char), len);
	if (!str)
		return (NULL);
	ft_strlcat(str, s1, len);
	ft_strlcat(str, s2, len);
	free(s1);
	return (str);
}

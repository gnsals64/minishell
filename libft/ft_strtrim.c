/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:16:33 by marvin            #+#    #+#             */
/*   Updated: 2022/07/28 15:55:13 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_trimcpy(char *tmp, int i)
{
	int		j;
	int		len;
	char	*str;

	j = 0;
	len = 0;
	if (!tmp)
		return (NULL);
	while (tmp[len + i])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (tmp[i + j])
	{
		str[j] = tmp[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*tmp;
	char	*str;

	i = 0;
	str = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (!set)
		return (ft_strdup(s1));
	if (len == 0)
		return (ft_strdup(""));
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, s1, len + 1);
	while (len > 0 && ft_check(set, tmp[--len]))
		tmp[len] = 0;
	while (i < ft_strlen(tmp) && ft_check(set, tmp[i]))
		i++;
	str = ft_trimcpy(tmp, i);
	free(tmp);
	return (str);
}

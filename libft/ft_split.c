/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 01:02:50 by marvin            #+#    #+#             */
/*   Updated: 2022/07/28 15:53:51 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_word(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
		{
			i++;
			if (s[i] == 0)
				return (cnt);
		}
		cnt++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cnt);
}

static char	*ch_strdup(char const *str, int s, int e)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = e - s;
	res = (char *)malloc(sizeof(char) * (len + 1));
	while (s < e)
	{
		res[i] = str[s];
		s++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	st;
	size_t	en;
	size_t	i;
	char	**str;

	st = 0;
	en = 0;
	i = 0;
	str = (char **)ft_calloc(check_word(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	while (s[st])
	{
		while (s[st] == c && s[st])
			st++;
		if (!s[st])
			break ;
		en = st;
		while (s[en] != c && s[en])
			en++;
		str[i++] = ch_strdup(s, st, en);
		st = en;
	}
	str[i] = 0;
	return (str);
}

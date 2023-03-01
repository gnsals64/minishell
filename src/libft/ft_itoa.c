/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:43:26 by hunpark           #+#    #+#             */
/*   Updated: 2022/07/28 15:54:22 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	int_len(long long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	ft_strrev(char *s)
{
	size_t	i;
	char	temp;

	i = 0;
	while (i < ft_strlen(s) / 2 && s[i])
	{
		temp = s[i];
		s[i] = s[ft_strlen(s) - i - 1];
		s[ft_strlen(s) - i - 1] = temp;
		i++;
	}
	return ;
}

char	*ft_itoa(int n)
{
	size_t		i;
	char		*str;
	long long	cpy;

	i = 0;
	if (n >= 0)
		cpy = n;
	else
		cpy = (long long)n * -1;
	str = (char *)malloc(sizeof(char) * (int_len(cpy) + 2));
	if (!str)
		return (NULL);
	while (cpy > 0)
	{
		str[i++] = (cpy % 10) + 48;
		cpy /= 10;
	}
	if (n == 0)
		str[i++] = 48;
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}

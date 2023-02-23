/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hunpark <hunpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:08:10 by hunpark           #+#    #+#             */
/*   Updated: 2022/07/22 19:12:54 by hunpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cnt, size_t size)
{
	void	*tmp;

	if (((cnt * size) / size) != cnt)
		return (NULL);
	tmp = malloc(cnt * size);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, cnt * size);
	return (tmp);
}

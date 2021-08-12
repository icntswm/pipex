/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:25:17 by fkenned           #+#    #+#             */
/*   Updated: 2021/04/26 17:25:20 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	res;
	void	*sum;

	res = number * size;
	sum = (void *)malloc(res);
	if (!sum)
		return (NULL);
	ft_bzero(sum, res);
	return (sum);
}

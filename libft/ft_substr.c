/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkenned <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:37:11 by fkenned           #+#    #+#             */
/*   Updated: 2021/04/26 17:37:13 by fkenned          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < len)
		str = (char *)malloc(ft_strlen(s) + 1);
	else
		str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

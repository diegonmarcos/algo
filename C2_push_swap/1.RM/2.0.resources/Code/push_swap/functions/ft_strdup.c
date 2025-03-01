/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:09:18 by dnepomuc          #+#    #+#             */
/*   Updated: 2025/01/14 11:18:40 by dinepomu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

	/*
	Returns a new string that is a duplicate of the input string.
	It allocates memory for the new string and copies the contents
	of the input string into the new memory location.
	*/

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*s_alloc;

	len = ft_strlen(s) + 1;
	s_alloc = (char *)malloc(len * sizeof(char));
	if (s_alloc == NULL)
		return (NULL);
	ft_memcpy(s_alloc, s, len);
//	free (s_alloc);
	return (s_alloc);
}

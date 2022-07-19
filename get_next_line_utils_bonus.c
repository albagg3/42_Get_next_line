/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:26:23 by albagarc          #+#    #+#             */
/*   Updated: 2022/07/19 10:25:40 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char*s, int c)
{
	int	i;

	i = 0;
	if ((char) c == '\0')
		return ((char *) s + ft_strlen(s));
	while (*s)
	{
		if (s[i] == (char) c)
			return ((char *) s);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	count;

	count = 0;
	if (!s1)
		s1 = create_s1(s1);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (0);
	while (s1[count] != '\0')
	{
		new[count] = s1[count];
		count++;
	}
	count = 0;
	while (s2[count] != '\0')
	{
		new[count + ft_strlen(s1)] = s2[count];
		count++;
	}
	new[count + ft_strlen(s1)] = '\0';
	if (s1)
		free(s1);
	return (new);
}

char	*create_s1(char	*s1)
{
	s1 = malloc(sizeof(char) * 1);
	if (!s1)
		return (NULL);
	s1[0] = '\0';
	return (s1);
}

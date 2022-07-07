/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:16:56 by albagarc          #+#    #+#             */
/*   Updated: 2022/07/07 17:30:07 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
size_t	ft_strlen(const char *s)
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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && n != 0)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc (count * size);
	if (ptr != NULL)
	{
		ft_bzero (ptr, (count * size));
		return (ptr);
	}
	return (0);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	count;

	count = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new = malloc(sizeof(char) * (i + j + 1));
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
		new[count + i] = s2[count];
		count++;
	}
	new[count + i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	static char			*buffer;
	char				*lectura;
	char				*total_buffer;

	buffer = ft_calloc(1, 1);
	lectura = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while ( ft_strchr(lectura, '\n') == 0)
	{
		read(fd, lectura, BUFFER_SIZE);
		total_buffer = ft_strjoin(buffer, lectura);
		free (buffer);
		buffer = total_buffer;
	}
	free(lectura);
return (buffer);
}

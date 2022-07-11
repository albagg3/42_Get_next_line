/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:16:56 by albagarc          #+#    #+#             */
/*   Updated: 2022/07/08 15:24:35 by albagarc         ###   ########.fr       */
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

void	*ft_calloc_zero(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc (count * size);
	if (ptr != NULL)
	{
		while (i < size && size != 0)
		{
		((char *)ptr)[i] = 0;
		i++;
		}
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

//char	*clean_and_cut(char	*buffer)


char	*extract_line(char	*buffer) 
{
	int		i;
	char	*line;
	char	*rest;
	int 	j;

	j = 0;
	i = 0;

	printf("Hemos entrado en extract:%s\n", buffer);
	while (buffer[i] != '\n')
	{
//		line[i] = buffer[i];
		i++;
	}
	rest = ft_calloc_zero(ft_strlen(buffer) - i, sizeof(char));
	line = ft_calloc_zero(i + 1, sizeof(char));
	while (buffer[i] != '\0')
	{
		printf("j vale: %d\ni vale: %d\n", j, i);
		printf("rest[j]:%c\nbuffer[i]:%c\n", rest[j], buffer[i]);
		rest[j] = buffer[i];
		i++;
		j++;
	}
	printf ("rest es= %s\n", rest);

	printf("mi calloc es de = %d + 1\n", i);
	i = 0;
	while (buffer[i] != '\n')
	{
		printf("i = %d\n", i);
		line[i] = buffer[i];
		printf("line[i]=%c\nbuffer[i]=%c\n", line[i],buffer[i]);
		i++;
	}
	printf("line tiene guardado:%s\n", line);
	printf("i = %d\n", i);
	line[i] = '\n';
	line[i + 1] = '\0';

//	rest[j] = line[i + 1] 


	free (buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char			*buffer;
	char				*read_buffer_size;
	char				*join_buffer;
	char				*line;

	buffer = ft_calloc_zero(1, 1);
	read_buffer_size = ft_calloc_zero(BUFFER_SIZE + 1, sizeof(char));
	while (ft_strchr(read_buffer_size, '\n') == 0)
	{
		read(fd, read_buffer_size, BUFFER_SIZE);
		join_buffer = ft_strjoin(buffer, read_buffer_size);
		printf("strjoin tiene guardado:%s\n", join_buffer);
		free (buffer);
		buffer = join_buffer;
	}
	free(read_buffer_size);
	line = extract_line(buffer);
//	clean_and_cut(buffer);
//	free(buffer);
return (line);
}

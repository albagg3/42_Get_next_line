/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:16:56 by albagarc          #+#    #+#             */
/*   Updated: 2022/07/11 17:35:14 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/*void	*ft_calloc_zero(size_t count, size_t size)
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
}*/


char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	count;

	count = 0;
	if(!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if(!s1)
			return(NULL);
		s1[0] = '\0';
	}
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
	free(s1);
	return (new);
}



char	*extract_line(char	*buffer) 
{
	int		i;
	char	*line;

	i = 0;
	if(!buffer[0])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		i++;
	}
	line = malloc ((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *fill_static_buffer(char *buffer, int fd)
{
	char				*read_buffer_size;
	int 				num_bytes;
	
	read_buffer_size = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if(!read_buffer_size)
		return (NULL);
	read_buffer_size[0] = '\0';
	num_bytes = 1;
	while (num_bytes > 0 && !ft_strchr(read_buffer_size, '\n'))
	{
		num_bytes = read(fd, read_buffer_size, BUFFER_SIZE);
		if (num_bytes > 0)
		{
			read_buffer_size[num_bytes] = '\0';
			buffer = ft_strjoin(buffer, read_buffer_size);
		}
	}
	free (read_buffer_size);
	if (num_bytes == -1)
	{
		return(NULL);
	}
	
	return (buffer);

}

char *clean_static_buffer(char *buffer)
{
	int	i;
	int j;
	//buffer = hola\nque tal como estas
	//new_buffer = que tal como estas
	//
	char *new_buffer;
	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		i++;
	}
	if(buffer[i] == '\0')
	{
		free (buffer);
		return (NULL);
	}
	i++;
	new_buffer = malloc ((ft_strlen(buffer) + 1) * sizeof(char));
	if(!new_buffer)
		return (NULL);
	while (buffer[i] != '\0')
	{
		new_buffer[j] = buffer[i];
		i++;
		j++;
	}
	new_buffer[j] = '\0';

	free(buffer);
	return(new_buffer);
}

char	*get_next_line(int fd)
{
	static char			*buffer;
	char				*line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	if(!buffer || (buffer && !ft_strchr(buffer, '\n')))
		buffer = fill_static_buffer(buffer, fd);
	if(!buffer)
		return(NULL);
	line = extract_line(buffer);
	if(!line)
	{
		free(buffer);
		return(NULL);
	}
	buffer = clean_static_buffer(buffer);
	return (line);
}

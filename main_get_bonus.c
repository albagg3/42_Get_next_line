/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:38:19 by albagarc          #+#    #+#             */
/*   Updated: 2022/07/19 10:12:13 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
//#include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

int	main ()
{
	int		fd;
	int		fd2;
	int		fd3;
	int		fd4;
	char	*line;
	int		i;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);
	fd4 = open("text4.txt", O_RDONLY);

	while (1)
	{
		printf("el fd es= %d\n", fd); 
		line = get_next_line(fd);
		printf("%s\n", line);
		if (line)
			free(line);
		
		printf("el fd2 es= %d\n", fd2);	//Bonus
		line = get_next_line(fd2);		//Bonus
		printf("%s\n", line);			//Bonus
		if (line)						//Bonus
			free(line);					//Bonus
		close(fd2);

		printf("el fd3 es= %d\n", fd3);	//Bonus
		line = get_next_line(fd3);		//Bonus
		printf("%s\n", line);			//Bonus
		if (line)						//Bonus
			free(line);					//Bonus

		printf("el fd4 es= %d\n", fd4);	//Bonus
		line = get_next_line(fd4);		//Bonus
		printf("%s\n", line);			//Bonus
		if (line)						//Bonus
			free(line);					//Bonus
//	i++;
		if (!line)
			break;
	}
	
	close (fd);
	fd2 = open("text2.txt", O_RDONLY);
	printf("fd2=%d", fd2);
	close (fd2);
	close (fd3);
	close (fd4);
	return (0);
}


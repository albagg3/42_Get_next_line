/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:38:19 by albagarc          #+#    #+#             */
/*   Updated: 2022/07/11 16:33:43 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
//#define MITAM 80

/*int	main () 
{
	int fd;
//	char *buffer;
//	int	nbytes;
//	int fd1;
	char *line;
	printf("holi\n");
//	buffer = malloc ((MITAM + 1) * sizeof(char));
	fd = open("text copy.txt", O_RDONLY);
//	fd1 = open("sheila.txt", O_RDONLY);
//	nbytes = read(fd, buffer, MITAM);

//	buffer[MITAM]= '\0';
//	printf("texto leido:|%s|\n", buffer);
//	printf("nbytes:%d\n", nbytes);
	printf("fd:%d\n", fd);
//	printf("fd1:%d\n", fd1);
	printf("entra");
	line = get_next_line(fd);
//	printf("%s", line);
}*/


int	main ()
{
	int fd;
	char *storage;


	printf ("holi algun dia acabareis este proyecto!!\n");
	fd = open("text.txt", O_RDONLY);
	printf("fd:%d\n", fd);
	storage = get_next_line(fd);
	printf("storage:%s", storage);
	

}

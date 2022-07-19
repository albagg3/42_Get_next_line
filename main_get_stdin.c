/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:38:19 by albagarc          #+#    #+#             */
/*   Updated: 2022/07/19 10:14:01 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
//#include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
//#define MITAM 80




int main()
{
	char* line;
	//int	fd;
	int i = 0;
    line = get_next_line(0);			// 1
    while (line)

    {
    	printf("Gnl %d line : %s", i++, line);
        free(line);
    	line = get_next_line(0);
    }
    printf("\n");
    free(line);					// 2
    return (0);
}

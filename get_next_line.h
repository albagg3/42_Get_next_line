/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:28:10 by albagarc          #+#    #+#             */
/*   Updated: 2022/07/07 17:30:05 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <unistd.h> //para printf y read
#include <stdio.h> //para write y open
#include <fcntl.h> // para fd
#include <stdlib.h> //para malloc

char	*get_next_line(int fd);

#endif

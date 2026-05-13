/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoorpra <mnoorpra@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 07:08:09 by mnoorpra          #+#    #+#             */
/*   Updated: 2026/05/13 13:22:46 by mnoorpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdint.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>

/*
** Size of temporary read buffer
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*
** Linked list node used to store buffered file content
*/
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

/*
** Read and returns from a file descriptor
**	Returns : 	- A dynamicall allocated string containing the new line
**				- NULL if EOF is reached or on error
*/
char	*get_next_line(int fd);

/*
** Writes buffered content into the current line
*/
int		ft_putnode(int fd, t_list **tmp);

/*
** Add a new buffered node to the linked list
*/
int		ft_addnode(t_list **tmp, char *buf, int read_ptr);

/*
** Return the last node of the linked list
*/
t_list	*ft_lastlst(t_list *tmp);

/*
** Extract the current line from the buffered data
*/
void	ft_parseline(t_list *tmp, char **line);

/*
** Allocates and builds the line string
*/
void	ft_createline(t_list *tmp, char **line);

/*
** Cleans processed data form the buffer list
*/
void	ft_cleantmp(t_list **tmp);

/*
** Frees all of the buffer list
*/
void	ft_freetmp(t_list **tmp);

/*
** Returns the length of a string
*/
int		ft_strlen(char *s);

/*
** Check if there is new line character exists in the buffer
** Return 1 if new line is found, otherwise 0
*/
int		ft_findnl(t_list *tmp);

#endif
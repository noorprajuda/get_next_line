/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoorpra <mnoorpra@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 07:08:09 by mnoorpra          #+#    #+#             */
/*   Updated: 2026/05/13 11:08:53 by mnoorpra         ###   ########.fr       */
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

# ifndef BUF_SIZE
#  define BUF_SIZE 42
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		ft_putnode(int fd, t_list **tmp);
int	ft_addnode(t_list **tmp, char *buf, int read_ptr);
t_list	*ft_lastlst(t_list *tmp);
void	ft_parseline(t_list *tmp, char **line);
void	ft_createline(t_list *tmp, char **line);
void	ft_cleantmp(t_list **tmp);
void	ft_freetmp(t_list **tmp);
int		ft_strlen(char *s);
int		ft_findnl(t_list *tmp);

#endif
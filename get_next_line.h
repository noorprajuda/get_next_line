/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoorpra <mnoorpra@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 07:08:09 by mnoorpra          #+#    #+#             */
/*   Updated: 2026/05/15 04:05:00 by mnoorpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		ft_putnode(int fd, t_list **tmp);
int		ft_addnode(t_list **tmp, t_list **last, char *buf, int read_ptr);
t_list	*ft_lastlst(t_list *tmp);
void	ft_parseline(t_list *tmp, char **line);
int		ft_cleantmp(t_list **tmp);
void	ft_freetmp(t_list **tmp);
int		ft_strlen(char *s);
int		ft_findnl(t_list *tmp);

#endif

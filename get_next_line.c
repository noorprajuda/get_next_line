/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoorpra <mnoorpra@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 06:01:20 by mnoorpra          #+#    #+#             */
/*   Updated: 2026/05/15 04:05:00 by mnoorpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*tmp;
	char			*line;
	char			buf;

	line = NULL;
	if (fd < 0 || read(fd, &buf, 0) < 0 || BUFFER_SIZE < 0)
		return (ft_freetmp(&tmp), NULL);
	if (ft_putnode(fd, &tmp) < 0)
		return (ft_freetmp(&tmp), NULL);
	if (!tmp)
		return (NULL);
	ft_parseline(tmp, &line);
	if (!line)
		return (ft_freetmp(&tmp), NULL);
	if (ft_cleantmp(&tmp) == 0)
		return (ft_freetmp(&tmp), free(line), NULL);
	if (line[0] == '\0')
	{
		ft_freetmp(&tmp);
		free(line);
		return (NULL);
	}
	return (line);
}

int	ft_putnode(int fd, t_list **tmp)
{
	char	*buf;
	int		read_ptr;
	t_list	*last;

	read_ptr = 1;
	last = ft_lastlst(*tmp);
	while (!ft_findnl(last) && read_ptr != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (-1);
		read_ptr = read(fd, buf, BUFFER_SIZE);
		if (read_ptr == -1)
			return (free(buf), -1);
		if (read_ptr == 0)
			return (free(buf), 0);
		buf[read_ptr] = '\0';
		if (ft_addnode(tmp, &last, buf, read_ptr) < 0)
			return (free(buf), -1);
		free(buf);
	}
	return (0);
}

int	ft_addnode(t_list **tmp, t_list **last, char *buf, int read_ptr)
{
	t_list	*newnode;
	int		i;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (-1);
	newnode->content = malloc(sizeof(char) * (read_ptr + 1));
	if (!newnode->content)
		return (free(newnode), -1);
	i = -1;
	while (++i < read_ptr)
		newnode->content[i] = buf[i];
	newnode->content[i] = '\0';
	newnode->next = NULL;
	if (!*tmp)
	{
		*tmp = newnode;
		*last = newnode;
	}
	else
	{
		(*last)->next = newnode;
		*last = newnode;
	}
	return (0);
}

t_list	*ft_lastlst(t_list *tmp)
{
	if (!tmp)
		return (NULL);
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_parseline(t_list *tmp, char **line)
{
	t_list	*curr;
	int		len;
	int		i;

	len = 0;
	curr = tmp;
	while (curr)
	{
		i = 0;
		while (curr->content[i] && curr->content[i] != '\n')
		{
			i++;
			len++;
		}
		if (curr->content[i] == '\n' && len++)
			break ;
		curr = curr->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	if (!*line)
		return ;
	len = 0;
	while (tmp && !(i = 0))
	{
		while (tmp->content[i] && tmp->content[i] != '\n')
			(*line)[len++] = tmp->content[i++];
		if (tmp->content[i] == '\n')
			(*line)[len++] = tmp->content[i];
		if (tmp->content[i] == '\n')
			break ;
		tmp = tmp->next;
	}
	(*line)[len] = '\0';
}

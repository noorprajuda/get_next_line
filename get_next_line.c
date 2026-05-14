/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoorpra <mnoorpra@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 06:01:20 by mnoorpra          #+#    #+#             */
/*   Updated: 2026/05/14 23:15:10 by mnoorpra         ###   ########.fr       */
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
		return (NULL);
	if (tmp == NULL)
		return (NULL);
	ft_putnode(fd, &tmp);
	ft_parseline(tmp, &line);
	ft_cleantmp(&tmp);
	if (line[0] == '\0')
		return (ft_freetmp(&tmp), free(line), NULL);
	return (line);
}

int	ft_putnode(int fd, t_list **tmp)
{
	char	*buf;
	int		read_ptr;

	read_ptr = 1;
	while (!ft_findnl(*tmp) && read_ptr != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (perror("malloc failed"), -1);
		read_ptr = read(fd, buf, BUFFER_SIZE);
		if ((*tmp == NULL && read_ptr == 0) || read_ptr == -1)
		{
			free(buf);
			return (-1);
		}
		buf[read_ptr] = '\0';
		if (ft_addnode(tmp, buf, read_ptr) < 0)
			return (free (buf), -1);
		free(buf);
	}
	return (0);
}

int	ft_addnode(t_list **tmp, char *buf, int read_ptr)
{
	t_list	*newnode;
	int		i;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (-1);
	newnode->content = malloc (sizeof(char) * (read_ptr + 1));
	if (!newnode->content)
	{
		free(newnode);
		return (-1);
	}
	i = -1;
	while (++i < read_ptr)
		newnode->content[i] = buf[i];
	newnode->content[i] = '\0';
	newnode->next = NULL;
	if (!*tmp)
		*tmp = newnode;
	else
		ft_lastlst(*tmp)->next = newnode;
	return (0);
}

t_list	*ft_lastlst(t_list *tmp)
{
	t_list	*current;

	if (!tmp)
		return (NULL);
	current = tmp;
	while (current && current->next)
	{
		current = current->next;
	}
	return (current);
}

void	ft_parseline(t_list *tmp, char **line)
{
	int	i;
	int	j;

	if (!tmp)
		return ;
	ft_createline(tmp, line);
	if (!*line)
		return ;
	j = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i] != '\0' && tmp->content[i] != '\n')
			(*line)[j++] = tmp->content[i++];
		if (tmp && tmp->content[i] == '\n')
		{
			(*line)[j++] = tmp->content[i];
			tmp = NULL;
		}
		else
			tmp = tmp->next;
	}
	(*line)[j] = '\0';
}

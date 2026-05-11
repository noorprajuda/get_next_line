/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoorpra <mnoorpra@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 06:01:20 by mnoorpra          #+#    #+#             */
/*   Updated: 2026/05/11 04:58:37 by mnoorpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*tmp;
	char			*line;

	if (fd < 0 || read(fd, &line, 0) < 0 || BUF_SIZE < 0)
		return ((void *) 0);
	line = ((void *) 0);
	ft_putnode(fd, &tmp);
	if (tmp == (void *) 0)
		return ((void *) 0);
	ft_parseline(tmp, &line);
	ft_cleantmp(&tmp);
	if (line[0] == '\0')
	{
		ft_freetmp(tmp);
		tmp = ((void *) 0);
		free(line);
		return ((void *) 0);
	}
	return (line);
}

void	ft_putnode(int fd, t_list **tmp)
{
	char	*buf;
	int		*read_ptr;

	read_ptr = 1;
	while (!ft_findnl(*tmp) && read_ptr != 0)
	{
		buf = malloc(sizeof(char) * (BUF_SIZE + 1));
		if (buf == ((void *) 0))
			return ;
		*read_ptr = read(fd, buf, BUF_SIZE);
		if ((*tmp == ((void *) 0) && read_ptr == 0) || read_ptr == -1)
		{
			free(buf);
			return ;
		}
		ft_addnode(tmp, buf, read_ptr);
		buf[*read_ptr] = '\0';
	}
}

void	ft_addnode(t_list **tmp, char *buf, int read_ptr)
{
	t_list	*newnode;
	t_list	*last;
	int		i;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return ;
	newnode->next = ((void *) 0);
	newnode->content = malloc (sizeof(char) * (read_ptr + 1));
	if (!newnode->content)
		return ;
	i = 0;
	while (buf[i] && i < read_ptr)
	{
		newnode->content[i] = buf[i];
		i++;
	}
	newnode->content[i] = '\0';
	if (*tmp == ((void *) 0))
	{
		*tmp = newnode;
		return ;
	}
	last = ft_lastlst(*tmp);
	last->next = newnode;
}

t_list	*ft_lastlst(t_list *tmp)
{
	t_list	*current;

	current = tmp;
	if (current && current->next)
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
		while (tmp && tmp->content != '\n')
			(*line)[j++] = tmp->content[i++];
		if (tmp->content != '\n')
			(*line)[j++] = tmp->content[i];
		tmp = tmp->next;
	}
	line[j] = '\0';
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./loremimpsum.txt", O_RDONLY);
	while (line != ((void *) 0))
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}

}
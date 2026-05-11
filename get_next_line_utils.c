/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoorpra <mnoorpra@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:44:43 by mnoorpra          #+#    #+#             */
/*   Updated: 2026/05/12 01:11:40 by mnoorpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_createline(t_list *tmp, char **line)
{
	int	i;
	int	len;
	int	nl;

	if (!tmp)
		return ;
	len = 0;
	nl = 0;
	while (tmp && !nl)
	{
		i = 0;
		while (tmp->content[i] && tmp->content[i] != '\n')
		{
			len++;
			i++;
		}
		if (tmp->content[i] == '\n')
		{
			len++;
			nl = 1;
		}
		else
			tmp = tmp->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	if (!*line)
		return ;
}

void	ft_cleantmp(t_list **tmp)
{
	t_list	*cln;
	t_list	*last;
	size_t	i;
	size_t	j;

	last = ft_lastlst(*tmp);
	if (!tmp || !last || !last->content)
		return ;
	cln = malloc(sizeof(t_list));
	if (!cln)
		return ;
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	cln->content = malloc(sizeof(char) * (ft_strlen(last->content + i) + 1));
	if (cln->content == ((void *) 0))
	{
		free(cln);
		return ;
	}
	j = 0;
	while (last->content[i])
		cln->content[j++] = last->content[i++];
	cln->content[j] = '\0';
	cln->next = ((void *) 0);
	ft_freetmp(tmp);
	*tmp = cln;
}

void	ft_freetmp(t_list **tmp)
{
	t_list	*crn;
	t_list	*nxt;

	crn = *tmp;
	while (crn)
	{
		free(crn->content);
		nxt = crn->next;
		free(crn);
		crn = nxt;
	}
	*tmp = ((void *) 0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i ++;
	return (i);
}

int	ft_findnl(t_list *tmp)
{
	t_list	*crn;
	int		i;

	if (!tmp)
		return (0);
	crn = ft_lastlst(tmp);
	i = 0;
	while (crn->content[i])
	{
		if (crn->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

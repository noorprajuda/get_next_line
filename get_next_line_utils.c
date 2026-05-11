/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoorpra <mnoorpra@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:44:43 by mnoorpra          #+#    #+#             */
/*   Updated: 2026/05/11 20:53:15 by mnoorpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_createline(t_list *tmp, char **line)
{
	int	i;
	int	len;

	if (!tmp)
		return ;
	len = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i] && tmp->content[i] != '\n')
		{
			len++;
			i++;
		}
		if (tmp->content[i] == '\n')
			len++;
		tmp = tmp->next;
	}
	line = malloc(sizeof(char) * (len + 1));
}

void	ft_cleantmp(t_list **tmp)
{
	t_list	*cln;
	t_list	*last;
	size_t	i;
	size_t	j;

	cln = malloc(sizeof(t_list));
	if (!tmp || !cln)
		return ;
	cln->next = ((void *) 0);
	last = ft_lastlst(*tmp);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	cln->content = malloc(sizeof(char) * (ft_strlen(last->content) - i + 1));
	if (cln->content == ((void *) 0))
		return ;
	j = 0;
	while (last->content[i])
		cln->content[j++] = last->content[i++];
	cln->content[j] = '\0';
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

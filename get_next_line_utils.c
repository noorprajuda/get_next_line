/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoorpra <mnoorpra@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:44:43 by mnoorpra          #+#    #+#             */
/*   Updated: 2026/05/15 04:05:00 by mnoorpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_cleantmp(t_list **tmp)
{
	t_list	*cln;
	t_list	*crn;
	int		i;
	int		j;

	if (!tmp || !*tmp)
		return (1);
	crn = *tmp;
	while (crn && !ft_findnl(crn) && crn->next)
		crn = crn->next;
	i = 0;
	while (crn->content[i] && crn->content[i] != '\n')
		i++;
	if (crn->content[i] == '\n')
		i++;
	if (crn->content[i] == '\0')
		return (cln = crn->next, crn->next = NULL, ft_freetmp(tmp), *tmp = cln, 1);
	cln = malloc(sizeof(t_list));
	if (!cln || !(cln->content = malloc(ft_strlen(crn->content + i) + 1)))
		return (free(cln), 0);
	j = 0;
	while (crn->content[i])
		cln->content[j++] = crn->content[i++];
	cln->content[j] = '\0';
	return (cln->next = crn->next, crn->next = NULL, ft_freetmp(tmp), *tmp = cln, 1);
}

void	ft_freetmp(t_list **tmp)
{
	t_list	*crn;
	t_list	*nxt;

	if (!tmp || !*tmp)
		return ;
	crn = *tmp;
	while (crn)
	{
		free(crn->content);
		nxt = crn->next;
		free(crn);
		crn = nxt;
	}
	*tmp = NULL;
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_findnl(t_list *tmp)
{
	int	i;

	if (!tmp || !tmp->content)
		return (0);
	i = 0;
	while (tmp->content[i])
	{
		if (tmp->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

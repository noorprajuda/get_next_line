/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoorpra <mnoorpra@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 11:44:43 by mnoorpra          #+#    #+#             */
/*   Updated: 2026/05/02 11:50:19 by mnoorpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*saved;
	char			*line;
	int				readed;

	if (fd < 0 || read(fd, &line, 0) < 0 || BUFFER_SIZE < 0)
		return ((void *) 0);

}
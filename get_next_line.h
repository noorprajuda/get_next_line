/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoorpra <mnoorpra@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 07:08:09 by mnoorpra          #+#    #+#             */
/*   Updated: 2026/05/02 11:47:45 by mnoorpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>
# include <fcntl.h>

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

#endif
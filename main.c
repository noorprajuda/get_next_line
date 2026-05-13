/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoorpra <mnoorpra@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:04:59 by mnoorpra          #+#    #+#             */
/*   Updated: 2026/05/13 10:32:37 by mnoorpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		line_count;

	printf("=== Testing get_next_line ===\n\n");
	printf("Test 1: Reading from loremipsum.txt\n");
	//Test 1: Read from loremipsum.txt 
	fd = open("./loremipsum.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Could not open loremipsum.txt\n");
		return (1);
	}
	line_count = 0;
	line = get_next_line(fd);
	while (line != ((void *) 0))
	{
		line_count++;
		printf("Line %d: %s", line_count, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("Total lines read: %d\n\n", line_count);
	/* Test 2: Read from simple.txt */
	printf("Test 2: Reading from simple.txt\n");
	fd = open("./simple.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Could not open simple.txt\n");
		return (1);
	}
	line_count = 0;
	line = get_next_line(fd);
	while (line != ((void *) 0))
	{
		line_count++;
		printf("Line %d: %s", line_count, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("Total lines read: %d\n\n", line_count);
	/* Test 3: Handle non-existent file */
	printf("Test 3: Attempting to read non-existent file\n");
	fd = open("./nonexistent.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Could not open nonexistent.txt (Expected behavior)\n");
		return (0);
	}
	close(fd);
	printf("\n=== All tests completed ===\n");
	return (0);
}

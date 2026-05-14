*This project has been created as part of the 42 curriculum by mnoorpra*

<h1 align="center">  get_next_line </h1>

<p align="center"><i>"Reading a line from a file descriptor is way too tedious."</i></p>




# Description
Get next line allow the user to read and returns from a file descriptor. It will return A dynamicall allocated string containing the new line or NULL if EOF is reached or on error. 

This project is part of the 42 curriculum and focuses on:
- static variables
- memory management
- linked lists
- file descriptor handling
- buffer management

The function keeps reading from the file descriptor until it encounters a newline (`\n`) or reaches the end of the file.


## How It Works

1. Read from the file descriptor into a buffer
2. Store data inside linked list nodes
3. Detect newline characters
4. Extract one complete line
5. Clean processed data
6. Keep remaining content for the next call

---

## Learning Objectives

This project is covering the following:

- File I/O in C
- Static variables
- Dynamic memory allocation
- Linked list manipulation
- Efficient buffer handling
- Memory leak prevention

---

## Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters

- `fd` — File descriptor to read from.

### Return Value

- Returns the next line read from the file.
- Returns `NULL` when:
  - the end of the file is reached
  - an error occurs
  - invalid file descriptor

---

## Features

- Reads one line at a time
- Supports multiple file descriptors
- Handles variable buffer sizes
- Uses linked lists for buffered storage
- Dynamic memory allocation

---

## Project Structure

```text
.
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
└── README.md
```

---

# Instruction

## Compilation

Compile with:

```bash
cc -Wall -Wextra -Werror -D BUFFFER_SIZE=42 *.c
```

You can change the buffer size:

```bash
cc -Wall -Wextra -Werror -D BUFFFER_SIZE=100 *.c
```

---

## Example Usage
create a `test.txt` file
```txt
This is the first line.
And this is the second line.
But this is the third line.

```
create the main function `main.c` to test
```c
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	int		line_count;

	printf("=== Testing get_next_line ===\n\n");
	printf("Reading from test.txt\n");
	fd = open("./test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Could not open test.txt\n");
		return (1);
	}
	line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		printf("Line %d: %s", line_count, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	printf("\nTotal lines read: %d\n\n", line_count);
	printf("\n=== Test completed ===\n");
	return (0);
}

```
compile it

```bash
cc -Wall -Wextra -Werror -D BUFFFER_SIZE=42 *.c

```
display

```bash
./a.out

```

## Tests
Test with francinette on the shell

```bash
francinette

```
Test with francinette --strict on the shell

```bash
francinette --strict

```


---


## Included Functions


The following functions are used in the `get_next_line` project.

| Function | Description |
|----------|-------------|
| `get_next_line` | Reads and returns the next line from a file descriptor. |
| `ft_putnode` | Writes buffered content into the current line. |
| `ft_addnode` | Adds a new buffered node to the linked list. |
| `ft_lastlst` | Returns the last node of the linked list. |
| `ft_parseline` | Extracts the current line from buffered data. |
| `ft_createline` | Allocates and builds the line string. |
| `ft_cleantmp` | Cleans processed data from the buffer list. |
| `ft_freetmp` | Frees the entire buffer list. |
| `ft_strlen` | Returns the length of a string. |
| `ft_findnl` | Checks whether a newline character exists in the buffer. |

## Resources

### References

- [42 Norm](https://github.com/42School/norminette): coding standard enforced at 42

* [Valgrind Documentation](https://valgrind.org/docs/?utm_source=chatgpt.com)
  For detecting memory leaks


* [42 GitBook - get_next_line Overview](https://42-cursus.gitbook.io/guide/1-rank-01/get_next_line?utm_source=chatgpt.com)
  Explanation and breakdown of get_next_line project
* [Francinette](https://github.com/xicodomingues/francinette?utm_source=chatgpt.com) Tester for checking get_next_line project


### AI Usage

AI was used to get explanations of new difficult concepts after reading man, stackoverflow, and asked friend.


---
Made by mnoorpra: mnoorpra@student.42.fr | LinkedIn: [Marsetio Noorprajuda](https://id.linkedin.com/in/marsetio-noorprajuda-5633401b9) | Github: [noorprajuda](https://github.com/noorprajuda)
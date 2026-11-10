*This project has been created as part of the 42 curriculum by ltabbiz.*

# Libft

## Description

Libft is the first project of the 42 common core. Its goal is to rewrite a set of
standard C library functions, along with additional utility functions, and to
gather them into a static library, `libft.a`, that can be reused in future 42
projects.

Writing these functions from scratch is a way to understand how memory, strings,
characters and pointers work at a low level, instead of using them as black boxes.

## Instructions

### Compilation

The library is built with `cc` and the flags `-Wall -Wextra -Werror`, then
archived with `ar`.

| Command       | Effect                                           |
|---------------|--------------------------------------------------|
| `make`        | Compiles the sources and creates `libft.a`       |
| `make clean`  | Removes the object files (`.o`)                  |
| `make fclean` | Removes the object files and `libft.a`           |
| `make re`     | Runs `fclean`, then rebuilds the library         |

### Usage

Include the header in your source file:

```c
#include "libft.h"
```

Then link the library when compiling:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft
```

## Library description

### Part 1 — Libc functions

These functions have the same prototype and behavior as the originals described
in their `man` pages, with the `ft_` prefix.

| Category              | Functions |
|-----------------------|-----------|
| Character checks      | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion  | `ft_toupper`, `ft_tolower` |
| Strings               | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_atoi` |
| Memory                | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` |
| Allocation            | `ft_calloc`, `ft_strdup` |

### Part 2 — Additional functions

| Function         | Description |
|------------------|-------------|
| `ft_substr`      | Returns a new substring of `s`, starting at `start`, of at most `len` characters |
| `ft_strjoin`     | Returns a new string made of `s1` followed by `s2` |
| `ft_strtrim`     | Returns a copy of `s1` without the characters of `set` at its beginning and end |
| `ft_split`       | Splits `s` with the delimiter `c` into a `NULL`-terminated array of strings |
| `ft_itoa`        | Converts an `int` into a newly allocated string, negative numbers included |
| `ft_strmapi`     | Returns a new string made by applying `f` to each character of `s` |
| `ft_striteri`    | Applies `f` to each character of `s`, passed by address so it can be modified |
| `ft_putchar_fd`  | Writes a character to the given file descriptor |
| `ft_putstr_fd`   | Writes a string to the given file descriptor |
| `ft_putendl_fd`  | Writes a string followed by a newline to the given file descriptor |
| `ft_putnbr_fd`   | Writes an integer to the given file descriptor |

### Part 3 — Linked list

The list functions use the following structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

Each node stores the address of its data in `content` and the address of the
next node in `next`. The last node points to `NULL`.

| Function           | Description |
|--------------------|-------------|
| `ft_lstnew`        | Allocates a new node containing `content`, with `next` set to `NULL` |
| `ft_lstadd_front`  | Adds a node at the beginning of the list |
| `ft_lstsize`       | Counts the nodes of the list |
| `ft_lstlast`       | Returns the last node of the list |
| `ft_lstadd_back`   | Adds a node at the end of the list |
| `ft_lstdelone`     | Frees a node and its content with `del`, without freeing the next node |
| `ft_lstclear`      | Frees a node and all its successors, then sets the list pointer to `NULL` |
| `ft_lstiter`       | Applies `f` to the content of each node |
| `ft_lstmap`        | Creates a new list from the results of `f`, freeing everything with `del` on failure |

### Technical choices

- **Byte-level memory functions:** pointers are cast to `unsigned char *` so that
  memory is read and written one byte at a time, and values are compared as
  `unsigned char`, as the standard functions do.
- **`ft_memmove`:** copies forward when the destination is before the source, and
  backward otherwise, so overlapping areas are handled correctly.
- **`ft_calloc`:** checks that `nmemb * size` does not overflow before calling
  `malloc`, and returns a unique pointer that can be freed when `nmemb` or `size`
  is 0, as required by the subject.
- **`ft_itoa`:** works with a `long` so that `INT_MIN` can be converted without
  overflow.
- **`ft_split`:** frees every string already allocated if one allocation fails,
  so that no memory is leaked.

## Resources

### References

- The `man` pages of each standard function (`man 3 strlcpy`, `man 3 memmove`, ...)
- [cppreference — C standard library](https://en.cppreference.com/w/c)
- The 42 Norm (norminette)
- Valgrind documentation, used to find memory leaks and invalid reads

### AI usage

AI was used for testing: to help write small test programs comparing my functions
with the standard ones, and to understand the results of the tests.

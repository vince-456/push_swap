*This project has been created as part of the 42 curriculum by <login1>.*

# Libft - Your Very First Own Library

## Description

**Libft** is a project at 42 school that consists of creating a custom C standard library containing fundamental functions for string manipulation, memory management, character classification, and linked list handling. 

Since C programming can be tedious without access to standard functions, this project aims to provide a deep understanding of standard algorithms and memory management in C by reimplementing them from scratch. The library created during this project will serve as a foundational tool for future projects in the 42 curriculum.

---

## Technical Considerations

- Written in **C**, adhering strictly to the **42 Norm**.
- Functions must not crash unexpectedly (segmentation fault, bus error, double free, etc.).
- All heap-allocated memory is properly freed to prevent **memory leaks**.
- Compiled using `cc` with flags `-Wall -Wextra -Werror`.
- The static library `libft.a` is built at the root of the repository using `ar` (`libtool` is strictly forbidden).

---

## Instructions

### Compilation & Rules

The project includes a `Makefile` with the following standard rules:

- `make` or `make all`: Compiles the library source files into `libft.a`.
- `make clean`: Removes the generated object files (`.o`).
- `make fclean`: Removes the object files and the static library `libft.a`.
- `make re`: Recompiles the library from scratch.

### Usage in Another Project

To use **Libft** in your C project:

1. Clone or place the `libft` directory inside your project folder.
2. Compile Libft using `make`:
   ```bash
   make -C ./libft
   ```
3. Include the header in your C source files:
   ```c
   #include "libft.h"
   ```
4. Compile your program with the static library:
   ```bash
   cc -Wall -Wextra -Werror main.c -L./libft -lft -o my_program
   ```

---

## Detailed Description of the Library

### Part 1 - Libc Functions

Reimplementation of standard libc functions with the `ft_` prefix:

| Function | Description |
| :--- | :--- |
| **`ft_isalpha`** | Tests for an alphabetic character. |
| **`ft_isdigit`** | Tests for a digit (0 through 9). |
| **`ft_isalnum`** | Tests for an alphanumeric character. |
| **`ft_isascii`** | Tests whether `c` fits in the ASCII character set. |
| **`ft_isprint`** | Tests for any printable character. |
| **`ft_strlen`** | Computes the length of a string. |
| **`ft_memset`** | Fills a byte string with a byte value. |
| **`ft_bzero`** | Erases data in the memory by writing zeros. |
| **`ft_memcpy`** | Copies a memory area. |
| **`ft_memmove`** | Copies a memory area with handling for overlapping memory. |
| **`ft_strlcpy`** | Size-bounded string copying. |
| **`ft_strlcat`** | Size-bounded string concatenation. |
| **`ft_toupper`** | Converts a lowercase letter to uppercase. |
| **`ft_tolower`** | Converts an uppercase letter to lowercase. |
| **`ft_strchr`** | Locates the first occurrence of a character in a string. |
| **`ft_strrchr`** | Locates the last occurrence of a character in a string. |
| **`ft_strncmp`** | Compares two strings up to $n$ characters. |
| **`ft_memchr`** | Locates a byte in a byte string. |
| **`ft_memcmp`** | Compares two memory areas. |
| **`ft_strnstr`** | Locates a substring in a string with length limits. |
| **`ft_atoi`** | Converts the initial portion of a string to an integer. |
| **`ft_calloc`** | Allocates memory and sets its bytes to zero. |
| **`ft_strdup`** | Duplicates a string by allocating dynamic memory. |

---

### Part 2 - Additional Functions

Functions that are either not included in the standard libc or exist in a modified form:

| Function | Description |
| :--- | :--- |
| **`ft_substr`** | Extracts a substring from a string. |
| **`ft_strjoin`** | Concatenates two strings into a new dynamically allocated string. |
| **`ft_strtrim`** | Trims characters specified in `set` from the start and end of `s1`. |
| **`ft_split`** | Splits a string into an array of strings using a character delimiter. |
| **`ft_itoa`** | Converts an integer into a null-terminated string. |
| **`ft_strmapi`** | Applies a function to each character of a string to create a new string. |
| **`ft_striteri`** | Applies a function to each character of a string in-place by reference. |
| **`ft_putchar_fd`** | Writes a character to a given file descriptor. |
| **`ft_putstr_fd`** | Writes a string to a given file descriptor. |
| **`ft_putendl_fd`** | Writes a string followed by a newline to a given file descriptor. |
| **`ft_putnbr_fd`** | Writes an integer to a given file descriptor. |

---

### Part 3 - Linked List Functions (Bonus Part)

Functions to manipulate linked lists using the following structure defined in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Description |
| :--- | :--- |
| **`ft_lstnew`** | Creates a new list node. |
| **`ft_lstadd_front`** | Adds a node at the beginning of the list. |
| **`ft_lstsize`** | Counts the number of nodes in the list. |
| **`ft_lstlast`** | Returns the last node of the list. |
| **`ft_lstadd_back`** | Adds a node at the end of the list. |
| **`ft_lstdelone`** | Deletes and frees a single node using a deletion function. |
| **`ft_lstclear`** | Deletes and frees a node and all its successors. |
| **`ft_lstiter`** | Iterates over a list and applies a function to each node's content. |
| **`ft_lstmap`** | Applies a function to each node's content to create a new list. |

---

## Resources

### References
- [Linux Man Pages](https://man7.org/linux/man-pages/)
- [C Standard Library Reference](https://en.cppreference.com/w/c)
- 42 School subject PDF (`Libft` v19.3)

### Use of AI Tools
In compliance with the 42 AI policy:
- **Tasks performed with AI:** AI assistance was used exclusively for generating this structured `README.md` documentation file according to the specifications in Chapter V, and for clarifying edge-case scenarios described in standard manual pages (e.g., specific return behaviors for `calloc` or `memmove`).
- **Code implementation:** All function logic and algorithms were implemented manually without direct AI code generation to ensure full understanding of fundamental technical concepts, memory management, and peer-learning principles.
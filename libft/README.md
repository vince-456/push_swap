*This project has been created as part of the 42 curriculum by fozturk.*

# Libft - Your Very First Own Library

## Description
**Libft** is the first project in the 42 curriculum. The objective of this project is to create a custom C static library (`libft.a`) containing re-implementations of essential standard C library functions, alongside additional general-purpose utilities and linked list manipulation functions.

Writing these functions from scratch provides an in-depth understanding of standard libc behaviors, algorithmic logic, pointers, and memory management (heap allocation with `malloc` and deallocation with `free`). Once compiled, `libft.a` serves as a core toolkit to be reused in future 42 C projects.

---

## Library Content

The library consists of three main parts:

### 1. Part 1 - Libc Functions
Re-implementations of standard C library functions prefixed with `ft_` and adhering strictly to standard `man` specifications (without using external functions, except `malloc` for `calloc` and `strdup`):

- **Character Classification & Conversion**:
  - `ft_isalpha` - Test for an alphabetic character.
  - `ft_isdigit` - Test for a decimal digit character.
  - `ft_isalnum` - Test for an alphanumeric character.
  - `ft_isascii` - Test for a 7-bit US-ASCII character.
  - `ft_isprint` - Test for any printable character.
  - `ft_toupper` - Convert lowercase character to uppercase.
  - `ft_tolower` - Convert uppercase character to lowercase.

- **String Manipulation**:
  - `ft_strlen` - Compute the length of a string.
  - `ft_strchr` - Locate the first occurrence of a character in a string.
  - `ft_strrchr` - Locate the last occurrence of a character in a string.
  - `ft_strncmp` - Compare two strings up to `n` characters.
  - `ft_strnstr` - Locate a substring within a string (bounded).
  - `ft_strlcpy` - Size-bounded string copying.
  - `ft_strlcat` - Size-bounded string concatenation.

- **Memory Manipulation**:
  - `ft_memset` - Fill a byte string with a byte value.
  - `ft_bzero` - Write zeroes to a byte string.
  - `ft_memcpy` - Copy memory area.
  - `ft_memmove` - Copy memory area safely handling overlapping memory.
  - `ft_memchr` - Scan memory for a character.
  - `ft_memcmp` - Compare memory areas.

- **Dynamic Memory & Conversions**:
  - `ft_atoi` - Convert an ASCII string to an integer.
  - `ft_calloc` - Allocate zero-initialized memory.
  - `ft_strdup` - Allocate and duplicate a string.

---

### 2. Part 2 - Additional Functions
Functions not present in the standard libc or implemented in a distinct manner, designed for string transformations and file descriptor outputs:

- `ft_substr` - Extract a substring from a string.
- `ft_strjoin` - Concatenate two strings into a new dynamically allocated string.
- `ft_strtrim` - Trim characters defined in a set from the start and end of a string.
- `ft_split` - Split a string into an array of substrings using a delimiter character.
- `ft_itoa` - Convert an integer into an ASCII string.
- `ft_strmapi` - Apply a function to each character of a string to create a new mapped string.
- `ft_striteri` - Apply a function to each character of a string by reference (in-place).
- `ft_putchar_fd` - Output a single character to a specified file descriptor.
- `ft_putstr_fd` - Output a string to a specified file descriptor.
- `ft_putendl_fd` - Output a string followed by a newline to a specified file descriptor.
- `ft_putnbr_fd` - Output an integer to a specified file descriptor.

---

### 3. Part 3 - Linked List Functions (Bonus)
Utilities for creating and manipulating singly linked lists using the `t_list` structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

- `ft_lstnew` - Create a new list node.
- `ft_lstadd_front` - Add a node at the beginning of the list.
- `ft_lstsize` - Count the elements in the list.
- `ft_lstlast` - Retrieve the last element of the list.
- `ft_lstadd_back` - Add a node at the end of the list.
- `ft_lstdelone` - Free the content of a node and the node itself.
- `ft_lstclear` - Delete and free an entire linked list and its contents.
- `ft_lstiter` - Apply a function to the content of every node in the list.
- `ft_lstmap` - Iterate through a list and create a new list resulting from function applications.

---

## Instructions

### Technical Requirements
- Language: **C**
- Norm: Adheres strictly to the 42 Norm (Norminette).
- Compiler & Flags: `cc` / `gcc` compiled with `-Wall -Wextra -Werror`.
- Archive tool: `ar rcs` (libtool is strictly forbidden).
- No global variables allowed.
- Helper functions are declared `static` within the file scope.

### Compilation Commands

| Command | Action |
| :--- | :--- |
| `make` or `make all` | Compiles Part 1 and Part 2 source files into `libft.a`. |
| `make bonus` | Compiles both mandatory and linked list bonus functions into `libft.a`. |
| `make clean` | Removes object (`.o`) files. |
| `make fclean` | Removes object files and the static archive (`libft.a`). |
| `make re` | Performs a full rebuild (`fclean` followed by `all`). |

### Usage in Other Projects
To include `libft` in another C project:

1. Include the header file in your C source files:
   ```c
   #include "libft.h"
   ```

2. Compile your program by linking the archive:
   ```bash
   cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
   ```

---

## Resources

### References & Documentation
- Standard Unix Manual Pages: `man 3 strlen`, `man 3 memcpy`, `man 3 malloc`, etc.
- BSD General Documentation: `<bsd/string.h>` for `strlcpy` and `strlcat`.
- C Standard Library Reference (ISO/IEC 9899).
- 42 Libft Subject PDF (Version 19.3).

### AI Usage Declaration
In accordance with 42 curriculum guidelines (Chapter III - AI Instructions):
- **Conceptual Clarification**: AI was consulted to clarify edge cases regarding memory overlap behavior in `ft_memmove` vs `ft_memcpy`, and allocation edge cases in `ft_calloc`.
- **Logic & Implementation**: All code, memory allocation structures, and pointer arithmetic were written, reasoned through, and verified directly by the author. No unverified or direct code was pasted without understanding.
- **Documentation**: AI was utilized to assist in formatting and structuring this `README.md` file in compliance with the Subject Chapter V requirements.

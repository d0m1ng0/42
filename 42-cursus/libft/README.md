Libft
This project has been created as part of the 42 curriculum by dverdini.

Description
This project aims to create a C library (libft.a) that includes reimplementations of the standard C library functions and additional utility functions. This library will be used as a building block for future projects in the 42 curriculum.

Library Content
(Note: All files are located at the root of the repository. Categories below are for readability only).

Linked List
ft_lstnew.c, ft_lstadd_front.c, ft_lstsize.c, ft_lstlast.c

ft_lstadd_back.c, ft_lstdelone.c, ft_lstclear.c, ft_lstiter.c, ft_lstmap.c

Memory manipulation
ft_memset.c, ft_bzero.c, ft_memcpy.c, ft_memmove.c, ft_memchr.c, ft_memcmp.c,

ft_strdup.c, ft_calloc.c

String manipulation
ft_strlen.c, ft_strlcpy.c, ft_strlcat.c, ft_strchr.c, ft_strrchr.c, ft_strnstr.c, ft_strncmp.c


cType Classification & Conversion
ft_isalpha.c, ft_isdigit.c, ft_isalnum.c, ft_isascii.c, ft_isprint.c

ft_toupper.c, ft_tolower.c, ft_atoi.c, ft_itoa.c

File Descriptor Output
ft_putchar_fd.c, ft_putstr_fd.c, ft_putendl_fd.c, ft_putnbr_fd.c

Additional Utility
ft_substr.c, ft_strjoin.c, ft_strtrim.c, ft_split.c, ft_strmapi.c, ft_striteri.c

	|---linked-list
	|   |-ft_lstadd_back.c
	|   |-ft_lstadd_front.c
	|   |-ft_lstclear.c
	|   |-ft_lstdelone.c
	|   |-ft_lstiter.c
	|   |-ft_lstlast.c
	|   |-ft_lstmap.c
	|   |-ft_lstnew.c
	|   |-ft_lstsize.c
	|---file-descriptor-output
	|   |-ft_putchar_fd.c
	|   |-ft_putendl_fd.c
	|   |-ft_putnbr_fd.c
	|   |-ft_putstr_fd.c
	|---ctype-classifiction-convertion
	|   |-ft_isalnum.c
	|   |-ft_isalpha.c
	|   |-ft_isascii.c
	|   |-ft_isdigit.c
	|   |-ft_isprint.c
	|   |-ft_tolower.c
	|   |-ft_toupper.c	
	|   |-ft_atoi.c
	|   |-ft_itoa.c
	|---string-manipulation
	|   |-ft_strlen.c
	|   |-ft_strchr.c
	|   |-ft_strlcat.c
	|   |-ft_strlcpy.c
	|   |-ft_strncmp.c
	|   |-ft_strnstr.c
	|   |-ft_strrchr.c
	|---memory-manipulation
	|   |-ft_bzero.c
	|   |-ft_memchr.c
	|   |-ft_memcmp.c
	|   |-ft_memcpy.c
	|   |-ft_memmove.c
	|   |-ft_memset.c	
	|   |-ft_calloc.c
	|   |-ft_strdup.c
	|---additional-utility
	|   |-ft_split.c
	|   |-ft_striteri.c
	|   |-ft_strjoin.c
	|   |-ft_strmapi.c
	|   |-ft_strtrim.c
	|   |-ft_substr.c
	

Instructions

Compilation
To compile the library, run:
make        # Compiles standard functions
make bonus  # Compiles standard + linked list functions

Clean up
make clean   # Removes object files (.o)
make fclean  # Removes .o files and libft.a
make re      # Recompiles everything

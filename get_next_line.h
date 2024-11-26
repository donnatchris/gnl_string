#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct	s_list
{
	char			*content;
	struct	s_list	*next;
}					t_list;

size_t 	ft_strlen(const char *str);
int 	ft_has_newline(t_list *stash);
void	ft_free_list(t_list *stash);
t_list	*ft_lst_get_last(t_list *stash);
void	ft_clean_list(t_list **stash);
char	*get_next_line(int fd);
void	ft_read_to_list(int fd, t_list **stash);
void	ft_add_to_list(t_list **stash, char *buf, int readed);
void	ft_extract_line(t_list *stash, char **line);
void	ft_create_line(char **line, t_list *stash);

#endif

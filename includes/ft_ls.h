#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <dirent.h>
# include <errno.h>
# include <getopt.h>
# include <sys/stat.h>
# include <sys/types.h>

enum		e_filetype
{
    unknown,
    fifo,
    chardev,
    directory,
    blockdev,
    normal,
    symbolic_link,
    sock,
    whiteout,
    arg_directory
};

enum		e_sorttype
{
	sort_none = -1,
	sort_name,
	sort_time,
};

struct		s_queue
{
	char			*name;
	char			*realname;
	int				clarg;
	struct s_queue	*next;
};

struct		s_fileinfo
{
	char			*name;
	struct stat		stat;
	enum e_filetype	filetype;
};

struct		s_option
{
	int		all;
	int		reverse;
	int		recursive;
	int		long_form;
	int		sort_type;
};

struct		s_var
{
	size_t 				line_length;
	size_t				cwd_alloc;
	size_t				cwd_used;
	ino_t				inode;
	enum e_filetype		type;
	struct s_fileinfo	*cwd_file;
	struct s_queue		*pending;
	struct s_option		options;
};

typedef struct s_fileinfo	t_fileinfo;

int			argparse(int , char **, struct s_option *);

void		queue_dir(const char *, const char *, int, struct s_queue **);
uintmax_t	ingest_file(char *,struct s_var *, int, const char *);

int	gettype(struct dirent *f);
#endif

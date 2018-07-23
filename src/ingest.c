#include "../includes/ft_ls.h"

static void	cwd_realloc(struct s_var *var)
{
	struct s_fileinfo *new;

	new = (t_fileinfo *)malloc(var->cwd_alloc * sizeof(t_fileinfo) * 2);
	ft_memcpy(new, var->cwd_file, var->cwd_alloc * sizeof(t_fileinfo));
	var->cwd_alloc *= 2;
	free(var->cwd_file);
	var->cwd_file = new;
}

uintmax_t	ingest_file(
		char *name, struct s_var *var, int clarg, const char *dir)
{
	uintmax_t			blocks;
	struct s_fileinfo	*f;

	if (var->cwd_alloc == var->cwd_used)
		cwd_realloc(var);
	f = &var->cwd_file[var->cwd_used];
	ft_bzero(f, sizeof(t_fileinfo));
	f->stat.st_ino = var->inode;
	f->filetype = var->type;
}

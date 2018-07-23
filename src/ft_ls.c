#include "../includes/ft_ls.h"

static struct s_var	*init_var()
{
	struct s_var *var;

	var = (struct s_var *)ft_calloc(1, sizeof(struct s_var));
	var->line_length = 80;
	var->cwd_alloc = 100;
	var->cwd_file = malloc(sizeof(struct s_fileinfo) * 100);
	return (var);
}

int main(int argc, char **argv)
{
	int i;
	int argnum;
	struct s_var *var;

	if (!(var = init_var()))
		return (2);
	i = argparse(argc, argv, &var->options);
	argnum = argc - i;
	if (argnum <= 0)
		queue_dir(".", 0, 1, &var->pending);
	else
		while (i < argc)
			ingest_file(argv[i++], var, 1, 0);
	free(var);
	return (0);
}

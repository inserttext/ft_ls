#include "../includes/ft_ls.h"

static void	assign(char *flags, struct s_option *opt)
{
	while (*flags)
	{
		if (*flags == 'a')
			opt->all = 1;
		else if (*flags == 'l')
			opt->long_form = 1;
		else if (*flags == 'R')
			opt->recursive = 1;
		else if (*flags == 'r')
			opt->reverse = 1;
		else if (*flags == 't')
			opt->sort_type = sort_time;
		else
		{
			ft_fprintf(STDERR_FILENO, "\'%c\' does not exist\n", *flags);
			exit(2);
		}
		flags++;
	}
}

int			argparse(int argc, char **argv, struct s_option *opt)
{
	int i;
	int	ret;

	i = 1;
	ret = 0;
	ft_bzero(opt, sizeof(struct s_option));
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '-' && !argv[i][2])
				return (i + 1);
			assign(argv[i] + 1, opt);
		}
		else if (ret == 0)
			ret = i;
		i += 1;
	}
	return(ret);
}

#include "../includes/ft_ls.h"

void	queue_dir(
	const char *name, const char *realname, int clarg, struct s_queue **pending)
{
	struct s_queue *new;

	new = (struct s_queue *)malloc(sizeof(struct s_queue));
	new->name = name ? ft_strdup(name) : 0;
	new->realname = realname ? ft_strdup(realname) : 0;
	new->clarg = clarg;
	new->next = *pending;
	*pending = new;
}

void	free_pending(struct s_queue *ptr)
{
	free(ptr->name);
	free(ptr->realname);
	free(ptr);
}

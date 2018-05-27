#include "../includes/ft_ls.h"
#include <dirent.h>

int	gettype(struct dirent *f)
{
	if (f->d_type == DT_BLK)
		return (blockdev);
	else if (f->d_type == DT_CHR)
		return (chardev);
	else if (f->d_type == DT_DIR)
		return (directory);
	else if (f->d_type == DT_FIF)
		return (fifo);
	else if (f->d_type == DT_LNK)
		return (symbolic_link);
	else if (f->d_type == DT_REG)
		return (normal);
	else if (f->d_type == DT_SOC)
		return (sock);
	else if (f->d_type == DT_WHT)
		return (whiteout);
	else
		return(unknown);
}


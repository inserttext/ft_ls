/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tingo <tingo@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 21:11:02 by tingo             #+#    #+#             */
/*   Updated: 2018/12/06 19:11:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"
#include "../includes/ft_qsort.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

static char		ft_setmode(char *m, struct stat s)
{
	m[0] = s.st_mode & S_IRUSR ? 'r' : '-';
	m[1] = s.st_mode & S_IWUSR ? 'w' : '-';
	m[2] = s.st_mode & S_IXUSR ? 'x' : '-';
	m[3] = s.st_mode & S_IRGRP ? 'r' : '-';
	m[4] = s.st_mode & S_IWGRP ? 'w' : '-';
	m[5] = s.st_mode & S_IXGRP ? 'x' : '-';
	m[6] = s.st_mode & S_IROTH ? 'r' : '-';
	m[7] = s.st_mode & S_IWOTH ? 'w' : '-';
	m[8] = s.st_mode & S_IXOTH ? 'x' : '-';
	MATCH(S_ISDIR(s.st_mode), return ('d'));
	OR(S_ISCHR(s.st_mode), return ('c'));
	OR(S_ISBLK(s.st_mode), return ('b'));
	OR(S_ISSOCK(s.st_mode), return ('s'));
	OR(S_ISFIFO(s.st_mode), return ('p'));
	OR(S_ISLNK(s.st_mode), return ('l'));
	OTHERWISE(return ('-'));
}

int				print(struct s_file f, struct s_opt *o, int last)
{
	char		mode[11];
	char		link[256];
	char		*time;

	ft_bzero(link, 256);
	ft_bzero(mode, 11);
	if (!o->list)
		ft_printf("%s%s", f.name, last ? "\n" : "\t");
	else
	{
		time = ctime(&f.stat.st_ctime);
		time[ft_strlen(time) - 1] = 0;
		mode[0] = ft_setmode(mode + 1, f.stat);
		if (mode[0] == 'l')
			readlink(f.path, link, 255);
		ft_printf("%s %lu %s %s %ld %s %s %s %s\n",
		mode, f.stat.st_nlink, getpwuid(f.stat.st_uid)->pw_name,
		getgrgid(f.stat.st_gid)->gr_name, f.stat.st_size, time, f.name,
		mode[0] == 'l' ? "->" : "", mode[0] == 'l' ? link : "");
	}
	return (0);
}

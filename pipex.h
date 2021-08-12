#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <fcntl.h>

int		main(int argc, char **argv, char **envp);

int		ft_src_pwd_path(char **envp, char *pwpth);
char	**ft_free (char **array);
void	check_error_open_file(char **argv, int ifile);
void	check_and_clean_cmd(char ***spliting_cmd, char **cmd);
char	*ft_srccmd(char **spliting_path, char *spliting_cmd, int num_sp);

#endif
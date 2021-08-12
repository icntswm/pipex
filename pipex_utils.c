#	include "pipex.h"

int	ft_src_pwd_path(char **envp, char *pwpth)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] == pwpth[0] && envp[i][1] == pwpth[1]
			&& envp[i][2] == pwpth[2] && envp[i][3] == pwpth[3])
			break ;
		i++;
	}
	return (i);
}

char	**ft_free (char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

void	check_error_open_file(char **argv, int ifile)
{
	if (ifile < 0)
	{
		ft_putstr_fd("pipex error: no such file or directory: ", 1);
		ft_putendl_fd(argv[1], 1);
		exit (0);
	}
}

void	check_and_clean_cmd(char ***spliting_cmd, char **cmd)
{
	if (*cmd == NULL)
	{
		ft_putstr_fd("pipex error: command not found: ", 1);
		ft_putendl_fd(*spliting_cmd[0], 1);
	}
	ft_free(*spliting_cmd);
	free(*cmd);
}

char	*ft_srccmd(char **spliting_path, char *spliting_cmd, int num_sp)
{
	char	*slash;
	char	*cdm_file;

	while (num_sp > 0)
	{
		num_sp--;
		slash = ft_strjoin(spliting_path[num_sp], "/");
		cdm_file = ft_strjoin(slash, spliting_cmd);
		if (access(cdm_file, 0) == 0)
		{
			free(slash);
			return (cdm_file);
		}
		else
		{
			free(slash);
			free(cdm_file);
		}
	}
	return (NULL);
}

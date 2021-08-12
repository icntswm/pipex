#	include "pipex.h"

char	*search_cmd(char **envp, char *spliting_cmd)
{
	int		i_cmd;
	int		num_sp;
	char	*result;
	char	**spliting_path;
	char	*trim_path;

	num_sp = 0;
	i_cmd = ft_src_pwd_path(envp, "PATH=");
	trim_path = ft_strtrim(envp[i_cmd], "PATH=");
	spliting_path = ft_split(trim_path, ':');
	free(trim_path);
	while (spliting_path[num_sp])
		num_sp++;
	result = ft_srccmd(spliting_path, spliting_cmd, num_sp);
	ft_free(spliting_path);
	return (result);
}

void	par_proc(char **argv, char **envp, int *fd)
{
	int		ofile;
	char	*cmd;
	char	**spliting_cmd;
	pid_t	pid;

	wait (0);
	ofile = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY,
			S_IREAD | S_IWRITE | S_IRGRP | S_IROTH);
	spliting_cmd = ft_split(argv[3], ' ');
	cmd = search_cmd(envp, spliting_cmd[0]);
	if (cmd != NULL)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		dup2(ofile, 1);
		pid = fork();
		if (pid < 0)
			exit (0);
		else if (pid == 0)
			execve(cmd, spliting_cmd, envp);
	}
	wait(0);
	check_and_clean_cmd(&spliting_cmd, &cmd);
	close(ofile);
}

void	fork_proc(char **argv, char **envp, int *fd)
{
	int		ifile;
	char	*cmd;
	char	**spliting_cmd;
	pid_t	pid;

	ifile = open(argv[1], O_RDONLY);
	check_error_open_file(argv, ifile);
	spliting_cmd = ft_split(argv[2], ' ');
	cmd = search_cmd(envp, spliting_cmd[0]);
	if (cmd != NULL)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		dup2(ifile, 0);
		pid = fork();
		if (pid < 0)
			exit (0);
		else if (pid == 0)
			execve(cmd, spliting_cmd, envp);
	}
	wait(0);
	check_and_clean_cmd(&spliting_cmd, &cmd);
	close(ifile);
	exit (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putendl_fd("pipex error: 4 arguments required", 1);
		return (0);
	}
	if (pipe(fd) == -1)
	{
		ft_putendl_fd("pipex error: invalid fd", 1);
		return (0);
	}
	pid = fork();
	if (pid < 0)
	{
		ft_putendl_fd("pipex error: child process error", 1);
		return (0);
	}
	else if (pid == 0)
		fork_proc(argv, envp, fd);
	par_proc(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	return (0);
}

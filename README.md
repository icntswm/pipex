# pipex
You need to implement a program that will work similar to the one below:

`< file1 cmd1 | cmd2 > file2`

***
> Compilation commands:
> 
> `make` - compilation
> 
> `make re` - recompilation (deleting everything and compiling again)
> 
> `make clean` - deleting object files (.o)
> 
> `make fclean` - deleting object files (.o) and executable file
***
Program launch: `./pipex *infile* "cmd1" "cmd2" *outfile*`

Example command: `./pipex infile.txt "ls -l" "cat -e" outfile.txt`

# pipex
You need to implement a program that will work similar to the one below:

<img src="https://i.ibb.co/FJX3bDJ/2022-01-17-23-44-06.png" width="190" height="17" />

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

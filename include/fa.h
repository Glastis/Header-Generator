#ifndef FA_H_
# define FA_H_

# define READ_SIZE	50
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define WHITE		"\033[0m"
# define FUNC_NAME	"veritable_petit_beurre_de_lu_check_stack();\n"

void	print_function(char *str);
char	*get_src(char *path);
int	add_function(char *path, char *hpath);
int	is_c_file(unsigned char type, char *name);
int	get_c_files(char *path, char *hpath);
void	malloc_error();
char	*clone_str(char *str);
int	get_dir(char *path, char *hpath);
void	print_line(char *str);
int	is_func(char *str);
int	is_func_ended(char *str, int i);
int	is_same(char *str1, char *str2);
int	is_matching(char *str1, char *str2);
char	*str_coupler(char *str1, char *str2);

#endif /* FA_H_ */

/*
** my.h for my in /home/bechad_p/rendu/PSU_2014_minishell2/include
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Fri Nov 21 16:44:27 2014 Pierre Bechade
** Last update Sun Nov 30 15:26:51 2014 Pierre Bechade
*/

#ifndef MY_H_
# define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "tree.h"

typedef struct	s_env
{
  char		*str;
  struct s_env	*next;
}		t_env;

/* IN EXE_PATH.C */
char	*my_strcat(char *, char *);
char	*check_path(char **, char **);

/* IN MY_SH.C */
char	*prompt(t_env **, char **tab);
t_env	**add_end(t_env **list, char *data);
void	add(t_env **list, char **data);
char	**add_tab(t_env **envp);

/* IN MY_SIGHANDLER.C */
void	my_sighandler(int);

/* IN TOOL2.C */
int	compt_word(char *);
char	*my_strncpy(char *, char *, int);
char	**my_str_to_wordtab(char *, char);
int	compt_path(char *);
char	**my_path_to_wordtab(char *str);

/* IN TOOLS.C */
int	is_path(char *);
int	my_strlen(char *);
void	my_putchar(char);
void	my_putstr(char *);
char	*get_path(t_env *);

/* ERROR_FUNCRIONS.C */
void	my_putchar_e(char c);
void	my_putstr_e(char *str);
void	my_put_nbr_calc_e(int nb);
int	my_put_nbr_e(int nb);

/* IN TOOLS3.C */
void	*my_xmalloc(int);
int	my_strcmp(char *, char *);
char	*my_strdup(char *src);

/* IN BUILTIN.C */
int	is_built_in(char **);
void	exec_built_in(char **, t_env **envp);

/* IN MY_ENV.C */
void	my_env(t_env **envp);

/* IN MY_UNSETENV.C */
int	my_unsetenv(char **tab, t_env **envp);
int	check_unsetenv(char **tab);
t_env	*sub_env(t_env *list, char *valeur);

/* IN MY_SETENV.C */
int	my_setenv(char **tab, t_env **envp);
int	is_env_exist(char **tab, t_env **envp);

/* IN MY_EXIT.C */
int	my_calc_getnbr(char *str, int i, double nb_final, int nb_return);
int	my_getnbr(char *str);
int	my_exit(char **tab);

/* IN MY_ECHO_ENV.C */
char	*find_env(char  *str);
void	my_aff_error_echo(char *str);
int	my_echo_env(char **tab, t_env **envp);

/* IN MY_CD.C */
char	*my_strcat_cd(char *dest, char *src, int k);
int	my_env_cmp(char *s1, char *s2);
char	*my_find_str(t_env **list, char *str);
char	*my_create_pwd(char *pwd, char *chm, int k, int r);
int	my_aff_err(char *data);
char	*my_mv_pwd(char *pwd, char *chm,  int i, int j);
char	*my_catpwd(char *pwd, char *chm);
int	my_cd_dash(t_env **list);
int	data_test(char *data);
void	my_switch_env(t_env **list, char *data);
int	my_cd_next(t_env **list, char *data);
int	my_cd_home(t_env **list);
int	my_cd(t_env **list, char **tab_dat);

/* IN MY_PARSE.C */
t_tree	*result(char *str, t_tree **add);
t_tree	*my_parse(char *str);

/* IN MY_TOOLS_PARSE.C */
char	*s_left(char *str, int tmp);
char	*c_to_str(char c);
int	my_is_op(char *str);

/* IN MY_CALCUL.C */
void	my_calcul(t_tree **result, char **tab, t_env **envp, char **tabp);
void	set_null(t_tree **result);

#endif /* MY_H_ */

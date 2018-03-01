/*
** my_calcul.c for my_calcul in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Wed Nov 26 13:42:10 2014 Pierre Bechade
** Last update Sun Nov 30 14:56:48 2014 Pierre Bechade
*/

#include "my.h"

void	set_null(t_tree **result)
{
  (*result)->op = NULL;
  (*result)->right = NULL;
  (*result)->left = NULL;
}

void	my_calcul(t_tree **result, char **tab, t_env **envp, char **tabp)
{
  int	status;
  pid_t	pid;
  char	*path;
  char	**cpy_env;

  ((*result)->left != NULL) ? my_calcul(&(*result)->left, tab, envp, tabp) : 0;
  if ((*result)->right != NULL)
    my_calcul(&(*result)->right, tab, envp, tabp);
  if ((*result)->left == NULL &&
      (*result)->right == NULL && (*result)->op != NULL)
    {
      cpy_env = add_tab(envp);
      tab = my_str_to_wordtab((*result)->op, ' ');
      if (is_built_in(tab) == 0)
        exec_built_in(tab, envp);
      else if ((path = check_path(tabp, tab)) == NULL)
        (tab[0] != NULL) ? my_putstr_e((*result)->op),
	  my_putstr_e(": Command not found.\n") : 0;
      else
        {
          pid = fork();
          (pid == 0) ? execve(path, tab, cpy_env) : wait(&status);
        }
      set_null(&(*result));
    }
}

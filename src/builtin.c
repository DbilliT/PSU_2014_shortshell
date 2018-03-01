/*
** builtin.c for builtin in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Fri Nov 21 18:09:09 2014 Pierre Bechade
** Last update Sun Nov 30 15:21:43 2014 Pierre Bechade
*/

#include "my.h"

int	is_built_in(char **tab)
{
  if (tab[0] == NULL)
    return (-1);
  if (my_strcmp(tab[0], "exit") == 0)
    return (0);
  if (my_strcmp(tab[0], "cd") == 0)
    return (0);
  if (my_strcmp(tab[0], "env") == 0)
    return (0);
  if (my_strcmp(tab[0], "setenv") == 0)
    return (0);
  if (my_strcmp(tab[0], "unsetenv") == 0)
    return (0);
  if (my_strcmp(tab[0], "echo") == 0 && tab[1] != NULL && tab[1][0] == '$')
    return (0);
  return (-1);
}

void	exec_built_in(char **tab, t_env **envp)
{
  if (my_strcmp(tab[0], "exit") == 0)
    my_exit(tab);
  if (my_strcmp(tab[0], "cd") == 0)
    {
      if (my_find_str(envp, "PWD=") != NULL)
	my_cd(envp, tab);
      else
	my_putstr("Can't cd : PWD not set\n");
    }
  if (my_strcmp(tab[0], "env") == 0)
    my_env(envp);
  if (my_strcmp(tab[0], "setenv") == 0)
    my_setenv(tab, envp);
  if (my_strcmp(tab[0], "unsetenv") == 0)
    my_unsetenv(tab, envp);
  if (my_strcmp(tab[0], "echo") == 0 && tab[1] != NULL && tab[1][0] == '$')
    my_echo_env(tab, envp);
}

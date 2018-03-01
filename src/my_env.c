/*
** my_env.c for my_env in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Sat Nov 22 14:24:06 2014 Pierre Bechade
** Last update Thu Nov 27 16:59:27 2014 Pierre Bechade
*/

#include "my.h"

void	my_env(t_env **envp)
{
  t_env	*aff_env;

  aff_env = *envp;
  while (aff_env != NULL)
    {
      my_putstr(aff_env->str);
      my_putchar('\n');
      aff_env = aff_env->next;
    }
}

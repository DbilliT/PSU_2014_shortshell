/*
** my_sighandler.c for my_sighandler in /home/bechad_p/rendu/PSU_2014_minishell2
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Fri Nov 21 16:33:59 2014 Pierre Bechade
** Last update Fri Nov 28 17:49:49 2014 Pierre Bechade
*/

#include "my.h"

void	my_sighandler(int sig)
{
  if (sig == SIGINT)
    {
      my_putchar('\n');
      my_putstr("$>");
    }
}

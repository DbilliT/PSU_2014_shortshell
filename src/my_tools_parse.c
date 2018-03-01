/*
** my_tools_parse.c for my_tools_parse.c	 in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Thu Nov 27 17:05:04 2014 Pierre Bechade
** Last update Thu Nov 27 17:05:37 2014 Pierre Bechade
*/

#include "my.h"
#include "tree.h"

char	*c_to_str(char c)
{
  char	*new;

  new = my_xmalloc(sizeof(char) * 2);
  new[0] = c;
  new[1] = '\0';
  return (new);
}

char	*s_left(char *str, int tmp)
{
  str[tmp] = '\0';
  return (str);
}

int	my_is_op(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == ';' || str[i] == '|')
        return (-1);
      i++;
    }
  return (0);
}

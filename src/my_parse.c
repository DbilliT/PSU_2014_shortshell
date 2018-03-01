/*
** my_parse.c for my_parse in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Mon Nov 24 11:58:33 2014 Pierre Bechade
** Last update Fri Nov 28 17:09:47 2014 Pierre Bechade
*/

#include "my.h"
#include "tree.h"

char	*my_clean_str(char *str)
{
  int	i;
  int	j;
  char	*new;

  new = my_xmalloc(sizeof(char) * (my_strlen(str) + 1));
  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\t')
	while (str[i] == '\t')
	  str[i++] = ' ';
      else if (str[i] == ' ' && str[i + 1] == ';')
	i++;
      else if (str[i] != ' ' && str[i + 1] == ' ')
	{
	  new[j++] = str[i++];
	  while (str[i + 1] == ' ')
	    i++;
	}
      else
	new[j++] = str[i++];
    }
  new[j] = '\0';
  return (new);
}

t_tree		*my_prio(char *str, t_tree **add)
{
  int		size;
  int		tmp;
  char		*tmp_b;
  char		*tmp_p;

  size = 0;
  size = my_strlen(str);
  tmp_b = my_strdup("");
  tmp_p = my_strdup("");
  while (size >= 0)
    {
      (str[size] == '|') ? tmp = size, tmp_b[0] = '|' : 0;
      (str[size] == ';') ? tmp = size, tmp_p[0] = ';', size = 0 : 0;
      size--;
    }
  if (my_is_op(str) == 0)
    return (*add = my_create(str, NULL));
  else if (tmp_p[0] != '\0')
    *add = my_create(NULL, c_to_str(tmp_p[0]));
  else if (tmp_b[0] != '\0')
    *add = my_create(NULL, c_to_str(tmp_b[0]));
  my_prio(s_left(str, tmp), &(*add)->left);
  my_prio(str + tmp + 1, &(*add)->right);
  return (*add);
}

t_tree		*my_parse(char *str)
{
  t_tree	*result;

  result = NULL;
  result = my_prio(my_clean_str(str), &result);
  return (result);
}


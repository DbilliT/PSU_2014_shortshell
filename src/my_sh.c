/*
** my_sh.c for my_sh in /home/bechad_p/rendu/PSU_2014_minishell2/src
** 
** Made by Pierre Bechade
** Login   <bechad_p@epitech.net>
** 
** Started on  Fri Nov 21 18:26:19 2014 Pierre Bechade
** Last update Sun Nov 30 15:26:28 2014 Pierre Bechade
*/

#include "my.h"
#include "tree.h"

char		**add_tab(t_env **envp)
{
  t_env		*cpy;
  int		i;
  char		**new;

  i = 0;
  cpy = *envp;
  while (cpy != NULL)
    {
      cpy = cpy->next;
      i++;
    }
  cpy = *envp;
  new = my_xmalloc(sizeof(char *) * i);
  i = 0;
  while (cpy != NULL)
    {
      new[i] = my_strdup(cpy->str);
      cpy = cpy->next;
      i++;
    }
  new[i] = NULL;
  return (new);
}

char		*prompt(t_env **envp, char **tab)
{
  char		*str;
  int		nbr;
  char		**tabp;
  t_tree	*sort;

  str = my_xmalloc(sizeof(char) * 4096);
  if (get_path(*envp) != NULL)
    tabp = my_path_to_wordtab(get_path(*envp));
  else
    tabp = NULL;
  my_putchar('\b');
  my_putchar('\b');
  my_putstr("$>");
  if ((nbr = read(0, str, 4096)) == 0)
    {
      write(1, "\nexit\n", 6);
      return (NULL);
    }
  str[nbr - 1] = '\0';
  sort = my_parse(str);
  if (nbr > 0)
    my_calcul(&sort, tab, envp, tabp);
  return (prompt(envp, tab));
}

t_env	**add_end(t_env **list, char *data)
{
  t_env	*new;
  t_env	*temp;

  new = my_xmalloc(sizeof(t_env));
  new->str = data;
  new->next = NULL;
  if (*list == NULL)
    {
      *list = new;
      return (list);
    }
  else
    {
      temp = *list;
      while (temp->next != NULL)
	temp = temp->next;
      temp->next = new;
      return (list);
    }
}

void	add(t_env **list, char **data)
{
  int	i;

  i = 0;
  while (data[i] != '\0')
    {
      list = add_end(list, data[i]);
      i++;
    }
}

int	main(int ac, char **av, char **envp)
{
  t_env	*env_copy;
  char	**tab;

  ac = ac;
  av = av;
  tab = NULL;
  env_copy = NULL;
  signal(SIGINT, my_sighandler);
  if (envp[0] == NULL)
    {
      my_putstr_e("Error : No environnement found\n");
      return (-1);
    }
  add((&env_copy), envp);
  prompt(&env_copy, tab);
  return (0);
}

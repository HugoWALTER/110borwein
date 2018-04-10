/*
** main.c for main.c in /home/walter_h/110borwein
**
** Made by Hugo WALTER
** Login   <walter_h@epitech.net>
**
** Started on  Mon Apr 10 14:33:46 2017 Hugo WALTER
** Last update Wed Apr 12 16:02:00 2017 Hugo WALTER
*/

#include "my.h"

t_mapsize       *init_struct(t_mapsize *ms)
{
  ms->b = 0;
  ms->c = 5000;
  ms->d = ms->b;
  ms->e = (ms->c - ms->b) / 10000;
  ms->somme = 0;
  ms->pas = (double)ms->e;
  ms->f = 0;
  ms->g = 5000;
  ms->h = 5000.0 / 10000.0;
  ms->som = 1.0;
  ms->j = 0;
  ms->k = 5000.0;
  ms->l = (ms->k - ms->j) / 10000.0;
  ms->sm = 0;
  ms->final = 0;
  return (ms);
}

int	my_help()
{
  printf("USAGE\n\t./110borwein n\n\nDESCRIPTION\n\t\e[1mn\e[0m constant defining the integral to be computed\n");
  exit(84);
}

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      i++;
    }
  if (atoi(str) > 5000)
    return (1);
  return (0);
}

double  calc(int n, double x)
{
  double        somme;
  int           i;

  somme = 1;
  i = 0;
  while (i <= n)
    {
      if (x != 0)
	somme *= (sin(x / ((2.0 * i) + 1.0)) / (x / ((2.0 * i) + 1.0)));
      i++;
    }
  return (somme);
}

int     rectangle(double a, t_mapsize *ms)
{
  int		i;
  double	bs;

  i = 0;
  while (i < 10000)
    {
      ms->somme = ms->somme + calc(a, (ms->b + i * ms->pas));
      i++;
    }
  ms->somme = ms->somme * ms->pas;
  printf("Rectangles:\n");
  printf("I%.0f = %.10f\n", a, ms->somme);
  bs = ms->somme - (M_PI / 2);
  if (bs > -0.00000001 && bs <= 0.0)
    printf("diff = %.10f\n\n", fabs(bs));
  else
    printf("diff = %.10f\n\n", bs);
  return (0);
}

int     trapeze(double a, t_mapsize *ms)
{
  int		i;
  double	bs;

  i = 0;
  while (i < 10000)
    {
      ms->som = ms->som + calc(a, (i * ms->h));
      i++;
    }
  ms->som = ((ms->som * 2.0) + calc(a, ms->f) + calc(a, ms->g)) * (ms->g / 20000.0);
  ms->som = ms->som - 1;
  printf("Trapezoids:\n");
  printf("I%.0f = %.10f\n", a, ms->som);
  bs = ms->som - (M_PI / 2);
  if (bs > -0.00000001 && bs <= 0.0)
    printf("diff = %.10f\n\n", fabs(bs));
  else
    printf("diff = %.10f\n\n", bs);
  return (0);
}

int     simpson(double a, t_mapsize *ms)
{
  double	i;
  double	bs;

  i = 1;
  while (i < 10000)
    {
      ms->sm += calc(a, (i * ms->l));
      i++;
    }
  i = 0;
  while (i < 10000)
    {
      ms->final = ms->final + calc(a, (ms->j + i * ms->l) + (ms->l / 2.0));
      i++;
    }
  ms->res = ((ms->sm * 2) + (ms->final * 4) + calc(a, ms->j) + calc(a, ms->k)) * ((ms->k - ms->j) / 60000.0);
  printf("Simpson:\n");
  printf("I%.0f = %.10f\n", a, ms->res);
  bs = ms->res - (M_PI / 2);
  if (bs > -0.00000001 && bs <= 0.0)
    printf("diff = %.10f\n", fabs(bs));
  else
    printf("diff = %.10f\n", bs);
  return (0);
}

int	check_float(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    if (str[i] >= '0' && str[i] <= '9')
      i++;
    else
      exit(84);
  return (0);
}

int	check_error(int ac, char **av)
{
  if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
    my_help();
  if (ac == 1)
    exit(84);
  if (ac > 2)
    exit(84);
  if (atoi(av[1]) < 0)
    exit(84);
  check_float(av[1]);
}

int	main(int ac, char **av)
{
  t_mapsize	*ms;

  if ((ms = malloc(sizeof(t_mapsize))) == NULL)
    return (84);
  ms = init_struct(ms);
  check_error(ac, av);
  if (ac == 2)
    {
      if ((my_str_isnum(av[1])) == 0)
	{
	  rectangle(atoi(av[1]), ms);
	  trapeze(atoi(av[1]), ms);
	  simpson(atoi(av[1]), ms);
	}
      else
	my_help();
    }
  return (0);
}

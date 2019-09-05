#include "lem_in.h"

int	tablen(t_room **tab)
{
  return (tab && tab[0] ? tablen(tab + 1) + 1 : 0);
}

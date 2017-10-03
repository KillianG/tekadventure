/*
** init_fist.c for tekadv in /root/Delivery/tekaventure/Client/fist
** 
** Made by root
** Login   <kentin.pratelli@epitech.eu>
** 
** Started on  Tue Oct  3 06:06:48 2017 root
** Last update Tue Oct  3 15:43:43 2017 root
*/

#include "tekadv.h"

void		init_fist(t_displayer *displayer)
{
  t_fist	*fist;

  fist = malloc(sizeof(t_fist));
  if (fist == NULL)
    return ;
  fist->pos = vector2f(0, 0);
  fist->sprite = init_sprite(FIST, vector2f(0, 0),
			     vector2f(0.25, 0.25));
  fist->damages = 1;
  displayer->player->fist = fist;
}

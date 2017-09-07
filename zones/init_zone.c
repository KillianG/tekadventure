/*
** init_zone.c for tekadv in /home/killian/github/tekaventure/zones
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Thu Sep  7 14:48:45 2017 Killian
** Last update Thu Sep  7 16:42:49 2017 Killian
*/

#include "tekadv.h"

#include <time.h>

void		init_zone(t_displayer *displayer)
{
  sfCircleShape	*blue;
  sfVector2f	pos;

  srand(time(NULL));
  pos.x = (rand() % MAP_SIZEX) - 100;
  pos.y = (rand() % MAP_SIZEY) - 100;
  blue = sfCircleShape_create();
  sfCircleShape_setPosition(blue, pos);
  sfCircleShape_setRadius(blue, 100);
  sfCircleShape_setFillColor(blue, sfTransparent);
  sfCircleShape_setOutlineColor(blue, sfBlue);
  /*sfCircleShape_setOrigin(blue, vector2f(RADIUS, RADIUS));*/
  sfCircleShape_setOutlineThickness(blue, 10);
  displayer->blue_zone = blue;
  displayer->blue_start = pos;
}

/*
** displayer.c for tekadv in /home/killian/github/tekaventure/utils
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:32:50 2017 Killian
** Last update Tue Oct  3 15:36:22 2017 root
*/

#include "tekadv.h"

#include <time.h>

t_displayer		*init_displayer_part2(t_displayer *displayer)
{
  init_arrow(displayer);
  init_zone(displayer);
  init_houses(displayer);
  init_weapons(displayer);
  init_ennemies(displayer);
  init_hp(displayer);
  init_players(displayer);
  init_helmets(displayer);
  init_ammos(displayer);
  init_fist(displayer);
  return (displayer);
}

t_displayer		*init_displayer(int id)
{
  t_displayer           *displayer;
  sfRenderWindow        *window;
  sfSprite		*sprite;
  float			x;
  float			y;

  srand(time(NULL));
  x = (rand() % 10) * -1;
  y = (rand() % 10) * -1;
  window = create_window(GAME_NAME, SCREEN_WIDTH, SCREEN_HEIGHT);
  sprite = init_sprite(BACKGROUND, vector2f(x, y), vector2f(1.5, 1.5));
  if ((displayer = malloc(sizeof(t_displayer))) == NULL)
    return (NULL);
  displayer->window = window;
  displayer->map = sprite;
  displayer->player = init_player(id);
  displayer->player->pos.x = x;
  displayer->player->pos.y = y;
  displayer->bullet = init_sprite(BULLET, vector2f(0, 0), vector2f(0.2, 0.2));
  displayer->blue_radius = RADIUS;
  init_ammo_text(displayer);
  displayer = init_displayer_part2(displayer);
  return (displayer);
}
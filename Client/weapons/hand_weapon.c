/*
** hand_weapon.c for tekadv in /home/killian/github/tekaventure/weapons
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Sep  6 20:09:06 2017 Killian
** Last update Wed Oct  4 16:43:09 2017 Killian
*/

#include "tekadv.h"

void		draw_hand_weapon(t_displayer *displayer)
{
  if (displayer->player->weapon == NULL)
    return ;
  sfSprite_setPosition(displayer->player->weapon->sprite,
		       vector2f(SCREEN_WIDTH / 2 , SCREEN_HEIGHT - 50));
  sfSprite_setOrigin(displayer->player->weapon->sprite, vector2f(87, 25));
  sfSprite_setScale(displayer->player->weapon->sprite, vector2f(0.5, 0.5));
  sfRenderWindow_drawSprite(displayer->window,
			    displayer->player->weapon->sprite, NULL);
}

/*
** initializer.c for tekadventure in /home/ratch7t/Documents/semester_2/github/tekaventure/src
** 
** Made by ratch7t
** Login   <rudy.simon@epitech.eu>
** 
** Started on  Wed Sep  6 15:54:36 2017 ratch7t
** Last update Sat Oct  7 18:20:11 2017 Killian
*/

#include "rudy.h"

sfSprite	*init_sprite_menu(char *path)
{
  sfTexture	*texture;
  sfSprite	*sprite;

  sprite = sfSprite_create();
  if (sprite == NULL)
    return (NULL);
  texture = sfTexture_createFromFile(path, NULL);
  if (texture == NULL)
    return (NULL);
  sfTexture_setSmooth(texture, sfTrue);
  sfSprite_setTexture(sprite, texture, sfTrue);
  return (sprite);
}

t_displayer	*init_displayer_menu(void)
{
  t_displayer	*disp;

  if (!(disp = malloc(sizeof(t_displayer))))
    exit(84);
  disp->window = create_window_menu(GAME_NAME, SCREEN_WIDTH, SCREEN_HEIGHT);
  disp->zombies = 0;
  return (disp);
}

t_sprite	*init_str_sprite(void)
{
  t_sprite	*sprit;

  if (!(sprit = malloc(sizeof(t_sprite))))
    exit(84);
  sprit->zomb_01 = init_sprite_menu(ZOMBIE_1);
  sprit->background = init_sprite_menu(MENU_STANDARD);
  sprit->nw_game = init_sprite_menu(MENU_PLAY);
  sprit->option = init_sprite_menu(MENU_OPTION);
  sprit->exit = init_sprite_menu(EXIT);
  sprit->cursor = init_sprite_menu(MOUSE);
  sfSprite_setScale(sprit->cursor, vector2f(0.05, 0.05));
  return (sprit);
}

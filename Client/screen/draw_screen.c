/*
** draw_screen.c for tekadv in /home/killian/github/tekaventure/screen
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:31:30 2017 Killian
** Last update Sun Oct  8 18:00:10 2017 Killian
*/

#include <unistd.h>
#include "tekadv.h"

void		launch_thread(t_displayer *displayer)
{
  sfThread	*update;

  update = sfThread_create(loop_update, (void *)displayer);
  sfThread_launch(update);
}

void		draw_game(int id)
{
  sfThread	*draw;
  t_displayer	*displayer;

  displayer = init_displayer(id);
  read_config(displayer);
  launch_thread(displayer);
  draw = sfThread_create(loop_draw, (void *)displayer);
  start_music();
  while (!sfKeyboard_isKeyPressed(sfKeyEscape))
    {
      sfThread_launch(draw);
      loop_network((void *)displayer);
      displayer->player->angle = get_angle_from_mouse(displayer);
      sfThread_wait(draw);
      get_entries(displayer);
      update(displayer);
      displayer->player = update_player(displayer->player);
      sfRenderWindow_display(displayer->window);
      sfRenderWindow_clear(displayer->window, sfWhite);
    }
  free(displayer);
  exit(1);
}

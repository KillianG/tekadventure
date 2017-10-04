/*
1;4402;0c** draw_screen.c for tekadv in /home/killian/github/tekaventure/screen
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:31:30 2017 Killian
** Last update Wed Oct  4 12:11:00 2017 Killian
*/

#include <unistd.h>
#include "tekadv.h"

void		launch_thread(t_displayer *displayer)
{
  //sfThread	*network;
  sfThread	*update;

  //network = sfThread_create(loop_network, (void *)displayer);
  update = sfThread_create(loop_update, (void *)displayer);
  sfThread_launch(update);
  //  sfThread_launch(network);
}

void		draw_game(int id)
{
  t_displayer	*displayer;
  sfThread	*draw;

  displayer = init_displayer(id);
  launch_thread(displayer);
  draw = sfThread_create(loop_draw, (void *)displayer);
  while (!sfKeyboard_isKeyPressed(sfKeyEscape))
    {
      loop_network(displayer);
      sfThread_launch(draw);
      displayer->player->angle = get_angle_from_mouse(displayer);
      move_player_mouse(displayer);
      sfThread_wait(draw);
      get_entries(displayer);
      update(displayer);
      displayer->player = update_player(displayer->player);
      sfRenderWindow_display(displayer->window);
      sfRenderWindow_clear(displayer->window, sfBlack);
    }
  exit(1);
}
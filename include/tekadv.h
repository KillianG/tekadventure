/*
** tekadv.h for tekadv in /home/killian/github/tekaventure/include
** 
** Made by Killian
** Login   <killian.gardahaut@epitech.eu>
** 
** Started on  Wed Aug 30 16:16:52 2017 Killian
** Last update Thu Sep  7 16:48:55 2017 Killian
*/

#ifndef TEKADV_H_
# define TEKADV_H_

# include <SFML/Graphics.h>
# include <SFML/Window.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

/* __________ WINDOW UTILS _________ */

# define GAME_NAME "Tekadventure"
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 800
# define FONT "utils/font.ttf"

/* __________ PLAYER UTILS _________ */

# define SPEED 0.2
# define RADIUS 3000
# define ZONE_DMG 0.001
# define ZONE_SPEED 0.01

/* __________ MAP __________ */

# define MAP_SIZEX 4000
# define MAP_SIZEY 4000

/* __________ MATH UTILS _________ */

# define M_PI 3.14159265359
# define TO_RAD(a) (M_PI * a / 180)
# define SQUARE(a) (a*a)

/* __________ HOUSES UTILS __________ */

# define NB_HOUSES 5

/* _________ SPRITES ________ */

# define BACKGROUND "images/background.jpg"
# define PLAYER "images/players.png"
# define HOUSE "images/house.png"
# define AK47 "images/ak47.png"
# define BULLET "images/bullet.png"
# define AUG "images/aug.png"
# define FAMAS "images/Famas.png"
# define M416 "images/M416.png"
# define MK14 "images/mk14.png"
# define PKP "images/PKP.png"
# define ARROW "images/blue_arrow.png"

/* __________ WEAPONS UTILS __________*/

# define NB_WEAPONS 4
# define AK_DMG 15
# define AUG_DMG 8
# define FAMAS_DMG 10
# define M416_DMG 20
# define MK14_DMG 30

/* __________ ENNEMY UTILS _________ */

# define NB_ENNEMY 2
# define ENNEMY "images/Ganon.png"

/* __________ STRUCTURES __________ */

typedef struct		s_weapon
{
  sfVector2f		pos;
  sfVector2f		start;
  sfSprite		*sprite;
  int			damages;
  int			is_hand;
}			t_weapon;

typedef struct		s_house
{
  sfSprite		*sprite;
  sfIntRect		hitbox;
  sfVector2f		pos;
  sfVector2f		start;
}			t_house;

typedef struct          s_ennemy
{
  int                   hp;
  sfVector2f            pos;
  sfVector2f		start;
  sfSprite              *sprite;
}                       t_ennemy;

typedef struct          s_player
{
  float                 hp;
  sfVector2f            pos;
  int                   has_weapon;
  sfSprite              *sprite;
  sfIntRect             hitbox;
  t_weapon		*weapon;
  int			sprite_pos;
  int			shoot;
  float			shooting_angle;
}                       t_player;

typedef struct		s_displayer
{
  sfSprite		*arrow;
  float			blue_radius;
  sfVector2f		blue_start;
  sfCircleShape		*blue_zone;
  sfSprite		*bullet;
  sfRenderWindow	*window;
  sfSprite		*map;
  t_player		*player;
  t_house		*houses[NB_HOUSES + 1];
  t_weapon		*weapons[NB_WEAPONS + 1];
  t_ennemy		*ennemies[NB_ENNEMY + 1];
  sfText		*hp;
}			t_displayer;

/* __________ FUNCTIONS _________*/

void		draw_game();
t_displayer	*init_displayer();
sfRenderWindow	*create_window(char *, int, int);
sfSprite	*init_sprite(char *, sfVector2f, sfVector2f);
sfVector2f	vector2f(float, float);
t_player	*update_player(t_player *);
t_player	*init_player();
sfIntRect	int_rect(int, int, int, int);
void		get_entries(t_displayer *);
void		move_left(t_displayer *);
void		move_right(t_displayer *);
void		move_up(t_displayer *);
void		move_down(t_displayer *);
void		update_map(t_displayer *);
t_house		*init_house(sfVector2f, t_displayer *);
t_displayer	*init_houses(t_displayer *);
void		update_house(t_house *, t_displayer *);
void		update(t_displayer *);
int		collide(t_displayer *);
t_weapon	*init_weapon();
void		draw_houses(t_displayer *);
void		update_weapon(t_weapon *, t_displayer *);
void		interact(t_displayer *);
int		menu();
void		draw_hand_weapon(t_displayer *);
float		get_angle_from_mouse(t_displayer *);
sfVector2f	move_forward(sfVector2f, float, float);
void		shoot(t_displayer *);
void		continue_shooting(t_displayer *);
t_displayer	*init_weapons(t_displayer *);
void		update_weapons(t_displayer *);
void		draw_weapons(t_displayer *);
void		drop_weapon(t_displayer *);
t_ennemy	*init_ennemy(sfVector2f);
void		init_ennemies(t_displayer *);
void		draw_ennemies(t_displayer *);
void		update_ennemies(t_displayer *);
char		*my_itoa(int);
void		init_hp(t_displayer *);
void		update_hp(t_displayer *);
void		init_zone(t_displayer *);
void		draw_zone(t_displayer *);
void		update_zone(t_displayer *);
void		check_in(t_displayer *);
float		get_angle_from_pos(sfVector2f);
void		init_arrow(t_displayer *);
void		draw_arrow(t_displayer *);

#endif

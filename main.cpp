/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:37:56 by cdeniau           #+#    #+#             */
/*   Updated: 2015/11/08 17:16:18 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"
#include <string>
#include <chrono>
#include <thread>

void		scr_init( void ){


	initscr();
	curs_set(0); /* Hide cursor */
	noecho();
	keypad(stdscr, TRUE);
	timeout(0);
}

void get_action(Player *player, Enemy *bullet ){

	int		c = 0;

	while ( (c = getch() ) != ERR )
	{	
		if (c)
		{
			if (c == KEY_RIGHT && player->getW() < MAX_W)
				player->setW(player->getW() + 1);
			else if (c == KEY_LEFT && player->getW() > 0)
				player->setW(player->getW() - 1);
			else if (c == ' ')
			{
				if (bullet->getFlag() == 1)
					bullet->setFlag(0);
				else
					bullet->setFlag(1);
			}
			else if (c == 's')
				bullet->create_Special(bullet, player->getW(), player->getH());
			else if (c == 27)
				exit(0);
			bullet->create_Bullet(bullet, player->getW(), player->getH());
		}
	}
}

void		random_generate(Enemy *enemy) {
	if (rand() % 6)
		enemy->create_Enemy(enemy, random() % MAX_W, 0);
}

void		borders(Player *player) {
	int i = -1;
	int j = -1;
	int			max_y, max_x;

	move(0, 0);
	mvprintw(1, 1, "HP:");
	mvprintw(1, 9, "%i", player->getHp());
	mvprintw(2, 1, "Time:");
	mvprintw(2, 9, "%2.1f", ((double)clock() / 8000));
	mvprintw(3, 1, "Score:");
	mvprintw(3, 9, "%i", player->getScore() - 200);
	getmaxyx(stdscr, max_y, max_x);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	noecho();
	attron(COLOR_PAIR(1));
	while (++i < max_x)
	{
		mvprintw(i, 0, "#");
		mvprintw(i, max_y, "#");
	}
	while (++j < max_y)
	{
		mvprintw(0, j, "#");
		mvprintw(max_y - 1, j, "#");
	}
	attroff(COLOR_PAIR(1));
}

void		scr_update( Player *player, Enemy *enemy, Enemy *bullet) {
	erase();
	borders(player);
	mvprintw(player->getH(), player->getW(), PLAYER);
	enemy->check_Position(enemy, player);
	bullet->check_Bullet(bullet, enemy, player);
	if (player->getHp() <= 0)
		exit(0);
	enemy->update_Position(enemy);
	bullet->update_Bullet(bullet);
	refresh();
}

void		ncurses_loop( Player *player, Enemy *enemy, Enemy *bullet) {
	struct timeval	st;
	struct timeval	end;
	while ( 1337 )
	{
		gettimeofday(&st, NULL);
		get_action(player, bullet);
		bullet->create_Bullet(bullet, player->getW(), player->getH());
		random_generate(enemy);
		gettimeofday(&end, NULL);
		if (st.tv_usec < end.tv_usec)
			st.tv_usec = end.tv_usec;;
		usleep(( FRAME * 1000 ) - ( end.tv_usec - st.tv_usec ));
		scr_update(player, enemy, bullet);
	}
}

int 		main(void) {
	Player 		*player = new Player;
	Enemy 		*enemy = new Enemy[MAX_ENEMY];
	Enemy 		*bullet = new Enemy[MAX_BULLET];

	srand( time(NULL) );
	scr_init();
	scr_update( player, enemy, bullet);
	ncurses_loop(player, enemy, bullet);
	return (0);
}

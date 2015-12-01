/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 08:59:33 by cdeniau           #+#    #+#             */
/*   Updated: 2015/11/08 16:45:03 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "ft_retro.hpp"
# include "Ship.hpp"
# define MAX_ENEMY 10
# define MAX_BULLET 200

class Enemy : public  Ship {

public:

	Enemy(void);
	Enemy(int w, int h, int hp, int score, unsigned int bullet);
	Enemy(Enemy const & src);
	~Enemy(void);
	Enemy 			& operator=(Enemy const & rhs);
	Enemy  			&operator+=(int value);
	Enemy  			&operator-=(int value);
	void 			update_Position(Enemy enemy[MAX_ENEMY]);
	void 			update_Bullet(Enemy bullet[MAX_BULLET]);
	void 			gen_Mov();
	void 			gen_Bullet();
	void 			create_Enemy(Enemy enemy[MAX_ENEMY], int w, int h);
	void 			create_Bullet(Enemy Bullet[MAX_BULLET], int w, int h);
	void 			create_Special(Enemy Bullet[MAX_BULLET], int w, int h);
	void 			check_Position(Enemy enemy[MAX_ENEMY], Player *player);
	void 			check_Bullet(Enemy bullet[MAX_BULLET], Enemy enemy[MAX_ENEMY], Player *player);

private:

};

//std::ostream 				& operator<<(std::ostream & out, Enemy const & src);

#endif

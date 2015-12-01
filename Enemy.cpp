/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 08:43:00 by cdeniau           #+#    #+#             */
/*   Updated: 2015/11/08 16:45:58 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"
#include "Ship.hpp"
#include "Enemy.hpp"

Enemy::Enemy(void) : Ship(){
	this->_w = 1;
	this->_h = 1;
	this->_hp = 1;
	this->_score = 0;
	this->_bulletFlag = 0;
	return;
}

Enemy::Enemy(int w, int h, int hp, int score, unsigned int bullet) : Ship(w, h, hp, score, bullet){

	this->_w = w;
	this->_h = h;
	this->_hp = 0;
	this->_score = 0;
	this->_bulletFlag = 0;
	return;
}

Enemy::Enemy(Enemy const & src) : Ship(src){
	*this = src;
	return ;
}

Enemy::~Enemy(void){
	return;
}

Enemy 			& Enemy::operator=(Enemy const & rhs){
	setW(rhs.getW());
	setH(rhs.getH());
	setHp(rhs.getHp());
	return *this;
}

Enemy & Enemy::operator+=(int value)
{
	this->_h = this->_h + value;
	return (*this);
}

Enemy & Enemy::operator-=(int value)
{
	this->_h = this->_h - value;
	return (*this);
}


void Enemy::gen_Mov()
{
	if ( random() % 20 )
	{
		if ( this->getW() - 1 > 0 )
			this->setW( this->getW() - 1 );
		if ( this->getW() + 1 < MAX_W )
			this->setW( this->getW() + 1 );
		else
			return;
	}
}

void Enemy::gen_Bullet()
{
	if ( random() % 20 )
	{
		if ( this->getW() - 1 > 0 )
			this->setW( this->getW() - 1 );
		if ( this->getW() + 1 < MAX_W )
			this->setW( this->getW() + 1 );
		else
			return;
	}
}


void Enemy::create_Enemy(Enemy enemy[MAX_ENEMY], int w, int h){
	int i = 0;

	while (i < MAX_ENEMY)
	{
		if (enemy[i].getHp() <= 0)
		{	
			enemy[i].setW(w);
			enemy[i].setH(h);
			enemy[i].setHp(1);
			break;
		}
		i++;
	}
}

void Enemy::create_Bullet(Enemy bullet[MAX_BULLET], int w, int h){
	int i = 0;

	while (i < MAX_BULLET && bullet->getFlag())
	{
		if (bullet[i].getHp() <= 0)
		{	
			bullet[i].setW(w);
			bullet[i].setH(h);
			bullet[i].setHp(1);
			break;
		}
		i++;
	}
}

void Enemy::create_Special(Enemy bullet[MAX_BULLET], int w, int h){
	int i = 0;

	(void)w;
	while (i < MAX_W)
	{
		bullet[i].setW(i);
		bullet[i].setH(h);
		bullet[i].setHp(1);
		i++;
	}
}

void Enemy::check_Position(Enemy enemy[MAX_ENEMY], Player *player) // projectile c'est le contraire
{
	int i = 0;

	while (i < MAX_ENEMY)
	{
		if ((player->getW() == enemy[i].getW()) && (player->getH() == enemy[i].getH()))
			player->shoot();
		if (enemy[i].getH() > MAX_H) // < pour le tir player qui monte
		{
			enemy[i].setHp(0); //destroy
					player->setScore(player->getScore() - 1);
		}
		i++;
	}
}

void Enemy::check_Bullet(Enemy bullet[MAX_BULLET], Enemy enemy[MAX_ENEMY], Player *player)
{
	int i = 0;
	int	j;

	while (i < MAX_BULLET)
	{
		j = -1;
		while (++j < MAX_ENEMY)
		{
			if (((enemy[j].getW() == bullet[i].getW()) && enemy[j].getH() >= bullet[i].getH()))
			{
				if (bullet[i].getHp() == 1)
					player->setScore(player->getScore() + 1);
				bullet[i].setHp(0); //destroy
				enemy[j].setHp(0); //destroy
			}
		}
		if (bullet[i].getH() <= 0) // < pour le tir player qui monte
			bullet[i].setHp(0); //destroy
		i++;
	}
}

void Enemy::update_Position(Enemy enemy[MAX_ENEMY])
{

	int i = 0;
	while (i < MAX_ENEMY)
	{
		if (enemy[i].getHp() > 0)
		{
			enemy[i] += 1; //enemey ++
			enemy[i].gen_Mov(); 
			mvprintw(enemy[i].getH(), enemy[i].getW(), ENEMY);
		}
		i++;
	}
}

void Enemy::update_Bullet(Enemy bullet[MAX_BULLET])
{
	int i = 0;
	while (i < MAX_BULLET)
	{
		if (bullet[i].getHp() > 0)
		{
			bullet[i] -= 1; //enemey ++
			bullet[i].gen_Bullet(); 
			mvprintw(bullet[i].getH(), bullet[i].getW(), "|");
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 12:19:28 by cdeniau           #+#    #+#             */
/*   Updated: 2015/11/08 16:34:18 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_retro.hpp"

Ship::Ship(void){
	setW(0);
	setH(0);
	setHp(1);
	setScore(0);
	setFlag(0);
	return ;
}
Ship::Ship(unsigned int w, unsigned int h, unsigned int hp, unsigned int score, unsigned int flag) {
	setW(w);
	setH(h);
	setHp(hp);
	setScore(score);
	setFlag(flag);
	return ;
}

Ship::~Ship(void){

}

unsigned int					Ship::getW(void) const{
	return _w;
}

unsigned int					Ship::getH(void) const{
	return _h;
}

unsigned int					Ship::getHp(void) const{
	return _hp;
}

unsigned int					Ship::getScore(void) const{
	return _score;
}

unsigned int					Ship::getFlag(void) const{
	return _bulletFlag;
}

void					Ship::setW(unsigned int w){
	_w = w;
	return ;
}

void					Ship::setScore(unsigned int score){
	_score = score;
	return ;
}

void					Ship::setFlag(unsigned int flag){
	_bulletFlag = flag;
	return ;
}

void					Ship::setH(unsigned int h){
	_h = h;
	return ;
}

void					Ship::setHp(unsigned int hp){
	_hp = hp;
	return ;
}

void					Ship::move(unsigned int w, unsigned int h) {
	setW(w);
	setH(h);
	return ;
}

Ship 					&Ship::operator=(Ship const & rhs){
	setW(rhs.getW());
	setH(rhs.getH());
	return *this;
}

Ship::Ship(Ship const & src){
	*this = src;
	return ;
}

/*
void	Ship::setMap(Map *map){
	_map = map;
	return;
}

std::ostream 	& operator<<(std::ostream & o, Ship const & rhs){

	return o;
}*/

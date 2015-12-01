/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 15:33:10 by cdeniau           #+#    #+#             */
/*   Updated: 2015/11/08 16:28:19 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_HPP
# define SHIP_HPP

# include "ft_retro.hpp"

class Ship {

public:
	Ship(void);
	Ship(unsigned int w, unsigned int h, unsigned int hp, unsigned int score, unsigned int bulletflag);
	Ship(Ship const & src);
	 ~Ship(void);
	unsigned int			getW(void) const;
	unsigned int			getH(void) const;
	unsigned int			getHp(void) const;
	unsigned int			getScore(void) const;
	unsigned int			getFlag(void) const;
	void					setW(unsigned int w);
	void					setH(unsigned int h);
	void					setHp(unsigned int hp);
	void					setFlag(unsigned int bulletflag);
	void					setScore(unsigned int score);
	Ship 					& operator=(Ship const & rhs);

	void			move(unsigned int w, unsigned int h);
	//void			destroy(void);

protected:
	 int					_w;
	 int					_h;
	unsigned int			_hp;
	unsigned int			_score;
	unsigned int			_bulletFlag;
};

//std::ostream 	& operator<<(std::ostream & out, Ship const & src);

#endif

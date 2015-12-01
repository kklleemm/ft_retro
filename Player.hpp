/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 10:39:02 by cdeniau           #+#    #+#             */
/*   Updated: 2015/11/08 12:17:08 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "ft_retro.hpp"
# include <iostream>
# include <iomanip>
# include <sstream>


class Player : public Ship {

public:

	Player(void);
	//Player(unsigned int w, unsigned int h,unsigned int hp);
	Player(Player const & src);
	~Player(void);

	Player 			&operator=(Player const &rhs);

	void			move(int c, int max_w);
	void			shoot(void);
	//void			destroy(void);

private:
	
};

//std::ostream 	& operator<<(std::ostream & out, Player const & src);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dqh.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:00:19 by cdeniau           #+#    #+#             */
/*   Updated: 2015/11/08 16:11:36 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO
# define FT_RETRO
# define MAX_W		76
# define MAX_H		78
# include <ncurses.h>
# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "Ship.hpp"
# include "Player.hpp"
# include "Enemy.hpp"
#include <sys/time.h>

# define PLAYER		"^"
# define ENEMY		"o"
# define FSHOT		124
# define MAX_ENEMY 	10
//# define MAX_PROJECTILE 30
# define FRAME 60

#endif

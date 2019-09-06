/*
 * player.hpp
 *
 *  Created on: Aug 19, 2019
 *      Author: Shreya
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include<iostream>

class Player
{
private:
	std::string player_name;
	unsigned int score;
public:
	//Player();
	Player(const std::string &p_name,unsigned int& score);
	Player(const std::string &p_name);
	std::string get_player_name();
	unsigned int get_player_score();
	void set_score(int num_flips);
};



#endif /* PLAYER_HPP_ */

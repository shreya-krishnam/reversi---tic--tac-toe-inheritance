/*
 * player.cpp
 *
 *  Created on: Aug 19, 2019
 *      Author: Shreya
 */
#include "player.hpp"
#include<iostream>
//Player::Player():Player{" "}{std::cout<<"loo";}
Player::Player(const std::string& p_name,unsigned int& score):player_name{p_name},score{score}
{

}

Player::Player(const std::string& p_name):player_name{p_name}
{
}

std::string Player::get_player_name()
{
	return player_name;
}

unsigned int Player::get_player_score()
{
	return score;
}

void Player::set_score(int num_flips)
{
score+=num_flips;
}


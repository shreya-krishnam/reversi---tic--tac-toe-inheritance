/*
 * BaseClass.hpp
 *
 *  Created on: Aug 15, 2019
 *      Author: Shreya
 */
#ifndef BASECLASS_HPP_
#define BASECLASS_HPP_

#include<iostream>
#include<vector>
#include<map>
#include<list>
#include "player.hpp"
class BaseClass
{
private:
	unsigned int num_players;
	std::vector <std::vector<std::string> > game_state;
	std::map<int,std::string> symbols;
	char s;
	std::string first_player_symbol;
	std::string second_player_symbol;
	bool game_done_flag;
	unsigned int EmptyCellCount;
	std::vector<unsigned int> row_column;
	unsigned int row_number;
	unsigned int col_number;
	std::map<int,std::string>::iterator itr;
	std::map<std::string,int> get_winner_symbol;
public:
	BaseClass(unsigned int &row_count, unsigned int &col_count,
			std::vector<std::vector<std::string> > &game_state);
	~BaseClass();
	void print_board(std::vector <std::vector<std::string> > &game_state);
	std::vector <std::vector<std::string> > get_game_state();
	unsigned int get_num_players();
	std::map<int,std::string> get_player();
	bool set_IsDone(unsigned int status);
	unsigned int getEmptyCellCount();
	std::vector<unsigned int> get_move_player(Player& p,std::vector <std::vector<std::string> > &game_state);
	std::map<std::string,int> get_win_symbol();
	void DisplayResults(int status);
	bool IsLegal(unsigned int& row_number,unsigned int& col_number,std::vector <std::vector<std::string> > &game_state);
	//unsigned int num_players;
protected:
	unsigned int rows;
	unsigned int columns;
};



#endif /* BASECLASS_HPP_ */

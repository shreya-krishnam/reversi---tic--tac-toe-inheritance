/*
 * TicTacToe.hpp
 *
 *  Created on: Aug 17, 2019
 *      Author: Shreya
 */
//NAME: SHREYA KRISHNAM STUDENT ID:23162697
#ifndef TICTACTOE_HPP_
#define TICTACTOE_HPP_
#include<iostream>
#include<vector>
#include "BaseClass.hpp"
#include "player.hpp"

class TicTacToe: public BaseClass
{
private:
	unsigned int rows;
	unsigned int columns;
	std::vector <std::vector<std::string> > game_state;
	unsigned int check_num_players;
	std::map<int,std::string> symbols;
	unsigned int num_players;
	void start_game_loop(Player& one,Player& two);
	bool game_done;
	unsigned int EmptyCount;
	int turn;
	std::vector<unsigned int> row_column;
	unsigned int row_number;
	unsigned int col_number;
	unsigned int win_status;
	std::map<std::string,int> winning_symbol;
	int check_win();
public:
	TicTacToe(unsigned int& rows,unsigned int &columns,
			std::vector <std::vector<std::string> >& game_state);
	void Start();
	~TicTacToe();
};



#endif /* TICTACTOE_HPP_ */

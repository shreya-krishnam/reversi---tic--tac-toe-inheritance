/*
 * Reversi.hpp
 *
 *  Created on: Aug 23, 2019
 *      Author: Shreya
 */

#ifndef REVERSI_HPP_
#define REVERSI_HPP_

#include<iostream>
#include<vector>
#include "BaseClass.hpp"

class Reversi:public BaseClass
{
private:
	unsigned int rows;
	unsigned int columns;
	unsigned int initial_score;
	std::vector <std::vector<std::string> > game_state;
	unsigned int num_players;
	std::map<int,std::string> symbols;
	void set_initial_game_state();
	void show_scores(Player& one, Player& two);
	void start_game_loop(Player& one, Player& two);
	bool game_done;
	int turn;
	std::vector<unsigned int> row_column;
	bool valid_move_flag;
	bool valid_move(unsigned int current_row,unsigned int current_col,std::string player_symbol);
	std::vector<unsigned int> make_move(Player& p,std::string player_symbol);
	std::string get_opposite_player_symbol(std::string player_symbol);
	unsigned int row_number;
	unsigned int col_number;
	int current_col;
	bool check_bounds(int& current_row,int& current_col);
	unsigned int count_flips(unsigned int & row_number,unsigned int& col_number,std::string player_symbol);
	bool check_any_more_moves(std::string symbol);
	std::vector <std::vector<int> > flips(unsigned int& row_number,unsigned int& col_number,std::string player_symbol);
	std::vector <std::vector<int> > temp_flips;
	std::vector <std::vector<int> > result_flips;
	std::vector<unsigned int> row_col;
	void game_over(Player& one,Player& two);
	unsigned int num_flips;
	int upper_bound;
	int current_row;
	int current_column;
	int row_size;
		int col_size;
		bool any_more_moves;
	std::string opposite_player_symbol;
	std::string current_symbol;
	std::map<std::string,int> winning_symbol;
	int status;
	unsigned int cell_row;
	unsigned int cell_col;
	void change_state(Player& p,Player &opp, std::string symbol,unsigned int &row_number, unsigned int &col_number);


public:
	Reversi(unsigned int& rows,unsigned int & columns,std::vector <std::vector<std::string> > &game_state);
	~Reversi();
	void Start();
	void start_game_loop();
};



#endif /* REVERSI_HPP_ */

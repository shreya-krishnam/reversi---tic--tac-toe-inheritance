/*
 * TicTacToe.cpp
 *
 *  Created on: Aug 17, 2019
 *      Author: Shreya
 */
//NAME: SHREYA KRISHNAM STUDENT ID:23162697
#include<iostream>
#include<vector>
#include<map>
#include <iterator>
#include<list>
#include "TicTacToe.hpp"
TicTacToe::TicTacToe(unsigned int& rows,unsigned int& columns,
		std::vector <std::vector<std::string> >& game_state):BaseClass{rows,columns,game_state},game_state{game_state}
{
	std::cout<<"\nThis is the Derived Class TicTacToe Constructor\n"<<std::endl;
}
TicTacToe::~TicTacToe()
{
	std::cout<<"\nThis is the Derived Class TicTacToe Destructor\n"<<std::endl;
}
int TicTacToe::check_win()
{
		if (game_state[0][0] == game_state [0][1]  && game_state[0][1] == game_state[0][2] && game_state[0][0]!=" " )
			{	if ( game_state [0][0] == "X" )
				return winning_symbol["X"];
				else
				return winning_symbol["O"];
			}
		else if (game_state[1][0] == game_state [1][1]  && game_state[1][1] == game_state[1][2] && game_state[1][0]!=" ")
			{	if ( game_state [1][0] == "X" )
					return winning_symbol["X"];
					else
					return winning_symbol["O"];
			}

	else if (game_state[2][0] == game_state [2][1]  && game_state[2][1] == game_state[2][2] && game_state[2][0]!=" ")
		{			if ( game_state [2][0] == "X" )
						return winning_symbol["X"];
						else
						return winning_symbol["O"];
		}
	else if (game_state[0][0] == game_state [1][0]  && game_state[1][0] == game_state[2][0] && game_state[0][0]!=" ")
						{	if ( game_state [0][0] == "X" )
							return winning_symbol["X"];
							else
							return winning_symbol["O"];
						}
	else if (game_state[0][1] == game_state [1][1]  && game_state[1][1] == game_state[2][1] && game_state[0][1]!=" ")
							{	if ( game_state [0][1] == "X" )
								return winning_symbol["X"];
								else
								return winning_symbol["O"];
							}
	else if (game_state[0][2] == game_state [1][2]  && game_state[1][2] == game_state[2][2] && game_state[0][2]!=" ")
								{	if ( game_state [0][2] == "X" )
									return winning_symbol["X"];
									else
									return winning_symbol["O"];
								}
	else if (game_state[0][0] == game_state [1][1]  && game_state[1][1] == game_state[2][2] && game_state[0][0]!=" ")
									{	if ( game_state [0][0] == "X" )
										return winning_symbol["X"];
										else
										return winning_symbol["O"];
									}
	else if (game_state[0][2] == game_state [1][1]  && game_state[1][1] == game_state[2][0] && game_state[0][2]!=" ")
										{	if ( game_state [0][2] == "X" )
											return winning_symbol["X"];
											else
											return winning_symbol["O"];
										}

	else
	{
		return 0;
	}

}


void TicTacToe::start_game_loop(Player& one, Player& two)
{
turn = 1;
winning_symbol = get_win_symbol();
while(EmptyCount>0 and game_done!=true)
{
if(turn%2!=0)
{
	row_column = get_move_player(one,game_state);
	row_number = row_column[0];
	col_number = row_column[1];
	game_state[row_number-1][col_number-1] = symbols[1];
}
else
{
	row_column = get_move_player(two,game_state);
	row_number = row_column[0];
	col_number = row_column[1];
	game_state[row_number-1][col_number-1] = symbols[2];
}
print_board(game_state);
EmptyCount--;
win_status = check_win();
if(win_status==1 or win_status==2)
{
	DisplayResults(win_status);
	game_done = set_IsDone(0);

}
if(EmptyCount<=0 and win_status==0)
{
	DisplayResults(0);
	game_done = set_IsDone(0);
}
turn = !turn;
}
}
void TicTacToe::Start()
{
	num_players = get_num_players();
	if(num_players==2)
	{
		symbols = get_player();
		std::cout<<"------------------------------"<<std::endl;
		std::cout<<"Player 1 has the symbol "<<symbols[1]<<std::endl;
		std::cout<<"Player 2 has the symbol "<<symbols[2]<<std::endl;
		std::cout<<"------------------------------"<<std::endl;
		Player one("Player 1");
		Player two("Player 2");
		print_board(game_state);
		game_done = set_IsDone(1);
		EmptyCount = getEmptyCellCount();
		start_game_loop(one,two);
	}
}

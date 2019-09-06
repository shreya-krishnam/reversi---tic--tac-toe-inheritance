

#include "Reversi.hpp"

Reversi::Reversi(unsigned int &rows,unsigned int& columns,std::vector <std::vector<std::string> > &game_state)
:BaseClass{rows,columns,game_state},rows{rows},columns{columns},game_state{game_state}
{
}
void Reversi::set_initial_game_state()
{
	game_state[3][4] = game_state[4][3] = symbols[1];
	game_state[3][3] = game_state[4][4] = symbols[2];
}

void Reversi::show_scores(Player &one,Player &two)
{
std::cout<<"\n**************************SCOREBOARD**************************"<<std::endl;
std::cout<<"PLAYER NAME"<<"\t\tSYMBOL"<<"\t\tSCORE"<<std::endl;
std::cout<<one.get_player_name()<<"\t\t"<<symbols[1]<<"\t\t"<<one.get_player_score()<<std::endl;
std::cout<<two.get_player_name()<<"\t\t"<<symbols[2]<<"\t\t"<<two.get_player_score()<<std::endl;
std::cout<<"****************************************************************"<<std::endl;
}

bool Reversi::valid_move(unsigned int current_row,unsigned int current_col,std::string player_symbol)
{
	if(!(IsLegal(current_row,current_col,game_state)))
			{
		return false;
			}
	if(count_flips(current_row,current_col,player_symbol)==0)
		{
		return false;
		}
return true;
}

std::vector<unsigned int> Reversi::make_move(Player& p,std::string player_symbol)
{
	std::vector<unsigned int> row_col;
	std::cout<<"\nIt's "<<p.get_player_name()<<"'s turn"<<std::endl;
	std::cout<<"Enter the row number(1-"<<rows<<")"<<std::endl;
	std::cin>>row_number;
	std::cout<<"Enter the column number(1-"<<columns<<")"<<std::endl;
	std::cin>>col_number;
	while(not(valid_move(row_number,col_number,player_symbol)))
	{
		std::cout<<"\nInvalid move.Please try again"<<std::endl;
		std::cout<<"Enter the row number(1-"<<rows<<")"<<std::endl;
		std::cin>>row_number;
		std::cout<<"Enter the column number(1-"<<columns<<")"<<std::endl;
		std::cin>>col_number;
	}
	row_col.push_back(row_number);
	row_col.push_back(col_number);
return row_col;

}
std::string Reversi::get_opposite_player_symbol(std::string player_symbol)
{
if(player_symbol=="X")
	{
	opposite_player_symbol = "O";
	}
if(player_symbol=="O")
	{
opposite_player_symbol = "X";
	}
return opposite_player_symbol;
}
bool Reversi::check_bounds(int& current_row,int& current_col)
{
	upper_bound = rows-1;
	return ((current_row>=0 and current_row<=upper_bound) and (current_col>=0 and current_col<=upper_bound));
}
std::vector <std::vector<int> > Reversi::flips(unsigned int& row_number,unsigned int& col_number,std::string player_symbol)
{
	row_number = row_number-1;
	col_number = col_number-1;
	std::vector <std::vector<int> > result_flips;
	get_opposite_player_symbol(player_symbol);
	for(int x=-1;x<=1;x++)
	{
		for(int y= -1;y<=1;y++)
		{
			if(x==0 and y==0)
			{
				continue;
			}
				if(row_number+x>=0 and col_number+y>=0)
				{
					current_row = int(row_number+x);
					current_col = int(col_number+y);
					std::vector <std::vector<int> > temp_flips;
					while(check_bounds(current_row,current_col) and
							game_state[current_row][current_col]!=" " and game_state[current_row][current_col]!=player_symbol)
					{
						temp_flips.push_back({current_row,current_col});
						current_row+=x;
						current_col+=y;
					}
					if(check_bounds(current_row,current_col) and game_state[current_row][current_col]!=" " and
							game_state[current_row][current_col]==player_symbol)
					{
							result_flips.insert(result_flips.end(),temp_flips.begin(),temp_flips.end());
					}

				}
		}
	}
	return result_flips;
}

unsigned int Reversi::count_flips(unsigned int& current_row,unsigned int& current_col,std::string player_symbol)
{
	return flips(current_row,current_col,player_symbol).size();
}

bool Reversi::check_any_more_moves(std::string symbol)
{
	for(unsigned int i=0;i<rows;i++)
	{
		for(unsigned int j=0;j<columns;j++)
		{
			if (valid_move(i+1,j+1,symbol))
			{
				return true;
			}

		}
	}
	return false;
}

void Reversi::change_state(Player& p,Player& opp, std::string symbol,unsigned int &row_number, unsigned int &col_number)
{
result_flips = flips(row_number,col_number,symbol);
num_flips = result_flips.size();
p.set_score(num_flips+1);
opp.set_score(-num_flips);
game_state[row_number][col_number] = symbol;
for(unsigned int i=0;i<result_flips.size();i++)
{
game_state[result_flips[i][0]][result_flips[i][1]] = symbol;
}
}
void Reversi::game_over(Player& one,Player& two)
{
if(one.get_player_score()>two.get_player_score())
{
status = 1;
}
else if(one.get_player_score()<two.get_player_score())
{
	status = 2;
}
else if(one.get_player_score()==two.get_player_score())
{
	status = 0;
}
DisplayResults(status);
}
void Reversi::start_game_loop(Player& one, Player& two)
{
	winning_symbol=get_win_symbol();
	turn = 1;
	while(!(game_done))
	{
		if(turn%2!=0)
		{
			current_symbol = symbols[1];
			row_column = make_move(one,current_symbol);
			change_state(one,two,current_symbol,row_column[0],row_column[1]);
		}
		else
		{
			current_symbol = symbols[2];
			row_column = make_move(two,current_symbol);
			change_state(two,one,current_symbol,row_column[0],row_column[1]);
		}

		turn = !turn;
		print_board(game_state);
		show_scores(one,two);
		current_symbol = get_opposite_player_symbol(current_symbol);
		if(!(check_any_more_moves(current_symbol)))
		{
			if(!(check_any_more_moves(get_opposite_player_symbol(current_symbol))))
			{
				game_done = set_IsDone(0);
			}
			else
			{
			if(winning_symbol[current_symbol]==1)
			{
				std::cout<<"\n No more turns available for "<<one.get_player_name()<<". Turn Passes to "<<two.get_player_name()<<std::endl;
				}
			else if(winning_symbol[current_symbol]==2)
						{
							std::cout<<"\n No more turns available for "<<two.get_player_name()<<". Turn Passes to "<<one.get_player_name()<<std::endl;
							}
			turn = !turn;
			}


	}
}
game_over(one,two);
return;
}
void Reversi::Start()
{
	num_players = get_num_players();
	if(num_players==2)
	{
		symbols = get_player();
		initial_score = 2;
		Player one("Player 1",initial_score);
		Player two("Player 2",initial_score);
		std::cout<<"-------------------------------------------------"<<std::endl;
		std::cout<<one.get_player_name()<<" has the symbol "<<symbols[1]<<std::endl;
		std::cout<<two.get_player_name()<<" has the symbol  "<<symbols[2]<<std::endl;
		std::cout<<"--------------------------------------------------"<<std::endl;
		set_initial_game_state();
		print_board(game_state);
		show_scores(one,two);
		game_done = set_IsDone(1);
		start_game_loop(one,two);
	}
}

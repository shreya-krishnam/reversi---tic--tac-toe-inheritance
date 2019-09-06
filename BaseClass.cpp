
#include<iterator>
#include<iostream>
#include<vector>
#include<map>
#include "BaseClass.hpp"
BaseClass::BaseClass
(unsigned int& row_count, unsigned int& col_count,
		std::vector <std::vector<std::string> > &game_state):rows{row_count},
columns{col_count},game_state{game_state}
{
	std::cout<<"\nThis is the Base Class constructor"<<std::endl;
}
BaseClass::~BaseClass()
{
	std::cout<<"This is the BaseClass destructor\n"<<std::endl;
}

std::vector <std::vector<std::string> > BaseClass::get_game_state()
{
	return game_state;
}

void BaseClass::print_board(std::vector <std::vector<std::string> > &game_state)
{
	std::cout<<"\n ";
		for(unsigned int col=0;col<columns;col++)
		{
			std::cout<<"  "<<col+1<<" ";
		}
		std::cout<<"\n";
		for(unsigned int row=0;row<rows;row++)
		{
			std::cout<<" +";
			for(unsigned int col=0;col<columns;col++)
			{
					std::cout<<"---+";
			}
			std::cout<<"\n"<<row+1<<"|";
			for(unsigned int col=0;col<columns;col++)
			{
				std::cout<<" "<<game_state[row][col]<<" |";
			}
			std::cout<<"\n";
		}
		std::cout<<" +";
		for(unsigned int col=0;col<columns;col++)
		{
			std::cout<<"---+";
		}
		std::cout<<"\n";

}

unsigned int BaseClass::get_num_players()
{
	std::cout<<"Enter the number of players "<<std::endl;
	std::cin>>num_players;
	while(num_players!=2)
	{
		std::cout<<"This Game supports only a 2 player game. Try again"<<std::endl;
		std::cin>>num_players;
	}
return num_players;
}
std::map<int,std::string> BaseClass::get_player()
{
	std::cout<<"Enter the 1st Player's symbol(X / O)"<<std::endl;
	std::cin>>s;
	while(not(s=='X' or s=='O'))
	{
		std::cout<<"Invalid input. Enter a valid 1st Player's symbol(X / O)"<<std::endl;
		std::cin>>s;
	}
	first_player_symbol.append(1,s);
	if(first_player_symbol=="X")
	{
		second_player_symbol="O";
	}
	else
	{
		second_player_symbol="X";
	}
	symbols.insert(std::pair<int, std::string>(1,first_player_symbol));
	symbols.insert(std::pair<int, std::string>(2,second_player_symbol));
return symbols;
}

bool BaseClass::set_IsDone(unsigned int status)
{
if(status==0)
{
	game_done_flag =  true;
}
else if(status==1)
{
	game_done_flag = false;
}
return game_done_flag;
}
unsigned int BaseClass::getEmptyCellCount()
{
	EmptyCellCount = 0;
	for(unsigned int i=0;i<rows;i++)
	{
		for(unsigned int j=0;j<columns;j++)
		{
			if(game_state[i][j]==" ")
				{EmptyCellCount++;}
		}
	}
return EmptyCellCount;
}
bool BaseClass::IsLegal(unsigned int& row_number,unsigned int& col_number,std::vector <std::vector<std::string> > &game_state)
{
if((1<=row_number and row_number<=rows) and (1<=col_number and col_number<=columns))
{
	if(game_state[row_number-1][col_number-1]==" ")
	{
		return true;
	}
	return false;
}
return false;
}
std::vector<unsigned int> BaseClass::get_move_player(Player& p,std::vector <std::vector<std::string> > &game_state)
{
std::cout<<"\nIt's "<<p.get_player_name()<<"'s turn"<<std::endl;
std::cout<<"Enter the row number(1-"<<rows<<")"<<std::endl;
std::cin>>row_number;
std::cout<<"Enter the column number(1-"<<columns<<")"<<std::endl;
std::cin>>col_number;
while(not(IsLegal(row_number,col_number,game_state)))
{
	std::cout<<"\nInvalid move.Please try again"<<std::endl;
	std::cout<<"Enter the row number(1-"<<rows<<")"<<std::endl;
	std::cin>>row_number;
	std::cout<<"Enter the column number(1-"<<columns<<")"<<std::endl;
	std::cin>>col_number;
}
std::vector<unsigned int> row_column;
row_column.push_back(row_number);
row_column.push_back(col_number);
return row_column;
}
std::map<std::string,int> BaseClass::get_win_symbol()
{
	for (itr = symbols.begin(); itr != symbols.end(); ++itr)
	{
		get_winner_symbol.insert(std::pair<std::string, int>(itr->second,itr->first));
	}
return get_winner_symbol;
}
void BaseClass::DisplayResults(int status)
{
	if(status==1)
	{
		std::cout<<"----------------------"<<std::endl;
		std::cout<<"Player 1 won the game!"<<std::endl;
		std::cout<<"----------------------"<<std::endl;
	}
	else if(status==2)
	{
		std::cout<<"-----------------------"<<std::endl;
		std::cout<<"Player 2 won the game!"<<std::endl;
		std::cout<<"-----------------------"<<std::endl;
	}
	else if(status==0)
	{
		std::cout<<"-------------------------"<<std::endl;
		std::cout<<"No player won the game!"<<std::endl;
		std::cout<<"---------------------------"<<std::endl;
	}
	std::cout<<"GAME OVER!!!"<<std::endl;
return;
}

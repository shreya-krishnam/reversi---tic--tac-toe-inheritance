//NAME: SHREYA KRISHNAM STUDENT ID:23162697

#include "TicTacToe.hpp"
#include "BaseClass.hpp"
#include "Reversi.hpp"
#include<iostream>
#include<vector>
int main()
{
	std::string input;
	while(input!="3")
	{
		std::cout<<"\nWelcome! Which game do you want to play?"<<std::endl;
		std::cout<<"1.Tic-Tac Toe"<<std::endl;
		std::cout<<"2.Reversi"<<std::endl;
		std::cout<<"3.Quit"<<std::endl;
		std::cout<<"Enter 1,2 or 3 to continue:"<<std::endl;
		std::getline(std::cin,input);
		if(input=="1")
		{
			unsigned int rows = 3;
			unsigned int columns = 3;
			std::vector <std::vector<std::string> > game_state(rows, std::vector<std::string>(columns, " "));
			TicTacToe t{rows,columns,game_state};
			t.Start();
		}
		else if(input=="2")
		{
		unsigned int rows = 8;
		unsigned int columns = 8;
		std::vector <std::vector<std::string> > game_state(rows, std::vector<std::string>(columns, " "));
		Reversi r{rows,columns,game_state};
		r.Start();
		}
		std::cin.sync();

	}
	std::cout<<"\nGOODBYE!"<<std::endl;
return 0;
}





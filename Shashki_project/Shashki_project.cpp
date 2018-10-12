#include "pch.h"
#include "class.h"
#include "bot_control.h"
#include "main_control.h"
#include "player_control.h"

using namespace std;

int main()
{ 
	setlocale(0, "Russian");
	cout << "Добро пожаловать в игру шашки." << endl;
	checker massiv_iacheek[SIZE][SIZE];
	initialization(massiv_iacheek);
	vector <string> vector_pos(20);
	vector_pos.clear();
	draw_field(massiv_iacheek, &vector_pos);
	string coord_choice = "", coord_new = "";
	int i_k = 0, j_k = 0;
	bool black_turn = false, white_turn = true;
	bool error;
	while (!game_over(massiv_iacheek))
	{
		error = true;
		if (black_turn)
		{
			cout << "Ход переходит к чёрным." << endl;
			while (error)
			{
				getline(cin, coord_choice);
				preobras(massiv_iacheek, coord_choice, error);
				if ((error) || opr_color(coord_choice, massiv_iacheek) == "white")
				{
					cout << "Введите другие кординаты!" << endl;
					error = true;
					continue;
				};
				poisk(massiv_iacheek, coord_choice, i_k, j_k);
				if (massiv_iacheek[i_k][j_k].get_damka())
				{
					possible_turns_damka(coord_choice, massiv_iacheek, &vector_pos, 0);
				}
				else
				{
					possible_turns(coord_choice, massiv_iacheek, &vector_pos);
					possible_turns_eat(coord_choice, massiv_iacheek, &vector_pos, "black");
				}
				if (vector_pos.empty())
				{
					cout << "Введите другие кординаты!" << endl;
					error = true;
				};
			};
			error = true;
			while (error)
			{
				getline(cin, coord_new);
				preobras(massiv_iacheek, coord_choice, error);
				if (error)
				{
					cout << "Введите другие кординаты!" << endl;
					error = true;
					continue;
				};
				proverka(&vector_pos, coord_new, error);
				if (error)
					cout << "Вы не можете так сходить. Введите другие кординаты!" << endl;
				else
					for (int i = 0; i < SIZE; i++)
						for (int j = 0; j < SIZE; j++)
							if (massiv_iacheek[i][j].get_coord() == coord_choice)
								move_checker(coord_new, coord_choice, massiv_iacheek);
			};
			vector_pos.clear();
			draw_field(massiv_iacheek, &vector_pos);
			white_turn = true; black_turn = false;
			
		}
		else if (white_turn)
		{
			cout << "Ход переходит к белым." << endl;
			while (error)
			{
				getline(cin, coord_choice);
				preobras(massiv_iacheek, coord_choice, error);
				if ((error) || opr_color(coord_choice, massiv_iacheek) == "black")
				{
					cout << "Введите другие кординаты!" << endl;
					error = true;
					continue;
				};
				poisk(massiv_iacheek, coord_choice, i_k, j_k);
				if (massiv_iacheek[i_k][j_k].get_damka())
				{
					possible_turns_damka(coord_choice, massiv_iacheek, &vector_pos, 0);
				}
				else
				{
					possible_turns(coord_choice, massiv_iacheek, &vector_pos);
					possible_turns_eat(coord_choice, massiv_iacheek, &vector_pos, "white");
				}
				if (vector_pos.empty())
				{
					cout << "Введите другие кординаты!" << endl;
					error = true;
				};
			};
			error = true;
			while (error)
			{
				getline(cin, coord_new);
				preobras(massiv_iacheek, coord_choice, error);
				if (error)
				{
					cout << "Введите другие кординаты!" << endl;
					error = true;
					continue;
				};
				proverka(&vector_pos, coord_new, error);
				if (error)
					cout << "Вы не можете так сходить. Введите другие кординаты!" << endl;
				else
					for (int i = 0; i < SIZE; i++)
						for (int j = 0; j < SIZE; j++)
							if (massiv_iacheek[i][j].get_coord() == coord_choice)
								move_checker(coord_new, coord_choice, massiv_iacheek);
			};
			vector_pos.clear();
			draw_field(massiv_iacheek, &vector_pos);
			black_turn = true; white_turn = false;
		}
		
	}
	return 0;
};





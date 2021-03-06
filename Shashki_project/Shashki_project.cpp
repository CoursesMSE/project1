#include "pch.h"
#include "class.h"
#include "bot_control.h"
#include "main_control.h"
#include "player_control.h"

using namespace std;


int main()
{ 
	setlocale(0, "Russian");
	cout << "Добро пожаловать в игру шашки!!!." << endl;
	checker massiv_iacheek[SIZE][SIZE];
	initialization(massiv_iacheek);
	vector <string> vector_pos;
	vector <string> player_turn;
	vector_pos.clear();
	draw_field(massiv_iacheek, &vector_pos);
	string coord_choice = "", coord_new = "";
	int i_k = 0, j_k = 0;
	bool black_turn = false, white_turn = true;
	bool error; bool vvod = true;
	while (!game_over(massiv_iacheek))
	{
		error = true;
		if (black_turn)
		{
			cout << "Ход переходит к чёрным." << endl;
			while (error)
			{
				getline(cin, coord_choice);
				error = false;
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
					possible_turns_damka_eat(coord_choice, massiv_iacheek, &vector_pos, "black");
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
			vvod = true;
			while (vvod)
				while (error)
				{
					getline(cin, coord_new);
					if (coord_new != "end")
					{
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
						{
							player_turn.push_back(coord_new);
							error = true;
						}
					}
					else
					{
						vvod = false;
						error = false;
					}
				};
			for (int i = 0; i < SIZE; i++)
				for (int j = 0; j < SIZE; j++)
					if (massiv_iacheek[i][j].get_coord() == coord_choice)
						move_checker(player_turn[0], coord_choice, massiv_iacheek, &player_turn, 1);
			player_turn.clear();
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
				error = false;
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
					possible_turns_damka_eat(coord_choice, massiv_iacheek, &vector_pos, "white");
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
			vvod = true;
			while (vvod)
				while (error)
				{
					getline(cin, coord_new);
					if (coord_new != "end")
					{
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
						{
							player_turn.push_back(coord_new);
							error = true;
						}
					}
					else
					{
						vvod = false;
						error = false;
					}
				};
			for (int i = 0; i < SIZE; i++)
				for (int j = 0; j < SIZE; j++)
					if (massiv_iacheek[i][j].get_coord() == coord_choice)
						move_checker(player_turn[0], coord_choice, massiv_iacheek, &player_turn, 1);
			player_turn.clear();
			vector_pos.clear();
			draw_field(massiv_iacheek, &vector_pos);
			black_turn = true; white_turn = false;
		}
	}
	return 0;
};





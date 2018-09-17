#include "pch.h"
#include <iostream>

using namespace std;
const int SIZE = 8;

class checker
{
	string coord;
	string color;
public:
	void set_checker(string str, string color);
	void move_checker(string new_c, field p[][SIZE]);
	void delete_checker();
	string get_color();
};

class field
{
public:
	bool checker_is;
	string coord;
	checker bot;
};

void create_field(field p[][8]);
void inicialization_field(field p[][SIZE]);
void finding(string str, field p[][SIZE]);

int main()
{
	field pole[SIZE][SIZE];
	inicialization_field(pole);
	create_field(pole); 
	string coord_turn_choise, new_coord;
	while (true)
	{
		getline(cin, coord_turn_choise);
		getline(cin, new_coord);
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (pole[i][j].coord == coord_turn_choise)
				{
					pole[i][j].bot.move_checker(new_coord, pole);
					pole[i][j].checker_is = false;
				}
		create_field(pole);
	}			
	return 0;
}

void checker::delete_checker()
{

}
void checker::move_checker(string new_c, field p[][SIZE])
{
	coord = new_c;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (p[i][j].coord == new_c)
				p[i][j].checker_is = true;
}
void checker::set_checker(string str, string c)
{
	coord = str;
	color = c;
}
void create_field(field p[][SIZE])
{
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k <= 8 * 2; k++)
			cout << '-';
		cout << endl;
		for (int j = 0; j < 8; j++)
		{
			cout << '|';
			if (p[i][j].checker_is)
			{
				if (p[i][j].bot.get_color() == "white")
					cout << '1';
				else if (p[i][j].bot.get_color() == "black")
					cout << '0';
			}
			else
				cout << ' ';
		}
		cout << '|' << endl;
	}
	for (int k = 0; k <= 8 * 2; k++)
		cout << '-';
	cout << endl;
}
void inicialization_field(field p[][SIZE])
{
	string str;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			p[i][j].coord = char(i + 49) + char(j + 49);
			p[i][j].checker_is = false;
			if (i >= 0 && i <= 2 && (i + j) % 2 == 1)
			{
				str = char(i + 49) + char(j + 49);
				p[i][j].bot.set_checker(str, "black");
				p[i][j].checker_is = true;
			}
			if (i >= 5 && i <= 7 && (i + j) % 2 == 1)
			{
				str = char(i + 49) + char(j + 49);
				p[i][j].bot.set_checker(str, "white");
				p[i][j].checker_is = true;
			}
		}
}
string checker::get_color()
{
	return color;
}
void field::create_field(field p[][8])
{
	
}
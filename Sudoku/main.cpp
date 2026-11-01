#include <iostream>
#include <string>

using namespace std;

void draw(int board[9][9])
{
	/*cout << "\033[2J\033[1;1H";*/
	cout << "  1 2 3   4 5 6   7 8 9" << endl;
	for (int y = 0; y < 9; y++)
	{
		if (y == 3 || y == 6) cout << "--------+-------+------" << endl;
		cout << char('A' + y) << " ";
		for (int x = 0; x < 9; x++)
		{
			if (x == 3 || x == 6) cout << "| ";
			if (board[x][y] != 0) cout << abs(board[x][y]) << " ";
			else cout << "  ";
		}
		cout << endl;
	}
}

bool isLegal(int board[9][9], int x, int y, int value)
{
	if (x < 0 || x >= 9 || y < 0 || y >= 9) return false;

	for (int i = 0; i < 9; i++)  
		if (abs(board[i][y]) == value) return false;
	for (int j = 0; j < 9; j++)  
		if (abs(board[x][j]) == value) return false;

	int subgrid_x = (x / 3) * 3;
	int subgrid_y = (y / 3) * 3;

	for (int i = subgrid_x; i < subgrid_x + 3; i++)
		for (int j = subgrid_y; j < subgrid_y + 3; j++)
			if (abs(board[i][j]) == value) return false;

	return true;
}

int main()
{
	bool running = true;

	int board[9][9] =
	{
		{0, 0, 0, 8, 0, 1, 0, 2, 0},
		{0, 9, 0, 0, 0, 9, 0, 7, 0},
		{0, 0, 0, 0, 4, 0, 0, 0, 1},
		{0, 1, 0, 4, 0, 0, 5, 0, 0},
		{0, 5, 0, 0, 8, 0, 0, 2, 7},
		{0, 8, 7, 9, 1, 0, 0, 0, 0},
		{4, 0, 9, 1, 3, 0, 6, 0, 5},
		{1, 0, 2, 0, 0, 0, 0, 3, 0},
		{0, 0, 0, 0, 6, 0, 0, 0, 9},
	};

	while (running)
	{
		system("cls");
		cout << endl;
		draw(board);

		cout << "Example: set a1 4  or  a1 4" << endl;

		string command;
		getline(cin, command);

		if (command.substr(0, 3) == "set")
		{
			int y = command[4] - 'a';
			int x = command[5] - '1';
			int value = command[7] - '0';

			if (isLegal(board, x, y, value))
			{
				board[x][y] = value;
			}
			else
			{
				cout << "Move is illegal: " << endl;
			}
		}

		if (command.substr(0) == "a" || "b" || "c" || "d" ||"e" || "f" ||"g" || "h" ||"i")
		{
			int y = command[0] - 'a';
			int x = command[1] - '1';
			int value = command[3] - '0';

			if (isLegal(board, x, y, value))
			{
				board[x][y] = value;
			}
			else
			{
				cout << "Move is illegal: " << endl;
			}
		}

		if (command == "exit")
		{
			running = false;
		}
	}

	cout << "Game Closed";
	return 0;
}

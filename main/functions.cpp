#include "functions.h"

vector<vector<int>> fillInTheField(int n, int m) {
	vector<vector<int>>field;
	int number;
	set<int>b;
	b.insert(9);
	int setSize = b.size();
	for (int i = 0; i < n; i++) {
		vector<int>boof(m, 0);
		for (int j = 0; j < m;) {
			number = rand() % 10;
			setSize = b.size();
			b.insert(number);
			if (b.size() != setSize) {
				boof[j] = number;
				setSize = b.size();
				j++;
			}
		}
		field.push_back(boof);
		boof.clear();
	}
	//field[n - 1][m - 1] = 0;
	return field;
}

void showThefield(vector<vector<int>> field)
{

	for (int i = 0; i < field.size(); i++) {
		gotoxy(4, 2 * i + 1);
		for (size_t j = 0; j < field[i].size(); j++) {
			cout << field[i][j] << '\t';
		}
		cout << endl << endl;
	}
}

bool isMatrixGrow(vector<vector<int>> Matrix, bool* isError)
{
	vector<int> boof;
	bool isGrow = true;
	for (int i = 0; i < Matrix.size(); i++) {
		for (int j = 0; j < Matrix[i].size(); j++) {
			boof.push_back(Matrix[i][j]);
		}
	}

	for (int i = 1; i < boof.size(); i++) {
		if ((i == 6 and boof[i] == 8 and boof[i + 1] == 7)) {
			(*isError) = true;
			return true;
		}
		if (boof[i - 1] != i)
			return false;
	}

	if (boof[boof.size() - 1] != 0)
		return false;

	return true;
}

vector<int> find_number(vector<vector<int>> Matrix, int num)
{
	for (int i = 0; i < Matrix.size(); i++) {
		for (int j = 0; j < Matrix[i].size(); j++) {
			if (Matrix[i][j] == num)
				return { i, j };
		}
	}
	return { -1, -1 };
}

void swaps(vector<vector<int>>& Matrix, int* count)
{
	bool isError = false;
	int pressKey = -1;
	vector<int> position;
	int i, j;
	while (!isMatrixGrow(Matrix, &isError)) {
		if (isError)
		{
			cout << "Error" << endl;
			Sleep(400);
			break;
		}
		showThefield(Matrix);
		//printMatrixCentered(Matrix);
		pressKey = GetNumber<int>("Press key");
		position = find_number(Matrix, pressKey);

		if (position[1] - 1 >= 0 and (Matrix[position[0]][position[1] - 1] == 0)) {
			int data = (Matrix[position[0]][position[1] - 1]);
			(Matrix[position[0]][position[1] - 1]) = (Matrix[position[0]][position[1]]);
			(Matrix[position[0]][position[1]]) = data;
			(*count)++;
		}

		else if (position[0] - 1 >= 0 and Matrix[position[0] - 1][position[1]] == 0) {
			int data = Matrix[position[0] - 1][position[1]];
			Matrix[position[0] - 1][position[1]] = Matrix[position[0]][position[1]];
			(Matrix[position[0]][position[1]]) = data;
			(*count)++;
		}

		else if (position[1] + 1 < Matrix[0].size() and Matrix[position[0]][position[1] + 1] == 0) {
			int data = Matrix[position[0]][position[1] + 1];
			Matrix[position[0]][position[1] + 1] = Matrix[position[0]][position[1]];
			(Matrix[position[0]][position[1]]) = data;
			(*count)++;
		}

		else if (position[0] + 1 < Matrix.size() and Matrix[position[0] + 1][position[1]] == 0) {
			int data = Matrix[position[0] + 1][position[1]];
			Matrix[position[0] + 1][position[1]] = Matrix[position[0]][position[1]];
			Matrix[position[0]][position[1]] = data;
			(*count)++;
		}
		system("cls");
	}
}

void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
}


void printMatrixCentered(const std::vector<std::vector<int>>& matrix) {
	// Получаем дескриптор окна консоли
	HWND console = GetConsoleWindow();

	// Получаем размеры экрана
	RECT r;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &r, 0);
	int screen_width = r.right - r.left;

	// Вычисляем ширину матрицы (предполагаем, что все строки имеют одинаковую длину)
	int matrix_width = matrix[0].size() * 2; // Умножаем на 2, предполагая, что каждое число занимает 2 символа

	// Вычисляем начальную позицию X для центрирования матрицы
	int start_x = (screen_width - matrix_width) / 2;

	// Получаем дескриптор стандартного вывода
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// Выводим матрицу, начиная с позиции start_x
	for (const auto& row : matrix) {
		COORD pos = { start_x, 0 }; // Y-координата будет автоматически увеличиваться с каждой новой строкой
		SetConsoleCursorPosition(hOut, pos);
		for (int num : row) {
			std::cout << num << ' ';
		}
		std::cout << '\n';
	}
}
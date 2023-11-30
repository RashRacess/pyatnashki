#include "functions.h"

int main()
{
	system("mode con cols=60 lines=25");
    HWND console = GetConsoleWindow();
    // Получает размеры экрана
    RECT r;
    SystemParametersInfo(SPI_GETWORKAREA, 0, &r, 0);
    int screen_width = r.right - r.left;
    int screen_height = r.bottom - r.top;

    // Получает текущие размеры окна консоли
    RECT rc;
    GetWindowRect(console, &rc);
    int window_width = rc.right - rc.left;
    int window_height = rc.bottom - rc.top;

    // Вычисляет новые координаты для центрирования окна консоли
    int new_x = (screen_width - window_width) / 2;
    int new_y = (screen_height - window_height) / 2;

    // Изменяет позицию окна консоли
    SetWindowPos(console, NULL, new_x, new_y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	srand(time(0));
	vector<vector<int>>field;
	field = fillInTheField(3, 3);
	int countOfSwaps = 0;
	swaps(field, &countOfSwaps);
	showThefield(field);
	cout << endl << "count of swaps is: " << countOfSwaps << endl;
	return 0;
}

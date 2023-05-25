#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <locale.h>

using namespace std;

int main() {
	HANDLE hEvent;
	setlocale(LC_ALL, "rus");
	hEvent = OpenEvent(
		EVENT_ALL_ACCESS,
		TRUE,
		L"MyEventl"
	);
	if (hEvent == 0) {
		cout << "Ошибка открытия события в другом приложении.." << endl;
		_getch();
		return 0;
	}
	while (true) {
		cout << "1 - Запуск потоков." << endl;
		cout << "2 - Завершение потоков." << endl;
		fflush(stdin);
		int sw;
		cin >> sw;
		if (sw == 1) {
			cout << "Запускаем..." << endl;
			SetEvent(hEvent);
		}
		else if (sw == 2) {
			cout << "Завершаем..." << endl;
			ResetEvent(hEvent);
			return 0;
		}
		else return 0;
	}
	return 0;
}
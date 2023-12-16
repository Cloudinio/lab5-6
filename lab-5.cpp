#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Zoo {
private:
	string name;
	string country;
	string* list;
	int counter_animals;
	int cost_ticket;
	int hour_start;
	int min_start;
	int hour_end;
	int min_end;
public:
	//сеттеры
	void SetName(string name) {
		this->name = name;
	}
	void SetCountry(string country) {
		this->country = country;
	}
	void SetCounter_animals(int counter_animals) {
		string* animals = new string[abs(counter_animals - this->counter_animals)];
		for (int i = 0; i < abs(counter_animals - this->counter_animals); i++) {
			cin >> animals[i];
		}
		if (this->counter_animals < counter_animals) {
			for (int i = 0; i < (counter_animals - this->counter_animals); i++) {
				list[this->counter_animals + i] = animals[i];
			}
		}
		if (this->counter_animals > counter_animals) {
			for (int i = 0; i < this->counter_animals; i++) {
				for (int j = 0; j < (this->counter_animals - counter_animals);j++) {
					if (list[i] == animals[j]) {
						list[i] = " ";
					}
				}
			}
		}
		this->counter_animals = counter_animals;
	}
	void SetCost_ticket(int cost_ticket) {
		this->cost_ticket = cost_ticket;
	}
	void SetHour_start(int hour_start) {
		this->hour_start;
	}
	void SetHour_end(int hour_end) {
		this->hour_end;
	}
	void SetMin_start(int min_start) {
		this->min_start = min_start;
	}
	void SetMin_end(int min_end) {
		this->min_end = min_end;
	}
	//принтеры
	void PrintName() {
		cout << name << endl;
	}
	void PrintCountry() {
		cout << country << endl;
	}
	void PrintCounter_animals() {
		cout << counter_animals << endl;
	}
	void PrintCost_ticket() {
		cout << cost_ticket << endl;
	}
	void PrintTimeStart() {
		cout << hour_start << " : " << min_start << endl;
	}
	void PrintTimeEnd() {
		cout << hour_end << " : " << min_end << endl;
	}
	void PrintList() {
		for (int i = 0; i < 100; i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
	//геттеры
	string GetName() {
		return name;
	}
	string GetCountry() {
		return country;
	}
	//конструктор без параметров
	Zoo() {
		name = "None";
		country = "None";
		counter_animals = 0;
		cost_ticket = 0;
		hour_start = 0;
		min_start = 0;
		hour_end = 0;
		min_end = 0;
		list = new string[counter_animals];
	}
	//конструктор с параметрами
	Zoo(string name, string country, int counter_animals, int cost_ticket, int hour_start, int min_start, int hour_end, int min_end) {
		this->name = name;
		this->country = country;
		this->cost_ticket = cost_ticket;
		this->counter_animals = counter_animals;
		this->hour_start = hour_start;
		this->min_start = min_start;
		this->hour_end = hour_end;
		this->min_end = min_end;
		cout << "Enter animals: ";
		list = new string[100];
		for (int i = 0; i < counter_animals; i++) {
			cin >> list[i];
		}
	}
	//констурктор копирования
	Zoo(const Zoo& other) {
		name = other.name;
		country = other.country;
		list = other.list;
		counter_animals = other.counter_animals;
		cost_ticket = other.cost_ticket;
		hour_start = other.hour_start;
		min_start = other.min_start;
		hour_end = other.hour_end;
		min_end = other.min_end;
	}
	//дистуктор
	~Zoo()
	{
		delete[] list;
	}
	//функция вывода дынных зоопарка
	void PrintZoo() {
		cout << "Наименование зоопарка: " << name << "\n" << "Страна: " << country << endl;
		cout << "Количество животных: " << counter_animals << endl;
		cout << "Цена билета: " << cost_ticket << endl;
		cout << "Открытие зоопарка: " << hour_start << " : " << min_start << endl;
		cout << "Закрытие зоопарка: " << hour_end << " : " << min_end << endl;
		cout << "Животные: ";
		for (int i = 0; i < counter_animals; i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
	//1 функция, которая считает, сколько животных можно обойти
	void Function_1(int N) {
		int time = abs(hour_start*60 + min_start - hour_end*60 - min_end);
		double result = trunc(time / (counter_animals*N));
		cout << "Можно обойти ";
		cout << result;
		cout << " животных" << endl;
	}
	//метод для 2 функции
	double Lambda() {
		double lambda = cost_ticket / counter_animals;
		return lambda;
	}
};
//2 функция
Zoo* Function_2(Zoo mas[], const int size) {
	Zoo temp;
	for (int i = 0; i < (size - 1); i++) {
		for (int j = 0; j < (size - i - 1); j++) {
			if (mas[j].Lambda() > mas[j + 1].Lambda()) {
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
	}
	return mas;
}
//3 функция
Zoo* Function_3(Zoo mas[], const int size, string country, int& size_of_country) {
	Zoo* spisok = new Zoo[size];
	for (int i = 0; i < size; i++) {
		if (mas[i].GetCountry() == country) {
			spisok[size_of_country] = mas[i];
			size_of_country++;
		}
	}
	return spisok;
}

int main() {
	setlocale(LC_ALL, "RUS");
	int size_of_country = 0, n, N;
	Zoo zoo_Moscow("pasha", "Russia", 2, 2, 9, 0, 18, 0), zoo_Washington("sasha","USA",2,3,9,0,18,0), zoo_London("masha", "England", 2, 4, 9, 0, 18, 0);
	Zoo zoo_Voskresensk("yasha", "Russia", 2, 10, 9, 0, 18, 0);
	Zoo mas[4];
	mas[0] = zoo_Moscow;
	mas[1] = zoo_Washington;
	mas[2] = zoo_London;
	mas[3] = zoo_Voskresensk;
	//функция 1
	cout << "Сколько минут будете тратить на животных: ";
	cin >> N;
	zoo_Voskresensk.Function_1(N);
	//функция 2
	Zoo* array2 = Function_2(mas, 4);
	cout << "Вторая функция:" << endl;
	for (int i = 0; i < 4; i++) {
		cout << i + 1 << ") ";
		array2[i].PrintName();
	}
	cout << endl;
	//функция 3
	Zoo* array3 = Function_3(mas, 4, "Russia", size_of_country);
	cout << "Третья функция:" << endl;
	for (int i = 0; i < size_of_country; i++) {
		array3[i].PrintName();
	}
}

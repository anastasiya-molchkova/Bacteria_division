/* Каждая бактерия делится на две в течение одной минуты. В начальный момент имеется одна бактерия. 
Напишите программу, которая вычисляет общее количество бактерий 
после истечения указанного пользователем промежутка времени (например, после 5 или после 17 минут). */

#include <iostream>
#include <cmath> // для возведения в степень

// получаем от пользователя количество минут
unsigned get_minutes()
{
	std::cout << "Введите промежуток времени в минутах: ";
	int answer;
	std::cin >> answer;
	while (std::cin.fail() || (answer < 0))
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Промежуток времени должен выражаться натуральным числом! Повторите ввод: ";
		std::cin >> answer;
		std::cin.ignore(1000, '\n');
	}
	return static_cast<unsigned>(answer);
}

// считаем количество бактерий, расплодившихся из одной через заданное в минутах время
unsigned long bacterias_number(const unsigned minutes)
{
	return pow(2, minutes);
}

int main()
{
	setlocale(LC_CTYPE, "rus"); // для вывода сообщений на кириллице
	std::cout << "Каждая бактерия делится на две в течение минуты. Давайте посмотрим, сколько их будет через какое-то время. \n";
	while (true)
	{
		unsigned time{ 0 };
		time = get_minutes();
		std::cout << "Вот, сколько бактерий мы получим через это время: " << bacterias_number(time) << std::endl;
	}
}
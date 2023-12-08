// mat_vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<cmath>


 

struct MAT_VECTOR
{
	double x;
	double y;

	// Конструктор по умолчанию
	MAT_VECTOR()
	{
		x = 0;
		y = 0;
	}

	// Конструктор с параметрами для инициализации вектора
	MAT_VECTOR(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	

	//перегрузка сложения 
	MAT_VECTOR operator +(const MAT_VECTOR& p_end)                     
	{
		MAT_VECTOR Temp;
		Temp.x = this->x + p_end.x;
		Temp.y = this->y + p_end.y;
		return Temp;
	}

	// перегрузка вычитания 
	MAT_VECTOR operator -(const MAT_VECTOR& p_end)
	{
		MAT_VECTOR Temp;
		Temp.x = this->x - p_end.x;
		Temp.y = this->y - p_end.y;
		return Temp;
	}
	
	// перегрузка умножения ( умножение вектора на скаляр)
	MAT_VECTOR operator *(const MAT_VECTOR& p_end)
	{
		MAT_VECTOR Temp;
		Temp.x = this->x * p_end.x;
		Temp.y = this->y * p_end.x;
		return Temp;
	}


};

//перегрузка оператора вывода 
std::ostream& operator << (std::ostream& os, const MAT_VECTOR& person)
{
	return os << person.x << ',' << person.y;
}

// нахождение длины вектора
double length(double& result, MAT_VECTOR Begin)
{
	result = abs(sqrt(pow(Begin.x, 2) + pow(Begin.y, 2)));
	return result;
};

// нормализация вектора
MAT_VECTOR normaly(double result, MAT_VECTOR Begin)
{
	MAT_VECTOR Temp;
	Temp.x = sqrt(Begin.x / result);
	Temp.y = sqrt(Begin.y / result);
		return Temp;
}

int main()
{
	double result = 0;                  // длина вектора
	MAT_VECTOR Begin(4, 3);
	MAT_VECTOR End(4,9);
	MAT_VECTOR RES;    //  результирующий вектор сложения,вычитания, умножения на скаляр 
	std::string command;

	/*сложение двух векторов — команда add;
	вычитание двух векторов — команда subtract;
	умножение вектора на скаляр — команда scale;
	нахождение длины вектора — команда length;
	нормализация вектора — команда normalize.*/
	
	std::cout << "Enter command: add , subtract , scale , length , normalize : \n";
	std::cin >> command;

	if (command == "add")
	{
		std::cout <<  "Enter the coordinates of vector A: ";
		std::cin >> Begin.x >> Begin.y;
		std::cout << "Enter the coordinates of vector B: ";
		std::cin >> End.x >> End.y;
		RES = Begin + End;
		std::cout << "Result Vector is : " << RES;
		
		return 0;
	}
	else if (command == "subtract")
	{
		std::cout << "Enter the coordinates of vector A: ";
		std::cin >> Begin.x >> Begin.y;
		std::cout << "Enter the coordinates of vector B: ";
		std::cin >> End.x >> End.y;
		RES = Begin - End;
		std::cout << "Result Vector is : " << RES;

		return 0;
	}
	else if (command == "scale")
	{
		std::cout << "Enter the coordinates of vector : ";
		std::cin >> Begin.x >> Begin.y;
		std::cout << "Enter scalar: ";
		std::cin >> End.x;
		RES = Begin * End;
		std::cout << "Result Vector is : " << RES;

		return 0;
	}
	else if (command == "length")
	{
		std::cout << "Enter the coordinates of vector A: ";
		std::cin >> Begin.x >> Begin.y;
		result=length(result, Begin);
		std::cout << "Length of vector A is: " << result;

		return 0;
	}
	else if (command == "normalize")
	{
		std::cout << "Enter the coordinates of vector A: ";
		std::cin >> Begin.x >> Begin.y;
		result = length(result, Begin);
		RES = normaly(result, Begin);
		std::cout << "normalized vector coordinates is: \n" << RES;

		return 0;
	}
	else
	{
		std::cout << "Uncnown action";
		return 0;
	}
	
	

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

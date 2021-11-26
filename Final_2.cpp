#include<iostream>
#include<fstream>
#include<string>
#include<math.h>

using namespace std;



int pre(char n)
{
	if (n == '+')
	{
		return 1;
	}
	else if (n == '-')
	{
		return 2;
	}
	else if (n == '*')
	{
		return 3;
	}
	else if (n == '/')
	{
		return 4;
	}
	else if (n == '^')
	{
		return 5;
	}
}


int main()
{

	string ex;
	int total = 0;
	ifstream file("expression.txt");
	if (file.is_open())
	{

		getline(file, ex);
	}
	file.close();


	if (ex[1] == '+' || ex[1] == '-' || ex[1] == '*' || ex[1] == '/')
	{

		int pr = pre(ex[1]);
		if (pr == 1)
		{

			int a = (int)ex[0] - 48;

			int b = (int)ex[2] - 48;

			total = a + b;



		}
		else if (pr == 2)
		{
			int a = (int)ex[0] - 48;

			int b = (int)ex[2] - 48;

			total = a - b;

		}
		else if (pr == 3)
		{
			int a = (int)ex[0] - 48;

			int b = (int)ex[2] - 48;

			total = a * b;

		}
		else if (pr == 4)
		{
			int a = (int)ex[0] - 48;

			int b = (int)ex[2] - 48;

			total = a / b;

		}
	}

	cout << "Evaluated result: "<<total;
	cout << "\n";
	int cube = pow(total, 3);
	cout << "Cube: " << cube;
	cout << "\n";


	ofstream file2;

	file2.open("CubeOutput.txt");


	file2 << cube << "\n";
	file2.close();
	
}
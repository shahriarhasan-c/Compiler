#include<iostream>
#include<fstream>
#include<string>
#include<stack>
using namespace std;



int pre(char a)
{
	if (a == '+')
	{
		return 1;
	}
	else if (a == '-')
	{
		return 2;
	}
	else if (a == '*')
	{
		return 3;
	}
	else if (a == '/')
	{
		return 4;
	}
	else return 5;
}


int main()
{

	string ex,op1;
	int total = 0;

	ifstream file1("In.txt");
	if (file1.is_open())
	{

		getline(file1, ex);
	}
	file1.close();

	ifstream file2("Op.txt");
	if (file2.is_open())
	{

		getline(file2, op1);
	}
	file2.close();
	
	if (op1[0] == '+' || op1[0] == '-' || op1[0] == '*' || op1[0] == '/')
	{
     
		int pr = pre(op1[0]);
		if (pr == 1)
		{

			int a = (int)ex[0] - 48;

			int b = (int)ex[1] - 48;

			total = a + b;



		}
		else if (pr == 2)
		{
			int a = (int)ex[0] - 48;

			int b = (int)ex[1] - 48;

			total = a - b;

		}
		else if (pr == 3)
		{
			int a = (int)ex[0] - 48;

			int b = (int)ex[1] - 48;

			total = a * b;

		}
		else if (pr == 4)
		{
			int a = (int)ex[0] - 48;

			int b = (int)ex[1] - 48;

			total = a / b;

		}
		else
			cout << "Operator Error\n";
	}



	ofstream file3;

	file3.open("Out.txt");


	file3 << total << "\n";
	file3.close();

}
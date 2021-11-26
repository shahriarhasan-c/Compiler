#include<iostream>
#include<string.h>
#include<stdlib.h>
#include <string>
using namespace std;
void func(string input)
{
	int num;
	string s1;
	int flag = 0;
	int l = input.length();
	if (input[0] == '"')
	{
		string s1 = input.substr(1, 3);

		num =std::stoi(s1);
		
		if (num % 2 != 0)
		{
			flag = 1;
		}
		else flag = 0;

		if (flag == 1)
		{
			string s2 = input.substr(4, 5);
			if (s2 == "true" || s2 == "false")
			{
				string s3 = input.substr(9, 2);
				for (int i = 0; i < s3.length(); i++)
				{
					if (s3[i] >= 'A' && s3[i] <= 'Z')
					{
						flag = 1;
					}
					else {
						flag = 0;
						break;
					}
				}
				if (flag == 1)
				{
					string s4 = input.substr(11, 2);
					
					for (int i = 0; i < s4.length(); i++)
					{
						if (s4[i] >= 'a' && s4[i] <= 'z')
						{
							flag = 1;
						}
						else {
							flag = 0;
							break;
						}
					}
					if (flag == 1)
					{
						string s5 = input.substr(13, 3);
						if (s5 >= "001" && s5 <= "999")
						{
							if(input[input.length()-1] == '"')
							cout << "valid" << "\n";
							else
								cout << "Not valid\n";
						}
						else
							cout << "Not valid\n";
					}
					else
						cout << "Not valid\n";
				}

				else
					cout << "Not valid\n";
			}
			else
			cout << "Not valid\n";

		}
		else 
			cout << "Not valid\n";
	}
    else {
		cout << "Not valid\n";
	}



}
int main()
{
	string input;
	int n;
	do {
		cout << "\n****************\n1.expression\n2.exit\n";
		cout << "Enter a number: ";
		cin >> n;
		if (n == 1)
		{
			cout << "Enter a expration: ";
			cin >> input;
			func(input);
		}
		else if (n == 2)
		{
			break;
		}
	} while (true);
}

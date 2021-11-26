#include<iostream>
using namespace std;
void func(string input)
{
	string s1;
	int flag = 0;
	int l = input.length();
	for (int i = 0; i < l; i++)
	{
		if (input[i] == '@' || input[i] == '#' || input[i] == '$') {
			flag = 1;
			break;
		}
		else {
			s1.push_back(input[i]);
		}
	}
	string s2;
	string s3;
	int l1 = s1.length();
	if (flag == 1)
	{
		for (int i = 0; i < l1; i++)
		{
			if (s1[i] >= 'A' && s1[i] <= 'Z')
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
			s2 = input.substr(l1+1, 3);
			if (s2 == "UIU")
			{
				int k = l - (l1 + 4);
				s3 = input.substr(l1 + 4, k);
				
				
				for (int i = 0; i < s3.length()-1; i++)
				{
					if (s3[i] == '0')
					{
						if (s3[i + 1] == '0' && s3[i + 2] == '0')
						{
							flag == 0;
							break;
						}
					}
				}
				if (flag == 1)
				{
					
					for (int i = 0; i < s3.length() - 1; i++)
					{
						if (s3[i] >= '0' && s3[i] <= '9')
						{
							flag = 1;
						}
						else flag = 0;
						break;
					}
					if (flag == 1) {
						if (s3[s3.length() - 1] == '+' || s3[s3.length() - 1] == '-' || s3[s3.length() - 1] == NULL) {
							cout << "Valid\n";
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
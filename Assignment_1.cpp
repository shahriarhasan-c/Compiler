#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;


void func5() {
	string name;
	int middle=0,l=0;
	cout << "Enter string: ";
	cin >> name;
	l = name.length();
	
	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] == 'U')
		{
			++middle;
			break;
		}
		++middle;
	}
	string r1 = name.substr(0, middle - 1);
	if (r1 >= "a" && r1 <= "z")
	{
		string r2 = name.substr(middle-1, 3);
		if (r2 == "UIU")
		{
			string r3 = name.substr(middle + 2, 1);
			
			if (r3 >= "0" && r3 <= "9")
			{
				string r4 = name.substr(middle + 3, middle);
				if (r4 == r1)
				{
					cout << "String valid\n";
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
void func4() {
	string num;
	int middle = 0;
	cout << "Enter number:";
	
	cin >> num;
	int l = num.size();
	
	if ((num[0] == '+' && num[1] == '-') || (num[0] = '-' && num[1] == '+'))
	{
		cout << "Not Valid\n";
		
		return;
	}
	/*cout << num[0];
	if (num[0] == ' ')
		{
			
			cout << "Not valid\n";
			return;
		}*/
	
	if (num[l-1] == '.')
	{
		
		cout << "Not Valid\n";
		return;
	}


	for (int i = 0; i < num.length(); i++)
	{
		
		 if ((num[i] >= 'a' && num[i] <= 'z'))
		{
			
			cout << "Not valid\n";
			return;
		}
	}
	cout << "Valid\n";
	
}
void func3() {
	string pass;
	int flag1 = 0;
	cout << "Enter password: ";
	cin >> pass;
	int l = pass.size();
	
	if (l >= 8)
	{
		for (int i = 0; i < pass.length(); i++)
		{
			if (pass[i] >= 'a' && pass[i] <= 'z')
			{
				++flag1;
				
			 }
			
		}
		if (flag1 > 0)
		{
			flag1 = 0;

			for (int i = 0; i < pass.length(); i++)
			{
				if (pass[i] >= 'A' && pass[i] <= 'Z')
				{
					++flag1;
					
				}

			}
			if (flag1 > 0)
			{
				flag1 = 0;
				for (int i = 0; i < pass.length(); i++)
				{
					if (isdigit(pass[i]))
					{
						++flag1;
						
						
					}
				}
				if (flag1 > 0)
				{
					flag1 = 0;
					for (int i = 0; i < pass.length(); i++)
					{
						if (pass[i] == '@' || pass[i] == '#' || pass[i] == '%' || pass[i] == '&' || (pass[i] >= 'a' && pass[i] <= 'z') || (pass[i] >= 'A' && pass[i] <= 'Z') || (isdigit(pass[i])))
						{
							flag1 = 1;

						}
						else {
							flag1 = 0;
							break;
						}
					}
					if (flag1 > 0)
					{
						if (pass[l-1] == 'P')
						{
							
							cout << "Password valid\n";
						}
						else
							cout << "Password is not valid\n";
					}
					else
						cout << "Password is not valid\n";
				}
				else 
					cout << "Password is not valid\n";
			}
			else
				cout << "Password is not valid\n";

		}
		else
			cout << "Password is not valid\n";
	}
	else
		cout << "Password is not valid\n";

}
void func2() {
	string mail;
	string letter, num;
	int middle = 0,flag =0;
	cout << "Enter Email: ";
	cin >> mail;
	int l = mail.size();
	for (int i = 0; i < mail.length(); i++)
	{
		if (mail[i] == '@')
		{
			++middle;
			break;
		}
		++middle;
	}
	for (int i = 0; i < middle; i++)
	{
		if (isdigit(mail[i]))
			num.push_back(mail[i]);
		else if ((mail[i] >= 'A' && mail[i] <= 'Z') ||
			(mail[i] >= 'a' && mail[i] <= 'z'))
			letter.push_back(mail[i]);
		
	}

	for (int i = 0; i < letter.length(); i++)
	{
		if ((letter[i] >= 'A' && letter[i] <= 'Z') ||
			(letter[i] >= 'a' && letter[i] <= 'z'))
			flag = 0;
		else
			flag++;
	}
	if (flag == 0)
	{
		string r1 = num.substr(0, 2);
		if (r1 >= "05" && r1 <= "20")
		{
			string r2 = num.substr(2, 1);
				if (r2 >= "1" && r2 <= "3")
				{
					string r3 = num.substr(3, 3);
					if (r3 >= "001" && r3 <= "999")
					{
						string s1 = "@bscse.uiu.ac.bd";
						string s2 = "@bseee.uiu.ac.bd";
						string r4 = mail.substr(middle-1, l);
						if (r4 == s1 || r4 == s2)
						{
							cout << "Email is Valid\n";
						}
						else
							cout<< "Email is not Valid\n";
					}
					else
						cout << "Email is not Valid\n";
				}
				else
					cout << "Email is not Valid\n";

			}
		else
			cout << "Email is not Valid\n";
	}
	else
		cout << "Email is not Valid\n";

}
void func1() {
	string id;
	
	cout << "Enter ID: ";
	cin >> id;
	
	string s1 = "011";
	string r1 = id.substr(0, 3);
	
	if (s1 == r1)
	{
		string r2 = id.substr(3, 2);
		
		if (r2 >= "05" && r2 <= "20")
		{
			string r3 = id.substr(5,1);
			
			if (r3 >= "1" && r3 <= "3")
			{
				string r4 = id.substr(6, 3);
				if (r4 >= "001" && r4 <= "999")
					cout << "ID Valid\n";
				else
					cout << "ID not valid\n";
			}
			else
			cout << "ID not valid\n";

		}
		else
			cout << "ID not valid\n";

	}
	else
		cout << "ID not valid\n";



}

int main()
{
	int n;
	do {
		cout << "1.Validate uiu cse ID.\n2.Validate Email id.\n3.Validate password.\n4.Validate number.\n5.Validate string.\n6.Exit\n";
		cout << "Enter number:";
		cin >> n;
		if (n == 1)
			func1();
		else if (n == 2)
			func2();
		else if (n == 3)
			func3();
		else if (n == 4)
			func4();
		else if (n == 5)
			func5();
		else if (n == 6)
			break;

	} while (true);
}
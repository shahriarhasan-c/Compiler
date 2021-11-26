#include<iostream>
#include<string.h>
#include <string>

using namespace std;
string s[100][100];
int sz = 1;

void func1(string s1) {
	int l = 0;	
	
	l = s1.length();
	
	if (s1[l - 1] == ';')
	{
		string r1;
		for (int i = 0; i < l - 1; i++)
		{
			if (s1[i] == ' ')
				break;
			else	r1.push_back(s1[i]);
		}
		int l1 = r1.length();
		string r2;
		int k = (l - 1) - (l1 + 1);
		string r3;
		
		if (r1 == "int" || r1 == "float" || r1 == "double" || r1 == "char" || r1 == "string")
		{
			r2 = s1.substr(l1+1, k);
			int l2 = r2.length();
			string r3;
			int flag = 0;
			
			string pre, post;
			for (int i = 0; i < l2; i++)
			{

				r3.push_back(r2[i]);
				int rl = r3.length();

				if (r2[i + 1] == NULL)
				{
					int jl = 0;

					for (int j = 0; j < r3.length(); j++)
					{

						if (r3[j] == '=')
						{
							jl = j;
							flag = 1;

						}
					}
					if (flag == 1) {
						pre = r3.substr(0, jl);
						post = r3.substr(jl + 1, rl);
						int tracker = 0;
						for (int c = 0; c < sz; c++)
						{
							if (s[c][1] == pre)
							{
								tracker = 1;
							}
						}
						if (tracker > 0)
						{
							cout << "Variable "+ pre + " already used.\n";
							i++;
							flag--;
							r3.clear();
							pre.clear();
							post.clear();
						}
							else {
								s[sz][0] = to_string(sz);
								s[sz][1] = pre;
								s[sz][2] = r1;
								s[sz][3] = post;
								i++;
								sz++;
								flag--;
								r3.clear();
								pre.clear();
								post.clear();

							}
						

					}
					else {

						int tracker = 0;
						for (int c = 0; c < sz; c++)
						{
							if (s[c][1] == r3)
							{
								tracker = 1;
							}
						}
						if (tracker > 0)
						{
							cout << "Variable " + r3 + " already used.\n";
							i++;
							r3.clear();

						}
							else {
								s[sz][0] = to_string(sz);
								s[sz][1] = r3;
								s[sz][2] = r1;
								s[sz][3] = "NULL";
								i++;
								sz++;
								r3.clear();

							}

						

					}
				}

				else if (r2[i + 1] == ',') {

					int cl = 0;

					for (int j = 0; j < r3.length(); j++)
					{

						if (r3[j] == '=')
						{
							cl = j;
							flag = 1;

						}
					}
					if (flag == 1) {
						pre = r3.substr(0, cl);
						post = r3.substr(cl + 1, rl);
						int tracker = 0;
						for (int c = 0; c < sz; c++)
						{
							if (s[c][1] == pre)
							{
								tracker = 1;
							}
						}
						if (tracker > 0)
						{
							cout << "Variable " + pre + " already used.\n";
							i++;
							flag--;
							r3.clear();

						}
							else {
								
									
									
										s[sz][0] = to_string(sz);
										s[sz][1] = pre;
										s[sz][2] = r1;
										s[sz][3] = post;
										i++;
										sz++;
										flag--;
										r3.clear();

									
								

							}
						
					}
					else
					{
						int tracker = 0;
						for (int c = 0; c < sz; c++)
						{
							if (s[c][1] == r3)
							{
								tracker = 1;
							}
						}
						if (tracker > 0)
						{
							cout << "Variable " + r3 + " already used.\n";
							i++;
							
							r3.clear();

						}
							else {
								s[sz][0] = to_string(sz);
								s[sz][1] = r3;
								s[sz][2] = r1;
								s[sz][3] = "NULL";
								i++;
								sz++;
								r3.clear();


							}



						
					}

				}
			}
			
			cout << "\nData inserted successfully....\n";
		}
		else
			cout << "Wrong input!! Data-type error...\n";
	}
	else
		cout << "Wrong input!! semicolon needed...\n";
}


void func2(string del) {
	int flag = 0,m=0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (s[i][j] == del)
			{
				m = i;
				
				flag = 1;
				
			}
		}
	}
	
	if (flag == 1) {
		for (int i = m; i < sz; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				s[i][j] = s[i + 1][j];

			}
		}
		cout << "Delete successfully...\n";
	}
	else
		cout << "Variable not found...\n";

}


void func3(string up) {
	int flag = 0, m = 0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (s[i][j] == up)
			{
				m = i;

				flag = 1;

			}
		}
	}

	if (flag == 1) {
		int num = 0;
		string t, val;
		cout << "Variable found!! Which one do you want to update?\n1.TYPE\n2.Value\n";
		cin >> num;
		if (num == 1)
		{
			cout << "Give new type: ";
			cin >> t;
			s[m][2] = t;
			cout << "Update successfully...\n";
		}
		else if (num == 2)
		{
			cout << "Give new value: ";
			cin >> val;
			s[m][3] = val;
			cout << "Update successfully...\n";
		}
	}
	else
		cout << "Variable not found!!!\n";

}


void func4() {
	for (int i = 0; i < sz; i++)
	{
		
		for (int j = 0; j < 4; j++)
		{
			cout << s[i][j];
			cout << "\t";
			cout << "\t";
		}
		cout << "\n";
	}
}





int main() {
	int n;
	
	s[0][0] = "SL";
	s[0][1] = "NAME";
	s[0][2] = "TYPE";
	s[0][3] = "VALUE";
		do {
			cout << "\n*****************\n";
			cout << "1.Insert\n2.Remove\n3.Update\n4.Display\n5.Exit\n";
			cin >> n;
			if (n == 1)
			{
				string input;
				cout << "Enter insert value:";
				cin.ignore();
				getline(cin, input);
				func1(input);
			}
			else if (n == 2)
			{
				string del;
				cout << "Enter a variable name for delete...\n";
				cin >> del;
				func2(del);
			}
			else if (n == 3)
			{
				string up;
				cout << "Enter a variable name for Update...\n";
				cin >> up;
				func3(up);
			}
			else if (n == 4)
			{
				func4();
			}
			else
				break;
		} while (true);
}
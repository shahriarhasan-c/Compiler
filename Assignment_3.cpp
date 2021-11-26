#include<iostream>
#include<fstream>
#include<string>
#include<stack>

using namespace std;

string pre, post;

stack<char>stk1;
stack<char>stk2;

string final;


int presidence(char ch)
{
	if (ch == '+')
		return 1;
	if (ch == '-')
		return 1;
	if (ch == '*')
		return 2;
	if (ch == '/')
		return 2;
	if (ch == '^')
		return 3;
	if (ch == ')')
		return 4;
	if (ch == '(')
		return 4;
	else
		return 0;

}




void prefix(string pre) {
	
	stk1.push(NULL);
	reverse(pre.begin(), pre.end());
	int l = pre.length();
	
	for (int i = 0; i < l; i++)
	{
		
		int flag = 0,flag1=0;
		if (pre[i] == '+' || pre[i] == '-' || pre[i] == '*' || pre[i] == '/' || pre[i] == ')' || pre[i] == '^')
		{
			flag = presidence(pre[i]);
			
			flag1 = presidence(stk1.top());
			
			if (flag == 3 && flag1 == 3)
			{
				//if (presidence(pre[i + 2]) == 3 || presidence(pre[i + 1]) == 4)
				//{
				//	stk1.push(pre[i]);
				//}
				//else {
					final.push_back(stk1.top());
					stk1.pop();
					stk1.push(pre[i]);
				//}
			}
			else if (flag >= flag1) {
				

				stk1.push(pre[i]);
				
			}
			else {
				while ((presidence(stk1.top()) > presidence(pre[i])) && stk1.top() != ')') {
					
					final.push_back(stk1.top());
					stk1.pop();
				}
				
				stk1.push(pre[i]);
				
			}
		}
		else if (pre[i] == '(')
		{
			
			while (stk1.top() != ')')
			{
				
				final.push_back(stk1.top());
				stk1.pop();
			}
			stk1.pop();
		}
		else {
			final.push_back(pre[i]);
			
		}
		
		
	}
	
	while (stk1.size() != 1)
	{
		final.push_back(stk1.top());
		stk1.pop();
	}
	reverse(final.begin(), final.end());
}

void postfix(string post) {
	int l = post.length();
	stk1.push(NULL);
	//reverse(pre.begin(), pre.end());

	for (int i = 0; i < l; i++)
	{
		int flag = 0, flag1 = 0;
		if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '(' || post[i] == '^')
		{
			flag = presidence(post[i]);

			flag1 = presidence(stk1.top());
			if (post[i] == '(')
			{
				stk1.push(post[i]);
			}
			else if (flag == 3 && flag1 == 3)
			{
				//if (presidence(post[i + 2]) == 3 || presidence(post[i + 1])==4)
				//{
					stk1.push(post[i]);
				//}
				//else {
					//final.push_back(stk1.top());
					//stk1.pop();
					//stk1.push(post[i]);
				//}
			}
			else if (flag > flag1) {


				stk1.push(post[i]);
			}
			else {
				while ((presidence(stk1.top()) >= presidence(post[i]))&& stk1.top()!='(') {
					final.push_back(stk1.top());
					
					stk1.pop();
					
				}
				stk1.push(post[i]);
			}
		}
		else if (post[i] == ')')
		{
			while (stk1.top() != '(')
			{
				final.push_back(stk1.top());
				stk1.pop();
			}
			stk1.pop();
		}
		else {
			final.push_back(post[i]);
		}
	}
	while (stk1.size() != 1)
	{
		final.push_back(stk1.top());
		stk1.pop();
	}
	//reverse(final.begin(), final.end());
	
}
int main()
{
	string s1,s2,location;
	do {
		final.clear();
		pre.clear();
		stk1.empty();
		cout << "************************\n";

		cout << "Enter input by(console/file/exit): ";
		cin >> s1;
		if (s1 == "console")
		{
			cout << "Enter choice(prefix/postfix): ";
			cin >> s2;
			if (s2 == "prefix")
			{
				cout << "Enter a prefix Exprassion: ";
				cin >> pre;
				prefix(pre);
				
				cout << "************************\n" << "The Prefix: ";
				cout << final << "\n";

			}
			else if (s2 == "postfix")
			{
				cout << "Enter a postfix Exprassion: ";
				cin >> post;
				postfix(post);
				cout << "************************\n" << "The Postfix: ";
				cout << final << "\n";
			}
		}
		else if (s1 == "file")
		{
			cout << "Give a location of file: ";
			cin >> location;
			cout << "Enter choice(prefix/postfix): ";
			cin >> s2;
			if (s2 == "prefix")
			{
				ifstream myfile(location);
				if (myfile.is_open())
				{
					getline(myfile, pre);
				}
				myfile.close();
				prefix(pre);
				ofstream file;
				file.open(location);
				file << "************************\n" << "The Prefix: ";
				file << final << "\n";
				file.close();
				cout << "done\n";
				
			}
			else if (s2 == "postfix")
			{
				ifstream myfile(location);
				if (myfile.is_open())
				{
					getline(myfile, post);
				}
				myfile.close();
				postfix(post);
				
				ofstream Myfile; 
				Myfile.open(location);
				Myfile << "************************\n" << "The Postfix: ";
				Myfile << final << "\n";
				Myfile.close();
				cout << "done\n";
			}
		}
		else if (s1 == "exit")
		{
			break;
		}
	} while (true);
}
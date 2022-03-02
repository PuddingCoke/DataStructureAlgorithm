#include<iostream>
#include<cstdlib>

using namespace std;

void move(const int& n, const char& a, const char& b, const char& c)
{
	if (n == 1)
	{
		cout << a << "-->" << c << "\n";
		return;
	}
	
	move(n - 1, a, c, b);
	move(1, a, b, c);
	move(n - 1, b, a, c);

}

int main()
{
	move(3, 'A', 'B', 'C');
	return 0;
}
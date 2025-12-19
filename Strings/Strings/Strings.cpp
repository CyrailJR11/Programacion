#include <iostream>
#include <string>
#include <cstdlib> // Include support for randomizing.
#include <ctime> // Include support for ctime.
using namespace std;
//void main(void)
//{
//	char line[80];
//	int count = 0;
//
//	cout << "Enter a sentence of no more than 79 characters:\n";
//	cin.getline(line, 80);
//	cout << "The sentence you entered is :\n";
//	while (line[count] != '\0')
//	{
//		count << line[count];
//		count++;
//	}
//}

//void main(void)
//{
//	string x = "FROM:ayoussef@gwu.edi";
//	int colonPos = x.find(':');
//	string prefix = x.substr(0, colonPos); //=FROM
//	string suffix = x.substr(colonPos + 1);
//	cout << " - This message is from " << suffix << endl;
//
//}


int main() {
	srand(time(nullptr));
	for (int i = 0; i < 10; ++i) {
		cout << (rand() % 6) + 1 << endl;
	}
	return 0;
}
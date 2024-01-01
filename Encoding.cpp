#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
int main()
{
	string alphabet_encoding{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789)(*&^%$#@!~`" };
	string secret_code{ "onyxwvutsEDmlkjihgfedcbaZYzCBQPONMLKJIHGFpXWVUT87!@A12rqSR#$%^&*()563490`~" };
	string user_input{};
	string encoded_message{};
	string yn;
	bool bye =1;
	
	while (bye)
	{
		encoded_message = "";
		cout << "Enter the message to be encoded: ";
		getline(cin, user_input);

		for (int u = 0; u < 3; u++)
		{
			cout << "Encoding....." << endl;
			Sleep(300);
		}

		for (char a : user_input) {
			int index = alphabet_encoding.find(a);
			if (index != string::npos) {
				encoded_message += secret_code.at(index);
			}
			else
			{
				encoded_message += a;
			}

		}

		cout << "The encoded message is :" << encoded_message << endl;
		cout << "Well, what next - perhaps another(1) or no(0): ";
		exctp1:
		getline(cin, yn);
		if (yn == "0")
		{
			bye = 0;
		}
		else if (yn == "1")
		{
			bye = 1;
		}
		else {
			cout << "Please enter a valid option : ";
			goto exctp1;
		}
	}
	
	return 0;
}
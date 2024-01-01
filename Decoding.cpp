#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
int main()
{
	string alphabet_encoding{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789)(*&^%$#@!~` " };
	string secret_code{ "onyxwvutsEDmlkjihgfedcbaZYzCBQPONMLKJIHGFpXWVUT87!@A12rqSR#$%^&*()563490`~_" };
	string encoded_message{};
	string decoded_message{};
	string yn;
	bool bye = 1;
	while (bye)
	{
		decoded_message = "";
		cout << "Enter the encoded message: ";
		getline(cin, encoded_message);
		for (int u = 0; u < 3; u++)
		{
			cout << "Decoding....." << endl;
			Sleep(600);
		}


		for (char p : encoded_message) {
			int index2 = secret_code.find(p);
			if (index2 != string::npos)
			{
				decoded_message += alphabet_encoding.at(index2);
			}
			else
			{
				decoded_message += p;
			}

		}
		cout << "The decoded message is: " << decoded_message << endl;
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
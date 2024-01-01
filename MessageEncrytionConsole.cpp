#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
void startup(LPCSTR lpApplicationName);
int main()
{
    string yn, ui;
    LPCSTR encapp = "C:\\Users\\Raghav\\PROGRAMMING STUFF\\AllProjects\\Personal C++ Projects\\Message Encrytion Console\\Encoding.exe";
    LPCSTR decapp = "C:\\Users\\Raghav\\PROGRAMMING STUFF\\AllProjects\\Personal C++ Projects\\Message Encrytion Console\\Decoding.exe";

    while (1)
    {
        system("cls");
        cout << "Well....do something! - Encoder(1) || Decoder(0): ";
        exctp1:
        getline(cin, yn);
        if (yn == "0")
        {
            startup(decapp);
        }
        else if (yn == "1")
        {
            startup(encapp);
        }
        else if (yn == "-exit -f") {
            return 0;
        }
        else if (yn == "-exit")
        {
            cout << "Are u sure you ye want to exit? [1(Sure) | 0(Nope Mistake)]"<<endl;
            getline(cin, ui);
            if (ui == "1") {
                return 0;
            }
            else if (ui == "0") {
                continue;
            }
        }
        else {
            cout << "Please enter a valid option : ";
            goto exctp1;
        }
    }
}
void startup(LPCSTR lpApplicationName)
{
    // additional information
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    // set the size of the structures
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // start the program up
    CreateProcessA
    (
        lpApplicationName,   // the path
        NULL,                // Command line
        NULL,                   // Process handle not inheritable
        NULL,                   // Thread handle not inheritable
        FALSE,                  // Set handle inheritance to FALSE
        CREATE_NEW_CONSOLE,     // Opens file in a separate console
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory 
        &si,            // Pointer to STARTUPINFO structure
        &pi           // Pointer to PROCESS_INFORMATION structure
    );
    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}
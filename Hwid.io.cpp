// Hwid.io.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <stdio.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <urlmon.h>
#include <wininet.h>
#include <strsafe.h>
#include <conio.h>
#include <iosfwd>
#include "print.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <dwrite.h>
#include <urlmon.h>
#include "loader.h"


#pragma comment(lib, "Wininet.lib")

#pragma comment(lib, "urlmon.lib")

#define StrW VMProtectDecryptStringW
#define StrA VMProtectDecryptStringA
#include "print.h"
#include <filesystem>
#include <string>
#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <ostream>
#include <regex>
#include <filesystem>
#include <istream>
#include <cstdio>
#include <string>
#include <tchar.h>
#include <random>

using namespace std;
using namespace std::filesystem;


class Color
{
public:
    Color(int desiredColor) {
        consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        color = desiredColor;
    }

    friend std::ostream& operator<<(std::ostream& ss, Color obj) {
        SetConsoleTextAttribute(obj.consoleHandle, obj.color);
        return ss;
    }
private:
    int color;
    HANDLE consoleHandle;
    /*
    0 = black
    1 = blue
    2 = green
    3 = light blue
    4 = red
    5 = purple
    6 = gold
    7 = white
    */
};

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
namespace GlobalItems
{
    enum LicenseStates
    {
        LICENSE_AVERAGE = 0,
        LICENSE_UNEXPECTED,
        LICENSE_EXPIRED
    };
}
// yeah
int confirmLicone()
{
    VMProtectBeginUltra("licensingFn");
    std::ifstream inFile;
    inFile.open(StrA("C:\\ProgramData\\Saved.Key"));
    if (!inFile) {
        //std::cout << StrA("Error : 1\n");
        return GlobalItems::LicenseStates::LICENSE_UNEXPECTED;
    }

    if (inFile.is_open())
    {
        std::string line;
        getline(inFile, line);
        inFile.close();
        char serial[1024]; serial[0] = 0;
        int lic = VMProtectActivateLicense(line.c_str(), serial, sizeof(serial));
        int res = VMProtectSetSerialNumber(serial);
        if (!lic && !res)
        {
            printf(StrA("License Accepted!\n"));
            Sleep(700); system("cls");  return GlobalItems::LicenseStates::LICENSE_AVERAGE; // ok

        }
        else
        {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        }
    }
    else
    {
        //std::cout << StrA("error : 1");
        return GlobalItems::LicenseStates::LICENSE_UNEXPECTED;
        //printf(StrA("[+] License invalid!\n"));
        Sleep(700);
    }

    return GlobalItems::LicenseStates::LICENSE_AVERAGE; // ok
    VMProtectEnd();
}

void ConfirmLicense()
{
    VMProtectBeginUltra("ConfirmLicenseFn");
    VMProtectEnd();
}
void printlogo()
{

    system("cls");
    std::cout << Color(6) << R"(
                                                                       
                                                                                                   
 _|      _|  _|      _|  _|_|_|    _|_|_|      _|_|    _|_|_|_|_|  _|_|_|_|    _|_|_|  _|_|_|_|_|  
 _|      _|  _|_|  _|_|  _|    _|  _|    _|  _|    _|      _|      _|        _|            _|      
 _|      _|  _|  _|  _|  _|_|_|    _|_|_|    _|    _|      _|      _|_|_|    _|            _|      
   _|  _|    _|      _|  _|        _|    _|  _|    _|      _|      _|        _|            _|      
     _|      _|      _|  _|        _|    _|    _|_|        _|      _|_|_|_|    _|_|_|      _|      
                                                                                                   
                                                                                                                                                                                                       																			                                                                                   
        )";
    std::cout << "\n";
}

void Licensing()
{
    std::string choice;
    auto retn = confirmLicone();
    if (retn == GlobalItems::LicenseStates::LICENSE_AVERAGE)
    {
        ConfirmLicense();

        print::set_text("[1] Example \n", LightGray);
        std::getline(std::cin, choice);

        if (choice == "1")
        {
            system("CLS");
      
        }
       
        std::getline(std::cin, choice);
    }
    else
    {

        std::cout << StrA("[+] Enter your key: "); SetConsoleTextAttribute(hStdOut, 11);
        std::string keyInput;
        std::cin >> keyInput;
        std::ofstream myfile("C:\\ProgramData\\Saved.Key");
        myfile << keyInput;
        myfile.close();
        system("cls");
        Licensing();
    }
}

int main()
{
    printlogo();
    Licensing();
}
////////////////////////////////////////////////////////////////////////////////
// PrintUnicodeToConsoleWin.cpp : Print Unicode text to the Windows console.
// by Giovanni Dicanio
////////////////////////////////////////////////////////////////////////////////

#include <fcntl.h>      // for _setmode
#include <io.h>         // for _setmode
#include <stdio.h>      // for _fileno

#include <iostream>     // for std::wcout

#include "Utf8Conv.hpp" // Unicode UTF-8 conversion helpers


int main()
{
    static const int kExitOk = 0;
    static const int kExitError = -1;

    //
    // Change stdout to Unicode UTF-16
    //
    int result = _setmode(_fileno(stdout), _O_U16TEXT);
    if (result == -1)
    {
        std::wcout << L"*** ERROR: _setmode failed - Can't set stdout to Unicode UTF-16.\n\n";
        return kExitError;
    }
    std::wcout << L"Console output (stdout) correctly set to Unicode UTF-16.\n\n";


    //
    // Unicode      UTF-16          UTF-8
    //---------------------------------------------
    // U+65E5       0x65E5          0xE6 0x97 0xA5
    // U+672C       0x672C          0xE6 0x9C 0xAC
    //

    //
    // Print some Unicode text encoded in UTF-16
    //
    std::wcout << L" Japan written in Japanese: \x65e5\x672c (Nihon) [UTF-16] \n";

    //
    // Print some Unicode text encoded in UTF-8
    // (convert to UTF-16 for printing the text out)
    //
    const std::string kUtf8Nihon = "\xE6\x97\xA5\xE6\x9C\xAC";
    std::wcout << L" Japan written in Japanese: " << Utf8Conv::Utf8ToUtf16(kUtf8Nihon)
               << L" (Nihon) [UTF-8] \n";

    return kExitOk;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

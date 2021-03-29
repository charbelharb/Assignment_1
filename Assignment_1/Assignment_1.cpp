// Assignment_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GradeReport.h"
int main()
{
    GradeReport* rp = new GradeReport(201715389, "Charbel", "Harb", 15, 32);
    GradeReport rp2(20201233, "foo", "bar", NULL, NULL);
    
    std::cout << *(rp);
    *(rp) += 1;
    *(rp) = 20180000;
    *(rp) += *(rp);
    std::cout << *(rp);
    //delete rp;
    system("pause");
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

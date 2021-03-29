
#include <iostream>
#include "GradeReport.h"
int main()
{
    // question 1-2
    auto* rp = new GradeReport(201715389, "Charbel", "Harb", 15, 32);
    auto* rp1 = new GradeReport();
    GradeReport rp2(20201233, "foo", "bar", 0, 0);
    GradeReport rp3;
    
    // question 3-4
    std::cout << "Stream overload \n";
    std::cin >> *(rp1) >> rp3;
    std::cout << *(rp1) << rp3;

    // question 5
    std::cout << "++ overload \n";
    std::cout << *(rp) << std::endl;
    ++*(rp);
    std::cout << *(rp) << std::endl;

    // question 6
    std::cout << "+= overload \n";
    std::cout << rp2 << std::endl;
    rp2 += 7;
    std::cout << rp2 << std::endl;

    // question 7
    std::cout << "= overload \n";
    std::cout << rp3 << std::endl;
    rp3 = 20211234;
    std::cout << rp3 << std::endl;

    // question 8
    // same object
    GradeReport* rf = &rp3;
    std::cout << rp3 << std::endl;
    rp3 += *(rf);
    std::cout << rp3 << std::endl;

    // not same object
    std::cout << *(rp) << std::endl;
    *(rp) += rp2;
    std::cout << *(rp) << std::endl;

    //delete rp;
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    system("pause");
#elif __APPLE__ || __linux__ || __linux || __unix || __unix__ || __posix || defined(_POSIX_VERSION)
    std::cin.get();
#endif

}

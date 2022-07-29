#include "stopwatch.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
/*********************************************************************/
/*                                                                   */
/*   Author: Catherine Leung                                         */
/*                                                                   */
/*   To compile: c++ a2.cpp stopwatch.cpp                            */
/*   If you are compiling with VS in Windows, change line 9 in       */
/*   stopwatch.h to: #define PLATFORM WINDOWS                        */
/*                                                                   */
/*********************************************************************/

const int N = 1000000;
int main(int argc, char *argv[])
{

    //  uncomment next line for c++ file I/O
    std::ofstream outfile("myoutput.csv");

    //  uncomment next line to do C style file I/O.. note.. pick C or C++, not both.
    //  FILE* fp=fopen("myoutput.csv","w");

    int a[N];
    int P = atoi(argv[1]);
    for (P = atoi(argv[1]); P <= 100; P++)
    {
        for (int i = 0; i < N; i++)
        {
            a[i] = rand() % 100;
        }

        volatile int s;

        StopWatch watch;
        for (int i = 0; i < 5; i++)
        {
            watch.reset();
            watch.start(); // start the stop watch
            for (int i = 0; i < N; i++)
            {
                if (a[i] < P)
                {
                    s += a[i];
                }
            }
            watch.stop(); // stop the stop watch
            if (i < 4)
                outfile << watch.currtime() << ", ";
            if (i == 4)
                outfile << watch.currtime();
        }
        outfile << std::endl;
    }
    //  C++ style file output:

    /*
        outfile << "this text will go to the file myoutput.csv" << std::endl;
        outfile << "to print using C++ output, use the same syntax as you would with std::cout" << std::endl;
        outfile << "only difference is use file handle name instead of std::cout (in this case outfile)" << std::endl;
        outfile << "c++ io is doesn't require format codes.  Separate tokens of different types with <<" << std::endl;
        outfile << "example to print 2 variables P and N with comma separation to file: ";
        outfile << P << ", " << N << std::endl;
    */

    //  C style file output:
    /*
        fprintf(fp,"This text will go into the file myoutput.csv\n");
        fprintf(fp,"fprintf is similar to C printf, only need to pass in file pointer before format string\n");
        fprintf(fp,"to print 2 variables P and N with comma separation to file: ");
        fprintf(fp,"%d,%d\n",P,N);
        fclose(fp);
    */
}

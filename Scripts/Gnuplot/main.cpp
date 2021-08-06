#include <iostream>
#include "gnuplot_i.hpp" //Gnuplot class handles POSIX-Pipe-communikation with Gnuplot

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)
 #include <conio.h>   //for getch(), needed in wait_for_key()
 #include <windows.h> //for Sleep()
 void sleep(int i) { Sleep(i*1000); }
#endif


#define SLEEP_LGTH 2  // sleep time in seconds
#define NPOINTS    50 // length of array

void wait_for_key(); // Programm halts until keypress

using namespace std;

int main()
{
//   ConvexHull obj;
   //Generate N random points..
   int N = 100;
   double Min = 0, Max = 1;
   try{
        Gnuplot g1("lines");
        g1.set_title("Convex-Hull Graham-Scan   ;) TITULO");
	vector<double> xs, ys;
	for(int i = 0; i < N; i++)
        { 
         xs.push_back(Min + ((double)rand()/RAND_MAX)/(Max - Min));
         ys.push_back(Min + ((double)rand()/RAND_MAX)/(Max - Min));
        }
	g1.set_style("points").plot_xy(xs,ys,"Generated random points.");
        g1.showonscreen(); // window output
        wait_for_key();
   }catch (GnuplotException ge)
    {
        cout << ge.what() << endl;
    }

   
   return 0;
}
void wait_for_key ()
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__)  // every keypress registered, also arrow keys
    cout << endl << "Press any key to continue..." << endl;

    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    _getch();
#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__)
    cout << endl << "Press ENTER to continue..." << endl;

    std::cin.clear();
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    std::cin.get();
#endif
    return;
}

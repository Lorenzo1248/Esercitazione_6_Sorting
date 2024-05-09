#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


int main(int argc, char **argv)
{
    cout << argc <<endl;
    cout << argv[0] <<endl;
    cout << argv[1] <<endl;

    // per creare ordine si usa iota() o generate
    int n = 10;
    vector<int> v(10000);
    //iota(v.begin(), v.end(), n);
    generate(v.begin(),v.end(), [&n] () {return n--;});

    srand(10);

    for(unsigned int i= 0; i<10;i++)
    {
        v[i] = rand() % 100;
    }

    for(unsigned int i = 0; i<5; i++)
        cout<<v[i]<< " ";
    cout << endl;

    cout << n << endl;



    std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();

    sleep(10);

    std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();

    double duration = std::chrono::duration_cast <std::chrono::milliseconds>(t_end - t_begin).count();
    cout << duration << endl;

    return 0;
}


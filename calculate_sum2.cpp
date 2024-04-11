#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int threads_num = omp_get_max_threads();
    cout << "All Threads num: " << threads_num << endl;

    long int val = 0;
    double start, end;
    start = omp_get_wtime();

    cout << "Start: " << start << endl;
    // 総和を求める
    for (long int i = 0; i < 1000000000; i++)
    {
        val += i;
    }

    end = omp_get_wtime();
    cout << "End: " << end << endl;
    cout << "Sum: " << val << endl;
    cout << "Time: " << end - start << "s" << endl;  // 並列化しないと、だいたい2sくらい

    return 0;
}

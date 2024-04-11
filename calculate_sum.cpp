#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    int threads_num = omp_get_max_threads();
    cout << "All Threads num: " << threads_num << endl;

    int val = 0;

    // 0から79までの値の総和を求める
    #pragma omp parallel for reduction(+:val)
    for (int i = 0; i < 80; ++i)
    {
        val += i;
    }

    cout << "Sum: " << val << endl;

    return 0;
}

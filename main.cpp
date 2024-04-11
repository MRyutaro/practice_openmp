#include <iostream>
#include <omp.h>

using namespace std;  // std::を省略できる。例えば、coutをstd::coutと書かなくてもよい。

int main()
{
    int threads_num = omp_get_max_threads();
    cout << "All Threads num: " << threads_num << endl;

    #pragma omp parallel for
    for (int i = 0; i < 80; ++i)
    {
        // 並列する処理
        #pragma omp critical
        cout << "Thread No. " << omp_get_thread_num() << " : " << i << endl;
    }

    return 0;
}

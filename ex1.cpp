#include <iostream>
#include <omp.h>

using namespace std;  // std::を省略できる。例えば、coutをstd::coutと書かなくてもよい。

int main()
{
    int threads_num = omp_get_max_threads();
    cout << "All Threads num: " << threads_num << endl;

    int n = 500;
    // a, b, cはn✖️nの行列
    int a[n][n], b[n][n], c[n][n];

    // 行列a, bの初期化
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            // ランダムな値で初期化
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }
    // cout << "Matrix A:" << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "Matrix B:" << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "Matrix C:" << endl;

    double start, end;
    start = omp_get_wtime();
    ////////////////////////////////
    // 行列の積を直列で計算
    ////////////////////////////////]
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         c[i][j] = 0;
    //         for(int k = 0; k < n; k++)
    //         {
    //             c[i][j] += a[i][k] * b[k][j];
    //         }
    //     }
    // }
    ////////////////////////////////
    // 行列の積を並列で計算
    ////////////////////////////////
    
    end = omp_get_wtime();
    cout << "Time: " << end - start << "s" << endl;  // 0.3sくらい

    return 0;
}

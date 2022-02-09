#include <iostream>
#include <cblas.h>
#include <vector>
#include "Matrices.cpp"
using namespace std;

void printMatrix(int **mat)
{
    cout<<"\n Printing Matrix : \n";
    for(int i=0 ; i<=ROW-1 ; i++)
    {
        for(int j=0 ; j<=COL-1 ; j++)
            cout<< *(*(mat+i)+j)<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    float A[3][4] = {{1.0,0.2,0.6,0.9},{1.6,3.3,4.7,5.2},{0.2,2.6,9.0,2.5}};
    float B[4][2] = {{3.2,4.3},{1.1,6.6},{8.9,0.2},{2.4,5.6}};
    float C[3][2];
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,3, 2, 4, 1, *A, 4, *B,4, 1.0, *C,3);
    printMatrix(C);
    return 0;

}




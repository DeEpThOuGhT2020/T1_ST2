#include <iostream>
#include "mkl.h"
#include <bits/stdc++.h>
#include <vector>
#include <chrono>
using namespace std;
/*
void printMatrix(float *mat){
    int m = *(&mat + 1) - mat;
    int n = *(&mat[0] + 1) - mat[0];

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << *mat[i][j] << " ";
        }cout << endl; 
    }
}*/

float* initialize(int M, int N){
    float arr[M][N];
    srand(time(0));
    for(int i = 0 ; i < M ; ++i){
        for(int j = 0 ; j < N ; ++j){
            arr[i][j] = -1000.0 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(1000.0 - (-1000.0))));
        }
    }return *arr;
}
int main(){
    float *A = initialize(3,4);
    float *B = initialize(4,2);
    float *C;
    auto mkl_t_1 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,3, 2, 4, 1, A, 4, B,2, 1.0, C,3);
    auto mkl_t_2 = chrono::steady_clock::now();
    cout <<"T1" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_2 - mkl_t_1).count()<<"ns"<<"For 3X4 and 4X2 input";
    auto mkl_t_1 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,3, 2, 4, 1, A, 4, B,2, 1.0, C,3);
    auto mkl_t_2 = chrono::steady_clock::now();
    cout <<"T2" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_2 - mkl_t_1).count()<<"ns"<<"For 3X4 and 4X2 input";
    auto mkl_t_1 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,3, 2, 4, 1, A, 4, B,2, 1.0, C,3);
    auto mkl_t_2 = chrono::steady_clock::now();
    cout <<"T3" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_2 - mkl_t_1).count()<<"ns"<<"For 3X4 and 4X2 input";
    auto mkl_t_1 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,3, 2, 4, 1, A, 4, B,2, 1.0, C,3);
    auto mkl_t_2 = chrono::steady_clock::now();
    cout <<"T4" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_2 - mkl_t_1).count()<<"ns"<<"For 3X4 and 4X2 input";
    auto mkl_t_1 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,3, 2, 4, 1, A, 4, B,2, 1.0, C,3);
    auto mkl_t_2 = chrono::steady_clock::now();
    cout <<"T5" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_2 - mkl_t_1).count()<<"ns"<<"For 3X4 and 4X2 input";


    float *A = initialize(30,40);
    float *B = initialize(40,20);
    float *C;
    auto mkl_t_3 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,30, 20, 40, 1, A, 40, B,20, 1.0, C,20);
    auto mkl_t_4 = chrono::steady_clock::now();
    cout<<"T1" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_4 - mkl_t_3).count()<<"ns"<< "For 30X40 and 40X20 input";
    auto mkl_t_3 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,30, 20, 40, 1, A, 40, B,20, 1.0, C,20);
    auto mkl_t_4 = chrono::steady_clock::now();
    cout<<"T2" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_4 - mkl_t_3).count()<<"ns"<< "For 30X40 and 40X20 input";
    auto mkl_t_3 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,30, 20, 40, 1, A, 40, B,20, 1.0, C,20);
    auto mkl_t_4 = chrono::steady_clock::now();
    cout<<"T3" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_4 - mkl_t_3).count()<<"ns"<< "For 30X40 and 40X20 input";
    auto mkl_t_3 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,30, 20, 40, 1, A, 40, B,20, 1.0, C,20);
    auto mkl_t_4 = chrono::steady_clock::now();
    cout<<"T4" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_4 - mkl_t_3).count()<<"ns"<< "For 30X40 and 40X20 input";
    auto mkl_t_3 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,30, 20, 40, 1, A, 40, B,20, 1.0, C,20);
    auto mkl_t_4 = chrono::steady_clock::now();
    cout<<"T5" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_4 - mkl_t_3).count()<<"ns"<< "For 30X40 and 40X20 input";



    float *A = initialize(70,70);
    float *B = initialize(70,70);
    float *C;
    auto mkl_t_5 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,70, 70, 70, 1, A, 70, B,70, 1.0, C,70);
    auto mkl_t_6 = chrono::steady_clock::now();
    cout<<"T1" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_6 - mkl_t_5).count()<<"ns"<< "For 70X70 and 70X70 input";
     auto mkl_t_5 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,70, 70, 70, 1, A, 70, B,70, 1.0, C,70);
    auto mkl_t_6 = chrono::steady_clock::now();
    cout<<"T2" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_6 - mkl_t_5).count()<<"ns"<< "For 70X70 and 70X70 input";
     auto mkl_t_5 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,70, 70, 70, 1, A, 70, B,70, 1.0, C,70);
    auto mkl_t_6 = chrono::steady_clock::now();
    cout<<"T3" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_6 - mkl_t_5).count()<<"ns"<< "For 70X70 and 70X70 input";
     auto mkl_t_5 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,70, 70, 70, 1, A, 70, B,70, 1.0, C,70);
    auto mkl_t_6 = chrono::steady_clock::now();
    cout<<"T4" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_6 - mkl_t_5).count()<<"ns"<< "For 70X70 and 70X70 input";
     auto mkl_t_5 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,70, 70, 70, 1, A, 70, B,70, 1.0, C,70);
    auto mkl_t_6 = chrono::steady_clock::now();
    cout<<"T5" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_6 - mkl_t_5).count()<<"ns"<< "For 70X70 and 70X70 input";


    float *A = initialize(100,40);
    float *B = initialize(40,100);
    float *C;
    auto mkl_t_7 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,100, 100, 40, 1, A, 40, B,100, 1.0, C,100);
    auto mkl_t_8 = chrono::steady_clock::now();
    cout <<"T1"<< chrono::duration_cast<chrono::nanoseconds>(mkl_t_8 - mkl_t_7).count()<<"ns"<< "For 100X40 and 40X100 input";
    auto mkl_t_7 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,100, 100, 40, 1, A, 40, B,100, 1.0, C,100);
    auto mkl_t_8 = chrono::steady_clock::now();
    cout <<"T2"<< chrono::duration_cast<chrono::nanoseconds>(mkl_t_8 - mkl_t_7).count()<<"ns"<< "For 100X40 and 40X100 input";auto mkl_t_7 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,100, 100, 40, 1, A, 40, B,100, 1.0, C,100);
    auto mkl_t_8 = chrono::steady_clock::now();
    cout <<"T3"<< chrono::duration_cast<chrono::nanoseconds>(mkl_t_8 - mkl_t_7).count()<<"ns"<< "For 100X40 and 40X100 input";auto mkl_t_7 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,100, 100, 40, 1, A, 40, B,100, 1.0, C,100);
    auto mkl_t_8 = chrono::steady_clock::now();
    cout <<"T4"<< chrono::duration_cast<chrono::nanoseconds>(mkl_t_8 - mkl_t_7).count()<<"ns"<< "For 100X40 and 40X100 input";auto mkl_t_7 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,100, 100, 40, 1, A, 40, B,100, 1.0, C,100);
    auto mkl_t_8 = chrono::steady_clock::now();
    cout <<"T5"<< chrono::duration_cast<chrono::nanoseconds>(mkl_t_8 - mkl_t_7).count()<<"ns"<< "For 100X40 and 40X100 input";


    float *A = initialize(120,140);
    float *B = initialize(140,110);
    float *C;
    auto mkl_t_9 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,120, 110, 140, 1, A, 140, B,110, 1.0, C,110);
    auto mkl_t_10 = chrono::steady_clock::now();
    cout<<"T1" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_10 - mkl_t_9).count()<<"ns"<< "For 120X140 and 140X110 input";
     auto mkl_t_9 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,120, 110, 140, 1, A, 140, B,110, 1.0, C,110);
    auto mkl_t_10 = chrono::steady_clock::now();
    cout<<"T2" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_10 - mkl_t_9).count()<<"ns"<< "For 120X140 and 140X110 input"; auto mkl_t_9 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,120, 110, 140, 1, A, 140, B,110, 1.0, C,110);
    auto mkl_t_10 = chrono::steady_clock::now();
    cout<<"T3" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_10 - mkl_t_9).count()<<"ns"<< "For 120X140 and 140X110 input"; auto mkl_t_9 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,120, 110, 140, 1, A, 140, B,110, 1.0, C,110);
    auto mkl_t_10 = chrono::steady_clock::now();
    cout<<"T4" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_10 - mkl_t_9).count()<<"ns"<< "For 120X140 and 140X110 input"; auto mkl_t_9 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,120, 110, 140, 1, A, 140, B,110, 1.0, C,110);
    auto mkl_t_10 = chrono::steady_clock::now();
    cout<<"T5" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_10 - mkl_t_9).count()<<"ns"<< "For 120X140 and 140X110 input";

    

    float *A = initialize(200,150);
    float *B = initialize(150,180);
    float *C;
    auto mkl_t_11 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,200, 180, 150, 1, A, 150, B,180, 1.0, C,180);
    auto mkl_t_12 = chrono::steady_clock::now();
    cout<<"T1" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_12 - mkl_t_11).count()<<"ns"<< "For 200X150 and 150X180 input";
    auto mkl_t_11 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,200, 180, 150, 1, A, 150, B,180, 1.0, C,180);
    auto mkl_t_12 = chrono::steady_clock::now();
    cout<<"T2" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_12 - mkl_t_11).count()<<"ns"<< "For 200X150 and 150X180 input";
    auto mkl_t_11 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,200, 180, 150, 1, A, 150, B,180, 1.0, C,180);
    auto mkl_t_12 = chrono::steady_clock::now();
    cout<<"T3" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_12 - mkl_t_11).count()<<"ns"<< "For 200X150 and 150X180 input";
    auto mkl_t_11 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,200, 180, 150, 1, A, 150, B,180, 1.0, C,180);
    auto mkl_t_12 = chrono::steady_clock::now();
    cout<<"T4" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_12 - mkl_t_11).count()<<"ns"<< "For 200X150 and 150X180 input";
    auto mkl_t_11 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,200, 180, 150, 1, A, 150, B,180, 1.0, C,180);
    auto mkl_t_12 = chrono::steady_clock::now();
    cout<<"T5" << chrono::duration_cast<chrono::nanoseconds>(mkl_t_12 - mkl_t_11).count()<<"ns"<< "For 200X150 and 150X180 input";
    
    
    return 0;

}




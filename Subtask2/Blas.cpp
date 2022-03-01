#include <iostream>
#include "cblas.h"
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
float A[10000][10000];
float B[10000][10000];
float C[10000][10000];
void initialize_A(int M, int N){
    
    srand(time(0));
    for(int i = 0 ; i < M ; ++i){
        for(int j = 0 ; j < N ; ++j){
            A[i][j] = -1000.0 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(1000.0 - (-1000.0))));
        }
    }
}
void initialize_B(int M, int N){
    
    srand(time(0));
    for(int i = 0 ; i < M ; ++i){
        for(int j = 0 ; j < N ; ++j){
            B[i][j] = -1000.0 + static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX/(1000.0 - (-1000.0))));
        }
    }
}
int main(){
    initialize_A(3,4);
    initialize_B(4,2);
    
    auto blas_t_1 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,3, 2, 4, 1, *A, 4, *B,2, 1.0, *C,3);
    auto blas_t_2 = chrono::steady_clock::now();
    cout <<"T1: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_2 - blas_t_1).count()<<" ns "<<"For 3X4 and 4X2 input" <<endl;
    blas_t_1 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,3, 2, 4, 1, *A, 4, *B,2, 1.0, *C,3);
    blas_t_2 = chrono::steady_clock::now();
    cout <<"T2: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_2 - blas_t_1).count()<<" ns "<<"For 3X4 and 4X2 input"<<endl;
    blas_t_1 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,3, 2, 4, 1, *A, 4, *B,2, 1.0, *C,3);
    blas_t_2 = chrono::steady_clock::now();
    cout <<"T3: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_2 - blas_t_1).count()<<" ns "<<"For 3X4 and 4X2 input"<<endl;
    blas_t_1 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,3, 2, 4, 1, *A, 4, *B,2, 1.0, *C,3);
    blas_t_2 = chrono::steady_clock::now();
    cout <<"T4: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_2 - blas_t_1).count()<<" ns "<<"For 3X4 and 4X2 input"<<endl;
    blas_t_1 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,3, 2, 4, 1, *A, 4, *B,2, 1.0, *C,3);
    blas_t_2 = chrono::steady_clock::now();
    cout <<"T5: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_2 - blas_t_1).count()<<" ns "<<"For 3X4 and 4X2 input"<<endl;


    initialize_A(30,40);
    initialize_B(40,20);
    auto blas_t_3 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,30, 20, 40, 1, *A, 40, *B,20, 1.0, *C,20);
    auto blas_t_4 = chrono::steady_clock::now();
    cout<<"T1: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_4 - blas_t_3).count()<<" ns "<< "For 30X40 and 40X20 input"<<endl;
    blas_t_3 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,30, 20, 40, 1, *A, 40, *B,20, 1.0, *C,20);
    blas_t_4 = chrono::steady_clock::now();
    cout<<"T2: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_4 - blas_t_3).count()<<" ns "<< "For 30X40 and 40X20 input"<<endl;
    blas_t_3 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,30, 20, 40, 1, *A, 40, *B,20, 1.0, *C,20);
    blas_t_4 = chrono::steady_clock::now();
    cout<<"T3: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_4 - blas_t_3).count()<<" ns "<< "For 30X40 and 40X20 input"<<endl;
    blas_t_3 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,30, 20, 40, 1, *A, 40, *B,20, 1.0, *C,20);
    blas_t_4 = chrono::steady_clock::now();
    cout<<"T4: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_4 - blas_t_3).count()<<" ns "<< "For 30X40 and 40X20 input"<<endl;
    blas_t_3 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,30, 20, 40, 1, *A, 40, *B,20, 1.0, *C,20);
    blas_t_4 = chrono::steady_clock::now();
    cout<<"T5: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_4 - blas_t_3).count()<<" ns "<< "For 30X40 and 40X20 input"<<endl;



    initialize_A(70,70);
    initialize_B(70,70);
    
    auto blas_t_5 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,70, 70, 70, 1, *A, 70, *B,70, 1.0, *C,70);
    auto blas_t_6 = chrono::steady_clock::now();
    cout<<"T1: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_6 - blas_t_5).count()<<" ns "<< "For 70X70 and 70X70 input"<<endl;
    blas_t_5 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,70, 70, 70, 1, *A, 70, *B,70, 1.0, *C,70);
    blas_t_6 = chrono::steady_clock::now();
    cout<<"T2: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_6 - blas_t_5).count()<<" ns "<< "For 70X70 and 70X70 input"<<endl;
    blas_t_5 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,70, 70, 70, 1, *A, 70, *B,70, 1.0, *C,70);
    blas_t_6 = chrono::steady_clock::now();
    cout<<"T3: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_6 - blas_t_5).count()<<" ns "<< "For 70X70 and 70X70 input"<<endl;
    blas_t_5 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,70, 70, 70, 1, *A, 70, *B,70, 1.0, *C,70);
    blas_t_6 = chrono::steady_clock::now();
    cout<<"T4: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_6 - blas_t_5).count()<<" ns "<< "For 70X70 and 70X70 input"<<endl;
    blas_t_5 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,70, 70, 70, 1, *A, 70, *B,70, 1.0, *C,70);
    blas_t_6 = chrono::steady_clock::now();
    cout<<"T5: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_6 - blas_t_5).count()<<" ns "<< "For 70X70 and 70X70 input"<<endl;


    initialize_A(100,40);
    initialize_B(40,100);

    auto blas_t_7 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,100, 100, 40, 1, *A, 40, *B,100, 1.0, *C,100);
    auto blas_t_8 = chrono::steady_clock::now();
    cout <<"T1: "<< chrono::duration_cast<chrono::nanoseconds>(blas_t_8 - blas_t_7).count()<<" ns "<< "For 100X40 and 40X100 input"<<endl;
    blas_t_7 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,100, 100, 40, 1, *A, 40, *B,100, 1.0, *C,100);
    blas_t_8 = chrono::steady_clock::now();
    cout <<"T2: "<< chrono::duration_cast<chrono::nanoseconds>(blas_t_8 - blas_t_7).count()<<" ns "<< "For 100X40 and 40X100 input"<<endl;
    blas_t_7 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,100, 100, 40, 1, *A, 40, *B,100, 1.0, *C,100);
    blas_t_8 = chrono::steady_clock::now();
    cout <<"T3: "<< chrono::duration_cast<chrono::nanoseconds>(blas_t_8 - blas_t_7).count()<<" ns "<< "For 100X40 and 40X100 input"<<endl;
    blas_t_7 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,100, 100, 40, 1, *A, 40, *B,100, 1.0, *C,100);
    blas_t_8 = chrono::steady_clock::now();
    cout <<"T4: "<< chrono::duration_cast<chrono::nanoseconds>(blas_t_8 - blas_t_7).count()<<" ns "<< "For 100X40 and 40X100 input"<<endl;
    blas_t_7 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,100, 100, 40, 1, *A, 40, *B,100, 1.0, *C,100);
    blas_t_8 = chrono::steady_clock::now();
    cout <<"T5: "<< chrono::duration_cast<chrono::nanoseconds>(blas_t_8 - blas_t_7).count()<<" ns "<< "For 100X40 and 40X100 input"<<endl;


    initialize_A(120,140);
    initialize_B(140,110);

    auto blas_t_9 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,120, 110, 140, 1, *A, 140, *B,110, 1.0, *C,110);
    auto blas_t_10 = chrono::steady_clock::now();
    cout<<"T1: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_10 - blas_t_9).count()<<" ns "<< "For 120X140 and 140X110 input"<<endl;
    blas_t_9 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,120, 110, 140, 1, *A, 140, *B,110, 1.0, *C,110);
    blas_t_10 = chrono::steady_clock::now();
    cout<<"T2: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_10 - blas_t_9).count()<<" ns "<< "For 120X140 and 140X110 input"<<endl; 
    blas_t_9 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,120, 110, 140, 1, *A, 140, *B,110, 1.0, *C,110);
    blas_t_10 = chrono::steady_clock::now();
    cout<<"T3: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_10 - blas_t_9).count()<<" ns "<< "For 120X140 and 140X110 input"<<endl;
    blas_t_9 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,120, 110, 140, 1, *A, 140, *B,110, 1.0, *C,110);
    blas_t_10 = chrono::steady_clock::now();
    cout<<"T4: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_10 - blas_t_9).count()<<" ns "<< "For 120X140 and 140X110 input"<<endl; 
    blas_t_9 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,120, 110, 140, 1, *A, 140, *B,110, 1.0, *C,110);
    blas_t_10 = chrono::steady_clock::now();
    cout<<"T5: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_10 - blas_t_9).count()<<" ns "<< "For 120X140 and 140X110 input"<<endl;

    

    initialize_A(200,150);
    initialize_B(150,180);
    
    auto blas_t_11 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,200, 180, 150, 1, *A, 150, *B,180, 1.0, *C,180);
    auto blas_t_12 = chrono::steady_clock::now();
    cout<<"T1: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_12 - blas_t_11).count()<<" ns "<< "For 200X150 and 150X180 input"<<endl;
    blas_t_11 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,200, 180, 150, 1, *A, 150, *B,180, 1.0, *C,180);
    blas_t_12 = chrono::steady_clock::now();
    cout<<"T2: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_12 - blas_t_11).count()<<" ns "<< "For 200X150 and 150X180 input"<<endl;
    blas_t_11 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,200, 180, 150, 1, *A, 150, *B,180, 1.0, *C,180);
    blas_t_12 = chrono::steady_clock::now();
    cout<<"T3: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_12 - blas_t_11).count()<<" ns "<< "For 200X150 and 150X180 input"<<endl;
    blas_t_11 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,200, 180, 150, 1, *A, 150, *B,180, 1.0, *C,180);
    blas_t_12 = chrono::steady_clock::now();
    cout<<"T4: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_12 - blas_t_11).count()<<" ns "<< "For 200X150 and 150X180 input"<<endl;
    blas_t_11 = chrono::steady_clock::now();
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,200, 180, 150, 1, *A, 150, *B,180, 1.0, *C,180);
    blas_t_12 = chrono::steady_clock::now();
    cout<<"T5: " << chrono::duration_cast<chrono::nanoseconds>(blas_t_12 - blas_t_11).count()<<" ns "<< "For 200X150 and 150X180 input"<<endl;
    
    
    return 0;


}




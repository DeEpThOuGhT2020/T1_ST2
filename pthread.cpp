#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

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
int a ;
int b ;
int c ;
int counter = 0;
void* multiply(void* arg){
    int i = ++counter;
    for(int j = 0 ; j < c;++j){
        for(int k = 0 ; k < b;++k){
            C[i][j] += C[i][k]*C[k][j];
        }
    }
}
int main(){
    initialize_A(3,4);
    initialize_B(4,2);
    a = 3;
    b = 4;
    c = 2;
    counter = 0;
    pthread_t threads[a];
    auto pth_t_1 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){

        
        int* p;
        pthread_create(&threads[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads[i], NULL);  
    }
    auto pth_t_2 = chrono::steady_clock::now();
    cout <<"T1: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_2 - pth_t_1).count()<<" ns "<<"For 3X4 and 4X2 input" <<endl;
    pth_t_1 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads[i], NULL);  
    }
    pth_t_2 = chrono::steady_clock::now();
    cout <<"T2: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_2 - pth_t_1).count()<<" ns "<<"For 3X4 and 4X2 input"<<endl;
    pth_t_1 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads[i], NULL);  
    }
    pth_t_2 = chrono::steady_clock::now();
    cout <<"T3: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_2 - pth_t_1).count()<<" ns "<<"For 3X4 and 4X2 input"<<endl;
    pth_t_1 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads[i], NULL);  
    }
    pth_t_2 = chrono::steady_clock::now();
    cout <<"T4: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_2 - pth_t_1).count()<<" ns "<<"For 3X4 and 4X2 input"<<endl;
    pth_t_1 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads[i], NULL);  
    }
    pth_t_2 = chrono::steady_clock::now();
    cout <<"T5: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_2 - pth_t_1).count()<<" ns "<<"For 3X4 and 4X2 input"<<endl;

    
    initialize_A(30,40);
    initialize_B(40,20);
    a = 30;
    b = 40;
    c = 20;
    counter = 0;
    pthread_t threads_3[a];

    auto pth_t_3 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_3[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_3[i], NULL);  
    }
    auto pth_t_4 = chrono::steady_clock::now();
    cout<<"T1: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_4 - pth_t_3).count()<<" ns "<< "For 30X40 and 40X20 input"<<endl;
    pth_t_3 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_3[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_3[i], NULL);  
    }
    pth_t_4 = chrono::steady_clock::now();
    cout<<"T2: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_4 - pth_t_3).count()<<" ns "<< "For 30X40 and 40X20 input"<<endl;
    pth_t_3 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_3[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_3[i], NULL);  
    }
    pth_t_4 = chrono::steady_clock::now();
    cout<<"T3: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_4 - pth_t_3).count()<<" ns "<< "For 30X40 and 40X20 input"<<endl;
    pth_t_3 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_3[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_3[i], NULL);  
    }
    pth_t_4 = chrono::steady_clock::now();
    cout<<"T4: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_4 - pth_t_3).count()<<" ns "<< "For 30X40 and 40X20 input"<<endl;
    pth_t_3 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_3[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_3[i], NULL);  
    }
    pth_t_4 = chrono::steady_clock::now();
    cout<<"T5: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_4 - pth_t_3).count()<<" ns "<< "For 30X40 and 40X20 input"<<endl;


    initialize_A(70,70);
    initialize_B(70,70);
    a = 70;
    b = 70;
    c = 70;
    counter = 0;
    pthread_t threads_4[a];
    auto pth_t_5 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_4[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_4[i], NULL);  
    }
    auto pth_t_6 = chrono::steady_clock::now();
    cout<<"T1: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_6 - pth_t_5).count()<<" ns "<< "For 70X70 and 70X70 input"<<endl;
    pth_t_5 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_4[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_4[i], NULL);  
    }
    pth_t_6 = chrono::steady_clock::now();
    cout<<"T2: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_6 - pth_t_5).count()<<" ns "<< "For 70X70 and 70X70 input"<<endl;
    pth_t_5 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_4[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_4[i], NULL);  
    }
    pth_t_6 = chrono::steady_clock::now();
    cout<<"T3: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_6 - pth_t_5).count()<<" ns "<< "For 70X70 and 70X70 input"<<endl;
    pth_t_5 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_4[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_4[i], NULL);  
    }
    pth_t_6 = chrono::steady_clock::now();
    cout<<"T4: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_6 - pth_t_5).count()<<" ns "<< "For 70X70 and 70X70 input"<<endl;
    pth_t_5 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_4[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_4[i], NULL);  
    }
    pth_t_6 = chrono::steady_clock::now();
    cout<<"T5: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_6 - pth_t_5).count()<<" ns "<< "For 70X70 and 70X70 input"<<endl;


    initialize_A(100,40);
    initialize_B(40,100);
    a = 100;
    b = 40;
    c = 100;
    counter = 0;
    pthread_t threads_5[a];
    auto pth_t_7 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_5[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_5[i], NULL);  
    }
    auto pth_t_8 = chrono::steady_clock::now();
    cout <<"T1: "<< chrono::duration_cast<chrono::nanoseconds>(pth_t_8 - pth_t_7).count()<<" ns "<< "For 100X40 and 40X100 input"<<endl;
    pth_t_7 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_5[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_5[i], NULL);  
    }
    pth_t_8 = chrono::steady_clock::now();
    cout <<"T2: "<< chrono::duration_cast<chrono::nanoseconds>(pth_t_8 - pth_t_7).count()<<" ns "<< "For 100X40 and 40X100 input"<<endl;
    pth_t_7 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_5[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_5[i], NULL);  
    }
    pth_t_8 = chrono::steady_clock::now();
    cout <<"T3: "<< chrono::duration_cast<chrono::nanoseconds>(pth_t_8 - pth_t_7).count()<<" ns "<< "For 100X40 and 40X100 input"<<endl;
    pth_t_7 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_5[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_5[i], NULL);  
    }
    pth_t_8 = chrono::steady_clock::now();
    cout <<"T4: "<< chrono::duration_cast<chrono::nanoseconds>(pth_t_8 - pth_t_7).count()<<" ns "<< "For 100X40 and 40X100 input"<<endl;
    pth_t_7 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_5[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_5[i], NULL);  
    }
    pth_t_8 = chrono::steady_clock::now();
    cout <<"T5: "<< chrono::duration_cast<chrono::nanoseconds>(pth_t_8 - pth_t_7).count()<<" ns "<< "For 100X40 and 40X100 input"<<endl;


    initialize_A(120,140);
    initialize_B(140,110);
    a = 120;
    b = 140;
    c = 110;
    counter = 0;
    pthread_t threads_1[a];
    auto pth_t_9 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_1[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_1[i], NULL);  
    }
    auto pth_t_10 = chrono::steady_clock::now();
    cout<<"T1: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_10 - pth_t_9).count()<<" ns "<< "For 120X140 and 140X110 input"<<endl;
    pth_t_9 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_1[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_1[i], NULL);  
    }
    pth_t_10 = chrono::steady_clock::now();
    cout<<"T2: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_10 - pth_t_9).count()<<" ns "<< "For 120X140 and 140X110 input"<<endl; 
    pth_t_9 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_1[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_1[i], NULL);  
    }
    pth_t_10 = chrono::steady_clock::now();
    cout<<"T3: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_10 - pth_t_9).count()<<" ns "<< "For 120X140 and 140X110 input"<<endl;
    pth_t_9 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_1[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_1[i], NULL);  
    }
    pth_t_10 = chrono::steady_clock::now();
    cout<<"T4: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_10 - pth_t_9).count()<<" ns "<< "For 120X140 and 140X110 input"<<endl; 
    pth_t_9 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_1[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_1[i], NULL);  
    }
    pth_t_10 = chrono::steady_clock::now();
    cout<<"T5: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_10 - pth_t_9).count()<<" ns "<< "For 120X140 and 140X110 input"<<endl;


    initialize_A(200,150);
    initialize_B(150,180);
    a = 200;
    b = 150;
    c = 180;
    counter = 0;
    pthread_t threads_2[a];
    auto pth_t_11 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_2[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_2[i], NULL);  
    }
    auto pth_t_12 = chrono::steady_clock::now();
    cout<<"T1: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_12 - pth_t_11).count()<<" ns "<< "For 200X150 and 150X180 input"<<endl;
    pth_t_11 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_2[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_2[i], NULL);  
    }
    pth_t_12 = chrono::steady_clock::now();
    cout<<"T2: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_12 - pth_t_11).count()<<" ns "<< "For 200X150 and 150X180 input"<<endl;
    pth_t_11 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_2[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_2[i], NULL);  
    }
    pth_t_12 = chrono::steady_clock::now();
    cout<<"T3: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_12 - pth_t_11).count()<<" ns "<< "For 200X150 and 150X180 input"<<endl;
    pth_t_11 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_2[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_2[i], NULL);  
    }
    pth_t_12 = chrono::steady_clock::now();
    cout<<"T4: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_12 - pth_t_11).count()<<" ns "<< "For 200X150 and 150X180 input"<<endl;
    pth_t_11 = chrono::steady_clock::now();
    for(int i= 0 ; i < a; ++i){
        int* p;
        pthread_create(&threads_2[i], NULL, multiply, (void*)(p));
    }
    for (int i = 0; i < a; i++){
        pthread_join(threads_2[i], NULL);  
    }
    pth_t_12 = chrono::steady_clock::now();
    cout<<"T5: " << chrono::duration_cast<chrono::nanoseconds>(pth_t_12 - pth_t_11).count()<<" ns "<< "For 200X150 and 150X180 input"<<endl;
    
    return 0;
}
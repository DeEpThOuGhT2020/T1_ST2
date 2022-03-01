#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <string.h>
#include "inp_oup.h"
#include "matrix_and_vector_functions.h"

using std::vector;
using std::ofstream;
using std::ifstream;
using std::cout;
using std::endl;

using vf = vector<float>;
using vvf= vector<vf>;


void DNN(string infile, string outfile){
    vvf IP1_WT(250, vf (144));
    vvf IP2_WT(144, vf (144));
    vvf IP3_WT(144, vf (144));
    vvf IP4_WT(144, vf (12));
    read_weight_matrices_row_major(IP1_WT, IP2_WT, IP3_WT, IP4_WT);
    vvf IP1_BIAS(1, vf (144));
    vvf IP2_BIAS(1, vf (144));
    vvf IP3_BIAS(1, vf (144));
    vvf IP4_BIAS(1, vf (12));
    read_bias_row_vectors(IP1_BIAS, IP2_BIAS, IP3_BIAS, IP4_BIAS);

    ifstream inp_stream;
    inp_stream.open(infile);
    vvf input_feature_vector= read_row_vector(inp_stream);
    inp_stream.close();
    vvf dnn_matrix;
    dnn_matrix=dot_product_and_sum(input_feature_vector, IP1_WT, IP1_BIAS);
    dnn_matrix=compute_relu(dnn_matrix);
    dnn_matrix=dot_product_and_sum(dnn_matrix, IP2_WT, IP2_BIAS);
    dnn_matrix=compute_relu(dnn_matrix);
    dnn_matrix=dot_product_and_sum(dnn_matrix, IP3_WT, IP3_BIAS);
    dnn_matrix=compute_relu(dnn_matrix);
    dnn_matrix=dot_product_and_sum(dnn_matrix, IP4_WT, IP4_BIAS);
    vf prob_vec(12);
    for (int i = 0; i < 12; i++){
        prob_vec[i]=dnn_matrix[0][i];
    }
    prob_vec=softmax(prob_vec);
    ofstream oup_stream;
    oup_stream.open(outfile, std::ios::app);
    oup_stream<<outfile<<" ";
    write_keyword_probs(oup_stream, prob_vec);
    oup_stream.close();
}

int main(int argc, char** argv){
    try{
        if (argc<3) std::cerr<<"Not enough arguments.\n";
        else{
            DNN(argv[1], argv[2]);
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    return 0;
}
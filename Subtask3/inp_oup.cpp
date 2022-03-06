#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <math.h>
#include "inp_oup.h"
#include "libaudio.h"

using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;

using vf = vector<float>;
using vvf = vector<vf>;


const vector<string> keywords = {"silence", "unknown", "yes", "no", "up", "down", "left", "right", "on", "off", "stop", "go"};

void read_weight_matrices_row_major(vvf &IP1_WT, vvf &IP2_WT, vvf &IP3_WT, vvf &IP4_WT){
    ifstream inp_stream;
    inp_stream.open("dnn_weights.txt");
    char comma;
    int r, c;
    r=250; c=144;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            inp_stream>>IP1_WT[i][j];
            inp_stream>>comma;
        }
    }
    r=144; c=144; 
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            inp_stream>>IP2_WT[i][j];
            inp_stream>>comma;
        }
    }
    r=144; c=144; 
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            inp_stream>>IP3_WT[i][j];
            inp_stream>>comma;
        }
    }
    r=144; c=12; 
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            inp_stream>>IP4_WT[i][j];
            inp_stream>>comma;
        }
    }
    inp_stream.close();
}

void read_bias_row_vectors(vvf &IP1_BIAS, vvf &IP2_BIAS, vvf &IP3_BIAS, vvf &IP4_BIAS){
    ifstream inp_stream;
    inp_stream.open("dnn_bias.txt");
    char comma;
    int c;
    c=144;
    for (int i = 0; i < c; i++){
        inp_stream>>IP1_BIAS[0][i];
        inp_stream>>comma;
    }
    c=144;
    for (int i = 0; i < c; i++){
        inp_stream>>IP2_BIAS[0][i];
        inp_stream>>comma;
    }
    c=144;
    for (int i = 0; i < c; i++){
        inp_stream>>IP3_BIAS[0][i];
        inp_stream>>comma;
    }
    c=12;
    for (int i = 0; i < c; i++){
        inp_stream>>IP4_BIAS[0][i];
        inp_stream>>comma;
    }
    inp_stream.close();
}

vvf read_row_vector(ifstream &in){
//Reads in a row vector (extracted features, [1X250]) from an ifstream (in) associated with an already opened file and returns a vector<vector<float>>.
    if (!in.is_open()) throw std::runtime_error("Could not open requested file.");
    int n=250;
    vvf vec(1, vf (n));
    for (int i = 0; i < n; i++){
        in>>vec[0][i];
    }
    return vec;
}

void write_keyword_probs(string outfile, pred_t* pred){
//Writes the top 3 keywords with highest softmax probabilities, followed by their softmax probabilities in the same order.
    ofstream out;
    out.open(outfile, std::ios::app);
    out<<outfile<<" "<<keywords[(pred[0]).label]<<" "<<keywords[(pred[1]).label]<<" "<<keywords[(pred[2]).label]<<" "<<(pred[0]).prob<<" "<<(pred[1]).prob<<" "<<(pred[2]).prob<<std::endl;
    out.close();
}
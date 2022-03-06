#include "libaudio.h"

using vf = std::vector<float>;
using vvf= std::vector<vf>;
using std::ofstream;
using std::ifstream;

void read_weight_matrices_row_major(vvf &IP1_WT, vvf &IP2_WT, vvf &IP3_WT, vvf &IP4_WT);
void read_bias_row_vectors(vvf &IP1_BIAS, vvf &IP2_BIAS, vvf &IP3_BIAS, vvf &IP4_BIAS);
vvf read_row_vector(ifstream &in);
void write_keyword_probs(std::string outfile, pred_t* pred);
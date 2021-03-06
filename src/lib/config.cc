// File: config.cc
// Date: Sat May 04 22:22:20 2013 +0800
// Author: Yuxin Wu <ppwwyyxxc@gmail.com>

#include "config.hh"
#include "utils.hh"
using namespace std;

ConfigParser::ConfigParser(const char* fname) {
	if (not exists_file(fname))
		error_exit("Cannot find config file!");
	ifstream fin(fname);
	string s;s.resize(1000);
	double val;
	while (fin >> s) {
		if (s[0] == '#') {
			fin.getline(&s[0], 4096, '\n');
			continue;
		}
		fin >> val;
		data[s] = val;
	}
}

double ConfigParser::get(const std::string& s) {
	if (data.count(s) == 0)
		error_exit(ssprintf("No option %s in config file!", s.c_str()));
	return data[s];
}

bool CYLINDER;
bool TRANS;
bool CROP = true;
float FOCAL_LENGTH;
bool ESTIMATE_CAMERA;
bool USE_SIFT;
bool STRAIGHTEN;

int NUM_OCTAVE;
int NUM_SCALE;
float SCALE_FACTOR;

float GAUSS_SIGMA;
int GAUSS_WINDOW_FACTOR;

float JUDGE_EXTREMA_DIFF_THRES;
float CONTRAST_THRES;
float PRE_COLOR_THRES;
float EDGE_RATIO;

int CALC_OFFSET_DEPTH;
float OFFSET_THRES;

float ORI_RADIUS;

int ORI_HIST_SMOOTH_COUNT;

int DESC_HIST_SCALE_FACTOR;
int DESC_INT_FACTOR;

float MATCH_REJECT_NEXT_RATIO;
int MATCH_MIN_SIZE;
float CONNECTED_THRES;

int RANSAC_ITERATIONS;
double RANSAC_INLIER_THRES;

float SLOPE_PLAIN;

float OUTPUT_SIZE_FACTOR;

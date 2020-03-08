/**
 * Given two sequences {a1, a2, a3.. an} and {b1, b2, b3... bn},
 * their repeat convolution means:
 * r1 = a1*b1 + a2*b2 + a3*b3 + ... + an*bn
 * r2 = a1*bn + a2*b1 + a3*b2 + ... + an*bn-1
 * r3 = a1*bn-1 + a2*bn + a3*b1 + ... + an*bn-2
 * ...
 * rn = a1*b2 + a2*b3 + a3*b4 + ... + an-1*bn + an*b1
 * Notice n >= 2 and n must be power of 2.
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cmath>
#define for if (0); else for
using namespace std;

const int MaxFastBits = 16;
int **gFFTBitTable = 0;

int NumberOfBitsNeeded(int PowerOfTwo) {
	for (int i = 0;; ++i) {
		if (PowerOfTwo & (1 << i)) {
			return i;
		}
	}
}

int ReverseBits(int index, int NumBits) {
	int ret = 0;
	for (int i = 0; i < NumBits; ++i, index >>= 1) {
		ret = (ret << 1) | (index & 1);
	}
	return ret;
}

void InitFFT() {
    gFFTBitTable = new int *[MaxFastBits];
    for (int i = 1, length = 2; i <= MaxFastBits; ++i, length <<= 1) {
        gFFTBitTable[i - 1] = new int[length];
        for (int j = 0; j < length; ++j) {
            gFFTBitTable[i - 1][j] = ReverseBits(j, i);
		}
    }
}
inline int FastReverseBits(int i, int NumBits) {
    return NumBits <= MaxFastBits ? gFFTBitTable[NumBits - 1][i] : ReverseBits(i, NumBits);
}

void FFT(bool InverseTransform, vector<complex<double> >& In, vector<complex<double> >& Out) {
    if (!gFFTBitTable) { InitFFT(); }
    // simultaneous data copy and bit-reversal ordering into outputs
	int NumSamples = In.size();
    int NumBits = NumberOfBitsNeeded(NumSamples);
    for (int i = 0; i < NumSamples; ++i) {
		Out[FastReverseBits(i, NumBits)] = In[i];
    }
    // the FFT process
    double angle_numerator = acos(-1.) * (InverseTransform ? -2 : 2);
    for (int BlockEnd = 1, BlockSize = 2; BlockSize <= NumSamples; BlockSize <<= 1) {
        double delta_angle = angle_numerator / BlockSize;
        double sin1 = sin(-delta_angle);
        double cos1 = cos(-delta_angle);
        double sin2 = sin(-delta_angle * 2);
        double cos2 = cos(-delta_angle * 2);
        for (int i = 0; i < NumSamples; i += BlockSize) {
			complex<double> a1(cos1, sin1), a2(cos2, sin2);
            for (int j = i, n = 0; n < BlockEnd; ++j, ++n) {
				complex<double> a0(2 * cos1 * a1.real() - a2.real(), 2 * cos1 * a1.imag() - a2.imag());
				a2 = a1;
				a1 = a0;
				complex<double> a = a0 * Out[j + BlockEnd];
				Out[j + BlockEnd] = Out[j] - a;
				Out[j] += a;
            }
        }
        BlockEnd = BlockSize;
    }
    // normalize if inverse transform
    if (InverseTransform) {
        for (int i = 0; i < NumSamples; ++i) {
			Out[i] /= NumSamples;
        }
    }
}

vector<double> convolution(vector<double> a, vector<double> b) {
	int n = a.size();
	vector<complex<double> > s(n), d1(n), d2(n), y(n);
    for (int i = 0; i < n; ++i) {
        s[i] = complex<double>(a[i], 0);
	}
    FFT(false, s, d1);
    s[0] = complex<double>(b[0], 0);
    for (int i = 1; i < n; ++i) {
		s[i] = complex<double>(b[n - i], 0);
	}
    FFT(false, s, d2);
    for (int i = 0; i < n; ++i) {
		y[i] = d1[i] * d2[i];
    }
    FFT(true, y, s);
	vector<double> ret(n);
	for (int i = 0; i < n; ++i) {
		ret[i] = s[i].real();
	}
	return ret;
}

/*
int main() {
    double a[4] = {1, 2, 3, 4}, b[4] = {1, 2, 3, 4};
    vector<double> r = convolution(vector<double>(a, a + 4), vector<double>(b, b + 4));
	// r[0] = 30 (1*1 + 2*2 + 3*3 + 4*4)
	// r[1] = 24 (1*4 + 2*1 + 3*2 + 4*3)
	// r[2] = 22 (1*3 + 2*4 + 3*1 + 4*2)
	// r[3] = 24 (1*2 + 2*3 + 3*4 + 4*1)
	return 0;
}
*/

double a[400000] , b[400000];
double f[510][510];

int v(int x , int y){
	if(x<0 || y<0) return 0;
	return f[x][y];
}

int main(){
//	freopen("in.txt" , "r",  stdin);

	int T;
	int n , m , p , q;
	int i , j ;
	double key , sum;
	int x , y , px , py;
	double mmax;
	int w;

	vector<double> r;
	
	int ca , cb;
	
	scanf("%d" , &T);

	while(T--){
		scanf("%d %d %d %d" , &n , &m , &p , &q);
		ca = cb = 0;
		for(i=0; i<n; i++){
			sum = 0;
			for(j=0; j<m; j++){
				scanf("%lf" , &key);
				sum += key * key;
				a[ca++] = key;
				f[i][j] = (i > 0 ? f[i-1][j] : 0) + sum;
			}			
		}
		
		for(i=0; i<p; i++){
			for(j=0; j<q; j++){
				scanf("%lf" , &key);
		//		sb += key * key;
				b[cb++] = key;
			}
			for(;j<m; j++)
				b[cb++] = 0;
		}

		for(;i<n; i++){
			for(j=0; j<m; j++)
				b[cb++] = 0;
		}

		w = 1;
		while(1){
			if(w >= ca) break;
			w *= 2;
		}

		for(i=ca; i<w; i++){
			a[i] = 0;
			b[i] = 0;
		}
		ca = cb = w;		
		r = convolution(vector<double>(a, a + ca), vector<double>(b, b + cb));		

		// calc_answer : 

		mmax = -1e20;
		for(i=0; i<ca; i++){
			px = i / m;
			py = i % m;
			if(px > n - p) break;
			if(py <= m - q){
				if(r[i] * 2 - f[px+p-1][py+q-1] + v(px-1,py+q-1) + v(px+p-1 , py-1) - v(px-1 , py-1) > mmax){
					x = px; y = py;
					mmax = r[i] * 2 - f[px+p-1][py+q-1] + v(px-1,py+q-1) + v(px+p-1 , py-1) - v(px-1 , py-1);
				}
			}
		}
//		printf("%.0lf\n" , mmax);
		printf("%d %d\n" , x + 1 , y + 1);	

	}

	return 0;
}

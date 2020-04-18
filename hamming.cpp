//
// Created by saad on 18/04/2020.
//
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
int i,j,l,index;
int n, k;
int code[1024];
int red[1024], info[1024];
int m;
int parity[10];
int syn;
int error;

int test, result;
int main(int argc, char *argv[]){

    cin >> m >> error ;

    n = pow(2,m) - 1; // total of Data = r bits + data bits
    k = n - m;           // number of Data
    // Compute parity positions
    parity[1] = 1;     // 1,10,100,1000,10000 ...
    for(int i=2; i<=m; ++i){
        parity[i] = (parity[i-1] << 1) & 0xfffffffe;
    }
    cout << ("parity positions: ") ;
    for (int i=1; i<=m; i++) {
        cout << parity[i] <<' ';
    }
    cout << endl;

    // Generate random message
    for (int i=1; i<=k; i++){
        info[i] = ( rand() >> 10) & 0x01;
    }
    printf("information bits =r ");
    for (j=1; j<=k; j++)  cout << info[j] <<' ';
    cout << endl;

    // Compute parity bits
    for (int j=1; j<=m; j++)
    {
        red[j] = 0;
        l = 0;
        for (int i=1; i<=n; i++)
        {
            // Check that "i" is not a parity position = not a power of 2
            result = 0;
            test = 1;
            for (int index=1; index<=m; index++)
            {
                if (i==test) result = 1;
                test *= 2;
            }
            if (!result)
            {
                l++;
                if ( (i>>(j-1)) & 0x01 )
                    red[j] ^= info[l];
            }
        }
    }

    cout <<"parity bits = ";
    for (int j=1; j<=m; j++) cout<< red[j] << ' ';
    cout << endl;

    // Transmit codeword
    i = 1;
    l = 1;
    for (j=1; j<=n; j++)
        if (j==parity[l] && l<=m)
        {
            code[j] = red[l]; l++;
        }
        else
        {
            code[j] = info[i]; i++;
        }

    cout <<"codeword = ";
    for (j=1; j<=n; j++) cout << code[j]<<' ';
    cout << endl;

    // Add a hard error
    code[error] ^= 1;

    cout << "received = ";
    for (j=1; j<=n; j++) cout<< code[j]<<' ';
    cout << endl;

    // Compute syndrome
    syn = 0;
    for (i=1; i<=n; i++)
        if (code[i]) syn ^= i;

    cout << syn << endl;
    // Correct error if needed
    if (syn)
        code[syn] ^= 1;

    printf("estimate = ");
    for (j=1; j<=n; j++) cout << code[j] <<' ';
    cout << endl;


    return 0;
}

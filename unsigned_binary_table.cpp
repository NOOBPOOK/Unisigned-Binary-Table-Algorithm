//Unsigned Binary Number Algorithm

#include <iostream>
#include <iomanip>

using namespace std;

int de[2];
int b[2][40];
int ac[40];
int carry_n = 0;
int step = 0;
int cycles = 0;

void con_bin(int y);
void head();
void body();
void add();
void right_shift();

int main()
{
    cout << "Enter Number One:\t";
    cin >> de[0];
    cout << "Enter Number Two:\t";
    cin >> de[1];
    cout << "Binary for " << de[0] << " : ";
    con_bin(0);
    for(int i=0;i<8;i++){
        cout << b[0][i];
    }
    cout << endl;
    cout << "Binary for " << de[1] << " : ";
    con_bin(1);
    for(int i=0;i<8;i++){
        cout << b[1][i];
    }
    cout << endl << endl;
    head();
    while(cycles <= 8){
        body();
    }
    cout << endl << " " << string(45,'-') << endl;
    cout << "The final answer is ";
    for(int i=0;i<8;i++){
        cout << ac[i];
    }
    for(int i=0;i<8;i++){
        cout << b[1][i];
    }
}

void con_bin(int y)
{
    int i = 0;
    int gh[2][10];
    while (i<8){
        if(de[y] != 0){
            gh[y][i] = de[y]%2;
            de[y] = de[y]/2;
        }
        else if(de[y]==0){
            gh[y][i] = 0;
        }
        else if(i==7 && de[y]!=0){
            cout << "Number too big to hnadle\nPlease Enter a Valid Number:";
            main();
            abort();
        }
        i++;
    }
    i--;
    for(int j=0;i>=0;i--,j++){
        b[y][j] = gh[y][i];
    }
}
void head()
{
    cout << " " << string(45,'-') << endl;
    cout << "| C |    AC    |     Q    |        init       |" << endl;
    cout << " " << string(46,'-');
}
void body()
{
    cout << endl;
    cout << "|   |          |          |                   |" << endl;
    cout << "| " << carry_n << " | ";
    for(int i=0;i<8;i++){
        cout << ac[i];
    }
    cout << " | ";
    for(int i=0;i<8;i++){
        cout << b[1][i];
    }
    cout << " | ";
    if(step==0){
        cout << setw(18) << "Start" << "|";
    }
    else if(step == 1){
        cout << setw(18) << "Right Shift" << "|";
    }
    else{
        cout << setw(18) << "AC = AC + M" << "|";
    }
    step = 0;
    if(cycles<8){
        if(b[1][7]==1){
            step = 2;
            add();
            b[1][7] = 0;
        }
        else{
            step = 1;
            right_shift();
        }
    }
    else{
        cycles +=1;
    }
}
void add()
{
    int carry = 0;
    for(int i=7;i>=0;i--){
        if(carry==0){
            if(ac[i]==0 && b[0][i]==0){
                ac[i] = 0;
            }
            else if(ac[i]==1 && b[0][i]==0){
                ac[i] = 1;
            }
            else if(ac[i]==0 && b[0][i]==1){
                ac[i] = 1;
            }
            else{
                ac[i] = 0;
                carry = 1;
            }
        }
        else{
            if(ac[i]==0 && b[0][i]==0){
                ac[i] = 1;
                carry = 0;
            }
            else if(ac[i]==1 && b[0][i]==0){
                ac[i] = 0;
            }
            else if(ac[i]==0 && b[0][i]==1){
                ac[i] = 0;
            }
            else{
                ac[i] = 1;
                carry = 1;
            }
        }
    }
    if(carry==1 && carry_n==1){
        carry_n = 0;
    }
    else{
        carry_n = carry;
    }
}
void right_shift()
{
    int dum1[40];
    int dum[40];
    int  j=0;
    int k=ac[7];
    for(int i=0;i<8;i++){
        if(i==0){
            dum1[i] = carry_n;
        }
        else{
            dum1[i] = ac[j];
            j++;
        }
    }
    for(int i=0;i<8;i++){
        ac[i] = dum1[i];
    }
    j = 0;
    for(int i=0;i<8;i++){
        if(i==0){
            dum[i] = k;
        }
        else{
            dum[i] = b[1][j];
            j++;
        }
    }
    for(int i=0;i<8;i++){
        b[1][i] = dum[i];
    }
    cycles += 1;
}

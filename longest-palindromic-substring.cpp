#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>

using namespace std;

string longestPalindrome(string s){

    int size = s.size(), i = 0;
    char *t = new char[2*size + 2];
    char *q = t;
    int *p = new int[2*size + 2];
    int mx = 0, id = 0, MAX = 0, center = 0;

    for(*q='#',i=0; i<size; ++i,*++q='#'){
        *++q = s[i];
    }

    for(*++q=0,p[0]=i=1; i<(2*size+2); i++){
        p[i] = mx>i?min(p[2*id - i], mx-i):1;

        while(i+p[i] <= 2*size+1 && t[i+p[i]] == t[i-p[i]]){
            p[i]++;
        }

        if(i+p[i] > mx){
            mx = i + p[i];
            id = i;
        }

        if(p[i] > MAX){
            MAX = p[i];
            center = i;
        }
    }

    delete(t);
    delete(p);

    return s.substr((center-MAX+1)/2, MAX-1);
}

int main()
{
    string r,s;
    cout<<"input a string: ";
    cin>>s;
    r = longestPalindrome(s);

    cout<<"substring is: "<<r<<endl;

    return 0;
}

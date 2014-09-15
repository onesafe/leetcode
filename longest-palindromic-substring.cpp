#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>

using namespace std;

char *pre(const char *str){
    int length = strlen(str);
    char *prestr = new char[2*length + 4];
    prestr[0] = '$';
    prestr[1] = '#';
    for(int i=0; i<length; ++i){
        prestr[i*2 + 2] = str[i];
        prestr[i*2 + 3] = '#';
    }
    length = length*2 + 2;
    prestr[length] = 0;
    return prestr;
}

char *getMax(const char *str, int &maxlen){
    char *prestr = pre(str);
    int mx = 0, pi = 1;
    int len = strlen(prestr);

    int *p = new int[len];
    p[0] = 0;

    for(int i=1; i<len; i++){
        
        if(mx > i){
            p[i] = min(mx-i, p[2*pi -i]);
        }else{
            p[i] = 1;
        }

        while(prestr[i-p[i]] == prestr[i+p[i]] && i-p[i]>0 && i+p[i]<len){
            p[i]++;
        }

        if(i+p[i] > mx){
            pi = i;
        }
    }

    int ret = 0;
    for(int i=0; i<len; i++){
        if(p[i] > maxlen){
            maxlen = p[i];
            ret = i;
        }
    }

    int leftlen = ret - (maxlen - 1 );
    int rightlen = ret + (maxlen - 1);
    char *r = new char[rightlen - leftlen +1];
    for(int i=0,j=leftlen; j<rightlen; ++i,++j){
        r[i] = prestr[j];
    }

    delete []p;
    delete []prestr;

    return r;
}

int main()
{
    string s;
    int ret;
    int n = 0, j = 0;
    char *res;
    cout<<"input a string: ";
    cin>>s;
    res = getMax(s.c_str(), ret);
    int len = strlen(res);
    char *sub = new char(len);
    for(int i=0; i<len; i++){
        if(res[i] == '#'){
            continue;
        }else{
            sub[j++] = res[i];
        }
    }

    sub[j] = '\0';
    cout<<"substring length is: "<<ret-1<<endl;    
    cout<<"substring is: "<<sub<<endl;

    delete []res;
    delete []sub;
    return 0;
}

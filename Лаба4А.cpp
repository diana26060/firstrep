#include <iostream>
#include <cctype>
using namespace std;

bool isDigit(char c){
    return(c >= '0' && c<='9');
}

int _strcmp(const char* s1, const char* s2){
    while(*s1 && *s2){
        if(!isDigit(*s1) && !isDigit(*s2)){
        if(*s1!=*s2){
            return (*s1<*s2) ? -1 : 1;
        }
        } else if(isDigit(*s1) || isDigit(*s2) ){
            if(isDigit(*s1) && !isDigit(*s2)){
                return -1;
            } else if(!isDigit(*s1) && isDigit(*s2)){
                return 1;
            }
        }
        s1++;
        s2++;
    }
    return 0;
}


int main(){
    char s1[150];
    char s2[150];
    cout<<"Enter 1st str: ";
    cin.getline(s1,sizeof(s1));
    cout<<"Enter 2nd str: ";
    cin.getline(s2,sizeof(s2));

    cout<<_strcmp(s1,s2)<<endl;
    return 0;

}
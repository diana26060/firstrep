#include <iostream>
#include <cctype>

using namespace std;
int main(){
    char s[301];
    cin.getline(s,301);

    //делим строку на слова
    char words[100][30]; //макс. кол-во слов будет 100
    int wordsCount = 0;
    int start = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == ' '){
             //копируем слово в массив
            strncpy(words[wordsCount], &s[start], i - start);
            words[wordsCount][i - start] = '\0';
            wordsCount++;
            start = i+1;
        }
    }
    //копируем последнее слово
    strncpy(words[wordsCount], &s[start],strlen(s) - start );
    words[wordsCount][strlen(s) - start] = '\0';
    wordsCount++;

    //сортировка слов

    int i, m, l;
    for(i = 0; i< wordsCount; i++){
        for(m = i+1;m< wordsCount; m++ ){
        //проверка на наличие цифр в словах
        bool isDigit1 = true, isDigit2 = true;
        for(l = 0; words[i][l] != '\0';l++ ){
            if(!isdigit(words[i][l])){
                isDigit1 = false;
                break;
            }
        }
        for(l = 0;words[m][l] != '\0'; l++ ){
            if(!isdigit(words[m][l])){
                isDigit2 = false;
                break;
            }
        }
        //сортировка слов с числами и без

        if(!isDigit1 && isDigit2){
            char tmp [30];
            strcpy(tmp,words[i]);
            strcpy(words[i],words[m]);
            strcpy(words[m], tmp);
        }
        }
    }

//вывод результата
for(int i = 0; i < wordsCount; i++){
    cout<<words[i]<<' ';

}
cout<<endl;
return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAX_SIZE = 100; // максимальный размер массива
int main(){
    int n,max,min;                // кол-во элементов массива
    double arr[MAX_SIZE];
    //ввод кол-ва элесментов с соблюдением границ массива
    do {
        cout<<"enter the  amount of elements from 1 to "<< MAX_SIZE<<": "<<endl;
        cin>>n;
    }
while(n<1 || n>MAX_SIZE);
// выбираем способ ввода элементов
int choice;
cout<<"Method of filling array: "<<endl;
cout<<"1.By yourself"<<endl;
cout<<"2.Random"<<endl;
cin>>choice;
if(choice == 1){            //с клавиатуры
    for(int i = 0; i<n;i++){
    cout<<"enter "<<i+1<<"element of array";
    cin>>arr[i];
   }
}
   else if(choice == 2 ){   //рандомно
    cout<<"Enter min amount of elements: ";
    cin>>min;
    cout<<"enter max value of elements: ";
    cin>>max;

srand(static_cast<unsigned int>(time(0))); // инициализация генератора случайных чисел
        for (int i = 0; i < n; i++) {
            arr[i] = min + static_cast<double>(rand()) / RAND_MAX * (max - min);
        }
   }
        else {
            cout<<"Error"<<endl;
            return 1;
        }
    //вывод массива
    cout<<"Array";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";

    }
       cout<<endl;
       //вычисление суммы элементов массива с нечетными номерами
       double sumOddNumber = 0;
       for(int i = 0; i<n; i+=2){
        sumOddNumber+= arr[i];
       }
       //ищем первый и последний отрицательные элементы
       int firstNeg = -1, lastNeg = 1;
       for(int i = 0; i<n; i++){
        if(arr[i]< 0){
            if(firstNeg == -1){
                firstNeg = i;
            }
            lastNeg = i;
        }
       }
       //вычисляем произведение элементов между первым и последним отрицительным 
       double result = 1;
       if(firstNeg != -1 && lastNeg != -1){
        for(int i = firstNeg +1; i< lastNeg; i++){
            result *= arr[i];
        }
       }
       else{
        cout<<"there is no negative elements."<<endl;
       }
       cout<<"the product of elements between 1st and last negative: "<< result<<endl;
        //сжатие массива
        int newSize = 0;
        for(int i = 0;i<n; i++){
            if(abs(arr[i])> 1){
                arr[newSize++] = arr[i];
            }

        }
        for(int i = newSize; i<n;i++){
            arr[i]=0;
        }
        n = newSize;
        //вывод конечного результата
        cout<<"compressed array: ";
        for(int i = 0; i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return 0;
}


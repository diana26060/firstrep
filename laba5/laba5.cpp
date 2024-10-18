
#include <fstream>
#include <string>

int main(){
    std::ifstream fin("input.txt");
    std::ofstream fout1("output1.txt");
    std::ofstream fout2("output2.txt");

    std::string str;
     while(getline(fin,str)){
        ///int sigma1 = str.find(" ");!!!!!
        bool f = false;
        int klolk = 0;
        int i = 0;
        while (i < str.length()) {
            if (str[i] != ' ') {
                while (i < str.length() && str[i] != ' ')
                    i++;
                klolk++;
            } else 
                i++; 
        }
        
        if (klolk <= 2)
           fout1 << str << std::endl;
        else if (klolk <= 6) 
           fout2 << str << std::endl;
        }
       
    return 0;
}
// $ ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
// plaintext:  HELLO
// ciphertext: EHBBQ

#include<iostream>
#include<string>
#include<stdlib.h> //for strtol
#include<errno.h> //for errno
#include<limits.h> //for INT_MAX INT_MIN




int main(int argc, char* argv[]){

    std::string key = argv[1];
    std::string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    std::string text;
    std::string sub;

    std::cout << "plainttext: ";
    std::getline(std::cin, text);

    for(int i = 0; i < text.length(); i++){
        int a = int(text[i]);
        if(a > 96 && a < 123){
            a = a - 32;
            for(int j = 0; j < abc.length(); j++){
                int b = int(abc[j]);
                if(a == b){
                    char c = key[j];
                    int lowkey = int(c) + 32; 
                    c = char(lowkey);
                    std::cout << c;
                }
            }

        }else if(a > 64 && a < 91){
                for(int j = 0; j < abc.length(); j++){
                    int b = int(abc[j]);
                    if(a == b){
                        char c = key[j];
                        std::cout << c;
                    }
                }
        }else{
            std::cout << text[i];
        }
        
    }
    

    

    
}
#include<iostream>
#include<string>
#include<stdlib.h> //for strtol
#include<errno.h> //for errno
#include<limits.h> //for INT_MAX INT_MIN


int formula(int n, int k);
std::string cypher(std::string s, int k);

int main(int argc, char* argv[]){
    
    //conversion of char to int from input argv[]
    char *p;
    int key;
    
    long conv = strtol(argv[1], &p, 10);

    

    //checking if a proper input is made
    if(errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN){
        std::cout << "Only integers or valid numbers";
        return 1;
    }else{
       if(argc == 2){
        std::cout << "Success\n";
        }else{
        std::cout << "Usage: " << argv[0] << " key";
        } 
    }

    key = conv;

    std::string text;

    std::cout << "plaintext: ";
    std::getline(std::cin, text);

    std::string text_conversion = cypher(text, key);
    std::cout << "ciphertext: " << text_conversion;

}


std::string cypher(std::string s, int k){
    std::string ciphered;

    for(int i = 0; i < s.length(); i++){
        char x = s[i];
        int n = int(x);
        x = char(formula(n, k));
        ciphered.push_back(x);
    }
    return ciphered;
}

int formula(int n, int k){
    if(n > 64 && n < 91){
        n = ((n + k)%256);
        if(n > 90){
            n = n - 90 + 64;
        }
        return n;
    }else if(n > 96 && n < 123 ){
        n = ((n + k)%256);
        if(n > 122){
            n = n - 122 + 96;
        }
        return n;
    }else{
        return n;
    }
}





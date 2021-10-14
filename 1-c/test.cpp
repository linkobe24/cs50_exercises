#include<iostream>
#include<string>

std::string isValid(long long num, int n);
bool visa(int n);


int main(void){
    int total = 16;
    long long num = 5003600000000014;

    std::cout <<"helo\n";
    std::cout << isValid(num, total);

}

std::string isValid(long long num, int n){
    if(n==16){
       int first_digit = num/1000000000000000;
       if(visa(first_digit)){
            return "VISA";
        }else{
            return "Not valid";
        } 
    }
}

bool visa(int n){
    if(n == 4){
        return true;
    }
    return false;
}
#include<iostream>
#include<string>

typedef struct person
{
    std::string number;
    std::string othnum;
}person;


int main(void){

    person nums = {"454545", "6565656"};

    for(int i = 0; i < 2; i++){
        if(nums.number == "3"){
            std::cout << "greater";
        };
    }



}
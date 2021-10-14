#include<iostream>
#include<string>

typedef struct person{
    std::string name;
    std::string number;
}person;

int main(void){

    person people[2];

    people[0].name = "Manuel";
    people[0].number = "667-1-57-08-53";
    people[1].name = "Kobe";
    people[1].number = "667-2-55-65-80";

    for(int i = 0; i < 2; i++){
        if(people[i].name == "Manuel"){
            std::cout << "Found " << people[i].number << "\n";
            return 0;
        }
    }
    return 1;
}
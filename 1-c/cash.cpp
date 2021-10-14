//Implement, in cash.c, a program that first asks the user how much change is owed and then prints the minimum number of coins with which that change can be made.


#include<iostream>
#include<math.h>

int main(void){

    float cash = 0;
    int div = 0;
    int total = 0;
    int count = 0;


    do{
        std::cout<< "How much change is owed? \n";
        std::cin >> cash;
        if(cash < 0){
            std::cout <<"Please enter a valid (positive) number\n";
        }
    }while(cash < 0);

    // int cash_full = cash;  //use inherent int property to take only the integer of the float
    // int cash_cents = round((cash - cash_full)*100);
    
    total = cash*100;

    if(total >= 25){
        div = total/25;
        count = div;
        total = total%25;
    }
    if(total >= 10){
        div = total/10;
        count = count + div;
        total = total%10;
    }
    if(total >= 5){
        div = total/5;
        count = count + div;
        total = total%5;
    }
    if(total >= 1){
        div = total/1;
        count = count + div;
        total = total%1;
    }

    std::cout << count;

    

    

}


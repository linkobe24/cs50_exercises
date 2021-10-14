#include<iostream>
#include<string>

int last(long long num);
long long rest(long long num);
int sum2(int n);
std:: string isValid(long long num, int n);
int total_card_digits(long long num);
bool amex(int num);
bool visa(int num);
bool mc(int num);
int luhn_algo(long long num);


int main(void){
    unsigned long long card_num = 0;
    int total_digits = 0;
    int sum = 0;
 
    //ask for card number
    do{
    std::cout << "Enter card number: ";
    std::cin >> card_num;
    total_digits = total_card_digits(card_num);
    }while(total_digits < 0 || total_digits > 16);

    //luhn's algorithm called
    sum = luhn_algo(card_num);

    //check validity
    if(sum%10 == 0){
        std::cout << isValid(card_num, total_digits);
    }else{
        std::cout << "Not Valid";
    }

  
}


//obtain the last digit of every iteration
int last(long long num){
    int last = num%10;
    return last;
}

//obtain the remaing of the the card numbers after elimination of the last  4003600000000014 -> 400360000000001 -> 40036000000000 ...
long long rest(long long num){
    long long rest = num/10;
    return rest;
}

//if the digit is 2 numbers, perfoms a sum of the two digits. 6x2 = 12 -> 1+2=3
int sum2(int n){
    if(n>=10){
        int sum = (n/10) + (n%10);
        return sum;
    }else{
        return n;
    }
}

//performs Luhn's algorithm
int luhn_algo(long long num){
    int last_num = 0;
    int count = 0;
    int sum = 0;

    while(num > 0){
        last_num = last(num);
        num = rest(num);
        count++;
        if(count % 2 == 0){
            int everyother = last_num*2;
            int sum_mult = sum2(everyother);
            sum =  sum + sum_mult;
        }else{
            sum = sum + last_num;
        }
    }
    return sum;
}

//check validity of the card number
std::string isValid(long long num, int n){
    if(n == 15){
        int first_digits = num/10000000000000;
        if(amex(first_digits)){
            return "AMEX";
        }else{
            return "Not valid";
        }
    }
    if(n == 16){
       int first_digits = num/100000000000000;
       int first_digits_visa = num/1000000000000000;
       if(mc(first_digits)){
           return "MC";
       }else if(visa(first_digits_visa)){
           return "VISA";
       }else{
           return "Not valid";
       }
    }
    if(n == 13){
        int first_digits = num/1000000000000;
        if(visa(first_digits)){
            return "VISA";
        }else{
            return "Not valid";
        }
    }
    return "Not valid";
}


//checks if the card belongs to a certain brand
bool amex(int num){
    if(num == 34 || num == 37){
        return true;
    }
        return false;
}

bool mc(int num){
    if(num == 51 || num == 52 || num == 53 || num == 54 || num == 55){
        return true;
    }
    return false;
}

bool visa(int num){
    if(num == 4){
        return true;
    }
    return false;
}


//obtains the total digits of the card number
int total_card_digits(long long num){
    int count = 0;
    do{
        count ++;
        num = num/10;
    }while(num != 0);
    return count;
}
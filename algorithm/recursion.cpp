#include<iostream>

void draw(int n);

int main(void){
    
    int height = 0;

    std::cout << "Height: ";
    std::cin >> height;

    draw(height);
}

void draw(int n){
    if(n <= 0){    //base case to stop
        return;
    }
    draw(n - 1);
    for(int i = 0; i < n; i++){
        std::cout << "#";
    }
    std::cout << "\n";
}
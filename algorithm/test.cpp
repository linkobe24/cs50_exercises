#include<iostream>
#include<string>

typedef struct names{
   std::string name;
}names;

int main(int argc, char* argv[]){
   names person[3];

   for(int i = 0; i < argc-1; i++){
      person[i].name = argv[i+1];
   }

   std::cout << person[0].name << "\n";
   std::cout << person[1].name << "\n";
   std::cout << person[2].name<< "\n";

}
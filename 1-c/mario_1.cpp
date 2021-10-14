// Let’s recreate that pyramid in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramid itself is also be taller than it is wide.

//        #
//       ##
//      ###
//     ####
//    #####
//   ######
//  #######
// ########
// The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramid should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

// Here’s how the program might work if the user inputs 8 when prompted:

// $ ./mario
// Height: 8
//        #
//       ##
//      ###
//     ####
//    #####
//   ######
//  #######
// ########

#include<iostream>

int main(void){

    int height = 0;

    do{
        std::cout << "Enter height: ";
        std::cin >> height;
    }
    while(height < 0 || height > 8);


    for(int i = 0; i < height; i++){

      for(int j = 0; j < height; j++){
          if(j < (height - i - 1)){
              std::cout<<" ";
          }else{
              std::cout<<"#";
          }         
      }
        std::cout<< "\n";
    }

    return 0;


}



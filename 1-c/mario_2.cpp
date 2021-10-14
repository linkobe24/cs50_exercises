// Let’s recreate those pyramids in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramids themselves are also be taller than they are wide.

//    #  #
//   ##  ##
//  ###  ###
// ####  ####
// The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

// Here’s how the program might work if the user inputs 8 when prompted:

// $ ./mario
// Height: 8
//        #  #
//       ##  ##
//      ###  ###
//     ####  ####
//    #####  #####
//   ######  ######
//  #######  #######
// ########  ########


#include<iostream>

int main(void){

    int height = 0;

    do{                                    //Loop to ask for the appropriate height
        std::cout << "Enter height: ";      
        std::cin >> height;
    }
    while(height < 0 || height > 8);


    for(int i = 0; i < height; i++){     //main loop

      for(int j = 0; j < height; j++){  //loop for the left piramid
          if(j < (height - i - 1)){
              std::cout<<" ";
          }else{
              std::cout<<"#";
          }         
      }

       std::cout<< " ";     //space in between 

      for(int j = 0; j < height; j++){  //loop for the right piramid
          if(j <= i){
              std::cout<< "#";
          }
          else{
              std::cout<< " ";
          }
      } 

      std::cout << "\n";
    }

    return 0;


}

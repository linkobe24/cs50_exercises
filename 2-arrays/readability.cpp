#include<iostream>
#include<string>
#include<math.h>

int counting_letter(std::string s, int n);
int counting_all(std::string s);
int counting_word(std::string s);
int counting_sentence(std::string s);
int coleman_index(int n, int w, int s);

int main(void){

    std::string text;
    int letters = 0;
    int words = 0;
    int sentences= 0;
    int all_characters = 0;
    int grade = 0;

    std::cout<< "Text: ";
    std::getline(std::cin, text);

    all_characters = counting_all(text);

    letters= counting_letter(text, all_characters);  
    std::cout << letters << " letter(s)\n";
    words = counting_word(text);  
    std::cout << words << " word(s)\n";
    sentences = counting_sentence(text); 
    std::cout << sentences << " sentence(s)\n";
    grade = coleman_index(letters, words, sentences);
    if(grade < 1){
        std::cout << "Before grade 1";
    }else if(grade > 16){
        std::cout << "Grade 16+";
    }else{
        std::cout << "Grade " << grade;
    }
    


}



int counting_all(std::string s){
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        count++;
    }
    return count;
}


int counting_letter(std::string s, int n){
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' ' || s[i] == ',' || s[i] == '.' || s[i] == '\'' || s[i] == '"' || s[i] == '!' || s[i] == '?' || s[i] == ':' || s[i] =='-' || s[i] == ';'){
            count++;
        }
    }
    return n - count;
}

int counting_word(std::string s){
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            count++;
        }
    }
    return count + 1;
}

int counting_sentence(std::string s){
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '.' || s[i] == '?' || s[i] == '!'){
            count++;
        }
    }
    return count;
}

int coleman_index(int n, int w, int s){
    float L = (n * 100)/w;
    float S = (s * 100)/w;
    double index = (0.0588 * L) - (0.296 * S) - 15.8;
    
    return round(index);
}
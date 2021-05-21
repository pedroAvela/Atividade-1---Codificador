#include <iostream>
#include <string>

using namespace std;

int codificador(string *word, string *new_word, int word_length, char letter, char new_letter){
  string old_word = *word, codified_word = *new_word;
  int exchanges = 0;
  for(int i = 0; i < word_length; i++){
    if (old_word[i] != letter){
      codified_word += old_word[i];
    }else{
      codified_word += new_letter;
      exchanges += 1;
    }
  }

  *new_word = codified_word;

  return exchanges;
  
}

int main() {
  string word, new_word, *p, *pNew;
  int tamanho, exchanges;
  char letter, new_letter;

  cin >> word;
  cin >> letter;
  cin >> new_letter;

  tamanho = word.length();

  p = &word;
  pNew = &new_word;

  exchanges = codificador(p, pNew, tamanho, letter, new_letter);
 
  cout << new_word << endl;
  cout << word << endl;
  cout << exchanges << endl;
  
}
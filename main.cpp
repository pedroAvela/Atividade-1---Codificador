#include <iostream>
#include <string>

using namespace std;

int codificador(string *word, string *new_word, int word_length, char letter){
  string old_word = *word, codified_word = *new_word;
  int exchanges = 0;
  for(int i = 0; i < word_length; i++){
    if (old_word[i] != letter){
      codified_word += old_word[i];
    }else{
      codified_word += 'x';
      exchanges += 1;
    }
  }

  *new_word = codified_word;

  return exchanges;
  
}

int main() {
  string palavra = "internet", nova_palavra, *p, *pNew;
  int n = palavra.length(), exchanges;
  char letra = 'e';

  p = &palavra;
  pNew = &nova_palavra;

  cout << palavra << endl;

  exchanges = codificador(p, pNew, n, letra);
 
  cout << nova_palavra << endl;

  cout << exchanges << endl;
  
}
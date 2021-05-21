#include <iostream>
#include <string>
#include <vector>

using namespace std;

void codificador(string *word, char letter){
  string old_word = *word;
  for(int i = 0; i < old_word.length(); i++){
    if (old_word[i] == letter){
      old_word[i] = 'x';
    }
  }

  *word = old_word;

  return;
  
}

int main() {
  string palavra = "internet", *p;
  int n = palavra.length();
  char letra = 'e';
  char vetor[n];

  p = &palavra;

  cout << palavra << endl;

  codificador(p, letra);
 
  cout << palavra;
  
}
#include <iostream>
#include <string>

using namespace std;

string string_runner (char *ponteiro, string word, int word_length, int controle){
  for (int i = 0; i < word_length; i++){
    if(controle == 0){
      ponteiro[i] = word[i];
    }else{
      word += ponteiro[i];
    }
  }
  return word;
}

int codificador(char *word, char *new_word, int word_length, char letter, char new_letter){
  int exchanges = 0;
  for(int i = 0; i < word_length; i++){
    if ((word[i] != letter) && (word[i] != toupper(letter))){
      new_word[i] = word[i];
    }else{
      new_word[i] = new_letter;
      exchanges += 1;
    }
  }

  return exchanges;
}

int main() {
  string word, new_word;
  int sizeofString, exchanges;
  char letter, new_letter, *p, *pNew;

  cin >> word;
  cin >> letter;
  cin >> new_letter;

  sizeofString = word.length();

  char vetor_word[sizeofString], vetor_newWord[sizeofString];

  p = &vetor_word[0];
  pNew = &vetor_newWord[0];

  string_runner(p, word, sizeofString, 0);

  exchanges = codificador(p, pNew, sizeofString, letter, new_letter);
  new_word = string_runner(pNew, new_word, sizeofString, 1);

  cout << new_word << endl;
  cout << word << endl;
  cout << exchanges << endl;

  
}
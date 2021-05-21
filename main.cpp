#include <iostream>
#include <string>

using namespace std;

int codificador(char *word, char *new_word, int word_length, char letter, char new_letter){
  int exchanges = 0;
  for(int i = 0; i < word_length; i++){
    if ((word[i] != letter) || (word[i] != toupper(letter))){
      new_word[i] = word[i];
    }else{
      new_word[i] = new_letter;
      exchanges += 1;
    }
  }

  return exchanges;
}

int main() {
  string word;
  int sizeofString, exchanges;
  char letter, new_letter, *p, *pNew;

  cin >> word;
  cin >> letter;
  cin >> new_letter;

  sizeofString = word.length();

  char vetor_word[sizeofString], vetor_newWord[sizeofString];

  for (int i = 0; i < sizeofString; i++){
    vetor_word[i] = word[i];
  }

  p = &vetor_word[0];
  pNew = &vetor_newWord[0];

  exchanges = codificador(p, pNew, sizeofString, letter, new_letter);
  
  for (int i = 0; i < sizeofString; i++){
    cout << vetor_newWord[i];
  }

  cout << "\n" << word << endl;
  cout << exchanges << endl;

  
}
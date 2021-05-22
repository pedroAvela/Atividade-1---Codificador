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

  cout << R"(
       ____                __           ___                             __                    
      /\  _`\             /\ \   __   /'___\  __                       /\ \                   
      \ \ \/\_\    ___    \_\ \ /\_\ /\ \__/ /\_\     ___      __      \_\ \     ___    _ __  
       \ \ \/_/_  / __`\  /'_` \\/\ \\ \ ,__\\/\ \   /'___\  /'__`\    /'_` \   / __`\ /\`'__\
        \ \ \L\ \/\ \L\ \/\ \L\ \\ \ \\ \ \_/ \ \ \ /\ \__/ /\ \L\.\_ /\ \L\ \ /\ \L\ \\ \ \/ 
         \ \____/\ \____/\ \___,_\\ \_\\ \_\   \ \_\\ \____\\ \__/.\_\\ \___,_\\ \____/ \ \_\ 
          \/___/  \/___/  \/__,_ / \/_/ \/_/    \/_/ \/____/ \/__/\/_/ \/__,_ / \/___/   \/_/ by Pedro Avelar
  )" << endl;

  cout << "Codifique uma mensagem trocando seus caracteres!" << endl;
  cout << "Mensagem a ser codificada: ";
  cin >> word;
  cout << "Caracter que deseja substituir: ";
  cin >> letter;
  cout << "Novo caracter: ";
  cin >> new_letter;

  sizeofString = word.length();

  char vetor_word[sizeofString], vetor_newWord[sizeofString];

  p = &vetor_word[0];
  pNew = &vetor_newWord[0];

  string_runner(p, word, sizeofString, 0);

  exchanges = codificador(p, pNew, sizeofString, letter, new_letter);
  new_word = string_runner(pNew, new_word, sizeofString, 1);

  cout << "\033[2J\033[1;1H";
  cout << new_word << endl;
  cout << word << endl;
  cout << exchanges << endl;
  
}
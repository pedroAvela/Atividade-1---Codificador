#include <iostream>
#include <string>

using namespace std;

//Percorre a string e dependendo do controle ele converte uma string em um vetor char ou o inverso
//Controle: 0 recebe a string e transforma em um vetor char através do ponteiro;
// 1 recebe um vetor char através de um ponteiro e retorna uma string.
string string_runner (char *ponteiro, string word, int word_length, int controle){
  for (int i = 0; i < word_length; i++){
    if(controle == 0){
      //Coloca cada caracter da string em um ponteiro que aponta para um vetor char
      ponteiro[i] = word[i];
    }else{
      //Através do ponteiro cria uma string
      word += ponteiro[i];
    }
  }
  return word;
}

//Função responsável por codificar a mensagem trocando seus caracteres, retorna o numero de trocas realizada.
int codificador(char *word, char *new_word, int word_length, char letter, char new_letter){
  int exchanges = 0;
  for(int i = 0; i < word_length; i++){
    //Garante que substitua mesmo se for a versão maiúscula do caracter
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
  //Declara as variáveis
  string word, aux1, aux2;
  int sizeofString, exchanges;
  char letter, new_letter, *p, *pNew, controle;
  bool is_running = true;

  //Loop principal da função que permite que o código rode varias vezes.
  while (is_running){
    //Declara uma variavel string, está aqui para resetar toda vez que o loop inicia.
    string new_word;

    //Recebe os dados do usuário
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
    cin >> aux1;
    cout << "Novo caracter: ";
    cin >> aux2;

    //Essa parte só existe para impedir que o usuário digite algo maior que uma letra, onde deveria receber uma variável char
    //Com isso o que importa é somente o primeiro caracter que o usuário digitou
    letter = aux1[0];
    new_letter = aux2[0];

    //Recebe o tamanho da string
    sizeofString = word.length();

    //Crias os vetores char, com o tamanho da string
    char vetor_word[sizeofString], vetor_newWord[sizeofString];

    //Declara os ponteiros
    p = &vetor_word[0];
    pNew = &vetor_newWord[0];

    //Chama a função string_runner para colocar a string dentro de um vector char, através de um ponteiro.
    string_runner(p, word, sizeofString, 0);

    //Realiza a troca dos caracteres e retorna o numero de trocas feito dentro da variável exchange.
    exchanges = codificador(p, pNew, sizeofString, letter, new_letter);
    //Recebe um ponteiro de um vetor char e retorna uma string.
    new_word = string_runner(pNew, new_word, sizeofString, 1);

    //Por fim retorna a nova mensagem codificada, a mensagem antiga e o numero de trocas realizado
    cout << "\033[2J\033[1;1H";
    cout << "Nova mensagem: " << new_word << endl;
    cout << "Mensagem antiga: " << word << endl;
    cout << "Numero de trocas: " << exchanges << endl;
    cout << "\nDeseja codificar outra mensagem? Digite 'y' para continuar, ou 'n' para sair do mesmo" << endl;
    cin >> controle;
    if (controle == 'n'){
      is_running = false;
    }
    cout << "\033[2J\033[1;1H";
  }
  
  return 0;
}
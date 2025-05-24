#include <iostream>
#include <time.h>


using namespace std;

const int TAM = 5;

void criarvetor(int vetor[], int tam) {
    for (int i=0; i < tam; i++) {
        vetor[i] = rand() % 100 + 1;
    }
}

void imprimirvetor(int vetor[], int tam) {
    for (int i=0; i < tam; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void BUBBLESORT(int vet[], int tam) {
    int i = 1;
    bool trocou = true;
    while(i < tam && trocou) {
        trocou = false;
        for(int j = 0; j < tam - 1; j++) {
            if(vet[j] > vet[j + 1]) {
                int temp = vet[j];
                vet[j] = vet[j + 1]; 
                vet[j + 1] = temp;
                trocou = true;
            }
        }
    }
    i++;
}


int main() {
    srand(time(NULL));
    system("cls");

    cout << "Ordenacao por BUBBLESORT" << endl;
    

    int vet[TAM];
    criarvetor(vet, TAM);
    cout << "Vetor original: ";
    imprimirvetor(vet, TAM);
    BUBBLESORT(vet, TAM);
    cout << "Vetor ordenado: ";
    imprimirvetor(vet, TAM);
    

    return 0;
}

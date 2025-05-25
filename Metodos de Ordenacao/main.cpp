#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int TAM = 30;
const int REP = 10;

void criarvetor(int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        vetor[i] = rand() % 100 + 1;
    }
}

void copiarvetor(int origem[], int tam, int destino[]) {
    for (int i = 0; i < tam; i++) {
        destino[i] = origem[i];
    }
}

void imprimirvetor(int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void BUBBLESORT(int vet[], int tam, int *QtdT, int *QtdC) {
    *QtdT = 0;
    *QtdC = 0;
    int i = 1;
    bool trocou = true;
    while (i < tam && trocou) {
        trocou = false;
        for (int j = 0; j < tam - i; j++) {
            (*QtdC)++;
            if (vet[j] > vet[j + 1]) {
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                trocou = true;
                (*QtdT)++;
            }
        }
        i++;
    }
}

void insertionSort(int vet[], int tam, int *QtdT, int *QtdC) {
    *QtdT = 0;
    *QtdC = 0;

    for (int i = 1; i < tam; i++) {
        int eleito = vet[i];
        int j = i - 1;
        while (j >= 0) {
            (*QtdC)++;
            if (vet[j] > eleito) {
                vet[j + 1] = vet[j];
                j--;
                (*QtdT)++;
            } else {
                break;
            }
        }
        vet[j + 1] = eleito;
    }
}

void selectionSort(int vet[], int tam, int *QtdT, int *QtdC) {
    *QtdC = 0;
    *QtdT = 0;
    for (int i = 0; i < tam; i++) {
        int menor = i;
        for (int j = i + 1; j < tam; j++) {
            (*QtdC)++;
            if (vet[j] < vet[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            int temp = vet[i];
            vet[i] = vet[menor];
            vet[menor] = temp;
            (*QtdT)++;
        }
    }
}

int main() {
    srand(time(NULL));

    int totalCompBS = 0, totalTrocBS = 0;
    int totalCompIS = 0, totalTrocIS = 0;
    int totalCompSS = 0, totalTrocSS = 0;

    for (int r = 1; r <= REP; r++) {
        cout << "========== EXECUCAO " << r << " ==========" << endl;

        int original[TAM];
        criarvetor(original, TAM);
        cout << "Vetor original: ";
        imprimirvetor(original, TAM);

        int vet1[TAM], vet2[TAM], vet3[TAM];
        copiarvetor(original, TAM, vet1);
        copiarvetor(original, TAM, vet2);
        copiarvetor(original, TAM, vet3);

        int compBS = 0, trocBS = 0;
        int compIS = 0, trocIS = 0;
        int compSS = 0, trocSS = 0;

        BUBBLESORT(vet1, TAM, &trocBS, &compBS);
        insertionSort(vet2, TAM, &trocIS, &compIS);
        selectionSort(vet3, TAM, &trocSS, &compSS);

        totalCompBS += compBS;
        totalTrocBS += trocBS;

        totalCompIS += compIS;
        totalTrocIS += trocIS;

        totalCompSS += compSS;
        totalTrocSS += trocSS;

        cout << "\n[ Bubble Sort Melhorado ]" << endl;
        cout << "Comparacoes: " << compBS << ", Trocas: " << trocBS << endl;

        cout << "\n[ Insertion Sort ]" << endl;
        cout << "Comparacoes: " << compIS << ", Trocas: " << trocIS << endl;

        cout << "\n[ Selection Sort ]" << endl;
        cout << "Comparacoes: " << compSS << ", Trocas: " << trocSS << endl;

        cout << "=====================================\n\n";
    }

    cout << "\n======= MEDIAS FINAIS (10 execuções) =======" << endl;
    cout << "Algoritmo         | Media Comp | Media Trocas" << endl;
    cout << "------------------|------------|--------------" << endl;
    cout << "Bubble Melhorado  |     " << totalCompBS / REP << "      |      " << totalTrocBS / REP << endl;
    cout << "Insertion Sort    |     " << totalCompIS / REP << "      |      " << totalTrocIS / REP << endl;
    cout << "Selection Sort    |     " << totalCompSS / REP << "      |      " << totalTrocSS / REP << endl;

    return 0;
}

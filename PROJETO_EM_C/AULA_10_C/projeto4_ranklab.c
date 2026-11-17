
Thumbnails

2
/ 3





Ajustar página






#include <stdio.h>
#define TAM 10
/* Prototipos das funcoes */
void exibirCabecalho(void);
void lerPontuacoes(int v[], int n);
void copiarVetor(int origem[], int destino[], int n);
void exibirVetor(int v[], int n);
int bubbleSort(int v[], int n);
int selectionSort(int v[], int n);
int insertionSort(int v[], int n);
int vetoresIguais(int a[], int b[], int n);
int main(void) {
int pontuacoes[TAM];
int bubble[TAM];
int selection[TAM];
int insertion[TAM];
int compBubble;
int compSelection;
int compInsertion;
float mediana;
exibirCabecalho();
lerPontuacoes(pontuacoes, TAM);
/* Preserva o vetor original e cria tres copias independentes. */
copiarVetor(pontuacoes, bubble, TAM);
copiarVetor(pontuacoes, selection, TAM);
copiarVetor(pontuacoes, insertion, TAM);
/* Executa os tres algoritmos e guarda as comparacoes. */
compBubble = bubbleSort(bubble, TAM);
compSelection = selectionSort(selection, TAM);
compInsertion = insertionSort(insertion, TAM);
printf("\\n========== RESULTADOS ==========\\n");
printf("Original: ");
exibirVetor(pontuacoes, TAM);
printf("Bubble: ");
exibirVetor(bubble, TAM);
printf("Selection: ");
exibirVetor(selection, TAM);
printf("Insertion: ");
exibirVetor(insertion, TAM);
if (vetoresIguais(bubble, selection, TAM) &&
vetoresIguais(bubble, insertion, TAM)) {
printf("\\nResultados equivalentes: SIM\\n");
} else {
printf("\\nResultados equivalentes: NAO\\n");
}
/* Como os vetores estao em ordem crescente, usamos o Bubble. */
printf("Menor pontuacao: %d\\n", bubble[0]);
printf("Maior pontuacao: %d\\n", bubble[TAM - 1]);
/* Com dez valores, a mediana e a media dos elementos centrais. */
mediana = (bubble[4] + bubble[5]) / 2.0f;
printf("Mediana: %.2f\\n", mediana);
printf("\\nComparacoes realizadas:\\n");
printf("Bubble Sort: %d\\n", compBubble);
printf("Selection Sort: %d\\n", compSelection);
printf("Insertion Sort: %d\\n", compInsertion);
printf("===============================\\n");
return 0;
}
void exibirCabecalho(void) {
printf("========== RANKLAB ==========\\n");
printf("Central de Ordenacao Inteligente\\n");
printf("Digite 10 pontuacoes entre 0 e 100.\\n\\n");
}
void lerPontuacoes(int v[], int n) {
int i;

for (i = 0; i < n; i++) {
do {
printf("Pontuacao %d: ", i + 1);
if (scanf("%d", &v[i]) != 1) {
printf("Entrada invalida. Digite um numero inteiro.\\n");
/* Limpa caracteres invalidos da entrada. */
while (getchar() != '\\n') {
/* descarta o restante da linha */
}
v[i] = -1;
} else if (v[i] < 0 || v[i] > 100) {
printf("Valor fora do intervalo. Digite um numero de 0 a 100.\\n");
}
} while (v[i] < 0 || v[i] > 100);
}
}
void copiarVetor(int origem[], int destino[], int n) {
int i;
for (i = 0; i < n; i++) {
destino[i] = origem[i];
}
}
void exibirVetor(int v[], int n) {
int i;
for (i = 0; i < n; i++) {
printf("%d ", v[i]);
}
printf("\\n");
}
int bubbleSort(int v[], int n) {
int i, j, auxiliar;
int comparacoes = 0;
for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - 1 - i; j++) {
comparacoes++;
if (v[j] > v[j + 1]) {
auxiliar = v[j];
v[j] = v[j + 1];
v[j + 1] = auxiliar;
}
}
}
return comparacoes;
}
int selectionSort(int v[], int n) {
int i, j, menor, auxiliar;
int comparacoes = 0;
for (i = 0; i < n - 1; i++) {
menor = i;
for (j = i + 1; j < n; j++) {
comparacoes++;
if (v[j] < v[menor]) {
menor = j;
}
}
if (menor != i) {
auxiliar = v[i];
v[i] = v[menor];
v[menor] = auxiliar;
}
}
return comparacoes;
}
int insertionSort(int v[], int n) {
int i, j, chave;
int comparacoes = 0;

for (i = 1; i < n; i++) {
chave = v[i];
j = i - 1;
/*
* Conta cada comparacao entre elementos.
* A verificacao j >= 0 evita acessar uma posicao invalida.
*/
while (j >= 0) {
comparacoes++;
if (v[j] > chave) {
v[j + 1] = v[j];
j--;
} else {
break;
}
}
v[j + 1] = chave;
}
return comparacoes;
}
int vetoresIguais(int a[], int b[], int n) {
int i;
for (i = 0; i < n; i++) {
if (a[i] != b[i]) {
return 0;
}
}
return 1;
}


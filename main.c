/*===============================================================================================
Dentro deste espaço,
comente tudo o que você fez para Calibrar a simulação.
===============================================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Relogio = 0; // tempo em segundos
int Numero_Total_Clientes_Atendidos = 0;
int TempoTotalEsperaClientes = 0;
int TempoAtendimentoTodosClientes = 0;
int AcumuladorComprimentoTotalFila = 0;
bool CaixaVazio = true;

//=======================================================
// FILA (estrutura de dados FIFO).
// Função de colocar na fila um cliente
// Função de retirar da fila o cliente mais antigo
// Cada cliente guarda um número, que é a hora em que entrou na fila.
//=======================================================
// Função que sorteia número inteiro no intervalo [A, B]
int Sorteie_Entre_A_e_B (int A, int B) {
    return A + (rand() % (B - A));
}
//=======================================================
void main () {
    while (Numero_Total_Clientes_Atendidos < 1000) {
        Relogio = Relogio + 1;
        // Tire "fotografia" da fila; some o comprimento atual da fila a um acumulador,
        // que será usado para calcular o comprimento médio da fila.
        // Talvez gere um cliente, talvez não!
        // Se gerou, coloque na fila; além disso, marque nele que horas são agora,
        // porque depois queremos saber quanto tempo ficou na fila.
        // Se caixa está atendendo alguém, e chegou hora de fim desse atendimento {
        // some o tempo que demorou esse atendimento
        // num acumulador de tempo de atendimento de todos clientes;
        // some +1, em um acumulador que conta o número total de clientes atendidos.
        // deixe o caixa vazio.
        CaixaVazio = true;
        //}//SE
        // Se caixa estiver vazio, {
        // marque caixa ocupado
        CaixaVazio = false;
        // retire primeiro cliente da fila.
        // Sorteie quanto tempo demorará esse atendimento,
        // guarde numa variável quanto é essa demora,
        // guarde em outra variável a que horas o atendimento terminará.
        // Veja a que horas esse cliente havia entrado na fila,
        // e calcule quanto tempo ele ficou esperando; some esse tempo de espera
        // no tempo total de espera dos clientes.
        //}//SE
    }//WHILE
    printf ("Simulação demorou = %d\n", Relogio);
    printf ("Total Clientes = %d\n" , Numero_Total_Clientes_Atendidos);

    //print... Comprimento medio fila = (AcumuladorComprimentoTotalFila / Relogio);
    //print... Tempo medio espera = (TempoTotalEsperaClientes / Numero_Total_Clientes_Atendidos);
    //print... Tempo medio atendimento = (TempoAtendimentoTodosClientes / Numero_Total_Clientes_Atendidos);
}
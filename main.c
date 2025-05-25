/*===============================================================================================
Dentro deste espaço,
comente tudo o que você fez para Calibrar a simulação.

  Para calibrar a simulação foi necessário trabalhar com os valores de tempo de atendimento e a 
quantidade de clientes que entram na fila, pois esses valores influenciam diretamente nas métricas 
da fila. Quanto menor o tempo de atendimento, maior será quantidade de clientes atendidos em um
determinado período, e quanto mais clientes entram na fila, maior será o comprimento médio da fila, 
assim como o tempo de espera.
    Foram testadas diversas combinações de valores para o tempo de atendimento e a quantidade de clientes
que entram na fila, e a partir desses resultados foram escolhidos os valores que mais se aproximavam 
da meta proposta. O exercício foi realizado partindo do princípio de que a fila trabalha somente com
um caixa, comforme a descrição do problema, sendo esse um dos pontos de melhoria para o funcionamento da fila.
O número de clientes atendidos foi fixado em 1000. 
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

#define MAX_QUEUE_SIZE 1000
typedef struct {
    int id;
    int entrada;
    int saida;
    int tempo_espera;
} Cliente;

typedef struct {
    Cliente items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

static Queue fila_atendimento;

void initializeQueue() {
    fila_atendimento.front = -1;
    fila_atendimento.rear = -1;
}

bool isEmpty() {
    return fila_atendimento.front == -1;
}

void AdicionarCliente(Cliente value) {
    if (fila_atendimento.rear == MAX_QUEUE_SIZE - 1) {
        printf("A fila está cheia!\n");
        return;
    }
    if (isEmpty()) {
        fila_atendimento.front = 0;
    }
    fila_atendimento.rear++;
    fila_atendimento.items[fila_atendimento.rear] = value;
}

Cliente RemoverCliente() {
    Cliente emptyCliente = {0};
    if (isEmpty()) {
        printf("Fila vazia!\n");
        return emptyCliente;
    }
    Cliente item = fila_atendimento.items[fila_atendimento.front];
    if (fila_atendimento.front >= fila_atendimento.rear) {
        fila_atendimento.front = -1;
        fila_atendimento.rear = -1;
    } else {
        fila_atendimento.front++;
    }
    return item;
}

// Função que sorteia número inteiro no intervalo [A, B]
int Sorteie_Entre_A_e_B (int A, int B) {
    return A + (rand() % (B - A));
}
//=======================================================
void main () {
    int terminoAtendimento = 1;
    int tempoAtendimento = 0;
    while (Numero_Total_Clientes_Atendidos < 1000) {
        Relogio = Relogio + 1;
        AcumuladorComprimentoTotalFila = AcumuladorComprimentoTotalFila + fila_atendimento.rear;
        // Tire "fotografia" da fila; some o comprimento atual da fila a um acumulador,
        // que será usado para calcular o comprimento médio da fila.
        Cliente novoCliente;
        novoCliente.id = Numero_Total_Clientes_Atendidos;
        novoCliente.entrada = Relogio;

        // Talvez gere um cliente, talvez não!
        // Se gerou, coloque na fila; além disso, marque nele que horas são agora,
        // porque depois queremos saber quanto tempo ficou na fila.
        if (Sorteie_Entre_A_e_B(1, 19) == 1 )
            AdicionarCliente(novoCliente);

        // Se caixa está atendendo alguém, e chegou hora de fim desse atendimento {
        // some o tempo que demorou esse atendimento
        // num acumulador de tempo de atendimento de todos clientes;
        // some +1, em um acumulador que conta o número total de clientes atendidos.
        // deixe o caixa vazio.
        //CaixaVazio = true;
        //}//SE
        // Se caixa estiver vazio, {
        // marque caixa ocupado

        if (CaixaVazio && !isEmpty()) {    
            CaixaVazio = false;
            // retire primeiro cliente da fila.
            Cliente clienteEmAtendimento = RemoverCliente();
            // Sorteie quanto tempo demorará esse atendimento,
            // guarde numa variável quanto é essa demora,
            tempoAtendimento = Sorteie_Entre_A_e_B(1, 27);
            // guarde em outra variável a que horas o atendimento terminará.
            terminoAtendimento = Relogio + tempoAtendimento;
            // Veja a que horas esse cliente havia entrado na fila,
            // e calcule quanto tempo ele ficou esperando; some esse tempo de espera
            // no tempo total de espera dos clientes.
            TempoTotalEsperaClientes = TempoTotalEsperaClientes + (Relogio - clienteEmAtendimento.entrada);
        }//SE
        if (!CaixaVazio && terminoAtendimento == Relogio) {   
            TempoAtendimentoTodosClientes = TempoAtendimentoTodosClientes + tempoAtendimento;
            Numero_Total_Clientes_Atendidos++;
            CaixaVazio = true;
        }

    }//WHILE
    printf("Simulação demorou = %d\n", Relogio);
    printf("Total Clientes = %d\n" , Numero_Total_Clientes_Atendidos);

    printf("Comprimento medio fila = %d\n", AcumuladorComprimentoTotalFila / Relogio);
    printf("Tempo medio espera = %d\n", TempoTotalEsperaClientes / Numero_Total_Clientes_Atendidos);
    printf("Tempo medio atendimento = %d\n", TempoAtendimentoTodosClientes / Numero_Total_Clientes_Atendidos);
}
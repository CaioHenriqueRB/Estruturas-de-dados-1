/*1) Implemente um TAD contaBancaria, com os dados: número da conta, nome do titular
e saldo. Os clientes podem fazer as seguintes operações:
a) Iniciar um conta, para isso precisam ter um saldo inicial;
b) Depositar um valor;
c) Sacar um valor;
d) Imprimir o saldo.*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int numero;
    char titular[100];
    double saldo;
} ContaBancaria;

void iniciarConta(ContaBancaria *conta, int numero, char *titular, double saldoInicial) {
    conta->numero = numero;
    strncpy(conta->titular, titular, 99);
    conta->saldo = saldoInicial;
}

void depositar(ContaBancaria *conta, double valor) {
    if (valor <= 0) {
        printf("Valor de deposito invalido.\n");
        return;
    }
    conta->saldo += valor;
    printf("Deposito de R$ %.2f realizado com sucesso.\n", valor);
}

void sacar(ContaBancaria *conta, double valor) {
    if (valor <= 0) {
        printf("Valor de saque invalido.\n");
        return;
    }
    if (valor > conta->saldo) {
        printf("Saldo insuficiente.\n");
        return;
    }
    conta->saldo -= valor;
    printf("Saque de R$ %.2f realizado com sucesso.\n", valor);
}

void imprimirSaldo(ContaBancaria *conta) {
    printf("\n=== Conta #%d ===\n", conta->numero);
    printf("Titular: %s\n", conta->titular);
    printf("Saldo:   R$ %.2f\n\n", conta->saldo);
}

int main() {
    ContaBancaria conta;

    iniciarConta(&conta, 1001, "Caio", 500.00);
    imprimirSaldo(&conta);

    depositar(&conta, 200.00);
    imprimirSaldo(&conta);

    sacar(&conta, 150.00);
    imprimirSaldo(&conta);

    sacar(&conta, 1000.00); // saldo insuficiente
    imprimirSaldo(&conta);

    return 0;
}

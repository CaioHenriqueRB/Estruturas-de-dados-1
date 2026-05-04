/*2 - Definir e declarar o registro cuja representação gráfica é dada a seguir.
"Imagem no pdf"

3 - Escrever uma função para atribuir um valor ao campo de nome SALÁRIO do registro
REG, descrito no exercício anterior. Escreva também um programa para utilizar a função
criada.*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    float salario;
    int idade;
    int sexo;
} REG;

void atribuirSalario(REG *reg, float valor) {
    if (valor < 0) {
        printf("Salario invalido.\n");
        return;
    }
    reg->salario = valor;
}

int main() {
    REG funcionario;

    funcionario.salario = 0;

    printf("Salario antes: R$ %.2f\n", funcionario.salario);

    atribuirSalario(&funcionario, 3500.00);

    printf("Salario depois: R$ %.2f\n", funcionario.salario);

    return 0;
}



#include <stdio.h>

#define NUM_CONTA 5;
int lerCodigoTitular();
int lerTipoConta();
double lerSaldoInicial();
double lerLimite(int tipoConta);
void menuPrincipal();

int main() {
    
    // Conta 1
    int numeroConta1 = 1001, codTitular1, tipoConta1;
    double saldo1, saldoInicial1, limiteCheque1;
    
    // Conta 2
    int numeroConta2 = 1002, codTitular2, tipoConta2;
    double saldo2, saldoInicial2, limiteCheque2;

    // Conta 3
    int numeroConta3 = 1003, codTitular3, tipoConta3;
    double saldo3, saldoInicial3, limiteCheque3;

    // Conta 4
    int numeroConta4 = 1004, codTitular4, tipoConta4;
    double saldo4, saldoInicial4, limiteCheque4;

    // Conta 5
    int numeroConta5 = 1005, codTitular5, tipoConta5;
    double saldo5, saldoInicial5, limiteCheque5;

    //Cadastro da Conta1
    printf("\n=== CADASTRAR CONTA 1 ===\n", numeroConta1);
    
    codTitular1 = lerCodigoTitular();
    tipoConta1 = lerTipoConta();
    saldoInicial1 = lerSaldo();
    saldo1 = saldoInicial1; 
    limiteCheque1 = lerLimite(tipoConta1);

    //Cadastro da Conta 2
    printf("\n=== CADASTRAR CONTA 2 ===\n", numeroConta2);
    
    do {
        codTitular2 = lerCodigoTitular();
        if(codTitular2 == codTitular1) {
            printf("Erro: Titular ja cadastrado na Conta 1! Tente outro.\n");
        }
    } while(codTitular2 == codTitular1);

    tipoConta2 = lerTipoConta();
    saldoInicial2 = lerSaldo();
    saldo2 = saldoInicial2;
    limiteCheque2 = lerLimite(tipoConta2);

    //Cadastro da Conta 3
    printf("\n=== CADASTRAR CONTA 3 ===\n", numeroConta3);
    
    do {
        codTitular3 = lerCodigoTitular();
        if(codTitular3 == codTitular1 || codTitular3 == codTitular2) {
            printf("Erro: Titular ja cadastrado em outra conta! Tente outro.\n");
        }
    } while(codTitular3 == codTitular1 || codTitular3 == codTitular2);

    tipoConta3 = lerTipoConta();
    saldoInicial3 = lerSaldo();
    saldo3 = saldoInicial3;
    limiteCheque3 = lerLimite(tipoConta3);

    //Cadastro da Conta 4
    printf("\n=== CADASTRAR CONTA 4 ===\n", numeroConta4);
    
    do {
        codTitular4 = lerCodigoTitular();
        if(codTitular4 == codTitular1 || codTitular4 == codTitular2 || codTitular4 == codTitular3) {
            printf("Erro: Titular ja cadastrado em outra conta! Tente outro.\n");
        }
    } while(codTitular4 == codTitular1 || codTitular4 == codTitular2 || codTitular4 == codTitular3);

    tipoConta4 = lerTipoConta();
    saldoInicial4 = lerSaldoInicial();
    saldo4 = saldoInicial4;
    limiteCheque4 = lerLimite(tipoConta4);

    //Cadastro da Conta 5
    printf("\n=== CADASTRAR CONTA 5 ===\n", numeroConta5);
    
    do {
        codTitular5 = lerCodigoTitular();
        if(codTitular5 == codTitular1 || codTitular5 == codTitular2 || 
           codTitular5 == codTitular3 || codTitular5 == codTitular4) {
            printf("Erro: Titular ja cadastrado em outra conta! Tente outro.\n");
        }
    } while(codTitular5 == codTitular1 || codTitular5 == codTitular2 || 
            codTitular5 == codTitular3 || codTitular5 == codTitular4);

    tipoConta5 = lerTipoConta();
    saldoInicial5 = lerSaldo();
    saldo5 = saldoInicial5;
    limiteCheque5 = lerLimite(tipoConta5);

    printf("\n=== TODAS AS 5 CONTAS FORAM CADASTRADAS COM SUCESSO! ===\n");

    return 0;

    menuPrincipal();
}


int lerCodigoTitular() {
    int codigo;
    do {
        printf("Digite o codigo do titular (1000 a 9999): ");
        scanf("%d", &codigo);
        if(codigo < 1000 || codigo > 9999) {
            printf("Codigo invalido! Use exatamente 4 digitos.\n");
        }
    } while(codigo < 1000 || codigo > 9999);
    return codigo;
}

int lerTipoConta() {
    int tipo;
    do {
        printf("1-Corrente | 2-Poupanca | 3-Salario\nEscolha o tipo: ");
        scanf("%d", &tipo);
        if(tipo < 1 || tipo > 3) {
            printf("Opcao invalida! Escolha 1, 2 ou 3.\n");
        }
    } while(tipo < 1 || tipo > 3);
    return tipo;
}

double lerSaldoInicial() {
    double saldo;
    do {
        printf("Digite o saldo inicial: ");
        scanf("%lf", &saldo);
        if(saldo < 0) {
            printf("O saldo nao pode ser negativo!\n");
        }
    } while(saldo < 0);
    return saldo;
}

double lerLimite(int tipoConta) {
    double limite;
    if(tipoConta == 1) { 
        do {
            printf("Digite o limite de cheque: ");
            scanf("%lf", &limite);
            if(limite < 0) {
                printf("Limite invalido! O limite nao pode ser negativo.\n");
            }
        } while(limite < 0);
        return limite;
    } else {
        return 0.0; // Contas Poupança e Salário não têm limite
    }
}

void menuPrincipal(){

    printf("\n========================================\n");
    printf("     SISTEMA BANCARIO - MENU PRINCIPAL    \n");
    printf("========================================\n");
    printf("[1] Depositar\n");
    printf("[2] Sacar\n");
    printf("[3] Transferir entre contas\n");
    printf("[4] Aplicar rendimento mensal\n");
    printf("[5] Exibir extrato de uma conta\n");
    printf("[6] Exibir relatorio geral\n");
    printf("[0] Encerrar e gerar relatorio final\n");
    printf("========================================\n");

}
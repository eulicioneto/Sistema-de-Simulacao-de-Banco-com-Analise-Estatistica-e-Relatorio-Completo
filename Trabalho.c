/*Observações do que pode ser implementado:
1. Variável Global de Salário para quando a conta for tipo SALÁRIO o usuário nao precisa digitar novamente o quanto ele ganha na função de depósito;
2.
 */

#include <stdio.h>
#include <math.h>

int lerCodigoTitular();
int lerTipoConta();
double lerSaldoInicial();
double lerLimite(int tipoConta);
int menuPrincipal();
double depositar(int tipoConta);
void sacar(int tipoConta, int numeroConta);
void transferir();
void rendimentoMensal();
void exibirExtrato(int numeroConta);
int CalcularSaldo(double saldo);
void exibirRelatorioGeral();
void verificarTipoConta(int tipoConta, int *contasCorrente, int *contasPoupanca, int *contasSalario);
int Teste();

// Constantes
#define NUM_CONTAS 5
#define SALARIO_MINIMO 1412.00
#define LIMITE_NEGATIVO_SALARIO 500.00
#define JUROS_CHEQUE_ESPECIAL 0.085
#define JUROS_MORA 0.03
#define RENDIMENTO_POUPANCA 0.005
#define TAXA_CORRENTE 0.015
#define TAXA_SALARIO 0.008

// Acumuladores globais
int totalOperacoes = 0;
double totalDepositado = 0;
double totalSacado = 0;

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

int main()
{
    
    if(Teste() != 0){
    // Cadastro da Conta1
    printf("\n=== CADASTRAR CONTA 1 ===\n");

    codTitular1 = lerCodigoTitular();
    tipoConta1 = lerTipoConta();
    saldoInicial1 = lerSaldoInicial();
    saldo1 = saldoInicial1;
    limiteCheque1 = lerLimite(tipoConta1);

    // Cadastro da Conta 2
    printf("\n=== CADASTRAR CONTA 2 ===\n");

    do
    {
        codTitular2 = lerCodigoTitular();
        if (codTitular2 == codTitular1)
        {
            printf("Erro: Titular ja cadastrado na Conta 1! Tente outro.\n");
        }
    } while (codTitular2 == codTitular1);

    tipoConta2 = lerTipoConta();
    saldoInicial2 = lerSaldoInicial();
    saldo2 = saldoInicial2;
    limiteCheque2 = lerLimite(tipoConta2);

    // Cadastro da Conta 3
    printf("\n=== CADASTRAR CONTA 3 ===\n");

    do
    {
        codTitular3 = lerCodigoTitular();
        if (codTitular3 == codTitular1 || codTitular3 == codTitular2)
        {
            printf("Erro: Titular ja cadastrado em outra conta! Tente outro.\n");
        }
    } while (codTitular3 == codTitular1 || codTitular3 == codTitular2);

    tipoConta3 = lerTipoConta();
    saldoInicial3 = lerSaldoInicial();
    saldo3 = saldoInicial3;
    limiteCheque3 = lerLimite(tipoConta3);

    // Cadastro da Conta 4
    printf("\n=== CADASTRAR CONTA 4 ===\n");

    do
    {
        codTitular4 = lerCodigoTitular();
        if (codTitular4 == codTitular1 || codTitular4 == codTitular2 || codTitular4 == codTitular3)
        {
            printf("Erro: Titular ja cadastrado em outra conta! Tente outro.\n");
        }
    } while (codTitular4 == codTitular1 || codTitular4 == codTitular2 || codTitular4 == codTitular3);

    tipoConta4 = lerTipoConta();
    saldoInicial4 = lerSaldoInicial();
    saldo4 = saldoInicial4;
    limiteCheque4 = lerLimite(tipoConta4);

    // Cadastro da Conta 5
    printf("\n=== CADASTRAR CONTA 5 ===\n");

    do
    {
        codTitular5 = lerCodigoTitular();
        if (codTitular5 == codTitular1 || codTitular5 == codTitular2 ||
            codTitular5 == codTitular3 || codTitular5 == codTitular4)
        {
            printf("Erro: Titular ja cadastrado em outra conta! Tente outro.\n");
        }
    } while (codTitular5 == codTitular1 || codTitular5 == codTitular2 ||
        codTitular5 == codTitular3 || codTitular5 == codTitular4);

    tipoConta5 = lerTipoConta();
    saldoInicial5 = lerSaldoInicial();
    saldo5 = saldoInicial5;
    limiteCheque5 = lerLimite(tipoConta5);

    printf("\n=== TODAS AS 5 CONTAS FORAM CADASTRADAS COM SUCESSO! ===\n");
    }
    Teste();
    int opcao;

    do
    {

        opcao = menuPrincipal();

        switch (opcao)
        {

        case 0:
            printf("Encerrando e gerando o relatorio final.");
            break;
        case 1:
        {
            int numeroConta;
            double valor;

            printf("Digite o numero da conta de destino: ");
            scanf("%d", &numeroConta);

            if (numeroConta == numeroConta1)
            {

                valor = depositar(tipoConta1);

                saldo1 += valor;

                totalDepositado += valor;

                totalOperacoes++;
            }
            else if (numeroConta == numeroConta2)
            {

                valor = depositar(tipoConta2);

                saldo2 += valor;

                totalDepositado += valor;

                totalOperacoes++;
            }
            else if (numeroConta == numeroConta3)
            {

                valor = depositar(tipoConta3);

                saldo3 += valor;

                totalDepositado += valor;

                totalOperacoes++;
            }
            else if (numeroConta == numeroConta4)
            {

                valor = depositar(tipoConta4);

                saldo4 += valor;

                totalDepositado += valor;

                totalOperacoes++;
            }
            else if (numeroConta == numeroConta5)
            {

                valor = depositar(tipoConta5);

                saldo5 += valor;

                totalDepositado += valor;

                totalOperacoes++;
            }
            else
            {
                printf("Numero Invalido.\n");
            }
            break;
        }
        case 2:
        {
            int numeroConta = 0;
            while (numeroConta != numeroConta1 && numeroConta != numeroConta2 && numeroConta != numeroConta3 && numeroConta != numeroConta4 && numeroConta != numeroConta5)
            {

                printf("Digite o numero da conta: ");
                scanf("%d", &numeroConta);

                if (numeroConta == numeroConta1)
                {
                    sacar(tipoConta1, numeroConta1);
                }
                else if (numeroConta == numeroConta2)
                {
                    sacar(tipoConta2, numeroConta2);
                }
                else if (numeroConta == numeroConta3)
                {
                    sacar(tipoConta3, numeroConta3);
                }
                else if (numeroConta == numeroConta4)
                {
                    sacar(tipoConta4, numeroConta4);
                }
                else if (numeroConta == numeroConta5)
                {
                    sacar(tipoConta5, numeroConta5);
                }
                else
                {
                    printf("1 - Conta Inexistente.\n");
                }
            }
            break;
        }
        case 3:            
            transferir();
            break;
        case 4:
            rendimentoMensal(numeroConta1,tipoConta1,&saldo1);
            rendimentoMensal(numeroConta2,tipoConta2,&saldo2);
            rendimentoMensal(numeroConta3,tipoConta3,&saldo3);
            rendimentoMensal(numeroConta4,tipoConta4,&saldo4);
            rendimentoMensal(numeroConta5,tipoConta5,&saldo5);

            break;
        case 5:
            printf("\n Digite o numero da conta: ");
            int tipoConta = 0;
            scanf("%d", &tipoConta);
            exibirExtrato(tipoConta);
            break;
        case 6:
            exibirRelatorioGeral();
            break;
        default:
            printf("Opcao Invalida, digite novamente.\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}

// Menu Principal
int menuPrincipal()
{
    
    int opcao;

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
    scanf("%d", &opcao);

    return opcao;
}

int lerCodigoTitular()
{
    int codigo;
    do
    {
        printf("Digite o codigo do titular (1000 a 9999): ");
        scanf("%d", &codigo);
        if (codigo < 1000 || codigo > 9999)
        {
            printf("Codigo invalido! Use exatamente 4 digitos.\n");
        }
    } while (codigo < 1000 || codigo > 9999);
    return codigo;
}

int lerTipoConta()
{
    int tipo;
    do
    {
        printf("1-Corrente | 2-Poupanca | 3-Salario\nEscolha o tipo: ");
        scanf("%d", &tipo);
        if (tipo < 1 || tipo > 3)
        {
            printf("Opcao invalida! Escolha 1, 2 ou 3.\n");
        }
    } while (tipo < 1 || tipo > 3);
    return tipo;
}

double lerSaldoInicial()
{
    double saldo;
    do
    {
        printf("Digite o saldo inicial: ");
        scanf("%lf", &saldo);
        if (saldo <= 0)
        {
            printf("O saldo precisa ser estritamente maior que zero!\n");
        }
    } while (saldo <= 0);
    return saldo;
}

double lerLimite(int tipoConta)
{
    double limite;
    if (tipoConta == 1)
    {
        do
        {
            printf("Digite o limite de cheque: ");
            scanf("%lf", &limite);
            if (limite < 0)
            {
                printf("Limite invalido! O limite nao pode ser negativo.\n");
            }
        } while (limite < 0);
        return limite;
    }
    else
    {
        return 0.0; // Contas Poupanca e Salario nao tem Limite de Cheque
    }
}



// Função de Depósito
double depositar(int tipoConta)
{
    double deposito, valor_liquido;
    do
    {
        printf("Digite o valor do deposito: ");
        scanf("%lf", &deposito);
        if (deposito <= 0)
        {
            printf("Valor Invalido.\n");
        }
    } while (deposito <= 0);

    if (tipoConta == 1)
    {
        valor_liquido = deposito * (1 - TAXA_CORRENTE);
        return valor_liquido;
    }
    else if (tipoConta == 2)
    {
        printf("Usuário Isento.");
        return deposito;
    }
    else
    {

        if (deposito >= SALARIO_MINIMO)
        {
            printf("Usuário Isento.");
            return deposito;
        }
        else
        {
            valor_liquido = deposito * (1 - TAXA_SALARIO);
            return valor_liquido;
        }
    }
}

void sacar(int tipoConta, int numeroConta)
{
    double saque;
    double saldoAtual;
    double limiteAtual;

    // Ler valor do saque
    do
    {
        printf("Digite o valor para sacar: ");
        scanf("%lf", &saque);

        if (saque <= 0)
        {
            printf("2 - Valor Inválido.\n");
        }

    } while (saque <= 0);

    // Identificar saldo e limite da conta
    if (numeroConta == numeroConta1)
    {
        saldoAtual = saldo1;
        limiteAtual = limiteCheque1;
    }
    else if (numeroConta == numeroConta2)
    {
        saldoAtual = saldo2;
        limiteAtual = limiteCheque2;
    }
    else if (numeroConta == numeroConta3)
    {
        saldoAtual = saldo3;
        limiteAtual = limiteCheque3;
    }
    else if (numeroConta == numeroConta4)
    {
        saldoAtual = saldo4;
        limiteAtual = limiteCheque4;
    }
    else
    {
        saldoAtual = saldo5;
        limiteAtual = limiteCheque5;
    }

    // CONTA CORRENTE
    if (tipoConta == 1)
    {
        if (saque > (saldoAtual + limiteAtual))
        {
            printf("3 - Saldo insuficiente para o tipo da Conta.\n");
            return;
        }
        //Essa parte contêm um cálculo um pouco complicado, é bom estudar.

        double saldoAntes;

        saldoAntes = saldoAtual;

        saldoAtual -= saque;

        if (saldoAntes >= 0 && saldoAtual < 0)
        {
            double valorChequeEspecial;
            double juros;

            valorChequeEspecial = fabs(saldoAtual);

            juros = valorChequeEspecial * JUROS_CHEQUE_ESPECIAL;

            saldoAtual -= juros;
        }
    }

    // CONTA POUPANÇA
    else if (tipoConta == 2)
    {
        if (saque > saldoAtual)
        {
            printf("3 - Saldo insuficiente para o tipo de conta.\n");
            return; // O return irá permitir a volta para o menu principal dentro do switch-case no método int main()
        }

        saldoAtual -= saque;
    }

    // CONTA SALÁRIO
    else
    {
        if ((saldoAtual - saque) < -LIMITE_NEGATIVO_SALARIO)
        {
            printf("3 - Saldo insuficiente para o tipo de conta.\n");
            return;
        }

        saldoAtual -= saque;

    }

    // Atualizar saldo REAL da conta
    if (numeroConta == numeroConta1)
    {
        saldo1 = saldoAtual;
    }
    else if (numeroConta == numeroConta2)
    {
        saldo2 = saldoAtual;
    }
    else if (numeroConta == numeroConta3)
    {
        saldo3 = saldoAtual;
    }
    else if (numeroConta == numeroConta4)
    {
        saldo4 = saldoAtual;
    }
    else
    {
        saldo5 = saldoAtual;
    }

    // Atualizar acumuladores globais
    totalSacado += saque;
    totalOperacoes++;

    // Exibir resultado
    printf("\n=== SAQUE REALIZADO COM SUCESSO ===\n");
    printf("Valor sacado: %.2lf\n", saque);
    printf("Saldo atual: %.2lf\n", saldoAtual);
} //Pelo Visto, ta certo.

void transferir()
{
}

void rendimentoMensal(int NumConta,int tipoConta, double *saldo)
{
    printf("---------------------------------\n");
    printf("Numero da conta: %d\n",NumConta);
    printf("Saldo de entrada: $%.2f\n",*saldo);
    if(*saldo < 0){
        *saldo *= 1.03;
        printf("mora de 3%%, tornando o saldo mais negativo\n");
        printf("Saldo com o rendimento aplicado: $%.2f\n",*saldo);
    }
    else if(tipoConta == 2){
        *saldo *= 1.005;
        printf("rendimento de 0,5%%\n");
        printf("Saldo com o rendimento aplicado: $%.2f\n",*saldo);
    }
    else{
        printf("Contas Corrente e Assalariadas nao recebem rendimento mensal.\n");
    }
    
}

void exibirExtrato(int numeroConta)
{

    if (numeroConta == numeroConta1) {
        printf("| Numero da conta: %d \n", numeroConta1);
        printf("| Codigo Titular: %d\n", codTitular1);
        printf("| Tipo: %d\n", tipoConta1);
        printf("| Saldo atual: %.2f\n", saldo1);
        printf("| Limite cheque: %.2f\n", limiteCheque1);

        CalcularSaldo(saldo1);
    }
    else if (numeroConta == numeroConta2) {
        printf("| Numero da conta: %d \n", numeroConta2);
        printf("| Codigo Titular: %d\n", codTitular2);
        printf("| Tipo: %d\n", tipoConta2);
        printf("| Saldo atual: %.2f\n", saldo2);
        printf("| Limite cheque: %.2f\n", limiteCheque2);

        CalcularSaldo(saldo2);
    }
    else if (numeroConta == numeroConta3) {
        printf("| Numero da conta: %d \n", numeroConta3);
        printf("| Codigo Titular: %d\n", codTitular3);
        printf("| Tipo: %d\n", tipoConta3);
        printf("| Saldo atual: %.2f\n", saldo3);
        printf("| Limite cheque: %.2f\n", limiteCheque3);

        CalcularSaldo(saldo3);
    }
    else if (numeroConta == numeroConta4) {
        printf("| Numero da conta: %d \n", numeroConta4);
        printf("| Codigo Titular: %d\n", codTitular4);
        printf("| Tipo: %d\n", tipoConta4);
        printf("| Saldo atual: %.2f\n", saldo4);
        printf("| Limite cheque: %.2f\n", limiteCheque4);

        CalcularSaldo(saldo4);
    }
    else if (numeroConta == numeroConta5) {
        printf("| Numero da conta: %d \n", numeroConta5);
        printf("| Codigo Titular: %d\n", codTitular5);
        printf("| Tipo: %d\n", tipoConta5);
        printf("| Saldo atual: %.2f\n", saldo5);
        printf("| Limite cheque: %.2f\n", limiteCheque5);

        CalcularSaldo(saldo5);
    }
    else
    {
        printf("Numero de conta nao existente\n");
    }
    
    
}

// Uso exclusivo da função "exibirExtrato"
int CalcularSaldo(double saldo) {

    if (saldo >= 10 * SALARIO_MINIMO) {
        printf("| Saude financeira: 4");
        printf("\n\nCRITICA | 2=REGULAR | 3=BOA | 4=EXCELENTE");
        return 4;
    }
    else if (saldo >= 3 * SALARIO_MINIMO)
    {
        printf("| Saude financeira: 3");
        printf("\n\nCRITICA | 2=REGULAR | 3=BOA | 4=EXCELENTE");
        return 3;
    }
    else if (saldo >= 0)
    {
        printf("| Saude financeira: 2");
        printf("\n\nCRITICA | 2=REGULAR | 3=BOA | 4=EXCELENTE");
        return 2;
    }
    else if (saldo <= 0)
    {
        printf("| Saude financeira: 1");
        printf("\n\nCRITICA | 2=REGULAR | 3=BOA | 4=EXCELENTE");
        return 1;
        
    } 

    
}

void exibirRelatorioGeral()
{
    double mediaSaldos = (saldo1 + saldo2 + saldo3 + saldo4 + saldo5) / NUM_CONTAS;
    double SomaSaldos = saldo1 + saldo2 + saldo3 + saldo4 + saldo5;
    int ContasNegativas = 0;
    printf("\n=== RELATORIO GERAL ===\n");
    printf("Soma dos saldos: $%.2f\n", SomaSaldos);
    printf("Media dos saldos: $%.2f\n", mediaSaldos);
    
    //Maior saldo
    if(saldo1 >= saldo2 && saldo1 >= saldo3 && saldo1 >= saldo4 && saldo1 >= saldo5){
        printf("-------------------------------\n");
        printf("Conta com maior saldo: %d\n", codTitular1);
        printf("Saldo: $%.2f\n", saldo1);
        printf("-------------------------------\n");
    }
    else if(saldo2 >= saldo1 && saldo2 >= saldo3 && saldo2 >= saldo4 && saldo2 >= saldo5){
        printf("-------------------------------\n");
        printf("Conta com maior saldo: %d\n", codTitular2);
        printf("Saldo: $%.2f\n", saldo2);  
        printf("-------------------------------\n");
    }
    else if(saldo3 >= saldo1 && saldo3 >= saldo2 && saldo3 >= saldo4 && saldo3 >= saldo5){
        printf("-------------------------------\n");
        printf("Conta com maior saldo: %d\n", codTitular3);
        printf("Saldo: $%.2f\n", saldo3);
        printf("-------------------------------\n");
    }
    else if(saldo4 >= saldo1 && saldo4 >= saldo2 && saldo4 >= saldo3 && saldo4 >= saldo5){
        printf("-------------------------------\n");
        printf("Conta com maior saldo: %d\n", codTitular4);
        printf("Saldo: $%.2f\n", saldo4);
        printf("-------------------------------\n");
    }
    else{
        printf("-------------------------------\n");
        printf("Conta com maior saldo: %d\n", codTitular5);
        printf("Saldo: $%.2f\n", saldo5);
        printf("-------------------------------\n");
    }

    //Contar contas negativas
    if(saldo1 < 0){
        ContasNegativas++;
    }
    if(saldo2 < 0){
        ContasNegativas++;
    }
    if(saldo3 < 0){
        ContasNegativas++;
    }
    if(saldo4 < 0){
        ContasNegativas++;
    }
    if(saldo5 < 0){
        ContasNegativas++;
    }
    printf("Numero de contas com o saldo negativo: %d\n", ContasNegativas);

    // Quantidade de tipo de contas
    int ContasCorrente = 0;
    int ContasPoupanca = 0;
    int ContasSalario = 0;

    verificarTipoConta(tipoConta1, &ContasCorrente, &ContasPoupanca, &ContasSalario);
    verificarTipoConta(tipoConta2, &ContasCorrente, &ContasPoupanca, &ContasSalario);
    verificarTipoConta(tipoConta3, &ContasCorrente, &ContasPoupanca, &ContasSalario);
    verificarTipoConta(tipoConta4, &ContasCorrente, &ContasPoupanca, &ContasSalario);
    verificarTipoConta(tipoConta5, &ContasCorrente, &ContasPoupanca, &ContasSalario);
    
    for(int i = 0; i < 35; i++){
        printf("-");
    } printf("\n");

    printf("Quantidade de contas Corrente: %d\n", ContasCorrente);
    printf("Quantidade de contas Poupanca: %d\n", ContasPoupanca);
    printf("Quantidade de contas Salario: %d\n", ContasSalario);

}

// Função de uso exclusivo da função "exibirRelatorioGeral" para contar a quantidade de cada tipo de conta
void verificarTipoConta(int tipoConta, int *contasCorrente, int *contasPoupanca, int *contasSalario){
    if(tipoConta == 1){
        (*contasCorrente)++;
    }
    else if(tipoConta == 2){
        (*contasPoupanca)++;
    }
    else{
        (*contasSalario)++;
    }
}

int Teste(){
     numeroConta1 = 1001; 
     codTitular1 = 1001;
     tipoConta1 = 1;
     saldo1 = 2000;
     saldoInicial1 = 2000; 
     limiteCheque1 = 1000;

     numeroConta2 = 1002; 
     codTitular2 = 1002;
     tipoConta2 = 2;
     saldo2 = 1000;
     saldoInicial2 = 1000; 
     limiteCheque2 = 0;

     numeroConta3 = 1003; 
     codTitular3 = 1003;
     tipoConta3 = 3;
     saldo3 = 5;
     saldoInicial3 = 1000; 
     limiteCheque3 = 0;

     numeroConta4 = 1004; 
     codTitular4 = 1004;
     tipoConta4 = 2;
     saldo4 = 4000;
     saldoInicial4 = 4000; 
     limiteCheque4 = 0;

     numeroConta5 = 1005; 
     codTitular5 = 1005;
     tipoConta5 = 3;
     saldo5 = 5000;
     saldoInicial5 = 5000; 
     limiteCheque5 = 0;

     return 0;
}
     

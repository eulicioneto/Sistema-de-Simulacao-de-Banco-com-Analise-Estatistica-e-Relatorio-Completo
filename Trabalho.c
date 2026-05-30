/*Observações do que pode ser implementado:
1. Variável Global de Salário para quando a conta for tipo SALÁRIO o usuário nao precisa digitar novamente o quanto ele ganha na função de depósito;
2.
 */

#include <stdio.h>
#include <math.h>

double calcularDeposito(int tipoContaDestino, double valor);
int lerCodigoTitular();
int validarSaque(int tipoConta, double saldoAtual, double limiteAtual, double saque);
int lerTipoConta();
double lerSaldoInicial();
double lerLimite(int tipoConta);
int menuPrincipal();
double depositar(int tipoConta);
void sacar(int tipoConta, int numeroConta);
void transferir(int tipoContaOrigem, int tipoContaDestino);
void rendimentoMensal();
void exibirExtrato();
void exibirRelatorio();

// Constantes
#define NUM_CONTAS 5 // Essa constante ainda nao foi utilizada!!!
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

            if (numeroConta == numeroConta1) //Fazer uma funcao para identificar qual é a conta
            {

                valor = depositar(tipoConta1);

                saldo1 += valor;

                totalDepositado += valor;

                totalOperacoes++;

                printf("Saldo atual: %.2lf\n", saldo1);
            }
            else if (numeroConta == numeroConta2)
            {

                valor = depositar(tipoConta2);

                saldo2 += valor;

                totalDepositado += valor;

                totalOperacoes++;

                printf("Saldo atual: %.2lf\n", saldo2);
            }
            else if (numeroConta == numeroConta3)
            {

                valor = depositar(tipoConta3);

                saldo3 += valor;

                totalDepositado += valor;

                totalOperacoes++;

                printf("Saldo atual: %.2lf\n", saldo3);
            }
            else if (numeroConta == numeroConta4)
            {

                valor = depositar(tipoConta4);

                saldo4 += valor;

                totalDepositado += valor;

                totalOperacoes++;

                printf("Saldo atual: %.2lf\n", saldo4);
            }
            else if (numeroConta == numeroConta5)
            {

                valor = depositar(tipoConta5);

                saldo5 += valor;

                totalDepositado += valor;

                totalOperacoes++;

                printf("Saldo atual: %.2lf\n", saldo5);
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
{
    int numeroContaOrigem, numeroContaDestino;

    printf("Digite o numero da conta de origem: ");
    scanf("%d", &numeroContaOrigem);

    printf("Digite o numero da conta de destino: ");
    scanf("%d", &numeroContaDestino);

    if ((numeroContaOrigem != numeroContaDestino) &&
        (numeroContaDestino == numeroConta1 || numeroContaDestino == numeroConta2 ||
         numeroContaDestino == numeroConta3 || numeroContaDestino == numeroConta4 ||
         numeroContaDestino == numeroConta5) &&
        (numeroContaOrigem == numeroConta1 || numeroContaOrigem == numeroConta2 ||
         numeroContaOrigem == numeroConta3 || numeroContaOrigem == numeroConta4 ||
         numeroContaOrigem == numeroConta5))
    {

        transferir(numeroContaOrigem, numeroContaDestino);
    }else{
        printf("Conta de origem ou destino invalida, ou as contas sao iguais. Tente novamente.\n");
    }

    break;
}
 // Aqui ta com erro...
        case 4:
            rendimentoMensal();
            break;
        case 5:
            exibirExtrato();
            break;
        case 6:
            exibirRelatorio();
            break;
        default:
            printf("Opcao Invalida, digite novamente.\n");
            break;
        }
    } while (opcao != 0);

    return 0;
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

// Função de Depósito
double depositar(int tipoConta)
{
    double deposito;
    double valorLiquido;
    double taxaAplicada;

    do
    {
        printf("Digite o valor do deposito: ");
        scanf("%lf", &deposito);

        if (deposito <= 0)
        {
            printf("Valor Invalido.\n");
        }

    } while (deposito <= 0);

    valorLiquido = calcularDeposito(tipoConta, deposito);

    taxaAplicada = deposito - valorLiquido;

    printf("Valor bruto: %.2lf\n", deposito);
    printf("Taxa aplicada: %.2lf\n", taxaAplicada);
    printf("Valor liquido creditado: %.2lf\n", valorLiquido);

    return valorLiquido;
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
    if (numeroConta == numeroConta1) // Fazer uma funcao para identificar qual é a conta, para nao precisar ficar repetindo esse if-else toda hora
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

    // Validar saque
if (validarSaque(tipoConta, saldoAtual, limiteAtual, saque) == 0)
{
    printf("3 - Saldo insuficiente para o tipo de conta.\n");
    return;
}

// CONTA CORRENTE
if (tipoConta == 1)
{
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
else
{
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

void transferir(int numeroContaOrigem, int numeroContaDestino)
{
    double valorTransferencia;
    double saldoContaOrigem;
    double limiteAtual;
    int tipoContaOrigem;

    //Mudar o nome da variavel saldoAtual para saldoContaOrigem.

    do
    {
        printf("Digite o valor da transferencia: ");
        scanf("%lf", &valorTransferencia);

        if (valorTransferencia <= 0)
        {
            printf("2 - Valor Invalido.\n");
        }

    } while (valorTransferencia <= 0);

    // Identificar conta origem
    if (numeroContaOrigem == numeroConta1)
    {
        saldoContaOrigem = saldo1;
        limiteAtual = limiteCheque1;
        tipoContaOrigem = tipoConta1;
    }
    else if (numeroContaOrigem == numeroConta2)
    {
        saldoContaOrigem = saldo2;
        limiteAtual = limiteCheque2;
        tipoContaOrigem = tipoConta2;
    }
    else if (numeroContaOrigem == numeroConta3)
    {
        saldoContaOrigem = saldo3;
        limiteAtual = limiteCheque3;
        tipoContaOrigem = tipoConta3;
    }
    else if (numeroContaOrigem == numeroConta4)
    {
        saldoContaOrigem = saldo4;
        limiteAtual = limiteCheque4;
        tipoContaOrigem = tipoConta4;
    }
    else
    {
        saldoContaOrigem = saldo5;
        limiteAtual = limiteCheque5;
        tipoContaOrigem = tipoConta5;
    }

    // VALIDAR TRANSFERÊNCIA
    if (validarSaque(tipoContaOrigem, saldoContaOrigem,
                     limiteAtual, valorTransferencia) == 0)
    {
        printf("3 - Saldo insuficiente para o tipo de conta.\n");
        return; //Cancela a transferência se o saque for inválido
    }

    if(tipoContaOrigem == 1)
    {
        double saldoAntes;

        saldoAntes = saldoContaOrigem;

        saldoContaOrigem -= valorTransferencia;

        if (saldoAntes >= 0 && saldoContaOrigem < 0)
        {
            double valorChequeEspecial;
            double juros;

            valorChequeEspecial = fabs(saldoContaOrigem);

            juros = valorChequeEspecial * JUROS_CHEQUE_ESPECIAL;

            saldoContaOrigem -= juros;
        }

    }
    else
    {
        saldoContaOrigem -= valorTransferencia;
    }

    //Atualizar saldo da conta de origem 
    if (numeroContaOrigem == numeroConta1)
    {
        saldo1 = saldoContaOrigem;
    }
    else if (numeroContaOrigem == numeroConta2)
    {
        saldo2 = saldoContaOrigem;
    }
    else if (numeroContaOrigem == numeroConta3)
    {
        saldo3 = saldoContaOrigem;
    }
    else if (numeroContaOrigem == numeroConta4)
    {
        saldo4 = saldoContaOrigem;
    }
    else
    {
        saldo5 = saldoContaOrigem;
    }

    double valorLiquido;

    int tipoContaDestino;

    if (numeroContaDestino == numeroConta1)
    {
            tipoContaDestino = tipoConta1;
            valorLiquido = calcularDeposito(tipoContaDestino, valorTransferencia);

    }
    else if (numeroContaDestino == numeroConta2)
    {       
            tipoContaDestino = tipoConta2;
            valorLiquido = calcularDeposito(tipoContaDestino, valorTransferencia);

    }
    else if (numeroContaDestino == numeroConta3)
    {
            tipoContaDestino = tipoConta3;
            valorLiquido = calcularDeposito(tipoContaDestino, valorTransferencia);

    }
    else if (numeroContaDestino == numeroConta4)
    {
            tipoContaDestino = tipoConta4;
            valorLiquido = calcularDeposito(tipoContaDestino, valorTransferencia);

    }
    else
    {
            tipoContaDestino = tipoConta5;
            valorLiquido = calcularDeposito(tipoContaDestino, valorTransferencia);

    }

    double saldoContaDestino;
    //Atualizar saldo da conta de destino
    if (numeroContaDestino == numeroConta1)
    {
        saldo1+=valorLiquido;
        saldoContaDestino = saldo1;
    }
    else if (numeroContaDestino == numeroConta2)
    {
        saldo2+=valorLiquido; 
        saldoContaDestino = saldo2;
    }
    else if (numeroContaDestino == numeroConta3)
    {
        saldo3+=valorLiquido;
        saldoContaDestino = saldo3;
    }
    else if (numeroContaDestino == numeroConta4)
    {
        saldo4+=valorLiquido;
        saldoContaDestino = saldo4;
    }
    else
    {
        saldo5+=valorLiquido;
        saldoContaDestino = saldo5;
    }

    printf("=== TRANSFERENCIA REALIZADA COM SUCESSO ===\n");
    
    totalSacado += valorTransferencia;
    totalDepositado += valorLiquido;
    totalOperacoes++;

    printf("O saldo atual da conta origem é: %.2lf\n", saldoContaOrigem);
    printf("O saldo atual na conta destino é: %.2lf\n",saldoContaDestino);

}

void rendimentoMensal()
{
}

void exibirExtrato()
{
}

void exibirRelatorio()
{
}

// Funçã para verificar se o saque é valido, considerando o tipo da conta, o saldo atual e o limite de cheque especial (se aplicável), nesse caso, a função analisa retorna 0 para saque inválido e 1 para saque válido. Essa função é utilizada tanto para validar saques quanto transferências, já que ambas as operações envolvem a retirada de dinheiro da conta de origem.
int validarSaque(int tipoConta, double saldoAtual,
                 double limiteAtual, double saque)
{
    if (tipoConta == 1)
    {
        if (saque > (saldoAtual + limiteAtual))
        {
            return 0;
        }
    }
    else if (tipoConta == 2)
    {
        if (saque > saldoAtual)
        {
            return 0;
        }
    }
    else
    {
        if ((saldoAtual - saque) < -LIMITE_NEGATIVO_SALARIO)
        {
            return 0;
        }
    }

    return 1;
}

double calcularDeposito(int tipoConta, double valor){
    if (tipoConta == 1)
{
    return valor * (1 - TAXA_CORRENTE);
}
else if (tipoConta == 2)
{
    return valor;
}
else
{
    if (valor >= SALARIO_MINIMO)
    {
        return valor;
    }
    else
    {
        return valor * (1 - TAXA_SALARIO);
    }
}
}

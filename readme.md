# Sistema Bancário em C

## Sobre o Projeto

Este projeto consiste na implementação de um sistema bancário desenvolvido na linguagem C, com o objetivo de simular o funcionamento de uma pequena instituição financeira. O sistema gerencia exatamente cinco contas bancárias fixas, permitindo a realização de operações financeiras e a geração de relatórios estatísticos detalhados.

O trabalho foi desenvolvido seguindo uma série de restrições acadêmicas que visam reforçar os fundamentos da programação em C, exigindo a utilização exclusiva de variáveis primitivas, estruturas de controle, funções e ponteiros.

## Funcionalidades

O sistema oferece as seguintes operações:

* Cadastro de 5 contas bancárias fixas;
* Depósitos com aplicação de taxas específicas conforme o tipo da conta;
* Saques com regras distintas para contas Corrente, Poupança e Salário;
* Transferências entre contas;
* Aplicação de rendimento mensal ou juros de mora;
* Consulta de extrato individual;
* Geração de relatório geral do sistema;
* Emissão de relatório final contendo estatísticas e análise da evolução financeira das contas.

## Tipos de Conta

O sistema trabalha com três categorias de contas:

1. Conta Corrente
2. Conta Poupança
3. Conta Salário

Cada tipo possui regras próprias para depósitos, saques, limites e rendimentos.

## Restrições do Projeto

Como parte dos requisitos da atividade, o programa foi desenvolvido sem utilizar:

* Strings (`char`);
* Vetores ou arrays;
* Estruturas (`struct`);
* Arquivos externos.

Todos os dados das contas são armazenados em variáveis globais individuais, tornando o projeto um exercício de organização lógica e domínio dos conceitos fundamentais da linguagem C.

## Tecnologias Utilizadas

* Linguagem C (C99/C11)
* Biblioteca padrão (`stdio.h`)
* Biblioteca matemática (`math.h`)
* Biblioteca utilitária (`stdlib.h`)

## Objetivo Educacional

O principal objetivo deste projeto é demonstrar como sistemas mais complexos podem ser construídos utilizando apenas os elementos mais básicos da linguagem C. Além disso, o trabalho evidencia a importância de abstrações como vetores e estruturas de dados, mostrando na prática os desafios de desenvolver aplicações sem esses recursos.

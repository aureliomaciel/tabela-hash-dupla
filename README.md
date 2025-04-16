# Tabela Hash Dupla

Implementação em C++ de uma estrutura de tabela hash com encadeamento separado duplo.

## Descrição

A estrutura contém dois níveis de endereçamento:

- **Nível 1**: Vetor de 10 posições com hash para tabelas do segundo nível;
- **Nível 2**: Cada posição é uma tabela com listas ligadas para armazenar os objetos;
- O mapeamento da chave para ambos os níveis é feito por funções hash diferentes.

##  Funcionalidades

- Inserção de objetos com chave única
- Busca de objetos pela chave
- Impressão da estrutura interna da tabela

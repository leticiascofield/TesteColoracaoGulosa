# Essa coloração é gulosa?

## Introdução

Neste projeto, foi explorada a verificação da gulosidade de colorações de grafos, um problema fundamental na teoria dos grafos. Em vez de atribuir cores aos vértices, o foco foi determinar se uma dada coloração é gulosa, ou seja, se pode ser obtida por um algoritmo guloso. Um algoritmo guloso é uma abordagem heurística que faz escolhas locais ótimas em cada etapa, com o objetivo de alcançar uma solução globalmente ótima. No contexto deste trabalho, a gulosidade refere-se à capacidade de um conjunto de vértices em um grafo ser colorido de forma que cada vértice esteja conectado a pelo menos um vértice de cada cor menor que a dele.

Caso o grafo analisado seja guloso, implementamos métodos clássicos de ordenação, como bolha, seleção, inserção, quicksort, mergesort e heapsort, além de desenvolver um método de ordenação próprio adaptado ao problema, para ordenar os vértices do grafo de acordo com a ordem de preenchimento de suas cores. Investigamos diferentes conjuntos de entradas para avaliar o desempenho dos algoritmos, considerando propriedades como adaptabilidade e estabilidade. A análise comparativa dos métodos permitiu identificar suas vantagens e limitações, destacando a importância da escolha adequada do método de ordenação para resolver o problema da gulosidade de colorações de grafos.

Adicionalmente, para ilustrar a relevância da escolha do vértice inicial na gulosidade, foi feito um exemplo prático utilizando um grafo específico. Ao explorar diferentes estratégias de escolha dos vértices iniciais para a aplicação do algoritmo guloso, podemos observar variações significativas nas colorações obtidas. A capacidade de representar essas variações visualmente por meio de gráficos coloridos fornece uma compreensão mais profunda de como essa seleção impacta diretamente no resultado final.

![image](https://github.com/leticiascofield/TesteColoracaoGulosa/assets/125830543/c4ac57c0-bb01-4276-b384-40d059c3ed05)

## Método

### Descrição da Implementação

O programa foi desenvolvido em C++ e implementa um algoritmo de ordenação relacionado ao problema de coloração de grafos. O código se baseia na estrutura de dados de um grafo representado por vértices e suas arestas (implícitas pela lista de adjacência). Cada vértice contém informações sobre sua cor, grau e lista de adjacência.

Para resolver o problema de coloração de grafos, o programa implementa a função Guloso, que verifica se um vértice está conectado a pelo menos um outro vértice de cada cor abaixo da sua (as cores são ordenadas pelo seu valor). Além disso, o programa oferece opções para escolha de diferentes algoritmos de ordenação, como Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, Merge Sort, Heap Sort e uma implementação personalizada de ordenação. Esses algoritmos são escolhidos para ordenar a ordem em que os vértices do grafo foram coloridos.

### Estruturas de Dados

**Vertice:**
A estrutura de dados Vertice representa um vértice em um grafo, contendo informações essenciais sobre o vértice, como seu identificador único, a cor atribuída, o grau e uma lista de adjacência.

### Funções e Métodos Implementados do main.cpp

As principais funções são:

**Guloso(Vertice vertices[], int n)**
O algoritmo Guloso verifica se a coloração atual dos vértices é válida de acordo com a condição gulosa. Para cada vértice, o algoritmo verifica se o vértice está conectado a pelo menos um vértice de cada cor abaixo da sua própria cor.

- **Laço Externo:** O algoritmo percorre todos os vértices no grafo.
- **Laço Interno:**
  - Para cada vértice, o algoritmo verifica se ele está conectado a pelo menos um vértice de cada cor abaixo da sua própria cor.
  - Para isso, ele itera sobre a lista de adjacência do vértice atual e verifica se existem vizinhos de cada cor menor. Isso é feito através da comparação das cores dos vizinhos com cores de 1 até "vertices[k]->cor - 1", onde "k" é o índice do vértice atual.
- **Verificação:**
  - Se, para algum vértice, não existir pelo menos um vizinho de cada cor menor, o algoritmo retorna "false", indicando que a coloração não é válida segundo a condição gulosa.
- **Retorno:**
  - Se o algoritmo percorrer todos os vértices sem encontrar violações na condição gulosa, retorna "true", indicando que a coloração é válida.

**Estabilizar(Vertice vertices[], int n)**
A função “Estabilizar” é utilizada nos algoritmos de ordenação para garantir a estabilidade do processo, ou seja, preservar a ordem relativa dos vértices com chaves iguais durante a ordenação. Essa função compara os vértices adjacentes e, se eles tiverem a mesma cor, verifica se a ordem relativa entre eles é a mesma da posição inicial no array. Se não for, realiza a troca para manter a ordem estável.

**BubbleSort(Vertice vertices[], int n)**
O algoritmo de ordenação Bubble Sort percorre a lista de vértices várias vezes, comparando elementos adjacentes e trocando-os se estiverem na ordem errada. Esse processo é repetido até que a lista esteja totalmente ordenada. A função "Troca" é usada para trocar dois vértices.

**SelectionSort(Vertice vertices[], int n)**
O algoritmo Selection Sort divide a lista de vértices em duas partes: a parte ordenada e a parte não ordenada. Em cada iteração, o vértice com a cor mínima na parte não ordenada é selecionado e trocado com o primeiro vértice da parte não ordenada. Esse processo é repetido até que toda a lista esteja ordenada.

**InsertionSort(Vertice vertices[], int n)**
O algoritmo Insertion Sort percorre a lista de vértices e, para cada vértice, insere-o na posição correta na parte ordenada da lista. Isso é feito comparando o vértice com os elementos na parte ordenada e movendo os elementos maiores para a direita. Esse processo é repetido
até que toda a lista esteja ordenada.

**QuickSort(Vertice vertices[], int n)**
O algoritmo QuickSort escolhe um pivô da lista de vértices e particiona a lista em duas partes: uma com vértices de cor menor que o pivô e outra com vértices de cor maior. Esse processo é aplicado recursivamente a ambas as partes, resultando na ordenação da lista. A função "Particao" é responsável por realizar o particionamento.

**MergeSort(Vertice vertices[], int esq, int dir)**
O algoritmo MergeSort divide a lista de vértices pela metade e aplica recursivamente o MergeSort a ambas as metades. Em seguida, mescla as duas partes ordenadas para obter uma lista totalmente ordenada. A função "Merge" é responsável por realizar a mescla.

**HeapSort(Vertice vertices[], int n)**
O algoritmo HeapSort constrói uma estrutura de heap a partir da lista de vértices e, em seguida, extrai repetidamente o elemento máximo (raiz) do heap, mantendo a propriedade do heap. Isso resulta na ordenação da lista. A função "Heapify" é usada para manter a propriedade do heap.

**MySort(Vertice vertices[], int n)**
O algoritmo MySort é um método personalizado que agrupa os vértices de acordo com suas cores, mantendo a estabilidade na ordenação. Para cada cor possível, os vértices com a cor correspondente são adicionados ao array auxiliar "aux". Esse processo resulta em um array ordenado de forma estável, preservando a ordem relativa dos vértices com cores iguais.

## Conclusão

Em síntese, este trabalho culminou na criação de um programa robusto para lidar com grafos, utilizando o algoritmo Guloso para verificar a coloração. A implementação eficiente, combinada com estratégias de robustez e análises experimentais, não apenas ofereceu uma solução funcional para o problema, mas também demonstrou a aplicação prática dos conceitos de estruturas de dados e algoritmos estudados ao longo do curso. O programa destaca-se pela capacidade de processar grafos de diferentes complexidades, proporcionando uma experiência valiosa na interseção entre teoria e prática na disciplina de Estruturas de Dados.

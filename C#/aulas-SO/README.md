# ✏ Aulas de Sistemas Operacionais

Esta pasta possui alguns projetos utilizados em aula para um melhor entendimento do funcionamento de um sistema operacional.

## 📌 Conteúdo

| Arquivo               | Descrição                                                                 | Estado |
|------------------------|--------------------------------------------------------------------------|--------|
| [`SO`](./SO/SO/Program.cs)     | Simula funcionalidades básicas de um sistema operacional por meio de um menu interativo no console. Ele permite ao usuário listar os processos em execução (mostrando os 10 primeiros), capturar uma entrada de texto e salvá-la em um arquivo de log com data e hora, além de exibir o uso de memória do próprio programa. O menu se repete até que o usuário opte por sair, proporcionando uma introdução prática ao gerenciamento de processos, manipulação de arquivos e uso de recursos do sistema.  | [✅] Completo|
| [`Sequencial`](./Sequencial/Sequencial/Program.cs)   | Realiza o processamento sequencial de números primos, somando todos os primos menores que 50 milhões. Ele utiliza uma função otimizada para verificar se um número é primo e mede o tempo total de execução usando a classe Stopwatch, exibindo tanto a soma dos primos quanto o tempo gasto para o processamento. A aplicação é uma boa demonstração de desempenho e eficiência em algoritmos matemáticos intensivos, destacando o custo computacional de operações sequenciais. | [✅] Completo|
| [`SlaMan`](./SlaMan/SlaMan/Program.cs) | Compara o desempenho entre execução síncrona e assíncrona simulando o processamento de múltiplos arquivos. Na abordagem síncrona, os arquivos são processados um por vez com uma pausa de 500ms entre eles, enquanto na abordagem assíncrona todos são iniciados simultaneamente utilizando Task e await Task.WhenAll, permitindo execução concorrente. O tempo de execução de cada abordagem é medido com Stopwatch, e ao final é exibido o ganho de performance ao usar processamento assíncrono, evidenciando a vantagem em cenários com operações independentes e com espera, como I/O. | [✅] Completo|
| [`Thread exemplo`](./Thread%20exemplo/Thread%20exemplo/Program.cs)        | O código calcula a soma de números primos até 50 milhões utilizando múltiplas threads, dividindo o trabalho entre os núcleos do processador para acelerar o processo. Cada thread verifica uma parte dos números e soma os primos encontrados. No final, o programa exibe a soma total e o tempo de execução, mostrando o ganho de desempenho com paralelismo. | [✅] Completo |

---

## 🚀 Como compilar e rodar

Para rodar:

```bash
dotnet build
dotnet run


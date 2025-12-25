#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGTH 1000
#define MAX_ARGS 100

void executeCommand(char *command) {
    char *args[MAX_ARGS];
    char *token;
    pid_t pid;
    int status;

    // Dividir o comando em argumentos
    token = strtok(command, " ");
    int arg_count = 0;
    while (token != NULL && arg_count < MAX_ARGS - 1) {
        args[arg_count] = token;
        token = strtok(NULL, " ");
        arg_count++;
    }
    args[arg_count] = NULL; // Marcar o final da lista de argumentos

    // Executar o comando
    pid = fork();
    if (pid < 0) {
        perror("Erro ao criar processo filho");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Processo filho
        if (execvp(args[0], args) == -1) {
            perror("Erro ao executar o comando");
            exit(EXIT_FAILURE);
        }
    } else {
        // Processo pai
        waitpid(pid, &status, 0);
    }
}

void executeParallelCommands(char *commands[], int num_commands) {
    for (int i = 0; i < num_commands; i++) {
        executeCommand(commands[i]);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char *token;
    char *commands[MAX_ARGS];
    int num_commands = 0;
    bool is_parallel = false;

    while (1) {
        printf("wish> ");
        fflush(stdout);

        // Ler o comando do usuário
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0'; // Remover a nova linha do final do comando

        // Verificar se o comando é um comando embutido
        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "&") == 0) {
            is_parallel = true;
        } else {
            // Verificar se o comando deve ser executado em paralelo
            if (is_parallel || num_commands == 0) {
                // Separar o comando em tokens
                token = strtok(command, "&");
                while (token != NULL && num_commands < MAX_ARGS) {
                    commands[num_commands++] = token;
                    token = strtok(NULL, "&");
                }

                // Executar os comandos em paralelo
                executeParallelCommands(commands, num_commands);

                // Limpar a lista de comandos e reiniciar
                num_commands = 0;
                is_parallel = false;
            } else {
                // Executar o comando normalmente
                executeCommand(command);
            }
        }
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// help command is always necessary
void helpCommand(int argc, char *argv[]);

// other commands
void example(int argc, char *argv[]);

typedef void (*CommandHandler)(int argc, char *argv[]);

typedef struct {
    const char* name;
    CommandHandler handler;
    const char* help;
} Command;

Command commands[] = {
    {"example", example, "Example command"},
    {"help", helpCommand, "Display this help information"}
};

int numCommands = sizeof(commands) / sizeof(Command);

// Help command
void helpCommand(int argc, char *argv[]) {
    printf("Available commands:\n");
    for (int i = 0; i < numCommands; i++) {
        printf("  %s: %s\n", commands[i].name, commands[i].help);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: var__name__ <command> [<args>]\n");
        printf("\n");
        printf("var__desc__\n");
        printf("\n");
        helpCommand(argc, argv);  // Show help if no command is provided
        return 1;
    }

    for (int i = 0; i < numCommands; i++) {
        if (strcmp(argv[1], commands[i].name) == 0) {
            commands[i].handler(argc - 1, &argv[1]);
            return 0;
        }
    }

    printf("Unknown command: %s\n", argv[1]);
    helpCommand(argc, argv);
    return 1;
}

// Main function

void example(int argc, char *argv[]) {
    printf("Example command\n");
}
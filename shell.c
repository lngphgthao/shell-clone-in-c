#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

static pid_t shellPID; //shell process id  
static pid_t shellPGID; //shell process group id   
static int isInteractive; //flag to indicate if the shell is interactive

#define MAX_LINE 100 // max number of characters from user input
#define MAX_ARG 50 // max number of arguments to a command
#define MAX_HISTORY_SAVE 100 // max number of elements in the history  

static char *history[MAX_HISTORY_SAVE]; //array for the history of commands
static int numHistory = 0; //count variable of commands in the history

void shellinit() {
    PID = getpid();
    isInteractive = isatty(STDIN_FILENO);

    if (isInteractive) {

    }
}

void stopExec() {
    printf("\n");
    exit(0);
}

int cd(char *args[]) {
    // TH1: Khong co tham so hoac tham so la ~
    if (args[1] == NULL || strcmp(args[1], "~") == 0) {
        chdir(getenv("HOME"));
        pwd();
        return 1; // Lenh duoc thuc hien -> return 1
    } else {
        int status = chdir(args[1]);
        // TH2: Thu muc khong ton tai hoac duong dan khong hop le
        if (status == -1) {
            printf("cd: %s: %s\n", strerror(errno), args[1]);
            return -1; // Lenh co loi -> return -1
        } else {
            // TH3: Thu muc ton tai va duong dan hop le
            pwd();
            return 1;
        }
    }
    return 0; // Lenh khong duoc thuc hien -> return 0
}

void cat(char *args[]) {
    // TH1: Khong co tham so
    if (args[1] == NULL) {

        signal(SIGINT, stopExec);

        while (1) {
            char *line;
            scanf("%s", &line);
            printf("%s\n", line);
        }

        return 1;
    } else {
        // TH2: Co tham so
        while (args[i] != NULL) {
            FILE *file = fopen(args[i], "r");
            if (file == NULL) {
                if (strcmp(args[i], ">") == 0) {
                    // Ghi noi dung vao file
                } else if (strcmp(args[i], ">>") == 0) {
                    // Ghi noi dung vao cuoi file
                } else {
                printf("cat: %s: %s\n", args[i], strerror(errno));
            } else {
                char line[MAX_LINE];

                switch (args[1]) {
                    case "-A": // In tat ca cac ky tu
                        while (fgets(line, MAX_LINE, file) != NULL) {
                            printf("%s$", line);
                        }
                        fclose(file);
                        break;
                    case "-b":
                        // In so dong khong in dong trong
                        break;
                    case "-e":
                        // In so dong va them $ o cuoi dong
                        break;
                    case "-E":  
                        // In so dong va them $ o cuoi dong
                        break; 
                    case "-n":
                        // In so dong
                        break;
                    case "-s": 
                        // In so dong khong in dong trong
                        break;
                    case "-v":
                        // In so dong
                        break; 
                    case "-T":
                        // In so dong va them ^I o cuoi dong
                        break;
                    case "--help":
                        // In huong dan
                        printf("Usage: cat [OPTION]... [FILE]...\t"
                                "Concatenate FILE(s) to standard output.\t\n"
                                "With no FILE, or when FILE is -, read standard input.\t"
                                "  -A, --show-all           equivalent to -vET\t"
                                "  -b, --number-nonblank    number nonempty output lines, overrides -n\t"
                                "  -e                       equivalent to -vE\t"
                                "  -E, --show-ends          display $ at end of each line\t"
                                "  -n, --number             number all output lines\t"
                                "  -s, --squeeze-blank      suppress repeated empty output lines\t"
                                "  -t                       equivalent to -vT\t"
                                "  -T, --show-tabs          display TAB characters as ^I\t"
                                "  -u                       (ignored)\t"
                                "  -v, --show-nonprinting   use ^ and M- notation, except for LFD and TAB\t"
                                "      --help     display this help and exit\t"
                                "      --version  output version information and exit\t"
                                "Examples:\t"
                                "  cat f - g  Output f's contents, then standard input, then g's contents.\t"
                                "  cat        Copy standard input to standard output.\t\n"
                                "GNU coreutils online help: <https://www.gnu.org/software/coreutils/>\t"
                                "Full documentation <https://www.gnu.org/software/coreutils/cat>\t"
                                "or available locally via: info '(coreutils) cat invocation'\t");
                        break;
                    case "--version":
                        // In phien ban
                        printf("cat (GNU coreutils) 8.32\t"
                                "Copyright (C) 2020 Free Software Foundation, Inc.\t"
                                "License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\t"
                                "This is free software: you are free to change and redistribute it.\t"
                                "There is NO WARRANTY, to the extent permitted by law.\t\n"
                                "Written by Torbjorn Granlund and Richard M. Stallman.\t");
                        break;
                    default:
                        // In noi dung file
                        while (fgets(line, MAX_LINE, file) != NULL) {
                            printf("%s", line);
                        }
                        fclose(file);
                        break;
                }
            }
        }
    }
}

void ls();

void touch();

void pwd();

void mkdir();

void rm();

void cp();

void mv();

void top();

void ps();

void sort();

void date();

void who();

void less();

void help();

int main(void) 
{
    char *args[MAX_ARG]; /* command line arguments */
    char input[MAX_LINE]; // buffer for the user input
    int numTokens; //number of tokens in the command
    int flag = 1; //flag to indicate the state of the shell
    
    while (flag) {
        printf("it007sh>");
        fflush(stdout);
        
        memset(input, 0, MAX_LINE);
        fgets(input, MAX_LINE, stdin);

        if (())
    }
    return 0;
}
#include "globals.h"
#include "symtab.h"
#include "cgen.h"
#include "assembly.h"
#include <string.h>

#define END_SWITCH 67

const char *Prefixos[] = { "add", "sub", "mult", "div", "and", "or", "nand", "nor", "sle", "slt", "sge", "addi", "subi", "divi", "multi", "andi", "ori",
                             "nori", "slei", "slti", "beq", "bne", "blt", "bgt", "sti", "ldi", "str", "ldr", "halt", "in", "out", "jmp", "jal", "jst",
                             "sleep", "wake", "lstk", "sstk", "mov", "put", "ctso" };

const char *opcodeBins[] =   {"000000", "000000", "000000", "000000", "000000", "000000", "000000", "000000", "000000", "000000", "000000", 
                              "000001", "000010", "000011", "000100", "000101", "000110", "000111", "001000", "001001", "001010", "001011",
                              "001100", "001101", "001110", "001111", "010000", "010001", "010010", "010011", "010100", "010101", "010110",
                              "010111", "010110", "011010", "011011", "011100", "011101"};

const char *functBins[] = { "000000", "000001", "000010", "000011", "000100", "000101", "000110", "000111", "001000", "001001", "001010" };

int vetor[26];
void vetor_atua(int tamanho, int valor){
  int i, j;
  int aux = valor;
  for(i = 0; i < 26; i++) vetor[i] = 0;
  for(j = 0; j < tamanho, j++){
    vet[25-j] = aux%2;
    aux = aux/2;
  }
}

void assembly_binary(AssemblyCode codeLine){
    int i;
    Instruction inst;
    if(codeLine->kind == instr){
        inst = codeLine->line.instruction;
        switch(inst.format){
        case formatR:
            fprintf(listing,"ram[%d] = %s",codeLine->lineno, opcodeBins[inst.opcode]);
            void vetor_atua(5, inst.reg2);
            for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
            void vetor_atua(5, inst.reg3);
            for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
            void vetor_atua(5, inst.reg1);
            for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
            void vetor_atua(5, 0);
            for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
            fprintf(listing,"%s;",functBins[inst.opcode]);
            fprintf(listing,"   // %s\n",Prefixos[inst.opcode]);
            break;
        case formatJ:
            if(inst.opcode == jst){
                fprintf(listing,"ram[%d] = %s",codeLine->lineno, opcodeBins[inst.opcode]);
                void vetor_atua(26, 0);
                for(i = 0; i < 26; i++) fprintf(listing,"%d;",vet[25-i]);
                fprintf(listing,"   // %s\n",Prefixos[inst.opcode]);
            }else{
                fprintf(listing,"ram[%d] = %s",codeLine->lineno, opcodeBins[inst.opcode]);
                void vetor_atua(26, inst.imed);
                for(i = 0; i < 26; i++) fprintf(listing,"%d;",vet[25-i]);
                fprintf(listing,"   // %s\n",Prefixos[inst.opcode]);
            }
            break;
        case formatI:
            if(inst.opcode == sti || inst.opcode == ldi){
                fprintf(listing,"ram[%d] = %s",codeLine->lineno, opcodeBins[inst.opcode]);
                void vetor_atua(5, 0);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
                void vetor_atua(5, inst.reg1);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
                void vetor_atua(16, inst.imed);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
                fprintf(listing,"   // %s\n",Prefixos[inst.opcode]);
            }else if(inst.opcode == bgt || inst.opcode == blt){
                fprintf(listing,"ram[%d] = %s",codeLine->lineno, opcodeBins[inst.opcode]);
                void vetor_atua(5, inst.reg1);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
                void vetor_atua(5, inst.reg2);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
                void vetor_atua(16, inst.imed);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);             
                fprintf(listing,"   // %s\n",Prefixos[inst.opcode]);
            }else if(inst.opcode == mov || inst.opcode == put){
                fprintf(listing,"ram[%d] = %s",codeLine->lineno, opcodeBins[addi]);
                void vetor_atua(5, inst.reg2);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
                void vetor_atua(5, inst.reg1);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
                void vetor_atua(16, inst.imed);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);   
                fprintf(listing,"   // %s\n",Prefixos[inst.opcode]);
            }else{
                fprintf(listing,"ram[%d] = %s",codeLine->lineno, opcodeBins[inst.opcode]);
                void vetor_atua(5, inst.reg2);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
                void vetor_atua(5, inst.reg1);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
                void vetor_atua(16, inst.imed);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);  
                fprintf(listing,"   // %s\n",Prefixos[inst.opcode]);
            }
            break;
        case formatSYS:
            if(inst.opcode == halt || inst.opcode == sleep || inst.opcode == wake){
                fprintf(listing,"ram[%d] = %s",codeLine->lineno, opcodeBins[inst.opcode]);
                void vetor_atua(26, 0);
                for(i = 0; i < 26; i++) fprintf(listing,"%d;",vet[25-i]);
                fprintf(listing,"   // %s\n",Prefixos[inst.opcode]);
            }else if(inst.opcode == ctso){
                fprintf(listing,"ram[%d] = %s",codeLine->lineno, opcodeBins[inst.opcode]);
                void vetor_atua(26, END_SWITCH);
                for(i = 0; i < 26; i++) fprintf(listing,"%d;",vet[25-i]);
                fprintf(listing,"   // %s\n",Prefixos[inst.opcode]);
            }else{
                fprintf(listing,"ram[%d] = %s",codeLine->lineno, opcodeBins[inst.opcode]);
                void vetor_atua(5, 0);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
                void vetor_atua(5, inst.reg2);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]);
                void vetor_atua(16, 0);
                for(i = 0; i < 5; i++) fprintf(listing,"%d",vet[25-i]); 
                fprintf(listing,"   // %s\n",Prefixos[inst.opcode]);
            }
            break;
        }
    }else{
        fprintf(listing,"// %s\n",codeLine->line.label);
    }
}

void generateBinary () {
    AssemblyCode aux = getAssembly();
    char *bin;

    if(PrintCode)
        printf( "\nCódigo Binário:\n" );
    while (aux != NULL && listing != NULL) {
        assembly_binary(aux);
        aux = aux->next;
    }
    PrintCode = FALSE;
}

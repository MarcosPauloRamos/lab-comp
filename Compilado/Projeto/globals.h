/********************************************************************************/ 
/* File: globals.h                                                              */
/* Lex specification for Compiler                                               */
/* References: Compiler discipline, teacher Galvão, Unifesp - Brazil -2019      */
/* Marcos Paulo Ramos - mp001649@gmail.com                                      */
/********************************************************************************/
#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef YYPARSER

#include "Parser.tab.h"

/* ENDFILE é definido implicitamente pelo Yacc/Bison, e não está incluso no arquivo tab.h file */
#define ENDFILE 0

#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

/* MAXRESERVED = o número de palavras reservadas */
#define MAXRESERVED 8


#define nregisters 32 // numero de registradores
#define nregtemp 20 // numero de registradores temporários
#define nregparam 10 // numero de registradores de parametros
#define iniDataMem 361 // endereço da primeira posição da memória de dados
#define lploc 461 // endereço do inicio das variaveis locais

/* Yacc/Bison gera os próprios valores inteiros para os tokens */
typedef int TokenType;
typedef int FlagType;

extern FILE* source; /* arquivo texto do código fonte */
extern FILE* listing; /* listing output text file */
extern FILE* code; /* code text file for TM simulator */

extern int lineno; /* source line number for listing */
extern int init_code; /* posicao inicial da primeira instrucao */
/**************************************************/
/***********   Syntax tree for parsing ************/
/**************************************************/

typedef enum {StmtK,ExpK} NodeKind;
typedef enum {IfK,WhileK,AssignK,ReturnINT,ReturnVOID} StmtKind;
typedef enum {OpK,ConstK,IdK,VarDeclK,VetDeclK,FunDeclK,AtivK,TypeK,VetorK,VarParamK,VetParamK} ExpKind;

/* ExpType é usado para checagem de tipo */
typedef enum {Void,Integer,Boolean} ExpType;
typedef enum {INTTYPE, VOIDTYPE, NULLL} dataTypes;
typedef enum {VAR, PVAR, FUN, CALL, VET, PVET, RETT} IDTypes;

#define MAXCHILDREN 3

typedef struct treeNode {
  struct treeNode * child[MAXCHILDREN];
     struct treeNode * sibling;
     int lineno;
     int size;
     int add;
     int already_seem;
     NodeKind nodekind;
     union { StmtKind stmt; ExpKind exp;} kind;
     union { TokenType op;
             int val;
             char * name; } attr;
     char * idname;
     char *  scope;
     char * idtype;
     char * datatype;
     int vet;
     int declared;
     int params;
     dataTypes type; /* para checagem de tipo das exps */
   } TreeNode;


TreeNode * syntaxTree;

/* Caminhos dos arquivos a serem gerados pela compilação do arquivo */
char *ArvSint; // Caminho para a árvore sintática
char *TabSimb; // Caminho para a tabela de simbolos
char *interCode; // Caminho para o codigo intermediário
char *assCode; // Caminho para o codigo assembly
char *binCode; // caminho para o codigo binário

extern FlagType TraceScan;
extern FlagType TraceParse;
extern FlagType TraceAnalyze;
extern FlagType TraceCode;
extern FlagType PrintCode;
extern FlagType Error;
extern FlagType SO;
#endif


/*	lex.l	17:46:22	2013/5/10
*
*	Lexical analyzer for C++
*/
#ifndef YYLEX_H
#define YYLEX_H
#pragma once
#include	<string.h>	/* for strcmp, strdup & friends */
#include	<stdio.h>	/* for strcmp, strdup & friends */
#include	<stdlib.h>	/* for atoi() */
#include 	<iostream>
#include	<fstream>
using namespace std;

#include "yytab.h"




using namespace std;
const int START = 0;
const int LEXERROR = 32767;

int analysis(char *yytext,int n){
	int state = START;
	int N = n + 1;//N表示串长加1,为与状态数保持一致。
	int i = 0;
	for(int i = 0;i < N;i++)
	{
		switch(state){
		case 0:
		{
            if(yytext[i] == '$')
            {
                state = 155;
                break;
            }
            if(yytext[i] == '!')
			{
				state = 1;
				break;
			}
			if(yytext[i] == '%')
			{
				state = 2;
				break;
			}
			if(yytext[i] == '&')
			{
				state = 3;
				break;
			}
			if(yytext[i] == '\'')
			{
				state = 4;
				break;
			}
			if(yytext[i] == '(')
			{
				state = 5;
				break;
			}
			if(yytext[i] == ')')
			{
				state = 6;
				break;
			}
			if(yytext[i] == '*')
			{
				state = 7;
				break;
			}
			if(yytext[i] == '+')
			{
				state = 8;
				break;
			}
			if(yytext[i] == ',')
			{
				state = 9;
				break;
			}
			if(yytext[i] == '-')
			{
				state = 10;
				break;
			}
			if(yytext[i] == '.')
			{
				state = 11;
				break;
			}
			if(yytext[i] == '/')
			{
				state = 12;
				break;
			}
			if(yytext[i] == '0')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 39;
				break;
			}
			if(yytext[i] == ':')
			{
				state = 13;
				break;
			}
			if(yytext[i] == ';')
			{
				state = 14;
				break;
			}
			if(yytext[i] == '<')
			{
				state = 15;
				break;
			}
			if(yytext[i] == '=')
			{
				state = 16;
				break;
			}
			if(yytext[i] == '>')
			{
				state = 17;
				break;
			}
			if(yytext[i] == '?')
			{
				state = 18;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 40;
				break;
			}
			if(yytext[i] == '[')
			{
				state = 19;
				break;
			}
			if(yytext[i] == ']')
			{
				state = 20;
				break;
			}
			if(yytext[i] == '^')
			{
				state = 21;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 22;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 23;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 24;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 25;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 26;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 27;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 28;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 29;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 30;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 31;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 32;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 33;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 34;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 35;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 40;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 40;
				break;
			}
			if(yytext[i] == '{')
			{
				state = 36;
				break;
			}
			if(yytext[i] == '|')
			{
				state = 37;
				break;
			}
			if(yytext[i] == '}')
			{
				state = 38;
				break;
			}
			return LEXERROR;
		}
		case 1:
		{
			if(i == N-1){
				return BIT_NOT;
				break;
			}
			if(yytext[i] == '=')
			{
				state = 41;
				break;
			}
			return LEXERROR;
		}
		case 2:
		{
			if(i == N-1){
				return MOD_OP;
				break;
			}
			if(yytext[i] == '=')
			{
				state = 42;
				break;
			}
			return LEXERROR;
		}
		case 3:
		{
			if(i == N-1){
				return BIT_AND;
				break;
			}
			if(yytext[i] == '&')
			{
				state = 43;
				break;
			}
			if(yytext[i] == '=')
			{
				state = 44;
				break;
			}
			return LEXERROR;
		}
		case 4:
		{
			if(i == N-1){
				return SINGLE_QUOTATION;;
				break;
			}
			return LEXERROR;
		}
		case 5:
		{
			if(i == N-1){
				return LPAR;;
				break;
			}
			return LEXERROR;
		}
		case 6:
		{
			if(i == N-1){
				return RPAR;;
				break;
			}
			return LEXERROR;
		}
		case 7:
		{
			if(i == N-1){
				return MUL_OP;
				break;
			}
			if(yytext[i] == '=')
			{
				state = 45;
				break;
			}
			return LEXERROR;
		}
		case 8:
		{
			if(i == N-1){
				return ADD_OP;
				break;
			}
			if(yytext[i] == '+')
			{
				state = 47;
				break;
			}
			if(yytext[i] == '=')
			{
				state = 46;
				break;
			}
			return LEXERROR;
		}
		case 9:
		{
			if(i == N-1){
				return COMMA;;
				break;
			}
			return LEXERROR;
		}
		case 10:
		{
			if(i == N-1){
				return SUB_OP;
				break;
			}
			if(yytext[i] == '-')
			{
				state = 49;
				break;
			}
			if(yytext[i] == '=')
			{
				state = 48;
				break;
			}
			return LEXERROR;
		}
		case 11:
		{
			if(i == N-1){
				return DOT;;
				break;
			}
			return LEXERROR;
		}
		case 12:
		{
			if(i == N-1){
				return DIV_OP;
				break;
			}
			if(yytext[i] == '=')
			{
				state = 50;
				break;
			}
			return LEXERROR;
		}
		case 13:
		{
			if(i == N-1){
				return COLON;
				break;
			}
			return LEXERROR;
		}
		case 14:
		{
			if(i == N-1){
				return SEMICOLON;;
				break;
			}
			return LEXERROR;
		}
		case 15:
		{
			if(i == N-1){
				return L_OP;;
				break;
			}
			if(yytext[i] == '<')
			{
				state = 51;
				break;
			}
			if(yytext[i] == '=')
			{
				state = 52;
				break;
			}
			return LEXERROR;
		}
		case 16:
		{
			if(i == N-1){
				return ASSIGN;;
				break;
			}
			if(yytext[i] == '=')
			{
				state = 53;
				break;
			}
			return LEXERROR;
		}
		case 17:
		{
			if(i == N-1){
				return G_OP;;
				break;
			}
			if(yytext[i] == '=')
			{
				state = 54;
				break;
			}
			if(yytext[i] == '>')
			{
				state = 55;
				break;
			}
			return LEXERROR;
		}
		case 18:
		{
			if(i == N-1){
				return QUESTION;
				break;
			}
			return LEXERROR;
		}
		case 19:
		{
			if(i == N-1){
				return LBRACKET;
				break;
			}
			return LEXERROR;
		}
		case 20:
		{
			if(i == N-1){
				return RBRACKET;
				break;
			}
			return LEXERROR;
		}
		case 21:
		{
			if(yytext[i] == '=')
			{
				state = 56;
				break;
			}
			return LEXERROR;
		}
		case 22:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 58;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 59;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 23:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 60;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 61;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 62;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 24:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 63;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 64;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 25:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 65;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 26:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 66;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 67;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 27:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 68;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 28:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 69;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 70;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 29:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 71;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 30:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 72;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 31:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 73;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 74;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 75;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 76;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 32:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 77;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 33:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 78;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 34:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 79;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 35:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 80;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 36:
		{
			if(i == N-1){
				return LBRACE;;
				break;
			}
			return LEXERROR;
		}
		case 37:
		{
			if(i == N-1){
				return BIT_OR;
				break;
			}
			if(yytext[i] == '=')
			{
				state = 81;
				break;
			}
			if(yytext[i] == '|')
			{
				state = 82;
				break;
			}
			return LEXERROR;
		}
		case 38:
		{
			if(i == N-1){
				return RBRACE;;
				break;
			}
			return LEXERROR;
		}
		case 39:
		{
			if(i == N-1){
				{			return CONSTANT;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 39;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 39;
				break;
			}
			return LEXERROR;
		}
		case 40:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 41:
		{
			if(i == N-1){
				return NE_OP;;
				break;
			}
			return LEXERROR;
		}
		case 42:
		{
			if(i == N-1){
				return MOD_ASSIGN;;
				break;
			}
			return LEXERROR;
		}
		case 43:
		{
			if(i == N-1){
				return AND_OP;;
				break;
			}
			return LEXERROR;
		}
		case 44:
		{
			if(i == N-1){
				return AND_ASSIGN;;
				break;
			}
			return LEXERROR;
		}
		case 45:
		{
			if(i == N-1){
				return MUL_ASSIGN;;
				break;
			}
			return LEXERROR;
		}
		case 46:
		{
			if(i == N-1){
				return ADD_ASSIGN;;
				break;
			}
			return LEXERROR;
		}
		case 47:
		{
			if(i == N-1){
				return INC_OP;;
				break;
			}
			return LEXERROR;
		}
		case 48:
		{
			if(i == N-1){
				return SUB_ASSIGN;;
				break;
			}
			return LEXERROR;
		}
		case 49:
		{
			if(i == N-1){
				return DEC_OP;;
				break;
			}
			return LEXERROR;
		}
		case 50:
		{
			if(i == N-1){
				return DIV_ASSIGN;;
				break;
			}
			return LEXERROR;
		}
		case 51:
		{
			if(i == N-1){
				return LEFT_OP;;
				break;
			}
			if(yytext[i] == '=')
			{
				state = 83;
				break;
			}
			return LEXERROR;
		}
		case 52:
		{
			if(i == N-1){
				return LE_OP;;
				break;
			}
			return LEXERROR;
		}
		case 53:
		{
			if(i == N-1){
				return EQ_OP;;
				break;
			}
			return LEXERROR;
		}
		case 54:
		{
			if(i == N-1){
				return GE_OP;;
				break;
			}
			return LEXERROR;
		}
		case 55:
		{
			if(i == N-1){
				return RIGHT_OP;;
				break;
			}
			if(yytext[i] == '=')
			{
				state = 84;
				break;
			}
			return LEXERROR;
		}
		case 56:
		{
			if(i == N-1){
				return XOR_ASSIGN;;
				break;
			}
			return LEXERROR;
		}
		case 57:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 58:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 85;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 59:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 86;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 60:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 87;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 61:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 88;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 62:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 89;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 63:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 90;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 64:
		{
			if(i == N-1){
				if(strcmp(yytext, "do") == 0) {
					return DO;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 65:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 91;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 66:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 92;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 67:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 93;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 68:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 94;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 69:
		{
			if(i == N-1){
				if(strcmp(yytext, "if") == 0) {
					return IF;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 70:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 95;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 71:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 96;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 72:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 97;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 73:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 98;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 74:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 99;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 100;
				break;
			}
			return LEXERROR;
		}
		case 75:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 101;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 76:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 102;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 77:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 103;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 78:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 104;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 79:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 105;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 80:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 106;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 81:
		{
			if(i == N-1){
				return OR_ASSIGN;;
				break;
			}
			return LEXERROR;
		}
		case 82:
		{
			if(i == N-1){
				return OR_OP;;
				break;
			}
			return LEXERROR;
		}
		case 83:
		{
			if(i == N-1){
				return LEFT_ASSIGN;;
				break;
			}
			return LEXERROR;
		}
		case 84:
		{
			if(i == N-1){
				return RIGHT_ASSIGN;;
				break;
			}
			return LEXERROR;
		}
		case 85:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 107;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 86:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 108;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 87:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 109;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 88:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 110;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 89:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 111;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 112;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 90:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 113;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 91:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 114;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 92:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 115;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 93:
		{
			if(i == N-1){
				if(strcmp(yytext, "for") == 0) {
					return FOR;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 94:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 116;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 95:
		{
			if(i == N-1){
				if(strcmp(yytext, "int") == 0) {
					return INT;	;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 96:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 117;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 97:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 118;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 98:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 119;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 99:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 120;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 100:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 121;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 101:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 122;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 102:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 123;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 103:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 124;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 104:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 125;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 105:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 126;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 106:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 127;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 107:
		{
			if(i == N-1){
				if(strcmp(yytext, "bool") == 0) {
					return BOOL;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 108:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 128;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 109:
		{
			if(i == N-1){
				if(strcmp(yytext, "case") == 0) {
					return CASE;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 110:
		{
			if(i == N-1){
				if(strcmp(yytext, "char") == 0) {
					return CHAR;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 111:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 129;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 112:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 130;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 113:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 131;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 114:
		{
			if(i == N-1){
				if(strcmp(yytext, "else") == 0) {
					return ELSE;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 115:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 132;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 116:
		{
			if(i == N-1){
				if(strcmp(yytext, "goto") == 0) {
					return GOTO;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 117:
		{
			if(i == N-1){
				if(strcmp(yytext, "long") == 0) {
					return LONG;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 118:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 133;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 119:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 134;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 120:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 135;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 121:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 136;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 122:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 137;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 123:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 138;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 124:
		{
			if(i == N-1){
				if(strcmp(yytext, "true") == 0) {
					return TRUE;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 125:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 139;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 126:
		{
			if(i == N-1){
				if(strcmp(yytext, "void") == 0) {
					return VOID;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 127:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 140;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 128:
		{
			if(i == N-1){
				if(strcmp(yytext, "break") == 0) {
					return BREAK;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 129:
		{
			if(i == N-1){
				if(strcmp(yytext, "const") == 0) {
					return CONST;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 130:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 141;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 131:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 142;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 132:
		{
			if(i == N-1){
				if(strcmp(yytext, "false") == 0) {
					return FALSE;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 133:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 143;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 134:
		{
			if(i == N-1){
				if(strcmp(yytext, "short") == 0) {
					return SHORT;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 135:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 144;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 136:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 145;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 137:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 146;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 138:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 147;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 139:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 148;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 140:
		{
			if(i == N-1){
				{			return WHILE;			};
				break;
			}
			if(yytext[i] == ' ')
			{
				state = 149;
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 141:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 150;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 142:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 151;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 143:
		{
			if(i == N-1){
				if(strcmp(yytext, "return") == 0) {
					return RETURN;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 144:
		{
			if(i == N-1){
				if(strcmp(yytext, "signed") == 0) {
					return SIGNED;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 145:
		{
			if(i == N-1){
				if(strcmp(yytext, "sizeof") == 0) {
					return SIZEOF;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 146:
		{
			if(i == N-1){
				if(strcmp(yytext, "static") == 0) {
					return STATIC;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 147:
		{
			if(i == N-1){
				if(strcmp(yytext, "switch") == 0) {
					return SWITCH;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 148:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 152;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 149:
		{
			if(i == N-1){
				return WHILE;;
				break;
			}
			return LEXERROR;
		}
		case 150:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 153;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 151:
		{
			if(i == N-1){
				if(strcmp(yytext, "default") == 0) {
					return DEFAULT;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 152:
		{
			if(i == N-1){
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 154;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 153:
		{
			if(i == N-1){
				if(strcmp(yytext, "continue") == 0) {
					return CONTINUE;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
		case 154:
		{
			if(i == N-1){
				if(strcmp(yytext, "unsigned") == 0) {
					return UNSIGNED;;
					break;
				}
				{			return IDENTIFIER;			};
				break;
			}
			if(yytext[i] == '0')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '1')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '2')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '3')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '4')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '5')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '6')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '7')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '8')
			{
				state = 57;
				break;
			}
			if(yytext[i] == '9')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'A')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'B')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'C')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'D')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'E')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'F')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'G')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'H')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'I')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'J')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'K')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'L')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'M')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'N')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'O')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'P')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'R')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'S')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'T')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'U')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'V')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'W')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'X')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'Z')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'a')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'b')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'c')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'd')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'e')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'f')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'g')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'h')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'i')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'j')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'k')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'l')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'm')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'n')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'o')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'p')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'q')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'r')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 's')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 't')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'u')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'v')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'w')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'x')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'y')
			{
				state = 57;
				break;
			}
			if(yytext[i] == 'z')
			{
				state = 57;
				break;
			}
			return LEXERROR;
		}
        case 155:
        {
            if(i == N-1){
                return DOLLAR;
                break;
            }
            return LEXERROR;
        }
        }
	}

}

#endif //YYLEX_H

//int main() {
//	int size = 10;
//	char* str = new char[size];
//	
//	ifstream inFile("inputCode.cpp", ios::in);
//	if(!inFile) {
//		cout<<"scanner can't open the source .cpp file!"<<endl;
//	}
//	
//	ofstream outFile("scannerResult.txt", ios::out);
//	if(!outFile) {
//		cout<<"scanner create result file error!"<<endl;
//	}
//	
//	while(inFile>>str) {
//		outFile<<str<<"\t\t"<<analysis(str, strlen(str))<<endl;
//	}
//	
//	return 0;
//}


/**
 * @file ui.h
 * @author Thomas DUCLOS
 * @brief this is the header file for the user interface.
 * @version 1.2
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef UI_H
#define UI_H

#include <stdbool.h>

void Menu();
int Choice();
bool isWrongMenuChoice(int choice);

bool parseInt(char *str, int* val);
bool getInt(int* val);

#endif
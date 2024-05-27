/*
файл, где инициализируется дисплеи отрисовки и состояние OpenGL
*/
#pragma once
/// @brief выбор дисплеи из трех вариантов
void selectDisplay();
void displayStartMenu();
void displayEndMenu();
/// @brief основной дисплей игры. происходит вся отрисовка в ней
void displayGame();
void displayTroll();

/// @brief инизициализует состояние OpenGL: устанавливает размеры  и параметры
/// окна, таймеры
void initOpengl();
/*
файл, который должен был отвечать за музыку, но увы
*/
#pragma once
#include <stdio.h>

#include "miniaudio.h"
void data_callback(ma_device* pDevice, void* pOutput, const void* pInput,
                   ma_uint32 frameCount);
int playMusic(int argc, char** argv);
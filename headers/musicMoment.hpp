// musicMoment.hpp

// #define MINIAUDIO_IMPLEMENTATION
#pragma once
#include "miniaudio.h"
#include <stdio.h>
void data_callback(ma_device* pDevice, void* pOutput, const void* pInput,
                   ma_uint32 frameCount);
int playMusic(int argc, char** argv);
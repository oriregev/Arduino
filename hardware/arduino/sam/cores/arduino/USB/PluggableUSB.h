/*
  PluggableUSB.h
  Copyright (c) 2015 Arduino LLC

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef PUSB_h
#define PUSB_h

#include "USBAPI.h"
#include <cstddef>

#if defined(USBCON)

typedef struct __attribute__((packed))
{
  bool (*setup)(USBSetup& setup, uint8_t i);
  int (*getInterface)(uint8_t* interfaceNum);
  int (*getDescriptor)(int8_t t);
  int8_t numEndpoints;
  int8_t numInterfaces;
  uint32_t *endpointType;
} PUSBCallbacks;

class PUSBListNode {
public:
  PUSBListNode *next = NULL;
  PUSBCallbacks *cb;
  PUSBListNode(PUSBCallbacks *ncb) {cb = ncb;}
};

int8_t PUSB_AddFunction(PUSBListNode *node, uint8_t *interface);

int PUSB_GetInterface(uint8_t* interfaceNum);

int PUSB_GetDescriptor(int8_t t);

bool PUSB_Setup(USBSetup& setup, uint8_t i);

#endif

#endif

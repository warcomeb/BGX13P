/*
 * BGX13P - Library to manage BGX13P bluetooth module based on libohiboard
 * Copyright (C) 2019 Marco Giammarini <http://www.warcomeb.it>
 *
 * Authors:
 *  Marco Giammarini <m.giammarini@warcomeb.it>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*!
 * \file  /bgx13p.h
 * \brief
 */

#ifndef __WARCOMEB_BGX13P_H
#define __WARCOMEB_BGX13P_H

#ifdef __cplusplus
extern "C" {
#endif

#define WARCOMEB_BGX13P_LIBRARY_VERSION_MAJOR   (0x1ul)
#define WARCOMEB_BGX13P_LIBRARY_VERSION_MINOR   (0x0ul)
#define WARCOMEB_BGX13P_LIBRARY_VERSION_BUG     (0x0ul)
#define WARCOMEB_BGX13P_LIBRARY_VERSION         ((WARCOMEB_BGX13P_LIBRARY_VERSION_MAJOR << 16)\
                                                |(WARCOMEB_BGX13P_LIBRARY_VERSION_MINOR << 8 )\
                                                |(WARCOMEB_BGX13P_LIBRARY_VERSION_BUG        ))
#define WARCOMEB_BGX13P_LIBRARY_TIME            0

#include "bgx13ptype.h"

#if !defined (WARCOMEB_BGX13P_RX_BUFFER)
#define WARCOMEB_BGX13P_RX_BUFFER               128
#endif

/*!
 * BGX13P device class.
 */
typedef struct _BGX13P_Device_t
{
    Uart_DeviceHandle        device;
    Uart_Config              uartConfig;

    bool                     isAwake;

    bool                     isConnected;

    uint8_t                  rxBuffer[WARCOMEB_BGX13P_RX_BUFFER];
    UtilityBuffer_Descriptor rxDescriptor;

} BGX13P_Device_t, *BGX13P_DeviceHandle_t;

void BGX13P_init (BGX13P_DeviceHandle_t dev, BGX13P_Config_t* config);

/*!
 * This function resets the module.
 * There are two ways:
 *   \li by the use of the hardware pin,
 *   \li or via software command.
 *
 * \param[in]  dev:
 * \param[in] type:
 */
BGX13P_Errors_t BGX13P_reset (BGX13P_DeviceHandle_t dev, BGX13P_ResetType_t type);

BGX13P_Errors_t BGX13P_sleep (BGX13P_DeviceHandle_t dev);

BGX13P_Errors_t BGX13P_wake (BGX13P_DeviceHandle_t dev);

bool BGX13P_isAwake (BGX13P_DeviceHandle_t dev);

/*!
 * This function change the internal status of the device to awake.
 * The function doesn't send any message or perform any operation, just update
 * the module status.
 */
void BGX13P_awakeFromPin (BGX13P_DeviceHandle_t dev);

/*!
 * This function ask to the module the current firmware version.
 */
BGX13P_Errors_t BGX13P_getFirmwareVersion (BGX13P_DeviceHandle_t dev, char* data);

#ifdef __cplusplus
}
#endif

#endif /* __WARCOMEB_BGX13P_H */

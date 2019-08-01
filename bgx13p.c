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
 * \file  /bgx13p.c
 * \brief
 */

#include "bgx13p.h"

/*!
 * List of specific module commands.
 */
typedef enum _BGX13P_Command
{
    BGX13P_COMMAND_NONE = 0,
    BGX13P_COMMAND_GET_VERSION,
    BGX13P_COMMAND_REBOOT,
} BGX13P_Command_t;

static void initPins (BGX13P_DeviceHandle_t dev)
{
    Gpio_config(dev->pinReset, GPIO_PINS_INPUT);
}

static BGX13P_Errors_t sendCommand (BGX13P_DeviceHandle_t dev,
                                    BGX13P_Command_t command)
{

}

void BGX13P_init (BGX13P_DeviceHandle_t dev, BGX13P_Config_t* config)
{
    ohiassert(dev->pinReset != GPIO_PINS_NONE);

    // Initialize the device pointer
    memset(dev, 0, sizeof (BGX13P_Device_t));

    // Init Uart peripheral

    // Init pins

    // Reset module: hardware reset!
    BGX13P_reset(dev, BGX13P_RESETTYPE_HARDWARE);
}

BGX13P_Errors_t BGX13P_reset (BGX13P_DeviceHandle_t dev, BGX13P_ResetType_t type)
{
    BGX13P_Errors_t err = BGX13P_ERRORS_COMMAND_FAIL;

    // Reset internal module status
    dev->isAwake     = TRUE;
    dev->isConnected = FALSE;

    switch (type)
    {
    case BGX13P_RESETTYPE_HARDWARE:
        // Configure reset pin
        Gpio_config(dev->pinReset, GPIO_PINS_OUTPUT);
        Gpio_set(dev->pinReset);
        System_delay(2);
        Gpio_clear(dev->pinReset);
        System_delay(2);
        Gpio_config(dev->pinReset,GPIO_PINS_INPUT);
        System_delay(10);
        break;
    case BGX13P_RESETTYPE_SOFTWARE:
        sendCommand(dev,BGX13P_COMMAND_REBOOT);
        break;
    default:
        break;
    }

    return err;
}

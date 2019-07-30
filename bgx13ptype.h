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
 * \file  /bgx13ptype.h
 * \brief
 */

#ifndef __WARCOMEB_BGX13P_TYPE_H
#define __WARCOMEB_BGX13P_TYPE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __NO_PROFILES
#include "board.h"
#include "firmware.h"
#endif

/*!
 * List of possible module errors.
 */
typedef enum _BGX13P_Errors
{
	BGX13P_ERRORS_NO_ERROR,
	BGX13P_ERRORS_COMMAND_FAIL,
	BGX13P_ERRORS_CONNECTION_FAIL,
} BGX13P_Errors_t;

/*!
 * List module reset type.
 */
typedef enum _BGX13P_ResetType
{
    BLUETOOTH_RESETTYPE_HARDWARE = 0,
    BLUETOOTH_RESETTYPE_SOFTWARE = 1,
} BGX13P_ResetType_t;


#ifdef __cplusplus
}
#endif

#endif // __WARCOMEB_BGX13P_TYPE_H

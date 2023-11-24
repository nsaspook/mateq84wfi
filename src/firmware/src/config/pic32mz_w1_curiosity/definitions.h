/*******************************************************************************
  System Definitions

  File Name:
    definitions.h

  Summary:
    project system definitions.

  Description:
    This file contains the system-wide prototypes and definitions for a project.

 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
//DOM-IGNORE-END

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include "crypto/crypto.h"
#include "usb/usb_device_msd.h"
#include "usb/usb_msd.h"
#include "driver/memory/drv_memory.h"
#include "peripheral/ocmp/plib_ocmp2.h"
#include "system/time/sys_time.h"
#include "peripheral/coretimer/plib_coretimer.h"
#include "peripheral/spi/spi_master/plib_spi1_master.h"
#include "system/int/sys_int.h"
#include "system/ports/sys_ports.h"
#include "system/cache/sys_cache.h"
#include "system/reset/sys_reset.h"
#include "osal/osal.h"
#include "system/debug/sys_debug.h"
#include "peripheral/i2c/master/plib_i2c2_master.h"
#include "net_pres/pres/net_pres.h"
#include "net_pres/pres/net_pres_encryptionproviderapi.h"
#include "net_pres/pres/net_pres_transportapi.h"
#include "net_pres/pres/net_pres_socketapi.h"
#include "system/fs/sys_fs.h"
#include "system/fs/sys_fs_media_manager.h"
#include "system/fs/sys_fs_fat_interface.h"
#include "system/fs/fat_fs/file_system/ff.h"
#include "system/fs/fat_fs/file_system/ffconf.h"
#include "system/fs/fat_fs/hardware_access/diskio.h"
#include "driver/ba414e/drv_ba414e.h"
#include "usb/usb_chapter_9.h"
#include "usb/usb_device.h"
#include "system/net/sys_net.h"
#include "peripheral/adchs/plib_adchs.h"
#include "peripheral/uart/plib_uart1.h"
#include "system/mqtt/sys_mqtt.h"
#include "peripheral/uart/plib_uart2.h"
#include "peripheral/tmr/plib_tmr2.h"
#include "peripheral/tmr/plib_tmr3.h"
#include "driver/usb/usbfs/drv_usbfs.h"
#include "library/tcpip/tcpip.h"
#include "system/sys_time_h2_adapter.h"
#include "system/sys_random_h2_adapter.h"
#include "system/command/sys_command.h"
#include "peripheral/clk/plib_clk.h"
#include "peripheral/gpio/plib_gpio.h"
#include "peripheral/cache/plib_cache.h"
#include "peripheral/evic/plib_evic.h"
#include "peripheral/wdt/plib_wdt.h"
#include "driver/sst26/drv_sst26.h"
#include "wolfssl/wolfcrypt/port/pic32/crypt_wolfcryptcb.h"
#include "driver/wifi/pic32mzw1/include/wdrv_pic32mzw_api.h"
#include "system/wifi/sys_wifi.h"
#include "system/console/sys_console.h"
#include "system/console/src/sys_console_uart_definitions.h"
#include "FreeRTOS.h"
#include "task.h"
#include "peripheral/rtcc/plib_rtcc.h"
#include "app.h"
#include "app_wifi.h"
#include "msd_app.h"
#include "app_control.h"
#include "mqtt_app.h"



// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END

/* Device Information */
#define DEVICE_NAME			 "PIC32MZ1025W104132"
#define DEVICE_ARCH			 "MIPS"
#define DEVICE_FAMILY		 "PIC32MZW"
#define DEVICE_SERIES		 "PIC32MZW"

/* CPU clock frequency */
#define CPU_CLOCK_FREQUENCY 200000000

// *****************************************************************************
// *****************************************************************************
// Section: System Functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* System Initialization Function

  Function:
    void SYS_Initialize( void *data )

  Summary:
    Function that initializes all modules in the system.

  Description:
    This function initializes all modules in the system, including any drivers,
    services, middleware, and applications.

  Precondition:
    None.

  Parameters:
    data            - Pointer to the data structure containing any data
                      necessary to initialize the module. This pointer may
                      be null if no data is required and default initialization
                      is to be used.

  Returns:
    None.

  Example:
    <code>
    SYS_Initialize ( NULL );

    while ( true )
    {
        SYS_Tasks ( );
    }
    </code>

  Remarks:
    This function will only be called once, after system reset.
*/

void SYS_Initialize( void *data );

// *****************************************************************************
/* System Tasks Function

Function:
    void SYS_Tasks ( void );

Summary:
    Function that performs all polled system tasks.

Description:
    This function performs all polled system tasks by calling the state machine
    "tasks" functions for all polled modules in the system, including drivers,
    services, middleware and applications.

Precondition:
    The SYS_Initialize function must have been called and completed.

Parameters:
    None.

Returns:
    None.

Example:
    <code>
    SYS_Initialize ( NULL );

    while ( true )
    {
        SYS_Tasks ( );
    }
    </code>

Remarks:
    If the module is interrupt driven, the system will call this routine from
    an interrupt context.
*/

void SYS_Tasks ( void );

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* System Objects

Summary:
    Structure holding the system's object handles

Description:
    This structure contains the object handles for all objects in the
    MPLAB Harmony project's system configuration.

Remarks:
    These handles are returned from the "Initialize" functions for each module
    and must be passed into the "Tasks" function for each module.
*/

typedef struct
{
    SYS_MODULE_OBJ  sysTime;
    SYS_MODULE_OBJ  sysConsole0;

    SYS_MODULE_OBJ  netPres;


    SYS_MODULE_OBJ  ba414e;

    SYS_MODULE_OBJ  usbDevObject0;

    SYS_MODULE_OBJ  drvMemory0;
	SYS_MODULE_OBJ  drvUSBFSObject;


    SYS_MODULE_OBJ  tcpip;
    SYS_MODULE_OBJ  drvSST26;
    SYS_MODULE_OBJ  sysDebug;


    SYS_MODULE_OBJ  drvWifiPIC32MZW1;
    SYS_MODULE_OBJ  syswifi;

} SYSTEM_OBJECTS;

// *****************************************************************************
// *****************************************************************************
// Section: extern declarations
// *****************************************************************************
// *****************************************************************************

extern const USB_DEVICE_INIT usbDevInitData; 



extern SYSTEM_OBJECTS sysObj;

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* DEFINITIONS_H */
/*******************************************************************************
 End of File
*/


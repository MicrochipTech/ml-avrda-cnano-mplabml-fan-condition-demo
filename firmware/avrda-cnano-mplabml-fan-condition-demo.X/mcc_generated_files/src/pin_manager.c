/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/


#include "../include/pin_manager.h"
static void (*PORTA_PA2_InterruptHandler)(void);
static void (*PORTC_PC3_InterruptHandler)(void);
static void (*PORTA_PA1_InterruptHandler)(void);
static void (*PORTC_LED0_InterruptHandler)(void);
static void (*PORTA_PA4_InterruptHandler)(void);
static void (*PORTD_MIKRO1_INT_InterruptHandler)(void);
static void (*PORTA_PA6_InterruptHandler)(void);
static void (*PORTC_SW0_InterruptHandler)(void);
static void (*PORTA_PA5_InterruptHandler)(void);
static void (*PORTA_MIKRO1_CS_InterruptHandler)(void);
static void (*PORTC_PC0_InterruptHandler)(void);
static void (*PORTC_PC2_InterruptHandler)(void);
static void (*PORTA_PA0_InterruptHandler)(void);
static void (*PORTC_PC1_InterruptHandler)(void);

void PORT_Initialize(void);

void PIN_MANAGER_Initialize()
{
    PORT_Initialize();

    /* DIR Registers Initialization */
    PORTA.DIR = 0xD7;
    PORTB.DIR = 0x00;
    PORTC.DIR = 0x41;
    PORTD.DIR = 0x00;
    PORTE.DIR = 0x00;
    PORTF.DIR = 0x00;

    /* OUT Registers Initialization */
    PORTA.OUT = 0x01;
    PORTB.OUT = 0x00;
    PORTC.OUT = 0x01;
    PORTD.OUT = 0x00;
    PORTE.OUT = 0x00;
    PORTF.OUT = 0x00;

    /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x00;
    PORTA.PIN1CTRL = 0x00;
    PORTA.PIN2CTRL = 0x00;
    PORTA.PIN3CTRL = 0x00;
    PORTA.PIN4CTRL = 0x00;
    PORTA.PIN5CTRL = 0x00;
    PORTA.PIN6CTRL = 0x00;
    PORTA.PIN7CTRL = 0x00;
    PORTB.PIN0CTRL = 0x00;
    PORTB.PIN1CTRL = 0x00;
    PORTB.PIN2CTRL = 0x00;
    PORTB.PIN3CTRL = 0x00;
    PORTB.PIN4CTRL = 0x00;
    PORTB.PIN5CTRL = 0x00;
    PORTB.PIN6CTRL = 0x00;
    PORTB.PIN7CTRL = 0x00;
    PORTC.PIN0CTRL = 0x00;
    PORTC.PIN1CTRL = 0x08;
    PORTC.PIN2CTRL = 0x00;
    PORTC.PIN3CTRL = 0x00;
    PORTC.PIN4CTRL = 0x00;
    PORTC.PIN5CTRL = 0x00;
    PORTC.PIN6CTRL = 0x00;
    PORTC.PIN7CTRL = 0x0B;
    PORTD.PIN0CTRL = 0x00;
    PORTD.PIN1CTRL = 0x00;
    PORTD.PIN2CTRL = 0x00;
    PORTD.PIN3CTRL = 0x00;
    PORTD.PIN4CTRL = 0x00;
    PORTD.PIN5CTRL = 0x04;
    PORTD.PIN6CTRL = 0x02;
    PORTD.PIN7CTRL = 0x00;
    PORTE.PIN0CTRL = 0x00;
    PORTE.PIN1CTRL = 0x00;
    PORTE.PIN2CTRL = 0x00;
    PORTE.PIN3CTRL = 0x00;
    PORTE.PIN4CTRL = 0x00;
    PORTE.PIN5CTRL = 0x00;
    PORTE.PIN6CTRL = 0x00;
    PORTE.PIN7CTRL = 0x00;
    PORTF.PIN0CTRL = 0x00;
    PORTF.PIN1CTRL = 0x08;
    PORTF.PIN2CTRL = 0x02;
    PORTF.PIN3CTRL = 0x00;
    PORTF.PIN4CTRL = 0x00;
    PORTF.PIN5CTRL = 0x08;
    PORTF.PIN6CTRL = 0x08;
    PORTF.PIN7CTRL = 0x00;

    /* Multi-pin Config registers Initialization */
    PORTA.PINCONFIG = 0x00;
    PORTA.PINCTRLCLR = 0x00;
    PORTA.PINCTRLSET = 0x00;
    PORTA.PINCTRLUPD = 0x00;
    PORTB.PINCONFIG = 0x00;
    PORTB.PINCTRLCLR = 0x00;
    PORTB.PINCTRLSET = 0x00;
    PORTB.PINCTRLUPD = 0x00;
    PORTC.PINCONFIG = 0x00;
    PORTC.PINCTRLCLR = 0x00;
    PORTC.PINCTRLSET = 0x00;
    PORTC.PINCTRLUPD = 0x00;
    PORTD.PINCONFIG = 0x00;
    PORTD.PINCTRLCLR = 0x00;
    PORTD.PINCTRLSET = 0x00;
    PORTD.PINCTRLUPD = 0x00;
    PORTE.PINCONFIG = 0x00;
    PORTE.PINCTRLCLR = 0x00;
    PORTE.PINCTRLSET = 0x00;
    PORTE.PINCTRLUPD = 0x00;
    PORTF.PINCONFIG = 0x00;
    PORTF.PINCTRLCLR = 0x00;
    PORTF.PINCTRLSET = 0x00;
    PORTF.PINCTRLUPD = 0x00;

    /* PORTMUX Initialization */
    PORTMUX.ACROUTEA = 0x00;
    PORTMUX.CCLROUTEA = 0x00;
    PORTMUX.EVSYSROUTEA = 0x00;
    PORTMUX.SPIROUTEA = 0x00;
    PORTMUX.TCAROUTEA = 0x00;
    PORTMUX.TCBROUTEA = 0x00;
    PORTMUX.TCDROUTEA = 0x00;
    PORTMUX.TWIROUTEA = 0x02;
    PORTMUX.USARTROUTEA = 0x00;
    PORTMUX.USARTROUTEB = 0x00;
    PORTMUX.ZCDROUTEA = 0x00;

    // register default ISC callback functions at runtime; use these methods to register a custom function
    PORTA_PA2_SetInterruptHandler(PORTA_PA2_DefaultInterruptHandler);
    PORTC_PC3_SetInterruptHandler(PORTC_PC3_DefaultInterruptHandler);
    PORTA_PA1_SetInterruptHandler(PORTA_PA1_DefaultInterruptHandler);
    PORTC_LED0_SetInterruptHandler(PORTC_LED0_DefaultInterruptHandler);
    PORTA_PA4_SetInterruptHandler(PORTA_PA4_DefaultInterruptHandler);
    PORTD_MIKRO1_INT_SetInterruptHandler(PORTD_MIKRO1_INT_DefaultInterruptHandler);
    PORTA_PA6_SetInterruptHandler(PORTA_PA6_DefaultInterruptHandler);
    PORTC_SW0_SetInterruptHandler(PORTC_SW0_DefaultInterruptHandler);
    PORTA_PA5_SetInterruptHandler(PORTA_PA5_DefaultInterruptHandler);
    PORTA_MIKRO1_CS_SetInterruptHandler(PORTA_MIKRO1_CS_DefaultInterruptHandler);
    PORTC_PC0_SetInterruptHandler(PORTC_PC0_DefaultInterruptHandler);
    PORTC_PC2_SetInterruptHandler(PORTC_PC2_DefaultInterruptHandler);
    PORTA_PA0_SetInterruptHandler(PORTA_PA0_DefaultInterruptHandler);
    PORTC_PC1_SetInterruptHandler(PORTC_PC1_DefaultInterruptHandler);
}

void PORT_Initialize(void)
{
    /* On AVR devices all peripherals are enable from power on reset, this
     * disables all peripherals to save power. Driver shall enable
     * peripheral if used */

    /* Set all pins to low power mode */
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTE + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTF + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTA + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTB + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTC + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTD + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
}

/**
  Allows selecting an interrupt handler for PORTA_PA2 at application runtime
*/
void PORTA_PA2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA2_InterruptHandler = interruptHandler;
}

void PORTA_PA2_DefaultInterruptHandler(void)
{
    // add your PORTA_PA2 interrupt custom code
    // or set custom function using PORTA_PA2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_PC3 at application runtime
*/
void PORTC_PC3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_PC3_InterruptHandler = interruptHandler;
}

void PORTC_PC3_DefaultInterruptHandler(void)
{
    // add your PORTC_PC3 interrupt custom code
    // or set custom function using PORTC_PC3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA1 at application runtime
*/
void PORTA_PA1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA1_InterruptHandler = interruptHandler;
}

void PORTA_PA1_DefaultInterruptHandler(void)
{
    // add your PORTA_PA1 interrupt custom code
    // or set custom function using PORTA_PA1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_LED0 at application runtime
*/
void PORTC_LED0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_LED0_InterruptHandler = interruptHandler;
}

void PORTC_LED0_DefaultInterruptHandler(void)
{
    // add your PORTC_LED0 interrupt custom code
    // or set custom function using PORTC_LED0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA4 at application runtime
*/
void PORTA_PA4_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA4_InterruptHandler = interruptHandler;
}

void PORTA_PA4_DefaultInterruptHandler(void)
{
    // add your PORTA_PA4 interrupt custom code
    // or set custom function using PORTA_PA4_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_MIKRO1_INT at application runtime
*/
void PORTD_MIKRO1_INT_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_MIKRO1_INT_InterruptHandler = interruptHandler;
}

void PORTD_MIKRO1_INT_DefaultInterruptHandler(void)
{
    // add your PORTD_MIKRO1_INT interrupt custom code
    // or set custom function using PORTD_MIKRO1_INT_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA6 at application runtime
*/
void PORTA_PA6_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA6_InterruptHandler = interruptHandler;
}

void PORTA_PA6_DefaultInterruptHandler(void)
{
    // add your PORTA_PA6 interrupt custom code
    // or set custom function using PORTA_PA6_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_SW0 at application runtime
*/
void PORTC_SW0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_SW0_InterruptHandler = interruptHandler;
}

void PORTC_SW0_DefaultInterruptHandler(void)
{
    // add your PORTC_SW0 interrupt custom code
    // or set custom function using PORTC_SW0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA5 at application runtime
*/
void PORTA_PA5_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA5_InterruptHandler = interruptHandler;
}

void PORTA_PA5_DefaultInterruptHandler(void)
{
    // add your PORTA_PA5 interrupt custom code
    // or set custom function using PORTA_PA5_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_MIKRO1_CS at application runtime
*/
void PORTA_MIKRO1_CS_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_MIKRO1_CS_InterruptHandler = interruptHandler;
}

void PORTA_MIKRO1_CS_DefaultInterruptHandler(void)
{
    // add your PORTA_MIKRO1_CS interrupt custom code
    // or set custom function using PORTA_MIKRO1_CS_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_PC0 at application runtime
*/
void PORTC_PC0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_PC0_InterruptHandler = interruptHandler;
}

void PORTC_PC0_DefaultInterruptHandler(void)
{
    // add your PORTC_PC0 interrupt custom code
    // or set custom function using PORTC_PC0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_PC2 at application runtime
*/
void PORTC_PC2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_PC2_InterruptHandler = interruptHandler;
}

void PORTC_PC2_DefaultInterruptHandler(void)
{
    // add your PORTC_PC2 interrupt custom code
    // or set custom function using PORTC_PC2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA0 at application runtime
*/
void PORTA_PA0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA0_InterruptHandler = interruptHandler;
}

void PORTA_PA0_DefaultInterruptHandler(void)
{
    // add your PORTA_PA0 interrupt custom code
    // or set custom function using PORTA_PA0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_PC1 at application runtime
*/
void PORTC_PC1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_PC1_InterruptHandler = interruptHandler;
}

void PORTC_PC1_DefaultInterruptHandler(void)
{
    // add your PORTC_PC1 interrupt custom code
    // or set custom function using PORTC_PC1_SetInterruptHandler()
}
ISR(PORTF_PORT_vect)
{  
    // Call the interrupt handler for the callback registered at runtime

    /* Clear interrupt flags */
    VPORTF.INTFLAGS = 0xff;
}

ISR(PORTC_PORT_vect)
{  
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTC.INTFLAGS & PORT_INT3_bm)
    {
       PORTC_PC3_InterruptHandler();
    }
    if(VPORTC.INTFLAGS & PORT_INT6_bm)
    {
       PORTC_LED0_InterruptHandler();
    }
    if(VPORTC.INTFLAGS & PORT_INT7_bm)
    {
       PORTC_SW0_InterruptHandler();
    }
    if(VPORTC.INTFLAGS & PORT_INT0_bm)
    {
       PORTC_PC0_InterruptHandler();
    }
    if(VPORTC.INTFLAGS & PORT_INT2_bm)
    {
       PORTC_PC2_InterruptHandler();
    }
    if(VPORTC.INTFLAGS & PORT_INT1_bm)
    {
       PORTC_PC1_InterruptHandler();
    }

    /* Clear interrupt flags */
    VPORTC.INTFLAGS = 0xff;
}

ISR(PORTD_PORT_vect)
{  
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTD.INTFLAGS & PORT_INT6_bm)
    {
       PORTD_MIKRO1_INT_InterruptHandler();
    }

    /* Clear interrupt flags */
    VPORTD.INTFLAGS = 0xff;
}


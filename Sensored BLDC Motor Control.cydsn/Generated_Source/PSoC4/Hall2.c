/*******************************************************************************
* File Name: Hall2.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Hall2.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Hall2_PC =   (Hall2_PC & \
                                (uint32)(~(uint32)(Hall2_DRIVE_MODE_IND_MASK << (Hall2_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Hall2_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Hall2_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void Hall2_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Hall2_DR & (uint8)(~Hall2_MASK));
    drVal = (drVal | ((uint8)(value << Hall2_SHIFT) & Hall2_MASK));
    Hall2_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Hall2_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Hall2_DM_STRONG     Strong Drive 
*  Hall2_DM_OD_HI      Open Drain, Drives High 
*  Hall2_DM_OD_LO      Open Drain, Drives Low 
*  Hall2_DM_RES_UP     Resistive Pull Up 
*  Hall2_DM_RES_DWN    Resistive Pull Down 
*  Hall2_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Hall2_DM_DIG_HIZ    High Impedance Digital 
*  Hall2_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Hall2_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Hall2__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Hall2_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro Hall2_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Hall2_Read(void) 
{
    return (uint8)((Hall2_PS & Hall2_MASK) >> Hall2_SHIFT);
}


/*******************************************************************************
* Function Name: Hall2_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 Hall2_ReadDataReg(void) 
{
    return (uint8)((Hall2_DR & Hall2_MASK) >> Hall2_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Hall2_INTSTAT) 

    /*******************************************************************************
    * Function Name: Hall2_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 Hall2_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Hall2_INTSTAT & Hall2_MASK);
		Hall2_INTSTAT = maskedStatus;
        return maskedStatus >> Hall2_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */

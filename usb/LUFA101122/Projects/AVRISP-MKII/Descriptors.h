/*
             LUFA Library
     Copyright (C) Dean Camera, 2010.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2010  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Header file for Descriptors.c.
 */

#ifndef _DESCRIPTORS_H_
#define _DESCRIPTORS_H_

	/* Includes: */
		#include <avr/pgmspace.h>

		#include <LUFA/Drivers/USB/USB.h>

	/* Macros: */
		#if !defined(LIBUSB_DRIVER_COMPAT)
			/** Endpoint number of the AVRISP data OUT endpoint. */
			#define AVRISP_DATA_OUT_EPNUM      2

			/** Endpoint number of the AVRISP data IN endpoint. */
			#define AVRISP_DATA_IN_EPNUM       2
		#else
			/** Endpoint number of the AVRISP data OUT endpoint. */
			#define AVRISP_DATA_OUT_EPNUM      2

			/** Endpoint number of the AVRISP data IN endpoint. */
			#define AVRISP_DATA_IN_EPNUM       3
		#endif

		/** Size in bytes of the AVRISP data endpoint. */
		#define AVRISP_DATA_EPSIZE             64

	/* Type Defines: */
		/** Type define for the device configuration descriptor structure. This must be defined in the
		 *  application code, as the configuration descriptor contains several sub-descriptors which
		 *  vary between devices, and which describe the device's usage to the host.
		 */
		typedef struct
		{
			USB_Descriptor_Configuration_Header_t    Config;
			USB_Descriptor_Interface_t               AVRISP_Interface;
			USB_Descriptor_Endpoint_t                AVRISP_DataInEndpoint;
			USB_Descriptor_Endpoint_t                AVRISP_DataOutEndpoint;
		} USB_Descriptor_Configuration_t;

	/* Function Prototypes: */
		uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
		                                    const uint8_t wIndex,
		                                    const void** const DescriptorAddress)
		                                    ATTR_WARN_UNUSED_RESULT ATTR_NON_NULL_PTR_ARG(3);

#endif


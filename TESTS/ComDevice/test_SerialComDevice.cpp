/**
 * Project: Mbed-Shared-Components
 * File: test_SerialComDevice.cpp
 * Author: Matthew Yu (2021).
 * Created on: 06/08/21
 * Last Modified: 06/08/21
 * File Description: This program tests the serial communication device 
 * drivers. The user should see the following serial stream from the 
 * serial monitor: [ID][DATA] where is ID is a 4 chars wide and DATA is
 * is 8 chars wide. ID is 0x21.
 * L432KC Pinout:
 * https://os.mbed.com/media/uploads/bcostm/nucleo_l432kc_2017_10_09.png
 */
/** Custom Imports. */
#include <src/Message/Message.h>
#include <src/ComDevice/ComDevice.h>

#define USB_TX USBTX
#define USB_RX USBRX
#define COM_RATE_MS 50

/** Communication Device. */
ComDevice transceiver(ComDevice::SERIAL, USB_TX, USB_RX);

int testMain(void) {
    /* Initialize transceiver to begin serial communication. */
    transceiver.startMs(COM_RATE_MS);

    uint64_t dataVal = 0;
    while (true) {
        Message helloWorld = Message(0x21, dataVal);
        transceiver.sendMessage(&helloWorld);
        ++dataVal;
    }
}

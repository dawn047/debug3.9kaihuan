// NFCReader.h
#ifndef NFCREADER_H
#define NFCREADER_H

#include <SPI.h>
#include <MFRC522.h>

#define SCK_PIN 21
#define MISO_PIN 18
#define MOSI_PIN 19
#define SS_PIN 22
#define RST_PIN 5

class NFCReader {
public:
    NFCReader(uint8_t ssPin = 22, uint8_t rstPin = 5);
    void begin();
    bool readCard();
    String getUID() const;
    String getCardType() const;

private:
    MFRC522 mfrc522;
    String currentUID;
    String cardType;
};

#endif
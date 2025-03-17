// NFCReader.h
#ifndef NFCREADER_H
#define NFCREADER_H

#include <SPI.h>
#include <MFRC522.h>

class NFCReader {
public:
    NFCReader(uint8_t ssPin = 5, uint8_t rstPin = 22); // 默认引脚
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
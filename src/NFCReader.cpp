// NFCReader.cpp
#include "NFCReader.h"

NFCReader::NFCReader(uint8_t ssPin, uint8_t rstPin) 
    : mfrc522(ssPin, rstPin) {}

void NFCReader::begin() {
    SPI.begin();
    mfrc522.PCD_Init();
}

bool NFCReader::readCard() {
    currentUID = "";
    cardType = "";
    
    if (!mfrc522.PICC_IsNewCardPresent() || 
        !mfrc522.PICC_ReadCardSerial()) {
        return false;
    }

    // 获取卡片类型
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    cardType = mfrc522.PICC_GetTypeName(piccType);

    // 转换UID为字符串
    for (byte i = 0; i < mfrc522.uid.size; i++) {
        char buffer[3];
        sprintf(buffer, "%02X", mfrc522.uid.uidByte[i]);
        currentUID += buffer;
        if (i != mfrc522.uid.size-1) currentUID += ":";
    }

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    return true;
}

String NFCReader::getUID() const {
    return currentUID;
}

String NFCReader::getCardType() const {
    return cardType;
}
#ifndef __MAIL_H
#define __MAIL_H

#include "global.h"

typedef union {
    struct {
        u16 cgxID   :12,
            palID   :4;
    };
    u16 dat;
} MailIcon;

struct MessageData {
    u16 sentenceType;
    u16 sentenceID;
    u16 words[2];
};

struct MailData {
    u32 writerID;
    u8  sex;
    u8  region;
    u8  version;
    u8  design;
    u16 name[8];    // 7 character name + 1 character terminator
    MailIcon icon[3];
    u16 formBit;
    struct MessageData message[3];
};

#endif // __MAIL_H
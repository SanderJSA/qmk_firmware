#pragma once
#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
    #include <avr/io.h>
    #include <avr/interrupt.h>
#endif
#endif

#define LAYOUT_5x6( \
    L00, L01, L02, L03, L04, L05,                     R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,                     R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,                     R20, R21, R22, R23, R24, R25,\
    L30, L31, L32, L33, L34, L35,                     R30, R31, R32, R33, R34, R35,\
    L40, L41, L42, L43, L44, L45,                     R40, R41, R42, R43, R44, R45\
    ) \
    { \
        { L00, L01, L02, L03, L04, L05 }, \
        { L10, L11, L12, L13, L14, L15 }, \
        { L20, L21, L22, L23, L24, L25 }, \
        { L30, L31, L32, L33, L34, L35 }, \
        { L40, L41, L42, L43, L44, L45 }, \
        { R05, R04, R03, R02, R01, R00 },    \
        { R15, R14, R13, R12, R11, R10 },    \
        { R25, R24, R23, R22, R21, R20 },    \
        { R35, R34, R33, R32, R31, R30 },    \
        { R45, R44, R43, R42, R41, R40 }    \
    }

#define LAYOUT_new( \
    k00, k01, k02, k03, k04, k05,            k55, k54, k53, k52, k51, k50, \
    k10, k11, k12, k13, k14, k15,            k65, k64, k63, k62, k61, k60, \
    k20, k21, k22, k23, k24, k25,            k75, k74, k73, k72, k71, k70, \
    k30, k31, k32, k33, k34, k35,            k85, k84, k83, k82, k81, k80, \
                   k43, k44, k41,            k91, k94, k93, \
                        k45, k42,            k92, k95 \
)\
{\
    { k00, k01, k02, k03, k04, k05 }, \
    { k10, k11, k12, k13, k14, k15 }, \
    { k20, k21, k22, k23, k24, k25 }, \
    { k30, k31, k32, k33, k34, k35 }, \
    { KC_NO, k41, k42, k43, k44, k45 }, \
    { k50, k51, k52, k53, k54, k55 }, \
    { k60, k61, k62, k63, k64, k65 }, \
    { k70, k71, k72, k73, k74, k75 }, \
    { k80, k81, k82, k83, k84, k85 }, \
    { KC_NO, k91, k92, k93, k94, k95 }, \
}

BOOTMAGIC_ENABLE  = no
MOUSEKEY_ENABLE   = no
CONSOLE_ENABLE    = no
COMMAND_ENABLE    = no
MIDI_ENABLE       = no
AUDIO_ENABLE      = no
UNICODE_ENABLE    = no
BLUETOOTH_ENABLE  = no
RGBLIGHT_ENABLE   = no

RGB_MATRIX_ENABLE = WS2812
EXTRAKEY_ENABLE   = yes
WPM_ENABLE = yes
OLED_DRIVER_ENABLE = yes
TAP_DANCE_ENABLE = yes

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        # ./lib/rgb_state_reader.c \
        # ./lib/logo_reader.c \
        # ./lib/layer_state_reader.c \
        # ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \

EXTRAFLAGS += -flto

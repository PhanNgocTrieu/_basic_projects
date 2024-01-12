#ifndef UIKEYBOARD_H
#define UIKEYBOARD_H

#ifndef TIMMER_HOLDING_KEY_CHANGEVOLUME
#define TIMMER_HOLDING_KEY_CHANGEVOLUME         ((int)500)
#endif

enum class UIKeyEvent {
    Unknown = 0,
    Pressed,
    Released,
    PressedAndReleased,
    LongPressedAndReleased,
    ContinueHolding,
    Holded,
    VaSWPressed,
    FavoriteSWPressed,
};

#ifdef BUILD_BOARD
#include <linux/input.h>

#ifndef CONFIG_OS_EVENT_PATH_STR
#define CONFIG_OS_EVENT_PATH_STR            "/dev/input/eventSW"
#endif
enum class UIKeyCode : unsigned short
{
    VolumeMute = KEY_F13,
    VolumeUp = KEY_F15,
    VolumeDown = KEY_F14,
    SeekUp = KEY_F16,
    SeekDown = KEY_F17,
    Voice = KEY_F18,
    PressInfo = KEY_F19,
    Trip = KEY_F20,
    Favorite = KEY_F21,
    ShortInfo = KEY_F22,
    SWBankVolume = REL_RESERVED,
    SWBankMute = KEY_F23,
    ScreenShot = VolumeMute,
    Unknown = 0xFFFF,
};

#else
#include <linux/input.h>

#ifndef CONFIG_OS_EVENT_PATH_STR
#define CONFIG_OS_EVENT_PATH_STR                "/dev/input/event1"
#endif

enum class UIKeyCode : unsigned short
{
    VolumeDown = KEY_F1,
    VolumeUp = KEY_F2,
    VolumeMute = KEY_F3,
    SeekUp = KEY_F6,
    SeekDown = KEY_F5,
    Voice = KEY_F7,
    PressInfo = KEY_F8,
    Trip = KEY_F9,
    Favorite = KEY_F10,
    ShortInfo = KEY_I,
    SWBankVolume = KEY_V,
    SWBankMute = KEY_M,
    ScreenShot = KEY_X,
    Unknown = 0xFFFF,
};

#endif //BUILD_BOARD
#endif // UIKEYBOARD_H

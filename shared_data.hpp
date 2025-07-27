#ifndef SHARED_DATA_HPP
#define SHARED_DATA_HPP

#include <cstdint>

#define SHM_NAME "/window_control_shm"
#define SHM_SIZE sizeof(WindowControlData)

enum class WindowAction : uint8_t { NONE = 0, OPEN = 1, CLOSE = 2 };
enum class WindowPosition : uint8_t { FRONT_LEFT = 1, FRONT_RIGHT = 2, REAR_LEFT = 3, REAR_RIGHT = 4 };

struct WindowControlData {
    volatile bool has_new_command;
    WindowAction action;
    WindowPosition position;
    uint32_t sequence_number;
};

#endif // SHARED_DATA_HPP
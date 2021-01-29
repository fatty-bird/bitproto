// Code generated by bitproto. DO NOT EDIT.

// Proto drone describes the structure of the drone.

#ifndef __BITPROTO__DRONE_H__
#define __BITPROTO__DRONE_H__ 1

#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif

#if defined(__cplusplus)
extern "C" {
#endif

typedef int64_t Timestamp; // 64bit

typedef int32_t TernaryInt32[3]; // 96bit

typedef uint8_t DroneStatus; // 3bit

#define DRONE_STATUS_UNKNOWN 0
#define DRONE_STATUS_STANDBY 1
#define DRONE_STATUS_RISING 2
#define DRONE_STATUS_LANDING 3
#define DRONE_STATUS_FLYING 4

typedef uint8_t PropellerStatus; // 2bit

#define PROPELLER_STATUS_UNKNOWN 0
#define PROPELLER_STATUS_IDLE 1
#define PROPELLER_STATUS_ROTATING 2

typedef uint8_t RotatingDirection; // 2bit

#define ROTATING_DIRECTION_UNKNOWN 0
#define ROTATING_DIRECTION_CLOCK_WISE 1
#define ROTATING_DIRECTION_ANTI_CLOCK_WISE 2

typedef uint8_t PowerStatus; // 2bit

#define POWER_STATUS_UNKNOWN 0
#define POWER_STATUS_OFF 1
#define POWER_STATUS_ON 2

typedef uint8_t LandingGearStatus; // 2bit

#define LANDING_GEAR_STATUS_UNKNOWN 0
#define LANDING_GEAR_STATUS_UNFOLDED 1
#define LANDING_GEAR_STATUS_FOLDED 2

// Number of bytes to encode struct Propeller
#define BYTES_LENGTH_PROPELLER 2

struct Propeller {
    uint8_t id; // 8bit
    PropellerStatus status; // 2bit
    RotatingDirection direction; // 2bit
};

// Number of bytes to encode struct Power
#define BYTES_LENGTH_POWER 2

struct Power {
    uint8_t battery; // 8bit
    PowerStatus status; // 2bit
    bool is_charging; // 1bit
};

// Number of bytes to encode struct Network
#define BYTES_LENGTH_NETWORK 9

struct Network {
    // Degree of signal, between 1~10.
    uint8_t signal; // 4bit
    // The timestamp of the last time received heartbeat packet.
    Timestamp heartbeat_at; // 64bit
};

// Number of bytes to encode struct LandingGear
#define BYTES_LENGTH_LANDING_GEAR 1

struct LandingGear {
    LandingGearStatus status; // 2bit
};

// Number of bytes to encode struct Position
#define BYTES_LENGTH_POSITION 12

struct Position {
    uint32_t latitude; // 32bit
    uint32_t longitude; // 32bit
    uint32_t altitude; // 32bit
};

// Number of bytes to encode struct Pose
#define BYTES_LENGTH_POSE 12

// Pose in flight. https://en.wikipedia.org/wiki/Aircraft_principal_axes
struct Pose {
    int32_t yaw; // 32bit
    int32_t pitch; // 32bit
    int32_t roll; // 32bit
};

// Number of bytes to encode struct Flight
#define BYTES_LENGTH_FLIGHT 36

struct Flight {
    struct Pose pose; // 96bit
    // Velocity at X, Y, Z axis.
    TernaryInt32 velocity; // 96bit
    // Acceleration at X, Y, Z axis.
    TernaryInt32 acceleration; // 96bit
};

// Number of bytes to encode struct Drone
#define BYTES_LENGTH_DRONE 65

struct Drone {
    DroneStatus status; // 3bit
    struct Position position; // 96bit
    struct Flight flight; // 288bit
    struct Propeller propellers[4]; // 48bit
    struct Power power; // 11bit
    struct Network network; // 68bit
    struct LandingGear landing_gear; // 2bit
};

// Encode struct Drone to given buffer s.
int EncodeDrone(struct Drone *m, unsigned char *s);
// Decode struct Drone from given buffer s.
int DecodeDrone(struct Drone *m, unsigned char *s);

#if defined(__cplusplus)
}
#endif

#endif
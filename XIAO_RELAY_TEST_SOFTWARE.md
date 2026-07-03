# XIAO RP2040 Relay Test Software

This document summarizes the test firmware used to program and validate the Seeed XIAO RP2040 relay-control path.

## Hardware Context

- Detected board: `Seeed XIAO RP2040`
- Typical Linux serial port: `/dev/ttyACM0`
- Relay-control pin: `D2 / GPIO28`
- Target logic wiring:

```text
XIAO D2 / GPIO28 -> R1 1k -> 2N3904 base
XIAO GND -> 2N3904 emitter
2N3904 collector -> relay coil A2
XIAO VBUS_5V -> relay coil A1
D1 flyback diode across the relay coil, diode stripe toward +5V/A1
```

Keep mains voltage disconnected during all USB and firmware tests.

## Tooling

The test was built with `arduino-cli` and the Earle Philhower RP2040 Arduino core:

```text
https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
```

Target board:

```text
Seeed XIAO RP2040
FQBN: rp2040:rp2040:seeed_xiao_rp2040
```

Example setup:

```bash
arduino-cli config init --overwrite --additional-urls https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
arduino-cli core update-index
arduino-cli core install rp2040:rp2040
```

## Firmware Behavior

Firmware path:

```text
sketch_relay_test/sketch_relay_test.ino
```

Serial commands:

```text
on     -> relay ON for 5 seconds, then automatic OFF
pulse  -> same as on
off    -> immediate relay OFF
status -> print current relay state
```

The relay is forced OFF at boot:

```cpp
pinMode(RELAY_PIN, OUTPUT);
digitalWrite(RELAY_PIN, LOW);
```

Important constants:

```cpp
constexpr uint8_t RELAY_PIN = D2;
constexpr unsigned long RUN_MS = 5000;
constexpr bool AUTO_START_ON_BOOT = false;
```

## Compile

```bash
arduino-cli compile --fqbn rp2040:rp2040:seeed_xiao_rp2040 sketch_relay_test
```

Observed result:

```text
Sketch uses 54660 bytes (2%) of program storage space.
Global variables use 8944 bytes (3%) of dynamic memory.
```

## Upload

Automatic upload example:

```bash
arduino-cli upload -p /dev/ttyACM0 --fqbn rp2040:rp2040:seeed_xiao_rp2040 sketch_relay_test
```

Manual UF2 flow:

```bash
arduino-cli compile --fqbn rp2040:rp2040:seeed_xiao_rp2040 --output-dir build_relay_test sketch_relay_test
cp build_relay_test/sketch_relay_test.ino.uf2 /run/media/<user>/RPI-RP2/
sync
```

To enter bootloader mode on the XIAO RP2040, hold BOOT, press RESET, then release BOOT.

## Serial Tests

Configure the serial port:

```bash
stty -F /dev/ttyACM0 115200 raw -echo
```

Check status:

```bash
printf 'status\n' > /dev/ttyACM0
```

Expected response:

```text
STATUS_OFF
```

Start a 5-second relay pulse:

```bash
printf 'on\n' > /dev/ttyACM0
```

Expected response:

```text
RELAY_ON
TIMER_5S_STARTED
RELAY_OFF
TIMER_DONE
```

## Bench Validation

The final relay test should be performed with mains disconnected and USB only.

Recommended multimeter check:

```text
Continuity mode between relay contact 13 and 14.
Idle: no continuity.
Command on: continuity for about 5 seconds.
After timeout: no continuity.
```

## Safety Notes

- Never connect mains during USB tests unless the whole prototype has been isolated and independently reviewed.
- Never connect USB to a computer if there is any possible accidental connection between mains and low-voltage circuitry.
- Before USB testing, verify there is no continuity between mains `L/N` and logic `5V/GND`.
- This test firmware is not a final redundant safety timer for a UVB device.

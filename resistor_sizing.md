# SSR Input Resistor Sizing

Date: 2026-05-07

This note is retained for the earlier SSR variant. The retained public schematic now uses the mechanical relay design, but the calculation remains useful historical context.

## Context

- Microcontroller: ESP32-WROOM, 3.3 V GPIO.
- SSR candidate: Panasonic AQH3213.
- Datasheet assumptions:
  - input LED forward voltage: approximately `Vf = 1.2 to 1.3 V`;
  - maximum trigger LED current: `Ift_max = 10 mA`.

Goal: choose a series resistor that can trigger the SSR from a 3.3 V GPIO.

## Formula

SSR LED current:

`I = (Vgpio - Vf) / R`

with `Vgpio = 3.3 V`.

## Candidate Values

### R = 220 ohms

- With `Vf = 1.2 V`: `I = (3.3 - 1.2) / 220 = 9.55 mA`
- With `Vf = 1.3 V`: `I = (3.3 - 1.3) / 220 = 9.09 mA`

Conclusion: borderline against `Ift_max = 10 mA`.

### R = 180 ohms

- With `Vf = 1.2 V`: `I = 11.67 mA`
- With `Vf = 1.3 V`: `I = 11.11 mA`

Conclusion: better trigger margin while still keeping GPIO current reasonable.

### R = 150 ohms

- With `Vf = 1.2 V`: `I = 14.00 mA`
- With `Vf = 1.3 V`: `I = 13.33 mA`

Conclusion: more margin, but higher GPIO load.

## Resistor Dissipation

`P = I^2 * R`

For `R = 180 ohms`, at roughly 11.1 to 11.7 mA:

- `P_min ~ 0.022 W`
- `P_max ~ 0.025 W`

A 1/4 W resistor is sufficient.

## Historical Recommendation

- Recommended SSR input resistor: **180 ohms**.
- Use one series resistor per SSR input.
- Keep firmware logic explicit, with the output OFF at boot.
- A transistor or MOSFET driver can be added later for stronger logic isolation and drive margin.

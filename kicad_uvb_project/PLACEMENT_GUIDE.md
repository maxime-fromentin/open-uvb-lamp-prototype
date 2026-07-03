# Placement Guide

## Board zoning
- Keep the AC power path (`J1`, `F1`, `SW1`, `K1`, `J2`) clearly separated from low-voltage logic (`U2`, `Q1`, `R1`, control headers).
- Keep a no-man's boundary corridor (at least 6 to 8 mm) between AC and LV zones.

## Suggested origin and mechanical coordinates
- Board origin: bottom-left corner
- `J1` (IEC C14 or AC terminal): near left edge center
- `F1`: between `J1` and `SW1`
- `SW1`: near top-left edge for front-panel access
- `K1`: center-left, with safe separation from logic wiring
- `J2` (to ballast): left-bottom edge or left-mid edge
- `U1` (AC-DC module): right of AC zone boundary, top-right quadrant
- `U2` (XIAO header area): mid-right quadrant
- `Q1` and `R1`: near the relay coil control path on the low-voltage side

## Routing priorities
- Route AC first (short, wide traces).
- Route relay contact wiring on Live with clear spacing.
- Route LV command lines away from AC paths.
- Create dedicated netclass for AC (`wider traces`, `higher clearance`).

## Track and clearance starting points
- LV logic traces: 0.25 to 0.30 mm
- LV power traces (5V/GND): 0.50 mm
- AC traces: 1.2 mm minimum recommended start
- Clearance LV-to-AC: target 3.0 mm minimum, prefer more when possible

## Final checks
- ERC review in schematic editor
- DRC review in PCB editor if a PCB is produced
- 3D viewer: connector accessibility and vertical component collisions
- Verify switch orientation and connector mating direction

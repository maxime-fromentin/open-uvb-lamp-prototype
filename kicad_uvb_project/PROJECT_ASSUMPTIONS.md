# UVB Controller - Default Assumptions

- Input mains: `120 VAC / 60 Hz`
- AC wiring and low-voltage control wiring must be physically separated.
- Controller: `Seeed XIAO RP2040`.
- AC-DC supply: isolated AC-to-5V module or enclosed supply suitable for the enclosure.
- AC switching: mechanical relay on Live (L), driven through a transistor stage.
- External power connector:
- Cable: `NEMA 5-15P to IEC C13`.
- Appliance inlet or panel connector: `IEC C14` or equivalent rated inlet.
- UV lamp path:
- electromagnetic ballast;
- G23 socket;
- Philips PL-S 9W/01/2P lamp.

## Safety Notes

- Keep AC and low-voltage wiring separated.
- Add a fuse on AC Live before the downstream switch/load path.
- Bond accessible metal parts to protective earth where applicable.
- Place AC wiring away from MCU headers and USB access.
- Final validation should include creepage, clearance, strain relief, enclosure, grounding, thermal, and local-code review.

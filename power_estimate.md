# Power and Current Estimate

## Estimated Power

- Lamp + ballast: roughly 12 to 18 W, including ballast losses.
- Fan: roughly 1 to 15 W depending on the selected fan type.
- Control electronics: roughly 1 to 4 W.
- Typical total: roughly 14 to 37 W.

## Mains Current at 120 VAC

Using `I = P / V`:

- Low estimate: `14 W / 120 V = 0.117 A`
- High estimate: `37 W / 120 V = 0.308 A`

Use these values only as first-order sizing estimates. Actual current, inrush, ballast behavior, and thermal behavior must be measured on the assembled prototype.

## Relay and Control Note

The low-voltage XIAO output only controls the relay driver transistor. It does not power the AC load directly.

The relay contact, wiring, fuse, switch, inlet, ballast, and all mains clearances must be selected and reviewed for the real AC load, including inrush current.

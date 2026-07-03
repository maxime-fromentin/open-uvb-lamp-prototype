# Project Concept

The goal is to document a DIY narrowband UVB lamp prototype based on a Philips PL-S 9W/01/2P lamp. The design aims to capture practical FreeCAD files, wiring, BOM, safety, and test notes so that another technically competent person can understand the build.

This is not a finished medical device. The main value of the repository is transparency: mechanical files, wiring intent, BOM choices, test firmware, and safety assumptions are kept together.

The project is documented in a psoriasis-related prototyping context because narrowband UVB is commonly associated with clinical phototherapy. This repository does not provide a treatment protocol and does not claim medical efficacy.

## Target Lamp

- Philips UV-B Narrowband PL-S 9W/01/2P.
- G23 two-pin base.
- The lamp emits around 360 degrees, so a reflector is needed to avoid wasting much of the output.
- Internal wiring should use appropriately rated wire, such as AWG 18 or equivalent where suitable.

## Mechanical Ideas

- UV-opaque enclosure.
- Polished aluminum reflector.
- Light-trap ventilation path to block direct UV leakage while allowing airflow.
- Heat-resistant mounting near the lamp holder; PLA may soften near warm components.
- Metal or wood isolation plate around the lamp socket if needed.

## Controls and Safety Features

Potential features to document or add:

- redundant timer;
- visual distance guide, such as two angled lasers or a removable distance gauge;
- active cooling;
- red LCD display for readability through amber protective goggles;
- calibration or validation using a UVB meter;
- protective eyewear certified for UV exposure;
- skin shielding for areas that should not be exposed.

## Power and Ballast

The retained design uses a mechanical relay and an electromagnetic ballast approach. A conventional ferromagnetic ballast can be more tolerant in this kind of prototype than some compact electronic switching approaches, but every selected part still needs independent review.

Add a fuse holder on the live input conductor. A GFCI-protected outlet or power strip is strongly recommended for bench testing.

## Validation Ideas

- Use a spectroradiometer capable of measuring roughly 250-400 nm to verify the spectral output.
- Use a UVB radiometer, such as a Solarmeter-style meter, to measure irradiance in mW/cm2 at the actual working distance.
- Compare measurements against a known commercial phototherapy device only if the same measurement setup and distance are used.
- Use a thermal camera or contact temperature measurements to verify cooling.

## Risk Example

If the expected output is 3 mW/cm2 but the real build produces 6 mW/cm2 at the same distance, a two-minute exposure gives twice the intended dose. This is why measured output matters more than design assumptions.

# Publishing Checklist

Use this before making the GitHub repository public.

## Must do

- Rotate any Digi-Key/API credentials that were ever stored in local notes.
- Confirm `Bom.md` contains no API credentials.
- Confirm no personal paths remain, for example `/home/<name>`, `/run/media/<name>` or local mount paths.
- Confirm no personal marketplace links, private quote PDFs, addresses, phone numbers or emails are included.
- Confirm `datasheet/Quote_*.pdf` is not published unless manually reviewed.
- Publish only the retained schematic PDF: `output/pdf/uvb_controller_mechanical_relay.pdf`.
- Keep `uvb_controller_mechanical_relay.kicad_sch` as the active schematic.
- Keep archived schematics clearly marked as historical if they are published.

## Recommended repository files

- `README.md`
- `LICENSE.md`
- `.gitignore`
- `SAFETY.md`
- `Concept.md`
- `Bom.md`
- `digikey_bom_clean.csv`
- `kicad_uvb_project/BOM_mechanical_relay.csv`
- `kicad_uvb_project/PLACEMENT_GUIDE.md`
- `kicad_uvb_project/PROJECT_ASSUMPTIONS.md`
- `kicad_uvb_project/uvb_controller/uvb_controller.kicad_pro`
- `kicad_uvb_project/uvb_controller/uvb_controller_mechanical_relay.kicad_sch`
- `kicad_uvb_project/uvb_controller/uvb_custom.kicad_sym`
- `output/pdf/uvb_controller_mechanical_relay.pdf`
- `CAD/`
- `sketch_relay_test/sketch_relay_test.ino`
- `XIAO_RELAY_TEST_SOFTWARE.md`
- `docs/media/demo.gif` once available

## Do not publish by default

- `.tools/`
- `.arduino15/`
- `.code/`, `.agents/`, `.codex/`
- `build_relay_test/`
- `kicad_uvb_project/uvb_controller/fp-info-cache`
- `kicad_uvb_project/uvb_controller/uvb_controller-backups/`
- `datasheet/Quote_*.pdf`
- downloaded vendor datasheets unless their redistribution terms are clear

## Final safety wording

Make sure the README clearly states that the KiCad schematic is a wiring and soldering aid, not a certified electrical design, medical device validation, or complete numerical simulation.

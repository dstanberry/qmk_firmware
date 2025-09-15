# Keyboard Diagrams

## Usage

Install utility package with `pip install keymap-drawer`. Then run the following
command to generate a keyboard diagram:

```bash
qmk c2json ../keyboards/handwired/dactyl_manuform/5x7/keymaps/neon/keymap.c |\
  keymap parse -l Base sFN bFN HW -c 10 -q - >dactyl_manuform_keymap.yaml
keymap -c config.yaml draw -j dactyl_manuform_keymap.json dactyl_manuform_keymap.yaml >dactyl_manuform.svg
```

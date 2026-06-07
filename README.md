# Genpass 🕵️‍♂️

A simple but efficient password generator optimized for cryptographic security. Especially useful if you use KeePass or similar password managers.

## Features

- **Cryptographically secure**: Uses OS-level random number generators (`getrandom()` on Linux, `arc4random()` on macOS, `CryptGenRandom()` on Windows)
- **Fast**: Generates passwords on-the-fly
- **Clipboard support**: Automatically copies to clipboard (X11, Wayland, macOS, Windows)
- **Safe input validation**: Proper error handling and bounds checking
- **No dependencies**: Pure C with system-level APIs
- **Cross-platform**: Linux, macOS, Windows

## Installation

### From Source

```sh
git clone https://github.com/yourusername/generador-password
cd generador-password
make
sudo make install           # Install to /usr/local/bin
# or
make install PREFIX=$HOME   # Install to ~/bin
```

### Build Options

```sh
make clean                  # Remove build artifacts
make                        # Compile with optimizations (-O2)
make uninstall              # Remove installed binary
```

## Usage

```sh
./genpass <length>          # Generate password of specified length
```

### Options

```sh
genpass --help              # Show help message
genpass --version           # Show version information
```

### Examples

```sh
genpass 12                  # Generate 12-character password
genpass 32                  # Generate strong 32-character password
genpass 8                   # Generate minimum 8-character password
```

### Requirements

- **Minimum length**: 8 characters
- **Maximum length**: 10,000 characters

### Character Sets

Passwords can contain:
- **Uppercase letters**: A-Z
- **Lowercase letters**: a-z
- **Numbers**: 0-9
- **Symbols**: `!@#$%^&*()_+-=[]{}|;:',.<>/?`

## Clipboard Support

The tool automatically detects your display environment:

| Platform | Method | Required |
|----------|--------|----------|
| **Linux (Wayland)** | `wl-copy` | ✓ Install with `pacman -S wl-clipboard` |
| **Linux (X11)** | `xclip` | ✓ Install with `pacman -S xclip` |
| **macOS** | `pbcopy` | ✓ Built-in |
| **Windows** | WinAPI | ✓ Built-in |

If clipboard is not available, an error will be shown but the password will still be displayed.

## Security Notes

- Uses cryptographically secure random number generators
- No predictable seeds (unlike `rand()`)
- Input validation prevents buffer overflows
- Proper memory management with dynamic allocation

## Troubleshooting

### "Error: no command wl-copy (Wayland)" or "no command xclip (X11)"

Install the missing clipboard tool:
```bash
# Arch/Artix
sudo pacman -S wl-clipboard   # Wayland
sudo pacman -S xclip          # X11

# Ubuntu/Debian
sudo apt install wl-clipboard  # Wayland
sudo apt install xclip         # X11

# Fedora
sudo dnf install wl-clipboard  # Wayland
sudo dnf install xclip         # X11

# macOS (should be built-in)
which pbcopy
```

### Or install via AUR
```bash
paru -S genpass
# or
yay -S genpass 
```

### "Error: no display environment detected"

You're not in a graphical environment. Run from a terminal in X11 or Wayland, or use SSH with X11 forwarding.

### File Structure

```
src/
├── main.c              # Entry point and argument parsing
├── genpass.c           # Password generation logic
├── random.c            # Cryptographic random number generation
├── copyclip.c          # Clipboard operations
├── strings.c           # Character sets configuration
└── includes/
    ├── genpass.h
    ├── random.h
    ├── copyclip.h
    ├── strings.h
    ├── colors.h
    └── os_detect.h
```

## License

This program is licensed under the **GNU General Public License v3.0** (GPLv3). See the [LICENSE](LICENSE) file for details.

## Author

Written by **Jakepys Perdomo**  
Contact: j4kyjak3@protonmail.com

---

*"There are no better things than learning and realizing you don't know, and never stopping doing it..." — Jpys*

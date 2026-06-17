# Custom Unix-like Shell

A command-line shell built from scratch in C, modeled on a Unix/bash-style CUI experience. Implements its own kernel-style command dispatcher, multi-user authentication, and 20+ built-in commands — no external shell library used.

---

## Highlights

- **Kernel-dispatcher architecture** — a central `kernel()` function tokenizes input and routes each command to its own handler function, mirroring how a real OS command interpreter separates parsing from execution.
- **Multi-user authentication** — login system backed by file-based credential storage (`uid.dtls`), with password masking at the terminal and a root-directory guard that blocks navigation above the user's home directory.
- **Custom string tokenizer** — command parsing is handled by a hand-written tokenizer (`command()` / `trim1()`) rather than `strtok`, splitting the command name from its arguments.
- **Terminal styling via ANSI escape codes** — `bold`, `italic`, `undrln` (underline), `clr` (font color), and `bkclr` (background color) commands manipulate terminal appearance directly through escape sequences.
- **20+ built-in commands** spanning file/directory operations, terminal control, and session management.

---

## Command reference

| Command | Function |
|---|---|
| `help` | Display all commands and their functions |
| `exit` | Exit the terminal |
| `vi` | Create a file, or write to / modify an existing file |
| `mkdir` | Create a new directory |
| `cat` | Display the contents of a file |
| `rmdir` | Remove a directory |
| `rm` | Remove a file |
| `ct` | Show the current time |
| `pwd` | Print the working directory |
| `cd` | Change directory |
| `echo` | Print a message |
| `rnm` | Rename a file or directory |
| `clear` | Clear the terminal |
| `mv` | Move a file or directory |
| `ls` | List files and directories in the current directory |
| `touch` | Create an empty file |
| `bkclr` | Change terminal background color |
| `clr` | Change terminal font color |
| `bold` | Set font to bold |
| `italic` | Set font to italic |
| `undrln` | Underline the font |
| `smpl` | Reset all font styling to default |

---

## Architecture

```
shell.c            Entry point — handles login, then loops reading and dispatching commands
kernel.h            Command dispatcher: tokenizes input and routes to the matching handler
handler.h           Implementations for terminal styling and session commands
check.h             Authentication logic — validates user ID against uid.dtls
about.dtls          Welcome/about text shown on login
help.dtls           Command reference text shown by the `help` command
```

The dispatcher pattern in `kernel.h` is intentionally close to how a real shell separates "what command was typed" from "what that command does" — each built-in is its own function, and adding a new command means adding one more `else if` branch and handler, rather than threading logic through a single monolithic parser.

---

## Building from source

Requires a C compiler with `conio.h` and `dirent.h` support (e.g. MinGW/GCC on Windows, or a POSIX-compatible substitute on Linux).

```bash
gcc shell.c -o shell
./shell
```

On first run, type `logup` at the user ID prompt to create a new account; on subsequent runs, log in with the credentials you set.

---

## Limitations

- Built and tested primarily on Windows (uses `conio.h` for input handling).
- Credentials are stored in plain text in `uid.dtls` — this is an educational shell, not a production authentication system.
- No piping, redirection, or background process support — each command runs synchronously to completion.

---

## License

This project is open source and available under the MIT License.

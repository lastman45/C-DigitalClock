# DigitalClock

A lightweight, terminal-based digital clock written in C that displays a live, updating clock in the console — with support for custom start times and automatic day rollover.

---

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Requirements](#requirements)
- [Getting Started](#getting-started)
  - [Compilation](#compilation)
  - [Running the Program](#running-the-program)
- [Usage](#usage)
  - [Input Format](#input-format)
  - [Example Session](#example-session)
- [How It Works](#how-it-works)
- [Limitations](#limitations)
- [Potential Improvements](#potential-improvements)
- [License](#license)

---

## Overview

`DigitalClock.c` is a simple C program that simulates a real-time digital clock in the terminal. The user provides an initial time in `HH:MM:SS` format, and the clock begins ticking from that point, updating every second. It handles minute, hour, and day rollovers automatically.

---

## Features

- **Custom start time** — set the clock to any valid 24-hour time
- **Real-time updates** — the display refreshes every second using `Sleep()`
- **Input validation** — rejects invalid hours, minutes, or seconds before starting
- **Day rollover** — when the clock passes `23:59:59`, it resets to `00:00:00` and announces a new day
- **Clean display** — screen is cleared between each tick for a clean, in-place clock effect
- **Zero-padded output** — always displays time in `HH:MM:SS` format (e.g., `09:04:02`)

---

## Requirements

| Requirement | Details |
|---|---|
| **Operating System** | Windows (uses `windows.h` for `Sleep()` and `system("cls")`) |
| **Compiler** | GCC (MinGW), MSVC, or any C99-compatible compiler on Windows |
| **C Standard** | C99 or later |

> ⚠️ **Note:** This program is **Windows-only** due to its use of `<windows.h>` for the `Sleep()` function and `system("cls")` for clearing the screen. See [Potential Improvements](#potential-improvements) for cross-platform alternatives.

---

## Getting Started

### Compilation

Using **GCC (MinGW)** on Windows:

```bash
gcc DigitalClock.c -o DigitalClock.exe
```

Using **MSVC** (from a Developer Command Prompt):

```bash
cl DigitalClock.c
```

### Running the Program

```bash
./DigitalClock.exe
```

Or simply double-click `DigitalClock.exe` in File Explorer (though a terminal window is recommended for the best experience).

---

## Usage

### Input Format

When prompted, enter the starting time in 24-hour `HH:MM:SS` format:

```
Enter time in HH:MM:SS format
```

**Valid ranges:**
- `HH` — hours: `00` to `23`
- `MM` — minutes: `00` to `59`
- `SS` — seconds: `00` to `59`

If the input falls outside these ranges, the program prints an error and exits:

```
Invalid time format
```

### Example Session

```
Enter time in HH:MM:SS format
22:59:58

Clock
22:59:59

Clock
23:00:00

...

Clock
00:00:00

New Day Started
```

---

## How It Works

The program follows a straightforward tick-based loop:

1. **Input** — the user enters an initial time, which is parsed and validated.
2. **Tick** — every iteration of the `while(1)` loop increments `seconds` by 1.
3. **Overflow handling** — if seconds exceed 59, minutes are incremented and seconds reset; similarly for minutes and hours.
4. **Day rollover** — if hours exceed 23, they reset to 0 and a "New Day Started" message is printed.
5. **Display** — the updated time is printed to the console in `HH:MM:SS` format.
6. **Sleep** — the program pauses for 1000 milliseconds (1 second) via `Sleep(d)`.
7. **Clear** — `system("cls")` wipes the screen before the next tick, creating an in-place update effect.

```
Start
  │
  ▼
Read & validate HH:MM:SS
  │
  ▼
┌─────────────────────────────┐
│  seconds++                  │
│  handle minute/hour rollover│
│  print time                 │
│  Sleep(1000ms)              │
│  clear screen               │
└────────────┬────────────────┘
             │ loop forever
             ▼
```

---

## Limitations

| Limitation | Description |
|---|---|
| **Windows-only** | Uses `<windows.h>` (`Sleep`) and `system("cls")`, which are not available on Linux/macOS |
| **No real system time sync** | The clock starts from user input and is not synced to the actual system clock |
| **No pause/stop** | The only way to stop the clock is to close the terminal or press `Ctrl+C` |
| **Drift potential** | Execution time of the loop itself is not accounted for, so the clock may drift slightly over long periods |
| **Single-threaded** | Display and timing are handled in the same thread, which can cause minor inaccuracies |

---

## Potential Improvements

- **Cross-platform support** — replace `Sleep()` with `usleep()` or `nanosleep()` (POSIX), and `system("cls")` with `system("clear")` or ANSI escape codes, and conditionally compile based on the OS
- **Sync to system time** — use `time()` and `localtime()` from `<time.h>` to read the real system clock instead of relying on user input
- **AM/PM mode** — add a 12-hour display option with AM/PM suffix
- **Graceful exit** — handle `SIGINT` (`Ctrl+C`) for a clean shutdown message
- **Accurate tick timing** — measure loop execution time and subtract it from the sleep duration to reduce drift
- **Color output** — use ANSI escape codes or the Windows Console API to add color to the display

---

## License

This project is provided as-is for educational purposes. Feel free to use, modify, and distribute it freely.

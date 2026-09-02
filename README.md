# 🎸 FretLab for Flipper Zero

FretLab is a guitar utility toolkit built for the Flipper Zero.

The goal is to turn the Flipper Zero into a pocket-sized companion for guitar practice, tuning, timing, ear training, and music theory.

## 🎵 Planned Features

### Version 0.1
- 🎸 Guitar tuning reference tones
- ⏱ Metronome
- 👆 Tap Tempo
- 🎚 Adjustable BPM

### Future Features
- Alternate guitar tunings
- Chord library
- Chord diagrams
- Guitar scales
- Scale finder
- Interval trainer
- Ear-training games
- Practice timer
- Random practice generator
- Saved practice settings
- Song BPM/key notes
- SD card storage

## 🎸 Standard Guitar Tuning

| String | Note | Frequency |
|-------|------|-----------|
| 6 | E2 | 82.41 Hz |
| 5 | A2 | 110.00 Hz |
| 4 | D3 | 146.83 Hz |
| 3 | G3 | 196.00 Hz |
| 2 | B3 | 246.94 Hz |
| 1 | E4 | 329.63 Hz |

## 🔧 Project Status

FretLab is currently under development.

Current target:

**FretLab v0.1**

The first working version will contain:

1. Tuning reference tones
2. Metronome
3. Tap Tempo

## 🐬 Hardware

- Flipper Zero
- microSD card

Future versions may support external GPIO hardware for additional guitar-related features.

## ⚠️ Guitar Input

The initial tuner is a reference-tone tuner. The Flipper generates the correct pitch and the guitarist tunes their string to match it.

A future version may use an external GPIO audio interface to allow FretLab to analyze the guitar signal directly.

Do not connect a guitar pickup or amplified audio signal directly to the Flipper Zero GPIO pins.

## 🛠 Built With

- C
- Flipper Zero SDK
- Flipper Application Package (.fap)

## 📜 License

License information will be added as the project develops.

---

Made for guitarists who want to get a little more out of their Flipper Zero. 🎸🐬

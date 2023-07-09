# Antman

lossless (un)compress files

## Installation

- install deps:
    - libc
    - cc (gcc)
    - make

```bash
git clone https://github.com/Saverio976/Antman.git
cd Antman
make
```

## Usage

### Compress

```bash
./antman/antman ./path/to/file 1 > ./file_compressed
```

### Uncompress

```bash
./giantman/giantman ./path/to/file 1 > ./file_uncompressed
```

## Performance

*measured with `make tests_run`*

- HTML files: `-33%` to the original file size
- PPM files: `-66%` to the original file size
- TXT and LYR files: `-21%` to the original file size

## Contributors

- [SimonVermeulen](https://github.com/SimonVermeulen)
- [Xavier Mitault](https://github.com/Saverio976)

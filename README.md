<div align = "center">

<h1><a href="https://2kabhishek.github.io/pgm-resize">PGM-Resize</a></h1>

<a href="https://github.com/2KAbhishek/PGM-Resize/blob/main/LICENSE">
<img alt="License" src="https://img.shields.io/github/license/2kabhishek/PGM-Resize?style=flat&color=eee&label="> </a>

<a href="https://github.com/2KAbhishek/PGM-Resize/graphs/contributors">
<img alt="People" src="https://img.shields.io/github/contributors/2kabhishek/PGM-Resize?style=flat&color=ffaaf2&label=People"> </a>

<a href="https://github.com/2KAbhishek/PGM-Resize/stargazers">
<img alt="Stars" src="https://img.shields.io/github/stars/2kabhishek/PGM-Resize?style=flat&color=98c379&label=Stars"></a>

<a href="https://github.com/2KAbhishek/PGM-Resize/network/members">
<img alt="Forks" src="https://img.shields.io/github/forks/2kabhishek/PGM-Resize?style=flat&color=66a8e0&label=Forks"> </a>

<a href="https://github.com/2KAbhishek/PGM-Resize/watchers">
<img alt="Watches" src="https://img.shields.io/github/watchers/2kabhishek/PGM-Resize?style=flat&color=f5d08b&label=Watches"> </a>

<a href="https://github.com/2KAbhishek/PGM-Resize/pulse">
<img alt="Last Updated" src="https://img.shields.io/github/last-commit/2kabhishek/PGM-Resize?style=flat&color=e06c75&label="> </a>

<h3>For your PGM resizng needs 🖼⚒️</h3>

</div>

## What is this

pgm-resize is a tool that allows you to quickly resize [.pgm](http://davis.lbl.gov/Manuals/NETPBM/doc/pgm.html) images.

## Inspiration

Needed a thumbnail generator for PGM(P2 type) images, all available tools were resizing it to P5 type, then decided to make this.

## Prerequisites

Before you begin, ensure you have met the following requirements:

- You have installed the latest version of `gcc`

## Getting pgm-resize

To get pgm-resize, follow these steps:

```bash
git clone https://github.com/2kabhishek/pgm-resize
cd pgm-resize
make
```

## Using pgm-resize

```bash
USAGE:
    pgm-resize path/to/image.pgm [WIDTH]

OPTIONS:
    WIDTH - Provide a custom output image width
            Height is proportionately adjusted
            (Halves original image width by default)

OUTPUT:
    The resized image will be placed in he same path
    as the original image with a '-resize' added

Example:

./pgm-resize images/apollonian.pgm 240
# output: images/apollonian-resize.pgm with 240 width
./pgm-resize images/venus.pgm
# output: images/venus-resizw.pgm with width halved
```

For alternate implementation with pipe operations, see [alt branch](https://github.com/2kabhishek/pgm-resize/tree/alt).

## How it was built

pgm-resize was built using `neovim`, 'gcc', 'make'

## Challenges faced

Faced some segfaults, `gcc -g` and `gdb` came to rescue

## What I learned

- Learned about the `.pgm` image format
- Worked with file IO in c
- Did some math tricks for resizing the images
  (Used mean to combine multiple pixels into one)

Hit the ⭐ button if you found this useful.

## More Info

<div align="center">

<a href="https://github.com/2KAbhishek/pgm-resize">Source</a> | <a href="https://2kabhishek.github.io/pgm-resize">Website</a>

</div>

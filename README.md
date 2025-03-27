# Fixer - a plugin to fix glitches and repair GEGL pipelines 

Plugin attempts to fix glitches in GIMP 3 while non-destructively editing

![image](https://github.com/user-attachments/assets/5c1f53dd-d0fb-4792-8bee-1e00a36bd558)


![image](https://github.com/user-attachments/assets/6b1b08c0-6cd1-4068-9494-3c0742a7eae3)

![image](https://github.com/user-attachments/assets/1f548d3c-1834-4f0b-b4d2-f5f6131c94d8)


## Directory to put Binaries (They do NOT go in the normal plugins folder)

**Windows**

 C:\Users\(USERNAME)\AppData\Local\gegl-0.4\plug-ins

 **Linux**

~/.local/share/gegl-0.4/plug-ins

 **Linux (Flatpak includes Chromebook)**

~/.var/app/org.gimp.GIMP/data/gegl-0.4/plug-ins

Then Restart Gimp and go to "GEGL Operation" and look for "fixer". Gimp 2.99.16+ users will find the filter in Filters>Generic>Repair GEGL pipeline, where as 2.10 plugins will only be found in the drop down list.


## Compiling and Installing

### Linux

To compile and install you will need the GEGL header files (`libgegl-dev` on
Debian based distributions or `gegl` on Arch Linux) and meson (`meson` on
most distributions).

```bash
meson setup --buildtype=release build
ninja -C build

```

### Windows

The easiest way to compile this project on Windows is by using msys2.  Download
and install it from here: https://www.msys2.org/

Open a msys2 terminal with `C:\msys64\mingw64.exe`.  Run the following to
install required build dependencies:

```bash
pacman --noconfirm -S base-devel mingw-w64-x86_64-toolchain mingw-w64-x86_64-meson mingw-w64-x86_64-gegl
```

Then build the same way you would on Linux:

```bash
meson setup --buildtype=release build
ninja -C build
```


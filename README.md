# Chocolate Duke3D

Chocolate Duke Nukem 3D is the equivalent of [Chocolate Doom](http://www.chocolate-doom.org/wiki/index.php/Chocolate_Doom).

A **port** that:

1. Remains as faithful as possible to the original source code.
2. Portable and compiling in one click on Windows, OS X and Linux.
3. Aimed at education, with lots of comments and documentation added in order to help programmers to understand and learn.

<img src="screenshot0.png" width="95%"></img>

## Belgian Chocolate Duke3D

This is a fork of Fabien Sanglard's project [Chocolate Duke Nukem 3D](https://github.com/fabiensanglard/chocolate_duke3D). As of January 2020, Fabien has archived his git repository.

After reading both Fabien Sanglard's Game Engine Black Books on [Wolfenstein 3D](https://github.com/fabiensanglard/gebbwolf3) and [Doom](https://github.com/fabiensanglard/gebbdoom), I slowly got curious on how Duke 3D would perform on a modern computer (an Intel Core i9-9900K) with a modern Operating System (Windows 10 and Ubuntu 18.04). After cloning his Chocolate Duke 3D git repository, I had to spend a bit of time getting the project up and running. While doing that, I've been keeping on adding some improvements.

* Ported to SDL2.
* Ported to vcpkg and CMake.
* Added continuous integration (via GitHub Actions).
* Added 64-bit support (savegames are compatible between 32-bit and 64-bit).

### Known Issues

* Engine: Leaning left/right falls back to low-res rendering.
* Engine: Minimap has rendering glitches when fully-textured (i.e. sprites).
* Engine: Pixel imprecision when rendering health/ammo numbers in the status bar, leaving ghost pixels.
* Game: Duke is always running, no matter whether SHIFT is pressed or not.

## Requirements

An original copy of [Duke Nukem 3D](https://3drealms.com/catalog/duke-nukem-3d_27/). Specifically the DUKE3D.GRP file from the original CD in binary working directory.

## Build

**Windows (Visual Studio 2019 x64 solution)** [![Windows CI Status](https://github.com/GPSnoopy/BelgianChocolateDuke3D/workflows/Windows%20CI/badge.svg)](https://github.com/GPSnoopy/BelgianChocolateDuke3D/actions?query=workflow%3A%22Windows+CI%22)
```
> vcpkg_windows.bat
> build_windows_x64.bat
```

**Linux (GCC Makefile)** [![Linux CI Status](https://github.com/GPSnoopy/BelgianChocolateDuke3D/workflows/Linux%20CI/badge.svg)](https://github.com/GPSnoopy/BelgianChocolateDuke3D/actions?query=workflow%3A%22Linux+CI%22)
```bash
> sudo apt-get install libenet-dev libsdl2-mixer-dev
> ./build_linux.sh
```
Here we do not use vcpkg but instead rely on the distro packages for ENet and SDL2. Unfortunately vcpkg SDL2 (and mixer) still depends on some development packages to be installed, and the MIDI subsystem is not correctly configured.

**MacOS**
_Not yet supported._

## Music (MIDI)

Depending on your operating system, your music experience and general MIDI play back will vary considerably. Independently, for a better Duke 3D music experience I recommend using [¥Weeds¥ General MIDI SoundFont v3.0](http://www.simpilot.net/~richnagel/#soundfonts).

**Windows**

Out of the box, MIDI music will play fine on Windows. By default, it will use [Microsoft GS Wavetable Synth](https://impossible-music.fandom.com/wiki/Microsoft_GS_Wavetable_Synth), which sounds surprisingly okay. However if you want to use another soundfont (such as the one above), install [OmniMIDI](https://officialblackmidi.fandom.com/wiki/OmniMIDI), load the soundfont and select the OmniMIDI mapper via `Tools -> ??? -> ???`.

**Linux**

Out of the box, you will not get any music unless you have a default soundfont installed (for example, the `fluid-soundfont-gm` package). Even then, it will likely sound pretty bad. To use another soundfont, you can use the following command.
```bash
> SDL_SOUNDFONTS=WeedsGM3.sf2 SDL_FORCE_SOUNDFONTS=1 ./ChocoDuke3D.64
```

**MacOs**
_Not yet supported._

## Contributors

* **Project Initiator:** [Fabien Sanglard](https://github.com/fabiensanglard)
* **Linux Integration:** [Juan Manuel Borges Caño](https://github.com/juanmabc)
* **64-bit Port:** [Rohit Nirmal](https://github.com/rohit-n)
* **64-bit Port:** [Jonathon Fowler] (https://github.com/jonof/jfduke3d)
* **Belgian Chocolate fork:** [Tanguy Fautre](https://github.com/GPSnoopy/)

## More Information

* **[Review of the Duke 3D source code](http://fabiensanglard.net/duke3d/)**
* [Simple DirectMedia Layer](https://wiki.libsdl.org/FrontPage), [SDL_Mixer](http://www.libsdl.org/projects/SDL_mixer/)
* [Duke Nukem 3D](https://3drealms.com/catalog/duke-nukem-3d_27/)

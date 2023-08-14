# Platinum Engine

## About

This is a (work-in-progress) upgrade to the game systems for US distributions of Pokemon Platinum.

### Project Goals

Since the project is still in-progress, it is more sensible to list out the goals for the project than a list of presently-implemented features.

* A completely revamped and upgraded Battle Engine sporting feature parity with Generation 8:
    * Hidden Abilities
    * Mega Evolution + Primal Reversion
    * Pokedex Expansion of all mons up through generation 8
    * Ability Expansion of all abilities up through generation 8
    * Updated effects for moves and abilities present in vanilla generation 4
* Configuration options and code to implement new functionality for battle systems, item systems, etc.
* Decompiled data files represented as easily-editable code structures.
* Support for enemy trainers with fully-customized competitive parties, including EV spreads, specific IV spreads, and explicit ability and nature specifications.

## Table of Contents

- [Platinum Engine](#platinum-engine)
  - [About](#about)
    - [Project Goals](#project-goals)
  - [Table of Contents](#table-of-contents)
  - [Setup Instructions](#setup-instructions)
    - [Windows](#windows)
    - [Mac OSX](#mac-osx)
    - [Linux](#linux)
  - [Build Instructions](#build-instructions)
  - [Credits](#credits)

## Setup Instructions

### Windows

1. Download and install the [Microsoft .NET Framework](https://dotnet.microsoft.com/en-us/download/dotnet-framework/net48).
   1. Choose the **Developer Pack** option.
   * If you have a different version of the .NET Framework already installed, then you may use the newest version which you have installed rather than the linked version.
2. Edit your environment variables.
   1. In the search bar in the Start Menu, search for "environment variables" and click on **Edit the system environment variables**. Wait for a new window to pop up titled **System Properties**.
   2. Click on **Environment Variables...** in the bottom right of the new window. Wait for a new window to pop up titled **Environment Variables**.
   3. In the lower half of the **Environment Variables** window, look for a variable called **Path** and highlight it.
   4. Click **Edit** on the lower half of the **Environment Variables** window. A third new window will open titled **Edit environment variable**.
   5. In this new window, press **New**, then **Browse...**.
   6. Navigate to **This PC** → **Local Disk** → **Windows** → **Microsoft .NET** → **Framework**.
   7. Select the newest version in this folder (the last item in the list), then click **OK**.
   8. In the **Edit environment variable** window, click **OK**.
   9. In the **Environment Variables** window, click **OK**.
   10. In the **System Properties** window, click **OK**.
3. Enable Windows Subsystem for Linux.
   1. Open your command prompt as Administrator.
      1. In the search bar in the Start Menu, search for "cmd", right-click on **Command Prompt**, and click **Run as Administrator**.
   2. Execute the following command: `dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all`.
   3. After the process is complete and once prompted to do so, restart your PC by entering "Y".
   4. While rebooting your system, enable virtualization in your BIOS. This will vary by system, but you can find a general sketch of the instructions [here](https://bce.berkeley.edu/enabling-virtualization-in-your-pc-bios.html).
4. Install Ubuntu.
   1. In the search bar in the Start Menu, search for "store" and click on **Microsoft Store**.
   2. In the search bar, search for "Ubuntu".
   3. Click the blue **Get** button.
   4. Once installation is complete, launch Ubuntu from its page in the Microsoft Store to finish setup.
   5. Once setup is complete, enter a username and password for the system.
5. Open WSL.
   1. Open the **Run** window by pressing the **Windows key** and **R** at the same time.
   2. Type `wsl` into the window and press **Enter**.
6. Update WSL.
   1. In WSL, type `sudo apt update` and press **Enter**.
   2. After the update process completes, type `sudo apt upgrade` and press **Enter**. This process may take a long time.
   3. When prompted to confirm that WSL should restart automatically during package updates, select **Yes** and press Enter.
7. Install necessary packages.
   1. In WSL, run the following commands as preliminary dependencies:
      1. `sudo apt-get install build-essential git libpng-dev gdebi-core python3 python3-pip cmake automake`
      2. `pip3 install ndspy`
   2. Still in WSL, run the following commands to install `dkp-pacman`:
      1. `wget https://apt.devkitpro.org/install-devkitpro-pacman`
      2. `chmod +x ./install-devkitpro-pacman`
      3. `sudo ./install-devkitpro-pacman`
8. Install devkitPro.
   1. In WSL, run `dkp-pacman -S gba-dev`, then press **Enter** when prompted to choose what to download from the `gba-dev` library.
   2. Close and re-open WSL so that changes applied by `dkp-pacman` will be loaded.
   3. Run the following commands in order:
      1. `export DEVKITPRO=/opt/devkitpro`
      2. `echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc`
      3. `export DEVKITARM=$DEVKITPRO/devkitARM`
      4. `echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc`
      5. `cd Documents` (or wherever else you want to store your project)
      6. `git clone https://github.com/lhearachel/plat-engine.git`

From here, continue to [Build Instructions](#Build-Instructions).

### Mac OSX

1. Download and install devkitPro.
   1. Use the Mac download (`.pkg`) and instructions [here](https://github.com/devkitPro/pacman/releases).
2. Install Homebrew.
   1. Run the following in Terminal: `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`.
3. Run the following commands:
   1. `xcode-select --install`
   2. `brew install python3`
   3. `brew install libpng`
   4. `brew install automake`
   5. `pip3 install ndspy`
4. Download and install Mono.
   1. Use the instructions [here](https://www.mono-project.com/docs/getting-started/install/mac/).
5. Finish setting up devkitPro.
   1. In Terminal, run `dkp-pacman -S gba-dev`, then press **Enter** when prompted to choose what to download from the `gba-dev` library.
   2. Close and re-open Terminal so that changes applied by `dkp-pacman` will be loaded.
   3. Run the following commands in order:
      1. `export DEVKITPRO=/opt/devkitpro`
      2. `echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc`
      3. `export DEVKITARM=$DEVKITPRO/devkitARM`
      4. `echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc`
      5. `cd Documents` (or wherever else you want to store your project)
      6. `git clone https://github.com/lhearachel/plat-engine.git`

From here, continue to [Build Instructions](#Build-Instructions).

### Linux

**These instructions are, at present, only for Debian-based systems.**

1. Download and install devkitPro.
   1. Use the download and instructions [here](https://github.com/devkitPro/pacman/releases).
2. In Terminal, run the following commands:
   1. `sudo apt-get install libpng-dev build-essential cmake python3-pip git automake`
   2. `pip3 install ndspy`
   3. `dkp-pacman -S gba-dev`
3. Close and re-open Terminal, then run the following commands:
   1. `export DEVKITPRO=/opt/devkitpro`
   2. `echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc`
   3. `export DEVKITARM=$DEVKITPRO/devkitARM`
   4. `echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc`
   5. `cd Documents` (or wherever else you want to store your project)
   6. `git clone https://github.com/lhearachel/plat-engine.git`

From here, continue to [Build Instructions](#Build-Instructions).

## Build Instructions

1. Get your ROM.
   1. Before running any builds, verify that your ROM's checksum matches the checksum for a verified dump of **Pokemon Platinum (US) (Rev 1)**.
      1. On **Windows**: Open your command prompt and run the following command: `certutil -hashfile [file location] SHA256`.
      2. On **Mac OSX**: Open your Terminal and run the following command: `shasum -a 256 [file location]`.
      3. On **Linux**: Open your Terminal and run the following command: `sha256sum [file location]`.
   2. Verify the output of whatever command you ran above against the following: `fbce4c4def0c7797f8dd238a3d7a5e48b4a7e3abd86890ac65f6321cef781bdb`.
   3. It is **highly** recommended that you do all scripting and mapping updates to this file **before** you run the build process for the engine, then apply the engine at the end!
2. Place your ROM in the same directory as this file and rename it to `rom.nds`.
3. In Terminal/WSL, navigate to this directory.
4. Run `./install_deps.sh`. This will compile most of the tools that the engine needs to build.
5. Run `make`.
6. After the above process is complete, a new file will appear in this folder named `test.nds`. This new file is a copy of your ROM with the engine applied to it.

## Credits

* [Skeli789 (Complete Fire Red Upgrade Engine)](https://github.com/Skeli789/Complete-Fire-Red-Upgrade)
* [pret decompilation projects (nitrogfx, msgenc)](https://github.com/pret/pokediamond)
* [Mikelan98 and Nomura (ARM9 Expansion Subroutine)](https://pokehacking.com/tutorials/ramexpansion/)
* [BluRose and turtleisaac (hg-engine)](https://github.com/BluRosie/hg-engine)
* [Rafael Vuijik (ndstool)](https://github.com/devkitPro/ndstool)
* [Kingcom (armips)](https://github.com/Kingcom/armips)
* [Drayano (Fairy-type graphical resources from Renegade Platinum)](https://projectpokemon.org/home/forums/topic/52294-pok%C3%A9mon-renegade-platinum/)

# Dedicated Server
The dedicated server is a version of Minecraft: Pi Edition modified to run in a headless environment. It loads settings from a ``server.properties`` file.

This server is also compatible with MCPE Alpha v0.6.1[^1].

## Setup
To use, install and run the ``minecraft-pi-reborn-server`` AppImage. It will generate the world and ``server.properties`` in the current directory.

## Server Limitations
* Player data is not saved because of limitations with MCPE LAN worlds
  * An easy workaround is to place your inventory in a chest before logging off
* Survival Mode servers are incompatible with unmodded MCPI

[^1]: The exception to this is buckets, those will crash MCPE players.

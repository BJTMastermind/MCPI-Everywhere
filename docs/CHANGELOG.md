# Changelog

**2.5.3**
* Add ``Replace Block Highlight With Outline`` Feature Flag (Enabled By Default)
  * By Default, The Outline Width Is Set Using The GUI Scale
  * This Can Be Overridden Using The ``MCPI_BLOCK_OUTLINE_WIDTH`` Environmental Variable
* Added ``overwrite_calls_within`` Function

**2.5.2**
* Add ``3D Chest Model`` Feature Flag (Enabled By Default)
* Stop Using Jenkins
* Replace ``iconv``
* Replace LibPNG

**2.5.1**
* Allow Overriding Custom Skin Server Using ``MCPI_SKIN_SERVER`` Environmental Variable
* Fix Bug With SDK Generation

**2.5.0**
* [Custom skin support](CUSTOM_SKINS.md)!
* Add ``Load Custom Skins`` Feature Flag (Enabled By Default)

**2.4.9**
* Allow Overriding GUI Scale With ``MCPI_GUI_SCALE`` Environmental Variable
* Add ``Disable Block Tinting`` Feature Flag (Disabled By Default)
* Add ``Disable Hostile AI In Creative Mode`` Feature Flag (Enabled By Default)
* Allow Accessing Configuration At Runtime (Useful For Mods That Need To Support Multiple Versions)

**2.4.8**
* Fix Bug In ``extract_from_bl_instruction``
* Update LIEF And GLFW
* Allow Mods To Access The Original GLFW Keycode For Key Events (But Better)
* More Accurate Sound

**2.4.7**
* Improve Server Performance
* Add ``Add Biome Colors To Grass`` Feature Flag (Disabled By Default)
* Add ``Generate Caves`` Feature Flag (Enabled By Default)
* Allow Mods To Access The Original GLFW Keycode For Key Events

**2.4.6**
* [Minimal Controller Support](CONTROLS.md)
* Fix Holding Left-Click When Attacking
* Fix Crashing On ARMHF
* Heavily Improved Crash Report Dialog

**2.4.5**
* Bundle QEMU

**2.4.4**
* Cache Previous Launcher Configuration
* Add ``MCPI_API_PORT`` Environmental Variable
* Fix Particles In Front-Facing View
* Fixed Launch Crash On Ubuntu ARM64
  * PatchELF Replaced With LIEF
* Moved ``3D Anaglyph`` Feature Flag To Options Screen
* Add ``Improved Classic Title Screen`` Feature Flag (Enabled By Default)
  * Add Quit button
  * Add Options Button (Moved From ``Fix Options Screen`` Feature Flag)
* Add ``Disable Speed Bridging`` Feature Flag (Disabled By Default)
* Add ``Disable Creative Mode Mining Delay`` Feature Flag (Disabled By Default)
* Improved Feature Flag Names
* Miscellaneous Bug Fixes
* Improved Build System

**2.4.3**
* Fix Signs With CP-437

**2.4.2**
* Fix Picking Up Lava
* Fix Wayland App ID

**2.4.1**
* Allow More Characters In Usernames And Chat
* Fix Running On ARMHF Debian Buster

**2.4.0**
* [Modding SDK](../example-mods/README.md)
* Cache Blacklist/Whitelist
* More Reliable AppImages
* CMake Refactors
* Disable Broken Touchscreen-Specific Block Outline Behavior
* Add ``Remove Forced GUI Lag (Can Break Joining Servers)`` Feature Flag (Disabled By Default)
* Add ``Add Buckets`` Feature Flag (Enabled By Default)
* Add ``Classic HUD`` Feature Flag (Enabled By Default)
* Add ``Translucent Toolbar`` Feature Flag (Enabled By Default)
* Add ``Force EGL`` Feature Flag (Disabled By Default)
* Fix Sound Pitch/Volume/Attenuation
* Fix Holding Left-Click When Attacking
* Don't Force EGL (Should Fix Some NVIDIA Systems)
* Performance Fixes

**2.3.13**
* Fix Texture Bug

**2.3.12**
* Media Layer Proxy Optimizations
* Bug Fixes

**2.3.11**
* ``--version`` Command Line Option
* TPS Measured In Benchmark & Server
* Front-Facing Third-Person
* GLESv1 Comparability Layer
* Miscellaneous Bug Fixes

**2.3.10**
* Add Crash Report Dialog
* Disable V-Sync By Default
* Refactor Child Process Management
* Improve Build System
  * Support For Building On Ubuntu 22.04

**2.3.9**
* Bundle An ARM Sysroot
  * Not Used On ARM32 Systems
  * Based On Debian Bullseye
* Colored Log Output

**2.3.8**
* Switch Up Mod Loading Order

**2.3.7**
* Don't Append Hyphens To New World Name, Only Folder Names

**2.3.6**
* Fix ``Invert Y-axis`` Option Name
* Improve Touch GUI Inventory In Non-Touch GUI
* New Create World Dialog
  * Controlled By ``Implement Create World Dialog`` Feature Flag (Enabled By Default)
  * Custom World Names
  * Game-Mode Selection
  * Custom Seeds

**2.3.5**
* Renamed Some Feature Flags
* Add ``Improved Title Background`` Feature Flag (Enabled By Default)
* Non-Touch GUI Rework
  * Make ``Full Touch GUI`` Feature Flag Disabled By Default
  * Add ``Force Touch GUI Button Behavior`` Feature Flag (Enabled By Default)
  * Add ``Improved Button Hover Behavior`` Feature Flag (Enabled By Default)

**2.3.4**
* AppImage Fixes
* Make Death Messages Customizable Server-Side
* Fix Q-Key Behavior Behavior When Editing Signs
* Add ``Force Touch Inventory`` Feature Flag (Disabled By Default)
* Add ``Fix Pause Menu`` Feature Flag (Enabled By Default)
  * Enables Server Visibility Toggle Button
* Options Changes (Not Supported On Legacy)
  * Add ``Fix Options Screen`` Feature Flag (Enabled By Default)
    * Adds Options Button To Classic UI Start Screen
    * Removes Useless Options Toggles
    * Fixes Options Toggles' Default Position
  * Store Multiple Settings In `options.txt`
    * ``Peaceful Mode`` Feature Flag Moved To ``game_difficulty``
    * ``Smooth Lighting`` Feature Flag Moved To ``gfx_ao``
    * ``Fancy Graphics`` Feature Flag Moved To ``gfx_fancygraphics``
    * ``Disable Hosting LAN Worlds`` Feature Flag Moved To ``mp_server_visible_default``

**2.3.3**
* Add More Blocks To Expanded Creative Inventory
* Add AppStream Metadata

**2.3.2**
* Simplify Launch Sequence
* Add More Blocks To Expanded Creative Inventory
* Fix Nether Reactor With Creative Restrictions Disabled
* Alphabetize Feature Flags
* Add ``Disable V-Sync`` Feature Flag (Disabled By Default)

**2.3.1**
* Internal Refactor Of ``libreborn``
* Remove Use Of ``/bin/sh``
* Load Custom Mods First
* Use Zenity Dark Mode
* Add ``Improved Cursor Rendering`` Feature Flag (Enabled By Default)

**2.3.0**
* Switch To AppImage For Packaging
* Prevent OpenAL From Crashing When Out Of Memory
* Vendor GLFW & Zenity
  * Seamless Wayland Support
* Add ``MCPI_DEBUG`` Environmental Variable
* Add ``Disable Hosting LAN Worlds`` Feature Flag (Disabled By Default)
* Add ``Fix Furnace Not Checking Item Auxiliary`` Feature Flag (Enabled By Default)
* Add ``Disable Raw Mouse Motion (Not Recommended)`` Feature Flag (Disabled By Default) For Broken X11 Setups
* Added Back `~/.minecraft-pi/mods`
* Improve Build System
* Improve Documentation

**2.2.11**
* Add ``Close Current Screen On Death`` Feature Flag (Enabled By Default) To Prevent Bugs
* Fix More Furnace UI Bugs When Using "Disable 'gui_blocks' Atlas"

**2.2.10**
* Fix Bug With Picking Up Items In "Remove Creative Mode Restrictions" Mode

**2.2.9**
* Fix String Sanitization
* Store Files In `/usr/lib`

**2.2.8**
* Add ``Hide Chat Messages`` Optional Feature Flag
* Add ``Remove Creative Mode Restrictions`` Optional Feature Flag
* Improve GLFW->SDL Mouse Motion Event Conversion
* Performance Optimizations
* Make Majority Of Server-Specific Logging Code Also Apply To The Client
* Simple Benchmark Mode
* Fix Typo When Audio Source File Doesn't Exist
* Improve Build System

**2.2.7**
* Fix Crash When OpenAL Is Unavailable
* Fix Command Input In Server

**2.2.5**
* Fix Bug In Texture Scaling Code

**2.2.5**
* Scale Animated Textures
* Add More Blocks To Expanded Creative Inventory
* Reduce Unnecessary Logging
* Log IPs In Server Mode

**2.2.4**
* Instead Of Crashing, Disable Polling Block Hits In Survival Mode Using The API

**2.2.3**
* Fix Crash When Taking Odd-Sized Screenshots

**2.2.2**
* Add More Missing Sound Events
* Make Missing Sound Event Cause Warning Rather Than Crash

**2.2.1**
* Prevent ``random.burp`` Sound From Crashing Game
* Always Cleanup Media Layer, Even On Crash
* Resolve All Sounds On Startup

**2.2.0**
* Sound Support
* Split Off ``Allow Joining Survival Servers`` From Game-Mode Mod
* Separate Headless Code From Server Code
* Fix Bug Where ``RakNetInstance`` Starts Pinging Potential Servers Before The "Join Game" Screen Is Opened
* Clean-Up Code
* Remove Support For Debian Buster

**2.1.8**
* Fix Crash On ARM Systems

**2.1.7**
* Fix On 64-Bit ARM Systems

**2.1.6**
* Optimize Media Layer Proxy

**2.1.5**
* Print Error Message If RakNet Fails To Start

**2.1.4**
* Fix ``RakNet::RakString`` Security Bug

**2.1.3**
* Workaround Broken Library Search Path On Some ARM 32-Bit Systems

**2.1.2**
* Fix Library Loading On ARM 32-Bit Systems

**2.1.1**
* Fix Symlink Code

**2.1.0**
* Allow Binding ``Q`` Key To Item Dropping
* Expose More Feature Flags
* Replace ``Mob Spawning`` Feature Flag With ``Force Mob Spawning``
* Fix ``ESC`` Key In Options Menu When ``Miscellaneous Input Fixes`` Is Enabled

**2.0.9**
* Fix Translucent Preview Items In Furnace UI Being Fully Opaque When The ``gui_blocks`` Atlas Is Disabled

**2.0.8**
* Use Default Port In ``servers.txt`` If Not Specified

**2.0.7**
* Fix Sign Text Not Updating In Multiplayer When Exiting Editing UI Using Escape Button
* Fix Item Dropping Not Working

**2.0.6**
* Fix Toolbar Size In Normal GUI

**2.0.5**
* Show Reborn Version In Start Screen
* External Server Support

**2.0.4**
* Optimize Media Layer Proxy

**2.0.3**
* Make ``kill`` Admin Command Print Death Message

**2.0.2**
* Fix Mouse Cursor Bugs

**2.0.1**
* Fix Blank Screen On Twister OS

**2.0.0**
* Major Rewrite

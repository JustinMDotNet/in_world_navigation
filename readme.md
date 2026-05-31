# In-World Navigation

> [!NOTE]
> **This is a community-maintained fork of [`jackhumbert/in_world_navigation`](https://github.com/jackhumbert/in_world_navigation).**
> The original mod's last release (`v0.1.20`) targeted Cyberpunk 2077 patch 2.30+ and the `2.3` update was started but not completed upstream. This fork picks the work back up: fixing outstanding bugs, modernizing the toolchain, and tracking newer game versions. All credit for the original design and reverse-engineering work goes to [@jackhumbert](https://github.com/jackhumbert).
>
> Looking for the original? → https://github.com/jackhumbert/in_world_navigation
>
> **Fork status:** active. See the [issues](https://github.com/JustinMDotNet/in_world_navigation/issues) for planned work.

This mod displays in-world holographic arrows for quest/point of interest navigation, mirroring the dots in the minimap. They're currently displayed all of the time, but will eventually be configurable.

![preview](preview.jpg)

## Installation

[Get the latest release here](https://github.com/JustinMDotNet/in_world_navigation/releases). If you're upgrading from the upstream mod or an older version of this fork, you may want to delete the `r6/scripts/in_world_navigation` folder, since files may have been renamed/removed.

## Requirements

* [RED4ext](https://github.com/WopsS/RED4ext)
* [Redscript](https://github.com/jac3km4/redscript)
* [Mod Settings](https://github.com/jackhumbert/mod_settings)

## Bugs

If you come across something that doesn't work quite right, or interferes with another mod, [search for or create an issue here](https://github.com/JustinMDotNet/in_world_navigation/issues). Bugs that also affect the upstream mod may already be tracked at the [upstream issue tracker](https://github.com/jackhumbert/in_world_navigation/issues) — feel free to cross-reference.

Special thanks to @psiberx for [Codeware Lib](https://github.com/psiberx/cp2077-codeware/), [InkPlayground Demo](https://github.com/psiberx/cp2077-playground), and Redscript & CET examples on Discord, @WopsS for [RED4ext](https://github.com/WopsS/RED4ext), @jac3km4 for [Redscript toolkit](https://github.com/jac3km4/redscript), @yamashi for [CET](https://github.com/yamashi/CyberEngineTweaks) and the [E-mode mod](https://www.nexusmods.com/cyberpunk2077/mods/3207?tab=description) (very helpful in figuring out how to work with FMOD), @rfuzzo & team (especially @seberoth!) for [WolvenKit](https://github.com/WolvenKit/WolvenKit), and all of them for being helpful on Discord.

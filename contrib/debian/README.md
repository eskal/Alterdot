
Debian
====================
This directory contains files used to package alterdotd/alterdot-qt
for Debian-based Linux systems. If you compile alterdotd/alterdot-qt yourself, there are some useful files here.

## alterdot: URI support ##


alterdot-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install alterdot-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your alterdot-qt binary to `/usr/bin`
and the `../../share/pixmaps/alterdot128.png` to `/usr/share/pixmaps`

alterdot-qt.protocol (KDE)


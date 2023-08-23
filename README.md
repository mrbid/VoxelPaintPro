# Voxel Paint Pro
Paint in 3D using solid shaded voxels. *(using the [Aurora 256 Color Palette](https://lospec.com/palette-list/aurora))*

![screenshot](https://dashboard.snapcraft.io/site_media/appmedia/2023/08/Screenshot_2023-08-06_07-36-03.png)

## Flathub
https://flathub.org/apps/com.voxdsp.VoxelPaintPro

## Snapcraft
https://snapcraft.io/voxelpaintpro

## Info
* Mouse locks when you click on the game window, press ESCAPE to unlock the mouse.
* Arrow Keys can be used to move the view around.
* Your state is automatically saved on exit. A backup `world.db.idle` is updated every time no input is detected for over 3 minutes.
* You can change the mouse sensitivity by passing the new sensitivity as the 1st command line parameter *[default is 0.003]* `./vox 0.003`.

## Input Bindings
* W,A,S,D = Move around based on relative orientation to X and Y.
* SPACE + L-SHIFT = Move up and down relative Z.
* Left Click / R-SHIFT = Place node.
* Right Click / R-CTRL = Delete node.
* Tab = Teleports you from colour palette to last position and vice-versa.
* Q / Middle Click / Mouse4 = Clone texture of pointed node.
* E / Mouse5 = Replace pointed node.
* R = Places node at your current position.
* F = Toggle player fast speed on and off.
* 1-7 = Change move speed for selected fast state.
* X + C / Slash + Quote = Change texture of pointed node.
* G = Gravity on/off.
* P = Toggle pitch lock.
* F1 = Resets environment state back to default.
* F3 = Save. (auto saves on exit, backup made if idle for 3 mins.)
* F8 = Load. (will erase what you have done since the last save)
* F10 = Export the VoxelPaintPro data to a zip file in $HOME/EXPORTS.

## Multi Selection
* Middle Mouse Click & Drag or Mouse4 & Drag (or Q and drag) to select area.
* V = Copies the selected nodes to the currently pointed position, the point you started the selection from is the point you will copy from at the new pointed location.
* T = Copies the selected nodes to the currently pointed position, but each time you press T it will iterate one of 24 rotations.
* Y = Shoots an array of the selected nodes in the direction you are facing in 24 different rotations. Pick the one you want.
* B = Fill selected nodes with selected color.
* N = Delete selected nodes.

## Known Bugs
* Sometimes when you copy a selection a single line of nodes on the edge of the selection will not be copied, this is easy to fix my doing a second copy or placing two nodes around the selection area using (R) to give the selection area a bit of margin/border.

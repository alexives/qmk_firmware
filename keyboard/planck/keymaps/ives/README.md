# Ives Keymap

This keymap uses a variety of layers. Like the default map, the three base layers represent the three main keyboard layout types, Qwerty, Colemak, and Dvorak. These base layers differ from the default map in two respects. First, the Escape key has been replaced with a control toggle. Second, the arrow keys have been moved to H,J,K,L in the raise layer and replaced with a toggle for a "Fn" layer that contains a mouse, as well as toggles for other keyboard layouts. In addition, a page up, page down, and delete button.

The major changes, in addition to the FN layer, include a mouse and a windows mode. Additionally, the raise and lower layers have been modified substantially. These are detailed in their individual layers. It also includes a "Windows Mode" layer.

## Layers

### Qwerty (Default Base, Toggled Base)

This layer is identical to the default Planck layout except for the exceptions above.

````
,-----------------------------------------------------------------------------------.
| Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
|------+------+------+------+------+------+------+------+------+------+------+------|
|ES/CTL|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
|------+------+------+------+------+-------------+------+------+------+------+------|
|Hyp/Cl| Ctrl | Alt  | GUI  |Raise |    Space    |Lower |  Fn  | Pg Up| Pg Dn| Del  |
`-----------------------------------------------------------------------------------'
````

### Colemak (Toggled Base)

This layer is identical to the default Planck layout except for the exceptions above.

````
,-----------------------------------------------------------------------------------.
| Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
|------+------+------+------+------+------+------+------+------+------+------+------|
|ES/CTL|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
|------+------+------+------+------+-------------+------+------+------+------+------|
|Hyp/Cl| Ctrl | Alt  | GUI  |Raise |    Space    |Lower |  Fn  | Pg Up| Pg Dn| Del  |
`-----------------------------------------------------------------------------------'
````

### Dvorak (Toggled Base)

This layer is identical to the default Planck layout except for the exceptions above.

````
,-----------------------------------------------------------------------------------.
| Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
|------+------+------+------+------+------+------+------+------+------+------+------|
|ES/CTL|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
|------+------+------+------+------+-------------+------+------+------+------+------|
|Hyp/Cl| Ctrl | Alt  | GUI  |Raise |    Space    |Lower |  Fn  | Pg Up| Pg Dn| Del  |
`-----------------------------------------------------------------------------------'
````

### Raise (Held)

While the number row in this layer is the same as the default layout, arow keys have been added at H,J,K,L and the punctuation has been moved to the left hand home row. The F-keys have been moved to the bottom row, with F1-F10 on the raise layer, and F11-F20 on the lower layer.

````
,-----------------------------------------------------------------------------------.
|   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|  Esc |   -  |   =  |   {  |   }  |   \  | Left | Down |  Up  | Right|      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      |      |      |      | XXXX |             |      | Next | Vol+ | Vol- | Play |
`-----------------------------------------------------------------------------------'
````

### Lower (Held)

Like raise, the lower layer has the same top row as default layer. However, the duplicate set of function keys has been removed and the function row now has F11-F20.

````
,-----------------------------------------------------------------------------------.
|   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|  Esc |   _  |   +  |   [  |   ]  |   |  |      |   (  |   )  |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      |      |      |      |      |             | XXXX |BL Tgl| BL + | BL - |      |
`-----------------------------------------------------------------------------------'
````

### FN/Mouse (Held)

The FN/Mouse layer has two discrete tasks: First, at as a mouse with movment mapped to W,A,S,D and clicks mapped to J and K. Second, it's used to toggle the other hard layers, EG: Colmark, Dvorak, and Windows mode.

````
,-----------------------------------------------------------------------------------.
|      |      | M Up |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      | M Le | M Dn | M Rt |      |      |      | L Clk| R Clk|      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |  Win |Qwerty|Colemk|Dvorak| Reset|      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      |      |      |      |      |             |      | XXXX |      |      |      |
`-----------------------------------------------------------------------------------'
````

### Windows Mode (Toggled)

This layer exists for those timest that you want the keyboard to be more like a normal windows keyboard with GUI and Alt swapped.

````
,-----------------------------------------------------------------------------------.
|      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      | Ctrl |  GUI |  Alt |      |             |      |      |      |      |      |
`-----------------------------------------------------------------------------------'
````
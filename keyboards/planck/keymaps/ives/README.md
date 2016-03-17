# Ives Planck Keymap

This keymap is designed for planck keyboards set up with the split space key (Which in this case is raise and lower).

This keymap is designed in mind for people who are primarily OS X users. Like the default map, the four base layers represent the four main keyboard layout types, Qwerty, Workman, Colemak, and Dvorak. Unlike the default map, the number row has been moved to the home row in the raise layer, and the associated punctuation has been moved to the lower layer. This mapping is not 1-1 to the number row shift, and some of the programmer focused punctuation has been arranged to be a bit more forward focused.

This graphic represents the layers on the Qwerty base, however when powered, you can specify a different base layer (which is not persisted).

[![the layout](https://raw.githubusercontent.com/alexives/qmk_firmware/ives_layouts/keyboards/planck/keymaps/ives/ives-planck.png)](http://www.keyboard-layout-editor.com/#/gists/d986a67930f00d119511e40e50eb6431)

## Layers

### Qwerty (Default Base, Toggled Base)

This layer is identical to the default Planck layout except for the exceptions above.

```
,-----------------------------------------------------------------------------------.
| Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
|------+------+------+------+------+------+------+------+------+------+------+------|
|ES/CTL|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
|------+------+------+------+------+-------------+------+------+------+------+------|
|Hyp/Cl| Ctrl | Alt  | Nav  |Super | Raise|Lower |Space | Left | Down |  Up  | Right|
`-----------------------------------------------------------------------------------'
```

### Colemak (Toggled Base)

This layer is identical to the default Planck layout except for the exceptions above.

```
,-----------------------------------------------------------------------------------.
| Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
|------+------+------+------+------+------+------+------+------+------+------+------|
|ES/CTL|   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
|------+------+------+------+------+-------------+------+------+------+------+------|
|Hyp/Cl| Ctrl | Alt  | Nav  |Super | Raise|Lower |Space | Left | Down |  Up  | Right|
`-----------------------------------------------------------------------------------'
```

### Dvorak (Toggled Base)

This layer is identical to the default Planck layout except for the exceptions above.

```
,-----------------------------------------------------------------------------------.
| Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
|------+------+------+------+------+------+------+------+------+------+------+------|
|ES/CTL|   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
|------+------+------+------+------+-------------+------+------+------+------+------|
|Hyp/Cl| Ctrl | Alt  | Nav  |Super | Raise|Lower |Space | Left | Down |  Up  | Right|
`-----------------------------------------------------------------------------------'
```

### Raise (Held)

 ```
,-----------------------------------------------------------------------------------.
|      |      |   @  |   {  |   }  |      |      |   \  |   !  |   ~  |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  `   |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|Sleep |      |      |      | XXXX |      |      |  GUI | Next | Vol+ | Vol- | Play |
`-----------------------------------------------------------------------------------'
```

### Lower (Held)

```
,-----------------------------------------------------------------------------------.
|      |      |   $  |   [  |   ]  |      |      |   |  |   &  |   `  |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |   -  |   =  |   #  |   +  |   %  |   ^  |   _  |   *  |   (  |   )  |   ~  |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |  F11 |  F12 |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|Sleep |      |      |      |      |      |      | XXXX |      | BL + | BL - |BL Tgl|
`-----------------------------------------------------------------------------------'
```

### Nav/Mouse (Held)

The Nav/Mouse layer has two discrete tasks: First, at as a mouse with movment mapped to W,A,S,D and clicks mapped to J and K. Second, it's used to toggle the other hard layers, EG: Colmark, Dvorak, and Windows mode.

```
,-----------------------------------------------------------------------------------.
|      |      | M Up |      |      |      |      |      | L Clk| R Clk|      | RESET|
|------+------+------+------+------+------+------+------+------+------+------+------|
|      | M Le | M Dn | M Rt |      |      |      | Left | Down |  Up  | Right|      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      |      |      | XXXX |      |      | Alt  | Gui  |  Win |Qwerty|Colemk|Dvorak|
`-----------------------------------------------------------------------------------'
```

### Windows Mode (Toggled)

This layer exists for those timest that you want the keyboard to be more like a normal windows keyboard with GUI and Ctrl swapped.

```
,-----------------------------------------------------------------------------------.
|      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+------+------+------+------+------+------+------|
|      |      |      |      |      |      |      |      |      |      |      |      |
|------+------+------+------+------+-------------+------+------+------+------+------|
|      |  Gui |      |      | Ctrl |      |      |      |      |      |      |      |
`-----------------------------------------------------------------------------------'
```
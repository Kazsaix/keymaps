# rafaelromao's keyboard layout

## Romak

Romak is a new keyboard layout, inspired by [Colemak](https://colemak.org) and [BEAKL](https://ieants.cc/beakl), improved to remove load from pinkies and for typing in Portuguese and English, and for coding.

![img](https://i.imgur.com/BvpA5vs.png)

- Romak is the layout used in the base layer of my keyboards.
- Romak has a higher SFB rate than Colemak, but lower than Workman, and most of this load goes to the stronger fingers.
- There is a commented out transition path from Qwerty to Romak in the [keymap_blocks.h](../src/qmk/users/rafaelromao/definitions/keymap_blocks.h), similar to Tarmak, but moving _ instead of J.

### From Qwerty to Romak in 6 steps

![img](https://i.imgur.com/9TxUFbp.png)

## Romak vs Colemak-DH
[Stevep99's Layout Analyzer Tool](https://stevep99.github.io/keyboard-layout-analyzer) was used to compare Romak with Colemak-DH and some other layouts, using the Magna Carta as text corpus, in [Portuguese](analysis/corpus.pt.txt) and [English](analysis/corpus.en.txt).
### General Performance
#### Portuguese
![img](https://i.imgur.com/0dex44r.png)
#### English
![img](https://i.imgur.com/bNEF93X.png)

### Heatmaps
#### Portuguese
<p float="left">
  <img src="https://i.imgur.com/0DllDXL.png" width="450" />
  <img src="https://i.imgur.com/XEoZ8eK.png" width="450" /> 
  <img src="https://i.imgur.com/ipPEwem.png" width="450" /> 
</p>

#### English
<p float="left">
  <img src="https://i.imgur.com/kqI1q4K.png" width="450" />
  <img src="https://i.imgur.com/9trwGNv.png" width="450" />   
  <img src="https://i.imgur.com/zoc13dC.png" width="450" /> 
</p>

Romak is more balanced for Portuguese than English, so if English is your primary language, it is recommended to swap some key pairs, like HM, DT, RS.

### Finger Usage
Pinkies will get less load in Romak, by design. This load will go to the ring and middle fingers.
#### Portuguese
![img](https://i.imgur.com/O4azuyV.png)
#### English
![img](https://i.imgur.com/46eHZ3l.png)

### Detailed Finger Analysis
The [Colemak mod-DH analysis tool](https://colemakmods.github.io/mod-dh/analyze.html) was also used to compare Romak against Colemak-DH and Workman (English text corpus only).
<p float="left">
  <img src="https://i.imgur.com/vgdCcJe.png" width="450" />
  <img src="https://i.imgur.com/3t4tMKo.png" width="450" /> 
  <img src="https://i.imgur.com/saVyUQU.png" width="450" /> 
</p>

Despite the higher SFB rate, total finger effort is lesser in Romak than in Colemak-DH or Workman.

##
[Home](../readme.md) | 
Base |
[Modifiers](modifiers.md) |
[Symbols and Numbers](symbols.md) |
[Functions and Media](functions.md) | 
[Navigation and Mouse](navigation.md) |
[Maintenance](maintenance.md) |

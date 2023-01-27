# Attiny-Music-Box

Remember those ancient mechanical music boxes?

The ones where you had to load a spring to play a song.

This project does the same, but with **electronics!**

Till now, the PCB consists of an ATTiny26L and a passive buzzer, but that was due to the tight deadline back then, but now it's time to spice it up. The songs added till now are:
- Fur Elise (disabled)
- Happy Birthday

### The planned updates for now are (by priority):
- Testing and integrating the ability to switch between songs using a pushbutton (was added and worked but needed debugging)
- Optimizing the storage system to add more songs (probably using nibbles)
- Adding an external EEPROM to the system as external storage (could be seen as the CD's for a CD player, each containing a playlist...)
- Figure out how to use an active buzzer instead of the passive one (better sound quality, better compatibility with online scores, cheaper, etc.)
- Fabricating a box for the PCB
- Adding a servo to spin a small ballerina model around (just for that authentic music box vibe)

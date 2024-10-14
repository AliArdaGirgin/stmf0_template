To build, flash and debug firmware for stmf0-discovery board on linux <br/> <br/>

# Build and Flash
on Debian install; <br/>
`sudo apt install make gcc-arm-none-eabi stlink-tools gdb-multiarch` <br/><br/>
To compile template program<br/>
`make` <br/> <br/>
After compiling, connect usb to stmf0-discovery board and check connection with; <br/>
`st-info --probe` <br/><br/>
If connection ok, Then flash to board <br/>
`make flash` <br/><br/>
example program should blink user leds (blue and green) on board every half-second<br\><br/>
# Debug
To debug, start a debugger server, then connect to it with gdb-multiarch <br/><br/>
to start debug server; <br/>
`st-util` <br/>
Get the port number from output (default 4242) <br/><br/>
Then in another terminal start gdb-multiarch; <br/>
`gdb-multiarch` <br/><br/>
Then in gdb-multiarch connect to remote <br/>
`(gdb)target remote localhost:4242`<br/><br/>
Load file with symbols<br/>
`(gdb)file template.elf`<br/><br/>
Should be ready to debug 

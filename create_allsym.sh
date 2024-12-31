#!/bin/bash
rm a.out

gcc -c allsym.c -o a.out


objcopy --add-symbol=symbol_B=.bss:0:undefined a.out a.out
objcopy --add-symbol=symbol_b=.bss:0:undefined,local a.out a.out
objcopy --add-symbol=symbol_N=.comment:hello a.out a.out
#missing n
objcopy --add-symbol=symbol_D=.data:42 a.out a.out
objcopy --add-symbol=symbol_d=.data:42,local a.out a.out
objcopy --add-symbol=symbol_A=.comment a.out a.out
objcopy --add-symbol=symbol_T=.text:42:global a.out a.out
objcopy --add-symbol=symbol_t=.text:42:local,function a.out a.out
objcopy --add-symbol=symbol_W=.text:42:function,weak a.out a.out
#missing w global
objcopy --add-symbol=symbol_V=.text:42:function,object,weak a.out a.out
#missing v global

#missing G
#missing g

#missing I
objcopy --add-symbol=symbol_i=.data:42:function,local,indirect-function a.out a.out
#missing U
#missing u
#missing C
#missing c
#missing p

objcopy --add-section .rodata=a.out a.out
objcopy --set-section-flags .rodata=load,alloc,readonly a.out
objcopy --add-symbol=symbol_R=.rodata:42:object,global a.out a.out
objcopy --add-symbol=symbol_r=.rodata:42:object,local a.out a.out

#missing S
#missing s
#missing - //-gstabs no longer supported by gcc or clang
#missing ?

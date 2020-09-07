#!/bin/bash

let Y=5
let X=10
let DY=6
let DX=11
let BY=5
let BX=10

#column_address=\E[%i%p1%dG
#row_address=\E[%i%p1%dd
#cursor_up=\E[A

BOX_W_DIGIT=`echo -e "\E(0\E["$Y"d
\E[A\E["$X"Glqqqqqqk
    \E["$X"Gx aaaa x
    \E["$X"Gxa   aax
    \E["$X"Gx    a x
    \E["$X"Gx   a  x
    \E["$X"Gx aa   x
    \E["$X"Gxaaaaaax
    \E["$X"Gmqqqqqqj\E(B"`

BOX=`echo -e "\E(0\E["$BY"d
\E[A\E["$BX"Glqqqqqqk
    \E["$BX"Gx      x
    \E["$BX"Gx      x
    \E["$BX"Gx      x
    \E["$BX"Gx      x
    \E["$BX"Gx      x
    \E["$BX"Gx      x
    \E["$BX"Gmqqqqqqj\E(B"`
    
DIGIT=`echo -e "\E(0\E["$DY"d
\E[A\E["$DX"G aaaa 
    \E["$DX"Ga   aa
    \E["$DX"G    a 
    \E["$DX"G   a  
    \E["$DX"G aa   
    \E["$DX"Gaaaaaa
    \E(B"`

echo -e "\E[H\E[2J"
#echo "$BOX_W_DIGIT"
echo "$BOX"
echo "$DIGIT"

#!/bin/bash

echo -e "\n"
echo `infocmp -1 -L | grep f5=`
echo -e "press F5 and Enter:"
read -r
echo -e "both ways are acceptable: \\\\E (press ESC) and ^[ (press ctrl+[)\m"

echo -e "\n"
echo `infocmp -1 -L | grep f6=`
echo -e "press F6 and Enter:"
read -r
echo -e "both ways are acceptable: \\\\E (press ESC) and ^[ (press ctrl+[)\n"

echo -e "\n"
echo `infocmp -1 -L | grep _up=`
echo -e "press arrow Up key and Enter:"
read -r

echo -e "\n"
echo `infocmp -1 -L | grep _left=`
echo -e "press arrow Left key and Enter:"
read -r

echo -e "\n"
echo `infocmp -1 -L | grep _right=`
echo -e "press arrow Right key and Enter:"
read -r

echo -e "\n"
echo `infocmp -1 -L | grep _down=`
echo -e "press arrow Down key and Enter:"
read -r

echo -e "\n"
echo -e "Press digits and letters on keyboard to test thier sequences:"
read -r
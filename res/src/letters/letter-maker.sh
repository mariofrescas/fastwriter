#!/usr/bin/sh

# \brief Crea todo el alfabeto de svgs en base al A-svg.
#        Cada letra esta separada por un archivo.
# \param path Ruta en donde se encuentra el archivo base y donde se creara el alfabeto
# \param svg_base Nombre completo del archivo base
#                             [path]          [svg_base]
# Usage: ./letter-maker.sh    ./blue/          A-blue.svg

declare -a letters=("B" "C" "D" "E" "F" "G" "H" "I" "J" "K" "L" "M" "N" "O" "P" "Q" "R" "S" "T" "U" "V" "W" "X" "Y" "Z")

for letter in "${letters[@]}"
do
    sed "s/A/$letter/g" $1$2 > $1$letter${2:1}
done
pause()
{
	read -n 1 -s -r -p "${1:-Press any key to continue}"
	echo
}

clear_dir()
{
    DIR="$1"
    echo $DIR
    for file in "$DIR"*; do
		if [ -f "$file" ]; then
            rm $file
		fi
	done
}

clear_log()
{
	rm logs/text_logs/log.txt #clear_dir logs/text_logs/
	clear_dir logs/dot-files/
	clear_dir logs/pictures/
	echo "logs deleted"
}

clear
clear_log
gcc -Wall -Wextra -Wshadow -Wconversion -Wunused "$1" src/Tree_implement.c src/debug_impliment.c src/graph_manager.c src/Tree_printer.c src/Tree_reader.c -o main.out
pause
time ./main.out

echo
echo "Create png starts"
	DIR="logs/dot-files/"
	PNG_FILE_NAME="logs/pictures/graph_pict"
	num_files=0

	for file in $(ls "$DIR" -tr); do
		file="$DIR$file"
		if [ -f "$file" ]; then
			((num_files++))
			echo "Dot file: $file"
			dot -Tpng "$file" -o "$PNG_FILE_NAME"_"$num_files".png
			echo PNG file: "$PNG_FILE_NAME"_"$num_files".png
			echo
		fi
	done
echo "Create png ends"

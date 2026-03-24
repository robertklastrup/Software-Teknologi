
DEST="./Collected_Code"
mkdir -p "$DEST"

find /c -type f \( -name "*.cpp" -o -name "*.h" \) \
    | xargs -n 1 dirname \
    | sort -u > directories_for_cpp_and_h.txt
 
echo "Directories found:"
cat directories_for_cpp_and_h.txt

while IFS= read -r DIR; do
    SAFE_NAME=$(echo "$DIR" | sed 's|^/||; s|/|_|g')
    TARGET="$DEST/$SAFE_NAME"
 
    if [ -d "$TARGET" ]; then
        echo "[SKIP] Already exists: $TARGET"
    else
        echo "[COPY] $DIR --> $TARGET"
        cp -r "$DIR" "$TARGET"
    fi
done < directories_for_cpp_and_h.txt
 
echo "Done! Results in: $DEST"


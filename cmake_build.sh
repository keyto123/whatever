# rm -rf build
name=thegame
mkdir build
set -e
cd build
cmake -G Ninja ..
cmake --build .
cd ..

if [ -f "$name" ]; then
    rm $name
fi
ln -s build/$name $name
./$name
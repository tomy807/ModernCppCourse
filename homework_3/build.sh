rm -r build
rm -r test.html
mkdir build
cd build
cmake ..
make 
cd ..
./bin/main >test.html
explorer.exe test.html

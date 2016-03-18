IF NOT EXIST _build (mkdir _build)

cd _build
cmake ../ -G "Visual Studio 12"
msbuild "Darc Engine.sln"
msbuild "INSTALL.vcxproj"
cd ..
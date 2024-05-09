BUILD AND COMPILE:

cmake . -B build

cmake --build <build folder name> --config <debug or release> (release does not work)

To run executable:
<build folder name>\<debug or release>\<filename>.exe

usually run from the debug subfolder with filename: App, and build folder: build

To clean build:
cmake --build <build folder name> --target clean
# mirc-tolk
An mIRC library to wrap [Tolk](http://davykager.com/projects/tolk "Tolk Official Site") for speech output via screen reader APIs.

## License And Credits
This project is licensed under the GNU Lesser General Public License (LGPL), V3.0. This is for maximum compatibility with Tolk, which is licensed LGPL V3.

Many thanks to Davy Kager for writing the Tolk library.

## Installation
Copy mirctolk.dll, Tolk.dll, dolapi32.dll, nvdaControllerClient32.dll, and SAAPI32.dll to the directory where mIRC.exe resides.
For your convenience, prebuilt binaries can be found in the bin directory of this repository.

## Usage
### Functions
The DLL provides the following functions.
* output - Speak and braille a string.
* output_interrupt - Cancel speech, then speak and braille a string.
* speak - Speak a string.
* speak_interrupt - Cancel speech, then speak a string.
* braille - Braille a string.
* silence - Cancel speech.
* detect_screenreader - Return the name of the currently running screen reader or NULL.

### Examples
Speak and braille some text:

> /dll tolkbridge.dll output Hello world!

Print the name of the currently running screen reader:

> //echo $dll(tolkbridge, detect_screenreader, $null)

## Compiling
In order to build mirctolk.dll from source, do the following.
1.  Either build Tolk from [source](https://github.com/dkager/tolk "Tolk GitHub Page"), or download the most recent [binary release](http://davykager.com/files/tolk/tolk-latest.zip "Tolk Binaries Direct Link").
2.  Copy the following files from the Tolk distribution to the src directory of this repository.
	* Tolk.dll from bin\x86
	* Tolk.lib from bin\x86 (Needed if compiling with MSVC)
	* dolapi32.dll from lib\x86
	* nvdaControllerClient32.dll from lib\x86
	* SAAPI32.dll from lib\x86
	* Tolk.h from src
3.  Either run compile-gcc.bat or compile-msvc.bat, depending on the compiler being used. Note that the batch scripts expect the compiler to be in the path.

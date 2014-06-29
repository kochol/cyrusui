#ifndef CUIDEF_H_INCLUDED
#define CUIDEF_H_INCLUDED

//************************************
// Version Information
//************************************
#define CUI_VERSION_NUM 0.1.0
#define CUI_VERSION_MAJOR 0
#define CUI_VERSION_MINOR 1
#define CUI_VERSION_RELEASE 0
#define CUI_VERSION_SUFFIX ""
#define CUI_VERSION_NAME "Cyrus UI 0.1.0"

#define CUI_VERSION ((CUI_VERSION_MAJOR << 16) | (CUI_VERSION_MINOR << 8) | CUI_VERSION_RELEASE)

//**************************************
// compiler and platform
//**************************************

#define CUI_PLATFORM_UNKNOWN 0 // Unknown platform
#define CUI_PLATFORM_WINDOWS 1 // Microsoft Windows
#define CUI_PLATFORM_LINUX 2 // Linux OS
#define CUI_PLATFORM_APPLE 3 // Apple MAC-OS
#define CUI_PLATFORM_ANDROID 4 // Android platform

#define CUI_COMPILER_UNKNOWN 0 // Unknown compiler
#define CUI_COMPILER_MSVC 1 // Microsoft Visual C++
#define CUI_COMPILER_GNUC 2 // GNU C/C++ compilers
#define CUI_COMPILER_BORL 3 // Borland C/C++ compiler
#define CUI_COMPILER_NDK 4 // NDK build system

#define CUI_ARCHITECTURE_UNKNOWN 0 // Unknown architecture
#define CUI_ARCHITECTURE_32 1 // 32-bit architecture CPU
#define CUI_ARCHITECTURE_64 2 // 64-bit architecture CPU

// find compiler type and version
#if defined( _MSC_VER )
#define CUI_COMPILER CUI_COMPILER_MSVC
#define CUI_COMP_VER _MSC_VER

#elif defined( __GNUC__ )
#define CUI_COMPILER CUI_COMPILER_GNUC
#define CUI_COMP_VER (((__GNUC__)*100) + \
(__GNUC_MINOR__*10) + \
__GNUC_PATCHLEVEL__)

#elif defined( __BORLANDC__ )
#define CUI_COMPILER CUI_COMPILER_BORL
#define CUI_COMP_VER __BCPLUSPLUS__

#elif defined( NDK )
#define CUI_COMPILER CUI_PLATFORM_ANDROID
#define CUI_COMP_VER 7

#else
#define CUI_COMPILER CUI_COMPILER_UNKNOWN
#pragma error "No known compiler. Compiling Abrot!"
#endif

// finds the platform
#if defined( __WIN32__ ) || defined( _WIN32 ) || defined(_WIN64)
#define CUI_PLATFORM CUI_PLATFORM_WINDOWS
#elif defined( __APPLE_CC__)
#define CUI_PLATFORM CUI_PLATFORM_APPLE
#elif defined(ANDROID)
#define CUI_PLATFORM CUI_PLATFORM_ANDROID
#elif defined(__unix__)
#define CUI_PLATFORM CUI_PLATFORM_LINUX
#else
#define CUI_PLATFORM CUI_PLATFORM_UNKNOWN
#endif

// finds the CPU architecture type
#if defined(__x86_x64__) || defined(_M_X64) || defined(__powerpc64__) || defined(__alpha__) || defined(__ia64__) || defined(__s390__) || defined(__s390x__)
#define CUI_ARCHITECTURE_TYPE CUI_ARCHITECTURE_64
#else
#define CUI_ARCHITECTURE_TYPE CUI_ARCHITECTURE_32
#endif

//*************************************
// Defining debug mode
//*************************************
#if defined(DEBUG) || defined(_DEBUG)
#define CUI_DEBUG_MODE 1
#else
#define CUI_DEBUG_MODE 0
#endif

//**************************************
// unicode
//**************************************
#if defined(_UNICODE) && (CUI_USE_UNICODE == 1)
#define CUI_SUPPORT_UNICODE 1
#else
#define CUI_SUPPORT_UNICODE 0
#endif

//**************************************
// compiler specific config
//**************************************

#if CUI_COMPILER == CUI_COMPILER_MSVC
// common compiler defines
#define CUI_USE_MSVC_ASM 1
#ifdef CUI_EXPORT
#define CUI_API __declspec(dllexport)
#else
#define CUI_API __declspec(dllimport)
#endif
#define CUI_IMPORT __declspec( dllimport )
#define NAKED_FUNC void _declspec (naked)

#else
#define CUI_API
#define CUILIB_API
#define CUI_IMPORT
#define NAKED_FUNC void
#endif

#endif // CUIDEF_H_INCLUDED

#pragma once

#ifdef RACELIB_EXPORTS
#	define RACELIB_API __declspec(dllexport)
#else
#	define RACELIB_API __declspec(dllimport)
#endif

/*
  ==============================================================================

    Logging.h
    Created: 14 Jul 2015 4:00:51pm
    Author:  Michael

  ==============================================================================
*/

#ifndef LOGGING_H_INCLUDED
	#define LOGGING_H_INCLUDED

	// See http://stackoverflow.com/questions/1149620/how-to-write-to-the-output-window-in-visual-studio for details
	// and http://blog.wavosaur.com/debugging-vst-2-4-part-1-visual-studio/ for how to set up Cantabile debugging.
	// you'll need to make the working directory ".\Debug".

	#include <iostream>
	#include <string>
	#include <sstream>

	#ifdef WIN32
		#include <Windows.h>

		// Use this for logging on Windows - different characterset or something.
		#define LOG_W( s )            \
		{                             \
			std::wostringstream os_;    \
			os_ << s;                   \
			os_ << "\n";					\
			OutputDebugStringW( os_.str().c_str() );  \
		}

		// Use this for logging on Linux.
		#define LOG( s )            \
		{                             \
			std::ostringstream os_;    \
			os_ << s;					\
			os_ << "\n";					\
			OutputDebugString( os_.str().c_str() );  \
		}
	#endif

#endif  // LOGGING_H_INCLUDED